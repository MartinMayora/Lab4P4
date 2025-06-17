#include "../include/Suscriptor.h"

Suscriptor::Suscriptor(DTFecha ultimaFechaConsulta, std::set<DTNotificacion> notificaciones) {
 this->notificaciones = notificaciones;
}

Suscriptor::Suscriptor(){
    
}
Suscriptor::~Suscriptor() {
    
}


void Suscriptor::agregarNotificacion(DTNotificacion notif) {
    this->notificaciones.insert(notif);
}

std::set<DTNotificacion> Suscriptor::getNotificaciones(){
    return this->notificaciones;
}

void Suscriptor::borrarNotificaciones() {
    this->notificaciones.clear();
}
