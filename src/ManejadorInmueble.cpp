#include "../include/ManejadorInmueble.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTInmueble.h"
#include "../include/DTCasa.h"
#include "../include/DTApartamento.h"
#include "../include/DTDato.h"
#include <iostream>

ManejadorInmueble *ManejadorInmueble::instancia = NULL;

ManejadorInmueble::ManejadorInmueble()
{
    codInc = 1;
}

ManejadorInmueble *ManejadorInmueble::getInstance()
{
    if (instancia == NULL)
        instancia = new ManejadorInmueble();
    return instancia;
}

// CASO DE USO ALTA USUARIO
void ManejadorInmueble::crearCasa(std::string direccion, int numeroPuerta, int superficie,
                                  int anioConstruccion, bool esPH, TipoTecho techo, Propietario *propietario)
{
    int codigo = codInc++;
    Casa *casa = new Casa(codigo, direccion, numeroPuerta, superficie, anioConstruccion, esPH, techo);
    casa->setPropietario(propietario);
    propietario->agregarInmueble(casa);
    inmuebles[codigo] = casa;
}

void ManejadorInmueble::crearApartamento(std::string direccion, int numeroPuerta, int superficie,
                                         int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes,
                                         Propietario *propietario)
{
    int codigo = codInc++;
    Apartamento *apto = new Apartamento(codigo, direccion, numeroPuerta, superficie, anioConstruccion, piso, tieneAscensor, gastosComunes);
    apto->setPropietario(propietario);
    // agregamos casa al set de inmuebles para propietario
    propietario->agregarInmueble(apto);
    // agregamos casa al map de inmuebles del manejador
    inmuebles[codigo] = apto;
}
// CASO DE ALTA PUBLICACIO
void ManejadorInmueble::agregarPub(Publicacion *aAgregar)
{
    std::cout << aAgregar->getCodigo() << "AGREGADO \n";
    this->publicaciones.insert(aAgregar);
}
// CASO DE USO CONSULTA DE PUBLICACIONES
std::set<DTPublicacion> ManejadorInmueble::getPublicaciones(
    TipoPublicacion tipoPublicacion,
    float precioMinimo,
    float precioMaximo,
    TipoInmueble tipoInmueble)
{
    std::set<DTPublicacion> resultado;

    std::set<Publicacion *>::iterator it;
    for (it = publicaciones.begin(); it != publicaciones.end(); ++it)
    {
        Publicacion *p = *it;
        if (p->getEstaActiva() && p->getTipoPublicacion() == tipoPublicacion)
        {
            float precio = p->getPrecio();
            if (precio >= precioMinimo && precio <= precioMaximo)
            {
                DTDato dato = p->getDataPublicacion();
                if (dato.getTi() == tipoInmueble)
                {
                    DTPublicacion dtpub(
                        p->getCodigo(),
                        p->getFecha(),
                        p->getTexto(),
                        p->getPrecio(),
                        dato.getNombre());
                    resultado.insert(dtpub);
                }
            }
        }
    }

    return resultado;
}

DTInmueble *ManejadorInmueble::detalleInmueble(int codigo)
{
    std::map<int, Inmueble *>::iterator it = inmuebles.find(codigo);
    if (it == inmuebles.end())
        return NULL;

    Inmueble *in = it->second;
    if (in == NULL)
        return NULL;

    int cod = in->getCodigo();
    std::string dir = in->getDireccion();
    int puerta = in->getNumeroPuerta();
    int superficie = in->getSuperficie();
    int anio = in->getAnoConstruccion();
    // casa
    Casa *casa = dynamic_cast<Casa *>(in);
    if (casa != NULL)
    {
        return new DTCasa(cod, dir, puerta, superficie, anio,
                          casa->getEsPH(), casa->getTecho());
    }
    // apto
    Apartamento *apto = dynamic_cast<Apartamento *>(in);
    if (apto != NULL)
    {
        return new DTApartamento(cod, dir, puerta, superficie, anio,
                                 apto->getPiso(), apto->getTieneAscensor(), apto->getGastosComunes());
    }

    return NULL;
}

// CASO DE USO ELIMINAR INMUEBLE
std::set<DTInmuebleListado> ManejadorInmueble::darInmuebles()
{
    std::set<DTInmuebleListado> resultado;

    for (std::map<int, Inmueble *>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it)
    {
        Inmueble *in = it->second;

        if (in == NULL)
            continue;

        std::string propietario = "Desconocido";
        if (in->getPropietario() != NULL)
        {
            propietario = in->getPropietario()->getNickname();
        }

        DTInmuebleListado dtil(in->getCodigo(), in->getDireccion(), propietario);
        resultado.insert(dtil);
    }
    return resultado;
}

void ManejadorInmueble::eliminarInmueble(int codigoInmueble)
{
    Inmueble *in = this->getInmueble(codigoInmueble); // igual que find pero ya estaba escrita
    if (in == NULL)
        return;
    else
    {
        in->eliminarLinks();
        this->inmuebles.erase(codigoInmueble);
        delete in;
    }
}

Inmueble *ManejadorInmueble::getInmueble(int codigoInmueble)
{
    std::map<int, Inmueble *>::iterator iter = this->inmuebles.find(codigoInmueble);
    if (iter != this->inmuebles.end())
        return iter->second;
    else
        return NULL;
}

void ManejadorInmueble::eliminarPublicacion(Publicacion* pub) {
    publicaciones.erase(pub); // solo saca el puntero del set
}