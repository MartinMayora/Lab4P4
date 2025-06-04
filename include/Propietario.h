#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include <string>
#include <set>
#include "Inmueble.h"

class Propietario : public Usuario {
    private:
        std::string cuentaBancaria;
        std::string telefono;
        //agregue un set a lo q ya venia 
        std::set<Inmueble*> inmuebles;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        ~Propietario();
        void agregarInmueble(Inmueble* inmueble);
        std::string getNickname();
        std::string getNombre();

};

#endif