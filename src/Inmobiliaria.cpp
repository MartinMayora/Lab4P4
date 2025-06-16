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

//getters
std::set<AdministraPropiedad*> Inmobiliaria::getAdmins(){
    return this->administra;
}

// Operaciones caso de uso ALTA ADMINISTRA PROPIEDAD
DTUsuario Inmobiliaria::getDTUsuario()
{
    return DTUsuario(this->getNickname(), this->getNombre());
}

std::set<DTInmuebleListado> Inmobiliaria::getInmueblesNoAdminPropietario()
{
    std::set<DTInmuebleListado> listInmueblesPropietario;

    std::set<Propietario *>::iterator it;
    std::set<Propietario *> propietariosfor = this->getPropietarios();
    std::cout << "[DEBUG] La inmobiliaria representa " << this->getPropietarios().size() << " propietarios." << std::endl;

    for (it = propietariosfor.begin(); it != propietariosfor.end(); ++it)
    {
        Propietario *p = *it;
        std::cout << "[DEBUG] Revisando propietario: " << p->getNickname()
                  << " con " << p->getInmuebles().size() << " inmuebles." << std::endl;

        std::set<DTInmuebleListado> aux = p->getInmueblesNoAdmin(this);
        std::cout << "[DEBUG] Inmuebles no administrados por esta inmobiliaria: " << aux.size() << std::endl;

        listInmueblesPropietario.insert(aux.begin(), aux.end());
    }

    std::cout << "[DEBUG] Total de inmuebles no administrados encontrados: " << listInmueblesPropietario.size() << std::endl;

    return listInmueblesPropietario;
}


void Inmobiliaria::altaAdministraPropiedad(Inmueble *inmueble, DTFecha *fechaActual)
{
    AdministraPropiedad *ap = new AdministraPropiedad(this, inmueble, fechaActual);
    this->administra.insert(ap);
    inmueble->asociarAdministracionPropiedad(ap);
}

// Operaciones caso de uso ALTA DE PUBLICACION

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


// Operaciones caso de uso SUSCRIBIRSE A NOTIFICACIONES
bool Inmobiliaria::tieneSuscriptor(std::string nickname)
{
    // para cada suscriptor del set chequea si es cliente o propietario y si el nickname coincide
    std::set<Suscriptor *>::iterator it;
    for (it = suscriptores.begin(); it != suscriptores.end(); ++it)
    {
        Cliente *c = dynamic_cast<Cliente *>(*it);
        if (c != NULL && c->getNickname() == nickname)
            return true;

        Propietario *p = dynamic_cast<Propietario *>(*it);
        if (p != NULL && p->getNickname() == nickname)
            return true;
    }
    return false;
}

bool Inmobiliaria::estaSuscripto(Suscriptor *s)
{
    return this->suscriptores.find(s) != this->suscriptores.end();
}

void Inmobiliaria::agregarSuscriptor(Suscriptor *s)
{
    suscriptores.insert(s);

}

std::set<Propietario*> Inmobiliaria::getPropietarios() {
    return this->propietarios; 
}


// Eliminar Suscripcion
void Inmobiliaria::eliminarSuscriptor(Suscriptor *s)
{
    suscriptores.erase(s);
    delete s;
};

//OPERACIONES CASO DE USO ALTA DE USUARIO
void Inmobiliaria::agregarPropietario(Propietario* propietario) {
    this->propietarios.insert(propietario); 
}
