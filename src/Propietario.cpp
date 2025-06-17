#include "../include/Propietario.h"
#include "../include/Inmueble.h"

//Constructor
Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre,
                         std::string email, std::string cuentaBancaria, std::string telefono)
    : Usuario(nickname, contrasena, nombre, email), cuentaBancaria(cuentaBancaria), telefono(telefono) {
}

//Destructor 
Propietario::~Propietario(){ 
}

//Getters
std::string Propietario::getNickname(){
    return Usuario::getNickname();
}

std::string Propietario::getNombre(){
    return Usuario::getNombre();
}

std::set<Inmueble*> Propietario::getInmuebles() {
    return this->inmuebles;
}


//CASO DE USO ALTA USUARIO
void Propietario::agregarInmueble(Inmueble* inmueble) {
    inmuebles.insert(inmueble);
}

void Propietario::agregarInmobiliaria(Inmobiliaria* i) {
    this->inmobiliarias.insert(i);
}


//CASO DE USO ALTA ADMINISTRACION PROPIEDAD
std::set<DTInmuebleListado> Propietario::getInmueblesNoAdmin(Inmobiliaria* i){
    std::set<DTInmuebleListado> listInmueblesPropietario;
    std::set<Inmueble*>::iterator it;
    for(it = inmuebles.begin(); it != inmuebles.end(); ++it){
        Inmueble* in = *it;
        bool administrado = in->esAdministrado(i);
        if (!administrado){
            listInmueblesPropietario.insert(DTInmuebleListado(in->getCodigo(), in->getDireccion(), this->getNickname()));
        }
    }
    return listInmueblesPropietario;
}


//CASO DE USO ELIMINAR INMUEBLE
void Propietario::eliminarLinkPropietario(Inmueble* in) {
    this->inmuebles.erase(in);
}


