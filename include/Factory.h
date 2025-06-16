#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IAltaUsuario.h"
#include "IAltaAdministracionPropiedad.h"
#include "ISuscribirseANotificaciones.h"
#include "IEliminarSuscripciones.h"
#include "IConsultaDePublicaciones.h"
<<<<<<< HEAD
#include "IAltaPublicacion.h"
=======
#include "IEliminarInmueble.h"
>>>>>>> marcos
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
        ~Factory();
};

#endif