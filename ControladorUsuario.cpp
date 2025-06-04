#include "../include/...ControladorUsuario.h"
#include "../include/...ManejadorUsuario.h"
#include "../include/...Cliente.h"
#include "../include/...Propietario.h"
#include "../include/...Inmobiliaria.h"
#include "../include/...DTUsuario.h"

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

bool ControladorUsuario::altaCliente(std::string nickname, std::string contrasena,std::string nombre, std::string email,std::string apellido, std::string documento) {
    return ManejadorUsuario::getInstance()->crearCliente(nickname, contrasena, nombre, email, apellido, documento);
}
