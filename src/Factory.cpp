#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include <cstddef>
#include "../include/ControladorUsuario.h"
#include "../include/ControladorInmueble.h"
#include "../include/IEliminarInmueble.h"


Factory* Factory::instance = NULL;

Factory::Factory() {
}

Factory* Factory::getInstance() {
    if (instance == NULL) {
        instance = new Factory();
    }
    return instance;
}

IControladorFechaActual* Factory::getControladorFechaActual(){
    return ControladorFechaActual::getInstance();
}

IAltaUsuario* Factory::getAltaUsuario() {
    return ControladorUsuario::getInstance();
}

IAltaPublicacion* Factory::getAltaPublicacion(){
    return ControladorInmueble::getInstance();
}

IConsultaDePublicaciones* Factory::getConsultaDePublicaciones(){
    return ControladorInmueble::getInstance();
}

IEliminarInmueble* Factory::getEliminarInmueble() {
    return ControladorInmueble::getInstance(); 
}

ISuscribirseANotificaciones* Factory::getSuscribirseANotificaciones(){
    return ControladorUsuario::getInstance();
}


IEliminarSuscripciones* Factory::getEliminarSuscripciones(){
    return ControladorUsuario::getInstance();
}

IAltaAdministracionPropiedad* Factory::getAltaAdministracionPropiedad(){
    return ControladorUsuario::getInstance();
}

void Factory::deleteInstance(){
    if (instance != NULL) {
        delete instance; //aca llama al destructor ~Factory()
        instance = NULL;      
    }
}

void Factory::eliminarControladores(){
    ControladorFechaActual::deleteInstance();
    ControladorInmueble::deleteInstance();
    ControladorUsuario::deleteInstance();
}

Factory::~Factory(){
}