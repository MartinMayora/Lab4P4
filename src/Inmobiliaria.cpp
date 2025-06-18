#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"
#include "../include/DTInmuebleListado.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include <iostream>

// Constructor
Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email,
                           std::string direccion, std::string url, std::string telefono) : Usuario(nickname, contrasena, nombre, email),
                                                                                           direccion(direccion), url(url), telefono(telefono)
{
}

// Destructor
Inmobiliaria::~Inmobiliaria()
{
}

// Getters
std::set<AdministraPropiedad*> Inmobiliaria::getAdmins(){
    return this->administra;
}

std::set<Propietario*> Inmobiliaria::getPropietarios(){
    return this->propietarios; 
}

//CASO DE USO ALTA DE PUBLICACION
std::set<DTInmuebleAdministrado> Inmobiliaria::getAdministrados(){
    std::set<AdministraPropiedad*>::iterator administraAux;
    std::set<DTInmuebleAdministrado> aReturn;
    for(administraAux = this->administra.begin(); administraAux != this->administra.end(); ++administraAux){
        AdministraPropiedad* ap = *administraAux;
        DTFecha* fecha = (*ap).getFecha();
        Inmueble* inm = (*ap).getInmueble();
        int codigo = inm->getCodigo();
        std::string direccion = inm->getDireccion();
        DTInmuebleAdministrado* aAgregar = new DTInmuebleAdministrado(codigo, direccion, fecha);
        aReturn.insert(*aAgregar);
    }
    return aReturn;
}

void Inmobiliaria::agregarNotificacion(std::string nickname,int codigoInmueble,std::string texto,TipoPublicacion tipoPublicacion, TipoInmueble tipoInmueble){
    DTNotificacion* notif = new DTNotificacion(nickname, codigoInmueble, texto, tipoPublicacion, tipoInmueble);
    std::set<Suscriptor*> suscriptores = this->suscriptores;
    std::set<Suscriptor*>::iterator it;
    for( it = suscriptores.begin(); it != suscriptores.end(); ++it){
        Suscriptor* sus = * it;
        sus->agregarNotificacion(*notif);
    }
}
//CASO DE USO ALTA ADMINISTRA PROPIEDAD
DTUsuario Inmobiliaria::getDTUsuario(){
    return DTUsuario(this->getNickname(), this->getNombre());
}

std::set<DTInmuebleListado> Inmobiliaria::getInmueblesNoAdminPropietario(){
    std::set<DTInmuebleListado> listInmueblesPropietario;
    std::set<Propietario *>::iterator it;
    std::set<Propietario *> propietariosfor = this->getPropietarios();
    for (it = propietariosfor.begin(); it != propietariosfor.end(); ++it){
        Propietario *p = *it;
        std::set<DTInmuebleListado> aux = p->getInmueblesNoAdmin(this);
        listInmueblesPropietario.insert(aux.begin(), aux.end());
    }
    return listInmueblesPropietario;
}


void Inmobiliaria::altaAdministraPropiedad(Inmueble *inmueble, DTFecha *fechaActual){
    AdministraPropiedad *ap = new AdministraPropiedad(this, inmueble, fechaActual);
    this->administra.insert(ap);
    inmueble->asociarAdministracionPropiedad(ap);
}


//CASO DE USO SUSCRIBIRSE A NOTIFICACIONES
bool Inmobiliaria::tieneSuscriptor(std::string nickname) {
    for (std::set<Suscriptor*>::iterator it = suscriptores.begin(); it != suscriptores.end(); it++) {
        if ((*it)->getNickname() == nickname)
            return true;
    }
    return false;
}

bool Inmobiliaria::estaSuscripto(Suscriptor *s){
    return this->suscriptores.find(s) != this->suscriptores.end();
}

void Inmobiliaria::agregarSuscriptor(Suscriptor *s)
{
    suscriptores.insert(s);

}

//CASO DE USO ELIMINAR SUSCRIPCIONES
void Inmobiliaria::eliminarSuscriptor(Suscriptor *s){
    suscriptores.erase(s);
    delete s;
};

//CASO DE USO ALTA DE USUARIO
void Inmobiliaria::agregarPropietario(Propietario* propietario) {
    this->propietarios.insert(propietario); 
}
