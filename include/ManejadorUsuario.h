#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include "Usuario.h"
#include "Cliente.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include "ICollection.h"
#include <string>
#include <map>

class ManejadorUsuario {
private:
    map<string, Usuario*> usuarios;
    map<string, Cliente*> clientes;
    map<string, Propietario*> propietarios;
    map<string, Inmobiliaria*> inmobiliarias;

    static ManejadorUsuario* instancia;

    ManejadorUsuario(); 
    ~ManejadorUsuario();

public:
    static ManejadorUsuario* getInstance();
    static void deleteInstance();

    bool crearCliente(std::string nickname, std::string contrasena, std::string nombre,std::string email, std::string apellido, std::string documento);

    bool crearPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);

    bool crearInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url,std::string telefono);
};

#endif
