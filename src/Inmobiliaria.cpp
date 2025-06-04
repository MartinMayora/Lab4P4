#include "../include/Inmobiliaria.h"

//Constructor
Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, 
    std::string direccion, std::string url, std::string telefono):Usuario(nickname,contrasena,nombre,email), 
    direccion(direccion),url(url),telefono(telefono){
}

//Destructor
Inmobiliaria::~Inmobiliaria(){
}
