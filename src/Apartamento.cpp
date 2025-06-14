#include "../include/Apartamento.h"

Apartamento::Apartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion,
                         int piso, bool tieneAscensor, float gastosComunes) : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion),
                                                                              piso(piso), tieneAscensor(tieneAscensor), gastosComunes(gastosComunes)
{
}

Apartamento::~Apartamento()
{
}

TipoInmueble Apartamento::getTipoInmueble()
{
    return TipoApartamento;
}

int Apartamento::getPiso() {
    return this->piso;
}

bool Apartamento::getTieneAscensor(){
    return this->tieneAscensor;
}

float Apartamento::getGastosComunes(){
    return this->gastosComunes;
}


