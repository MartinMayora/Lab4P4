#include "../include/Publicacion.h"
#include "../include/DTPublicacion.h"
#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include "../include/AdministraPropiedad.h"

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

DTDato Publicacion::getDataPublicacion() const {
    std::string nombre = admin->getInmobiliaria()->getNombre();
    TipoInmueble ti = admin->getInmueble()->getTipoInmueble();

    return DTDato(nombre, ti);
}

//CASO DE USO ALTA PUBLICACION
bool Publicacion::existeFecha(DTFecha *fechaActual){
    return this->fecha->operator==(fechaActual);
}
bool Publicacion::existeTipoPub(TipoPublicacion TipoPublicacion){
    return this->getTipoPublicacion() == TipoPublicacion;
}
void Publicacion::actiualizarActivo(bool nuevoEstado){
    this->activa = nuevoEstado;
}