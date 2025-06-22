#ifndef ICONSULTADENOTIFICACIONES_H
#define ICONSULTADENOTIFICACIONES_H

#include <set>
#include "DTNotificacion.h"
class IConsultaDeNotificaciones{
    //en las interfaces agregamos todas las operaciones que corresponden al caso de uso 
    public:
        virtual std::set<DTNotificacion> listarNotificaciones(std::string nickname)=0;
        virtual void eliminarNotificaciones(std::string nickname)=0;
        virtual std::set<std::string> listarSuscriptos()=0;
};

#endif