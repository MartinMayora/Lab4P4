#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IAltaUsuario.h"
#include "ISuscribirseANotificaciones.h"

class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        //TODO: Get interfaces de controladores
        IAltaUsuario* getAltaUsuario();
        ISuscribirseANotificaciones* getSuscribirseANotificaciones();
        IAltaAdministracionPropiedad* getAltaAdministracionPropiedad();
        ~Factory();
};

#endif