#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include "Usuario.h"
#include "Cliente.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include <string>
#include <map>

class Usuario;
class Cliente;
class Propietario;
class Inmobiliaria;

class ManejadorUsuario {
private:
<<<<<<< HEAD
    map<string, Usuario*> usuarios;
    map<string, Cliente*> clientes;
    map<string, Propietario*> propietarios;
    std::set<Inmobiliaria*> inmobiliarias;
=======
    std::map<std::string, Usuario*> usuarios;
    std::map<std::string, Cliente*> clientes;
    std::map<std::string, Propietario*> propietarios;
    std::map<std::string, Inmobiliaria*> inmobiliarias;
>>>>>>> e97bfb04a8cf650f348a62c310b1c573990484bc

    static ManejadorUsuario* instancia;

    ManejadorUsuario(); 
    ~ManejadorUsuario();

public:
    static ManejadorUsuario* getInstance();
    static void deleteInstance();


    //Operaciones caso de uso ALTA USUARIO
    bool existeUsuario(std::string nickname);
    bool crearCliente(std::string nickname, std::string contrasena, std::string nombre,std::string email, 
        std::string apellido, std::string documento);
    bool crearPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, 
        std::string cuentaBancaria, std::string telefono);
    bool crearInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, 
        std::string direccion, std::string url,std::string telefono);
<<<<<<< HEAD
    
    bool existeInmobiliaria(map<string, Inmobiliaria*> inmobiliarias; std::string nickname)
=======
    std::set<DTUsuario> listarPropietarios();
    void representarPropietario(std::string nicknamePropietario, Inmobiliaria* inmobiliariaRecordada);
>>>>>>> e97bfb04a8cf650f348a62c310b1c573990484bc
    Propietario* getPropietario(std::string nickname);
    Inmobiliaria* getInmobiliaria(std::string nicknameInmobiliaria);

    //Operaciones caso de uso ALTA DE ADMINISTRACION DE PROPIEDAD
    std::map<std::string, Inmobiliaria*>& getInmobiliarias();

    //Operaciones caso de uso SUSCRIBIRSE A NOTIFICACIONES
    std::set<std::string> listarInmobiliariasNoSuscriptas(std::string nicknameUsuario);
    void suscribirseAInmobiliaria(std::string nicknameUsuario, std::string nicknameInmobiliaria);


};

#endif
