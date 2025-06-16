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
        //agregue un set a lo q ya venia 
        std::set<Inmueble*> inmuebles;
        //son las inmobiliarias que representan al propietario 
        std::set<Inmobiliaria*> inmobiliarias;


    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        ~Propietario();
        void agregarInmueble(Inmueble* inmueble);
        void agregarInmobiliaria(Inmobiliaria* i);

        std::string getNickname();
        std::string getNombre();

        // para func listarInmueblesNoAdministradosInmobiliaria
        std::set<DTInmuebleListado> getInmueblesNoAdmin(Inmobiliaria* i);
        void eliminarLinkPropietario(Inmueble* in);
        std::set<Inmueble*> getInmuebles();


};

#endif