#ifndef SUSCRIPTOR_H
#define SUSCRIPTOR_H

#include "DTFecha.h"
#include "DTNotificacion.h"
#include <set>

class Suscriptor  {
private:
    std::set<DTNotificacion> notificaciones;
public:
    Suscriptor();
    Suscriptor(DTFecha ultimaFechaConsulta,std::set<DTNotificacion> notificaciones);
    virtual ~Suscriptor();
    void setUltimaFechaConsulta(DTFecha fecha);
    DTFecha getUltimaFechaConsulta();
    void agregarNotificacion(DTNotificacion notif);
    std::set<DTNotificacion> getNotificaciones();

};

#endif
