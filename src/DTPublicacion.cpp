#include "../include/DTPublicacion.h"

DTPublicacion::DTPublicacion(int codigo, DTFecha *fecha, std::string texto, float precio, std::string inmobiliaria)
{
    this->codigo = codigo;
    this->fecha = new DTFecha(fecha);
    this->texto = texto;
    this->precio = precio;
    this->inmobiliaria = inmobiliaria;
}

int DTPublicacion::getCodigo()
{
    return codigo;
}

DTFecha *DTPublicacion::getFecha()
{
    return fecha;
}

std::string DTPublicacion::getTexto()
{
    return texto;
}

float DTPublicacion::getPrecio() const
{
    return precio;
}

std::string DTPublicacion::getInmobiliaria()
{
    return inmobiliaria;
}

DTPublicacion::~DTPublicacion()
{
    delete fecha;
}