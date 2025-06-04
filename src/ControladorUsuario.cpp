#include "../include/ControladorUsuario.h"
#include "../include/ManejadorUsuario.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario() {
    this->propietarioRecordado = NULL;
    this->inmobiliariaRecordada = NULL;
}

ControladorUsuario* ControladorUsuario::getInstance() {
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

bool ControladorUsuario::altaCliente(std::string nickname, std::string contrasena,std::string nombre,
     std::string email,std::string apellido, std::string documento) {
    return ManejadorUsuario::getInstance()->crearCliente(nickname, contrasena, nombre, email, apellido, documento);
}

bool ControladorUsuario::altaPropietario(std::string nickname, std::string contrasena,std::string nombre,
     std::string email,std::string cuentaBancaria, std::string telefono) {
        ManejadorUsuario* mu = ManejadorUsuario::getInstance();
        bool alta= mu->crearPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        if (alta){
            propietarioRecordado=mu->getPropietario(nickname);
        }
    return alta;
}

bool ControladorUsuario::altaInmobiliaria(std::string nickname, std::string contrasena,std::string nombre,
     std::string email,std::string direccion, std::string url,std::string telefono){
    return ManejadorUsuario::getInstance()->crearPropietario(nickname, contrasena, nombre, email, direccion, url, telefono);
}

void ControladorUsuario::altaCasa(std::string direccion, int numeroPuerta, int superficie,
                                  int anioConstruccion, bool esPH, TipoTecho techo) {
    if (propietarioRecordado != NULL) {
        ManejadorInmueble::getInstance()->crearCasa(direccion, numeroPuerta, superficie, anioConstruccion,
            esPH, techo,propietarioRecordado);
    }
}
