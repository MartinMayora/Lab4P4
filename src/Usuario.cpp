#include "../include/Usuario.h"


Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email):
nickname(nickname), contrasena(contrasena), nombre(nombre), email(email) {
}

Usuario::~Usuario() { }
