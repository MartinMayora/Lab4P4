#include "../include/ControladorUsuario.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorInmueble.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"
#include "../include/DTInmuebleListado.h"
#include <iostream>

ControladorUsuario *ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario()
{
    this->propietarioRecordado = NULL;
    this->inmobiliariaRecordada = NULL;
}

ControladorUsuario *ControladorUsuario::getInstance()
{
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

ControladorUsuario::~ControladorUsuario(){
    
}

void ControladorUsuario::deleteInstance() {
    if (instancia != NULL) {
        delete instancia;
        instancia = NULL;
    }
}


//CASO DE USO ALTA USUARIO 
bool ControladorUsuario::altaCliente(std::string nickname, std::string contrasena, std::string nombre,
                                     std::string email, std::string apellido, std::string documento)
{
    return ManejadorUsuario::getInstance()->crearCliente(nickname, contrasena, nombre, email, apellido, documento);
}

bool ControladorUsuario::altaPropietario(std::string nickname, std::string contrasena, std::string nombre,
                                         std::string email, std::string cuentaBancaria, std::string telefono)
{
    ManejadorUsuario *mu = ManejadorUsuario::getInstance();
    bool alta = mu->crearPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    if (alta)
    {
        propietarioRecordado = mu->getPropietario(nickname);
    }
    return alta;
}

bool ControladorUsuario::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre,
                                          std::string email, std::string direccion, std::string url, std::string telefono)
{
    ManejadorUsuario *mu = ManejadorUsuario::getInstance();
    bool alta = mu->crearInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    if (alta)
    {
        inmobiliariaRecordada = mu->getInmobiliaria(nickname);
    }
    return alta;
}

void ControladorUsuario::altaCasa(std::string direccion, int numeroPuerta, int superficie,
                                  int anioConstruccion, bool esPH, TipoTecho techo)
{
    if (propietarioRecordado != NULL)
    {
        ManejadorInmueble::getInstance()->crearCasa(direccion, numeroPuerta, superficie, anioConstruccion,
                                                    esPH, techo, this->propietarioRecordado);
    }

}

void ControladorUsuario::altaApartamento(std::string direccion, int numeroPuerta, int superficie,
                                         int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes)
{
    if (propietarioRecordado != NULL)
    {
        ManejadorInmueble::getInstance()->crearApartamento(direccion, numeroPuerta, superficie, anioConstruccion,
                                                           piso, tieneAscensor, gastosComunes, this->propietarioRecordado);
    }
}

std::set<DTUsuario> ControladorUsuario::listarPropietarios()
{
    return ManejadorUsuario::getInstance()->listarPropietarios();
}

bool ControladorUsuario::representarPropietario(std::string nicknamePropietario)
{
    if (inmobiliariaRecordada != NULL)
    {
        return ManejadorUsuario::getInstance()->representarPropietario(nicknamePropietario, inmobiliariaRecordada);
    }
    return false;
}


void ControladorUsuario::finalizarAltaUsuario()
{
    propietarioRecordado = NULL;
    inmobiliariaRecordada = NULL;
}



//CASO DE USO ALTA ADMINISTRACION PROPIEDAD
std::set<DTUsuario> ControladorUsuario::listarInmobiliarias(){
    std::set<DTUsuario> res;
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    std::map<std::string, Inmobiliaria*>& li = m->getInmobiliarias();
    std::map<std::string, Inmobiliaria*>::iterator iter;
    for(iter = li.begin(); iter != li.end(); ++iter){
        Inmobiliaria* i = iter->second;
        res.insert(i->getDTUsuario());
    }
    return res;
}

void ControladorUsuario::altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble){
    ManejadorUsuario* mU = ManejadorUsuario::getInstance();
    Inmobiliaria* ci = mU->getInmobiliaria(nicknameInmobiliaria);
    ManejadorInmueble* mI = ManejadorInmueble::getInstance();
    Inmueble* cin = mI->getInmueble(codigoInmueble);
    ci->altaAdministraPropiedad(cin, ControladorFechaActual::getInstance()->getFechaActual());
    ci->altaAdministraPropiedad(cin, ControladorFechaActual::getInstance()->getFechaActual());
}

std::set<DTInmuebleListado> ControladorUsuario::listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria)
{
    std::set<DTInmuebleListado> listInmuebles;
    ManejadorUsuario *m = ManejadorUsuario::getInstance();
    Inmobiliaria *ci = m->getInmobiliaria(nicknameInmobiliaria);
    listInmuebles = ci->getInmueblesNoAdminPropietario();
    return listInmuebles;
}

//CASO DE USO SUSCRIBIRSE A NOTIFICACIONES 
std::set<std::string> ControladorUsuario::listarInmobiliariasNoSuscriptas(std::string nicknameUsuario)
{
    return ManejadorUsuario::getInstance()->listarInmobiliariasNoSuscriptas(nicknameUsuario);
}

void ControladorUsuario::suscribirseAInmobiliaria(std::string nicknameUsuario, std::string nicknameInmobiliaria)
{
    ManejadorUsuario::getInstance()->suscribirseAInmobiliaria(nicknameUsuario, nicknameInmobiliaria);
}


//CASO DE USO ELIMINAR SUSCRIPCIONES
std::set<std::string> ControladorUsuario::listarSuscripciones(std::string nickname)
{
    return ManejadorUsuario::getInstance()->listarSuscripciones(nickname);
}

void ControladorUsuario::eliminarSuscripcion(std::string nicknameUsuario, std::string nicknameInmobiliaria)
{
    ManejadorUsuario::getInstance()->eliminarSuscripcion(nicknameUsuario, nicknameInmobiliaria);
}
