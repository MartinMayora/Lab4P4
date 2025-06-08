#include "../include/Usuario.h"


Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email):
nickname(nickname), contrasena(contrasena), nombre(nombre), email(email) {
}

Usuario::~Usuario() { }


std::string Usuario::getNickname(){
    return nickname;
}

std::string Usuario::getContrasena(){
    return contrasena;
}

std::string Usuario::getNombre(){
    return nombre;
}

std::string Usuario::getEmail(){
    return email;
}