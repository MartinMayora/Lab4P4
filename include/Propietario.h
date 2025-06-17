#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include <string>
#include <set>
#include "Inmueble.h"
#include "DTInmuebleListado.h"
#include "Suscriptor.h"


class Inmueble;
class Inmobiliaria;

class Propietario : public Usuario, public Suscriptor{
    private:
        std::string cuentaBancaria;
        std::string telefono; 
        std::set<Inmueble*> inmuebles;
        std::set<Inmobiliaria*> inmobiliarias;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        ~Propietario();
        std::string getNickname();
        std::string getNombre();
        std::set<Inmueble*> getInmuebles();

        //CASO DE USO ALTA USUARIO
        void agregarInmueble(Inmueble* inmueble);
        void agregarInmobiliaria(Inmobiliaria* i);

        //CASO DE USO ALTA ADMINISTRACION DE PROPIEDAD
        std::set<DTInmuebleListado> getInmueblesNoAdmin(Inmobiliaria* i);

        //CASO DE USO ELIMINAR INMUEBLE
        void eliminarLinkPropietario(Inmueble* in);


};

#endif