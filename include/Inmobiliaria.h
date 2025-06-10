#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "Propietario.h"
#include "AdministraPropiedad.h"
#include "DTUsuario.h"
#include "DTInmuebleListado.h"
#include <string>
#include <set>

class AdministraPropiedad; 

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;
        //agregue set de propietarios
        std::set<Propietario*> propietarios;
        std::set<AdministraPropiedad*> administra;
    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
        ~Inmobiliaria();
        //agregue funciones para set de propietarios agregar y get por si desp sirven
        void agregarPropietario(Propietario* p);
        std::set<Propietario*> getPropietarios();

        //Operaciones caso de uso ALTA PUBLICACION 
        void publicarInmueble();

        DTUsuario getDTUsuario();
        
        // para func listarInmueblesNoAdministradosInmobiliaria
        std::set<DTInmuebleListado> getInmueblesNoAdminPropietario();

        void altaAdministraPropiedad(Inmueble* inmueble, DTFecha* fechaActual);

        //Operaciones caso de uso SUSCRIBIRSE A NOTIFICACIONES
        bool tieneSuscriptor(std::string nickname);
  


};

#endif