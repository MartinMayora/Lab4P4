#include "../include/Suscriptor.h"

Suscriptor::Suscriptor(DTFecha ultimaFechaConsulta, std::set<DTNotificacion> notificaciones) {
    this->ultimaFechaConsulta = ultimaFechaConsulta;
    this->notificaciones = notificaciones;
}

Suscriptor::~Suscriptor() {
    
}

//me genera dudas 
void Suscriptor::setUltimaFechaConsulta(DTFecha fecha) {
    this->ultimaFechaConsulta = fecha;
}

DTFecha Suscriptor::getUltimaFechaConsulta() {
    return this->ultimaFechaConsulta;
}

void Suscriptor::agregarNotificacion(DTNotificacion notif) {
    this->notificaciones.insert(notif);
}

std::set<DTNotificacion> Suscriptor::getNotificaciones(){
    return this->notificaciones;
}
