#ifndef IALTAUSUARIO_H
#define IALTAUSUARIO_H

#include "DTUsuario.h"
#include "TipoTecho.h"
#include <string>
#include <set>

class IAltaUsuario {
    public:
        virtual bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento) = 0;
        virtual bool altaPropietario(std::string nickname, std::string contrasena,std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) = 0;
        virtual bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url,std::string telefono) = 0;
        virtual void altaCasa(std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo) = 0;
        virtual void altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor,float gastosComunes) = 0;
        virtual std::set<DTUsuario> listarPropietarios() = 0;
        virtual bool representarPropietario(std::string nicknamePropietario) = 0;
        virtual void finalizarAltaUsuario() = 0;
        virtual ~IAltaUsuario(){};
};

#endif