#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include <cstddef>
#include "../include/ControladorUsuario.h"


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