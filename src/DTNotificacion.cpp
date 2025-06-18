#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion(std::string nickname, int codigo, std::string texto, TipoPublicacion tipo, TipoInmueble inmueble)
    : nickname(nickname), codigo(codigo), texto(texto), tipo(tipo), inmueble(inmueble) {}

std::string DTNotificacion::getNickname() const{
    return nickname;
}

int DTNotificacion::getCodigo() const{
    return codigo;
}

std::string DTNotificacion::getTexto() const{
    return texto;
}

TipoPublicacion DTNotificacion::getTipo() const{
    return tipo;
}

TipoInmueble DTNotificacion::getInmueble() const{
    return inmueble;
}


bool DTNotificacion::operator<(const DTNotificacion& other) const  {
    if (this->codigo != other.codigo)
        return this->codigo < other.codigo;
    
    return this->nickname < other.nickname;
}