#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion(std::string nickname, int codigo, std::string texto, TipoPublicacion tipo, TipoInmueble inmueble)
    : nickname(nickname), codigo(codigo), texto(texto), tipo(tipo), inmueble(inmueble) {}

std::string DTNotificacion::getNickname(){
    return nickname;
}

int DTNotificacion::getCodigo(){
    return codigo;
}

std::string DTNotificacion::getTexto() {
    return texto;
}

TipoPublicacion DTNotificacion::getTipo() {
    return tipo;
}

TipoInmueble DTNotificacion::getInmueble()  {
    return inmueble;
}


bool DTNotificacion::operator<(const DTNotificacion& other) const  {
    if (this->codigo != other.codigo)
        return this->codigo < other.codigo;
    
    return this->nickname < other.nickname;
}