#include "../include/ManejadorUsuario.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"

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

Propietario* ManejadorUsuario::getPropietario(std::string nickname) {
    auto it = propietarios.find(nickname);  
    if (it != propietarios.end())
        return it->second;
    else
        return NULL;
        
}

Inmobiliaria* ManejadorUsuario::getInmobiliaria(std::string nickname) {
    auto it = inmobiliarias.find(nickname);  
    if (it != inmobiliarias.end())
        return it->second;
    else
        return NULL;
        
}

std::set<DTUsuario> ManejadorUsuario::listarPropietarios(){
    std::set<DTUsuario> resu;
    //recorremos todo el mapa de propietarios y para cada uno creamos un DTUsuario y agregamos al resultado
    for (std::map<std::string, Propietario*>::iterator i = propietarios.begin(); i!=propietarios.end(); i++) {
        Propietario* propietario = i->second;
        std::string nickname= propietario->getNickname();
        std::string nombre= propietario->getNombre();
         //creamos el DTUsuario
        DTUsuario dtUsuario = DTUsuario(nickname,nombre);
        resu.insert(dtUsuario);
    }
    return resu;
}

map<string, Inmobiliaria*>& ManejadorUsuario::getInmobiliarias(){
    return this->inmobiliarias;
}

Inmobiliaria* ManejadorUsuario::getInmobiliaria(std::string nicknameInmobiliaria){
    Inmobiliaria* iter = this->inmobiliarias.find(nicknameInmobiliaria);  
    if (iter != this->inmobiliarias.end())
        return iter->second;
    else
        return NULL;
}

void ManejadorUsuario::representarPropietario(std::string nicknamePropietario, Inmobiliaria* inmobiliariaRecordada) {
    auto p = propietarios.find(nicknamePropietario);
    if (p != propietarios.end()) {
        Propietario* propietario = it->second;
        propietario->agregarInmobiliaria(inmobiliariaRecordada);
}
}

