#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"
#include "../include/DTInmuebleListado.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"

//Constructor
Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, 
    std::string direccion, std::string url, std::string telefono):Usuario(nickname,contrasena,nombre,email), 
    direccion(direccion),url(url),telefono(telefono){
}

//Destructor
Inmobiliaria::~Inmobiliaria(){
}

//Operaciones caso de uso ALTA ADMINISTRA PROPIEDAD
DTUsuario Inmobiliaria::getDTUsuario(){
    return DTUsuario(this->getNickname(), this->getNombre());
}

std::set<DTInmuebleListado> Inmobiliaria::getInmueblesNoAdminPropietario(){
    std::set<DTInmuebleListado> listInmueblesPropietario;
    std::set<Propietario*>::iterator it;
    for(it = this->getPropietarios().begin(); it != this->getPropietarios().end(); ++it){
        Propietario* p = *it;
        std::set<DTInmuebleListado> aux = p->getInmueblesNoAdmin(this);
        listInmueblesPropietario.insert(aux.begin(), aux.end());
    }
    return listInmueblesPropietario;
}

void Inmobiliaria::altaAdministraPropiedad(Inmueble* inmueble, DTFecha* fechaActual){
    AdministraPropiedad* ap = new AdministraPropiedad(this, inmueble, fechaActual);
    this->administra.insert(ap);
    inmueble->asociarAdministracionPropiedad(ap);
}

//Operaciones caso de uso ALTA DE PUBLICACION 
void Inmobiliaria::publicarInmueble(){
    std::set<AdministraPropiedad*>::iterator administraAux;
    for(administraAux = this->administra.begin(); administraAux != this->administra.end(); ++administraAux){
        AdministraPropiedad* ap = *administraAux;
        //ap->tieneInmueble(codigoInmueble);
    }
}

/*std::set<DTInmuebleAdministrado> Inmobiliaria::getAdministrados(){
    std::set<AdministraPropiedad*>::iterator administraAux;
    for(administraAux = this->administra.begin(); administraAux != this->administra.end(); ++administraAux){
        AdministraPropiedad* ap = *administraAux;
        //ap.getFecha();
    }
}
*/


//Operaciones caso de uso SUSCRIBIRSE A NOTIFICACIONES
bool Inmobiliaria::tieneSuscriptor(std::string nickname) {
    //para cada suscriptor del set chequea si es cliente o propietario y si el nickname coincide 
    std::set<Suscriptor*>::iterator it;
    for (it = suscriptores.begin(); it != suscriptores.end(); ++it) {
        Cliente* c = dynamic_cast<Cliente*>(*it);
        if (c != NULL && c->getNickname() == nickname)
            return true;

        Propietario* p = dynamic_cast<Propietario*>(*it);
        if (p != NULL && p->getNickname() == nickname)
            return true;
    }
    return false;
}

bool Inmobiliaria::estaSuscripto(Suscriptor* s){
    return this->suscriptores.find(s)!=this->suscriptores.end();
}

void Inmobiliaria::agregarSuscriptor(Suscriptor* s){
    suscriptores.insert(s);

}

std::set<Propietario*> Inmobiliaria::getPropietarios() {
    return this->propietarios; 
}
