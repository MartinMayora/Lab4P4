#include "../include/DTDato.h"

DTDato::DTDato(std::string nombre, TipoInmueble ti) {
    this->nombre = nombre;
    this->ti = ti;
}

std::string DTDato::getNombre() const {
    return nombre;
}

TipoInmueble DTDato::getTi() const {
    return ti;
}

bool DTDato::operator<(const DTDato& other) const {
    return nombre < other.nombre; 
}
