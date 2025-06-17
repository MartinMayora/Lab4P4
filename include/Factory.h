#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IAltaUsuario.h"
#include "IAltaAdministracionPropiedad.h"
#include "ISuscribirseANotificaciones.h"
#include "IEliminarSuscripciones.h"
#include "IConsultaDeNotificaciones.h"
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
        //TODO: Get interfaces de controladores

        IAltaPublicacion* getAltaPublicacion();
        IAltaUsuario* getAltaUsuario();
        ISuscribirseANotificaciones* getSuscribirseANotificaciones();
        IAltaAdministracionPropiedad* getAltaAdministracionPropiedad();
        IEliminarSuscripciones* getEliminarSuscripciones();
        IConsultaDePublicaciones* getConsultaDePublicaciones();
        IEliminarInmueble* getEliminarInmueble();
        IConsultaDeNotificaciones* getConsultaDeNotificaciones();
        ~Factory();
};

#endif