#include "../include/Publicacion.h"
#include "../include/DTPublicacion.h"

Publicacion::Publicacion(int codigo, DTFecha *fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa)
    : codigo(codigo), fecha(fecha), tipo(tipo), texto(texto), precio(precio), activa(activa) {}

Publicacion::~Publicacion()
{
    delete fecha;
}

// Getters
int Publicacion::getCodigo() const
{
    return codigo;
}

DTFecha *Publicacion::getFecha() const
{
    return fecha;
}

TipoPublicacion Publicacion::getTipoPublicacion() const
{
    return tipo;
}

std::string Publicacion::getTexto() const
{
    return texto;
}

float Publicacion::getPrecio() const
{
    return precio;
}

bool Publicacion::getEstaActiva() const
{
    return activa;
}

DTPublicacion Publicacion::getDataPublicacion(std::string nombreInmobiliaria) const
{
    return DTPublicacion(codigo, fecha, texto, precio, nombreInmobiliaria);
}
//altapublicacion
bool Publicacion::existeFecha(DTFecha *fechaActual){
    return this->fecha->operator==(fechaActual);
}
bool Publicacion::existeTipoPub(TipoPublicacion TipoPublicacion){
    return this->getTipoPublicacion() == TipoPublicacion;
}
void Publicacion::actiualizarActivo(bool nuevoEstado){
    this->activa = nuevoEstado
}