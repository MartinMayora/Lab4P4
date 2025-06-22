#include "../include/Casa.h"

Casa::Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion,
           bool esPH, TipoTecho techo) : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion), esPH(esPH), techo(techo)
{
}

Casa::~Casa()
{
}

TipoInmueble Casa::getTipoInmueble()
{
    return TipoCasa;
}

bool Casa::getEsPH() const {
    return this->esPH;
}

TipoTecho Casa::getTecho() const {
    return this->techo;
}
