#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"
#include "../include/DTInmuebleListado.h"
#include "../include/Propietario.h"

//Constructor
Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, 
    std::string direccion, std::string url, std::string telefono):Usuario(nickname,contrasena,nombre,email), 
    direccion(direccion),url(url),telefono(telefono){
}

//Destructor
Inmobiliaria::~Inmobiliaria(){
}

DTUsuario Inmobiliaria::getDTUsuario(){
    return DTUsuario(this->getNickname, this->getNombre);
}

std::set<DTInmuebleListado> Inmobiliaria::getInmueblesNoAdminPropietario(){
    std::set<DTInmuebleListado> listInmueblesPropietario;
    std::set<Propietario*>::iterator it;
    for(it = propietarios.begin(); it != propietarios.end; ++it){
        Propietario* p = *it;
        std::set<DTInmuebleListado> aux = p->getInmueblesNoAdmin(this);
        listInmueblesPropietario.insert(aux.begin(), aux.end());
    }
    return listInmueblesPropietario;
}

void Inmobiliaria::altaAdministraPropiedad(Inmueble* inmueble, DTFecha* fechaActual){
    AdministraPropiedad* ap = new AdministraPropiedad(this, inmueble, fechaActual);
    this->administra.insert(ap);
    inmueble.asociarAdministracionPropiedad(ap);
}