#include "../include/Publicacion.h"
#include "../include/DTPublicacion.h"
#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include "../include/AdministraPropiedad.h"
#include <iostream>

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

DTDato Publicacion::getDataPublicacion() const
{
    if (admin == NULL)
    {
        std::cerr << "Error: AdministraPropiedad no seteado en Publicacion." << std::endl;
        return DTDato("", TipoCasa); // Devolvé algo neutral o manejalo según tu diseño
    }

    Inmobiliaria *inmo = admin->getInmobiliaria();
    Inmueble *inmueble = admin->getInmueble();

    if (inmo == NULL || inmueble == NULL)
    {
        std::cerr << "Error: Inmobiliaria o Inmueble no seteados en AdministraPropiedad." << std::endl;
        return DTDato("", TipoCasa); // Idem
    }

    std::string nombre = inmo->getNombre();
    TipoInmueble ti = inmueble->getTipoInmueble();

    return DTDato(nombre, ti);
}

// CASO DE USO ALTA PUBLICACION
bool Publicacion::existeFecha(DTFecha *fechaActual)
{
    return this->fecha->operator==(fechaActual);
}
bool Publicacion::existeTipoPub(TipoPublicacion TipoPublicacion)
{
    return this->getTipoPublicacion() == TipoPublicacion;
}
void Publicacion::actiualizarActivo(bool nuevoEstado)
{
    this->activa = nuevoEstado;
}

void Publicacion::setAdministra(AdministraPropiedad *a)
{
    this->admin = a;
}

int Publicacion::getCodigoInmueble() const
{
    if (admin == NULL)
    {
        std::cerr << "Error: AdministraPropiedad no seteado en Publicacion." << std::endl;
        return -1; // Valor de error
    }

    Inmueble* inmueble = admin->getInmueble();

    if (inmueble == NULL)
    {
        std::cerr << "Error: Inmueble no seteado en AdministraPropiedad." << std::endl;
        return -1; // Valor de error
    }

    return inmueble->getCodigo();
}