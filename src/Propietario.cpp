#include "../include/Propietario.h"
#include "../include/Inmueble.h"

Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre,
                         std::string email, std::string cuentaBancaria, std::string telefono)
    : Usuario(nickname, contrasena, nombre, email), cuentaBancaria(cuentaBancaria), telefono(telefono) {
}

void Propietario::agregarInmueble(Inmueble* inmueble) {
    inmuebles.insert(inmueble);
}


