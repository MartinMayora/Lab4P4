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

void Propietario::agregarInmueble(Inmueble* inmueble) {
    inmuebles.insert(inmueble);
}

//Getters
std::string Propietario::getNickname() {
    return getNickname();
}

std::string Propietario::getNombre(){
    return getNombre();
}




