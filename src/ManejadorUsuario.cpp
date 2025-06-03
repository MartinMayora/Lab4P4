#include "../include/ManejadorUsuario.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario() {}

ManejadorUsuario* ManejadorUsuario::getInstance() {
    if (instancia == NULL)
        instancia = new ManejadorUsuario();
    return instancia;
}

bool ManejadorUsuario::existeUsuario(const string& nickname) {
	return (this->usuarios.find(nickname) != this->usuarios.end())
}

bool ManejadorUsuario::crearCliente(std::string nickname, std::string contrasena, std::string nombre,
    std::string email, std::string apellido, std::string documento){
        if (existeUsuario(nickname)) 
            return false;
        else{
            Cliente* c = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
            usuarios.insert(nickname,c)
            clientes.insert(nickname,c);
            return true;
        }
    }

bool ManejadorUsuario::crearPropietario(std::string nickname, std::string contrasena, std::string nombre,
    std::string email, std::string cuentaBancaria, std::string telefono){
        if (existeUsuario(nickname)) 
            return false;
        else{
            Propietario* p = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
            usuarios.insert(nickname,p)
            propietarios.insert(nickname,p);
            return true;
        }
    }


bool ManejadorUsuario::crearInmobiliaria(std::string nickname, std::string contrasena, std::string nombre,
    std::string email, std::string direccion, std::string url, std::string telefono){
        if (existeUsuario(nickname)) 
            return false;
        else{
            Inmobiliaria* i = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url,telefono);
            usuarios.insert(nickname,i)
            inmobiliarias.insert(nickname,i);
            return true;
        }
    }

