#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include <cstddef>
#include "../include/ControladorUsuario.h"
#include "../include/ControladorInmueble.h"

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

ISuscribirseANotificaciones* Factory::getSuscribirseANotificaciones(){
    return ControladorUsuario::getInstance();
}

IAltaAdministracionPropiedad* Factory::getAltaAdministracionPropiedad(){
    return ControladorUsuario::getInstance();
}

IEliminarSuscripciones* Factory::getEliminarSuscripciones(){
    return ControladorUsuario::getInstance();
}

IConsultaDePublicaciones* Factory::getConsultaDePublicaciones(){
    return ControladorInmueble::getInstance();
}