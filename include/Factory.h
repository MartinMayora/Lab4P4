#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IAltaUsuario.h"
#include "IAltaAdministracionPropiedad.h"
#include "ISuscribirseANotificaciones.h"
#include "IEliminarSuscripciones.h"
#include "IConsultaDePublicaciones.h"
#include "IAltaPublicacion.h"
#include "IEliminarInmueble.h"

class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        //Interfaces casos de uso, falta la de consultar suscripciones
        IAltaUsuario* getAltaUsuario();
        IAltaPublicacion* getAltaPublicacion();
        IConsultaDePublicaciones* getConsultaDePublicaciones();
        IEliminarInmueble* getEliminarInmueble();
        ISuscribirseANotificaciones* getSuscribirseANotificaciones();
        IEliminarSuscripciones* getEliminarSuscripciones();
        IAltaAdministracionPropiedad* getAltaAdministracionPropiedad();
        
        static void deleteInstance();
        void eliminarControladores();
        ~Factory();
};

#endif