#ifndef ICONSULTADENOTIFICACIONES_H
#define ICONSULTADENOTIFICACIONES_H

#include <set>
#include "DTNotificacion.h"
class IConsultaDeNotificaciones{
    //en las interfaces agregamos todas las operaciones que corresponden al caso de uso 
    public:
        virtual std::set<DTNotificacion> consultaNotificaciones(std::string nickname)= 0;
};

#endif