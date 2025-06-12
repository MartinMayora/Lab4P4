#include "../include/ControladorInmueble.h"
#include "../include/ManejadorInmueble.h"
#include "../include/ManejadorUsuario.h"
#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include "../include/AdministraPropiedad.h"
#include <string>
#include <map>
#include <set>

ControladorInmueble *ControladorInmueble::instancia = NULL;

ControladorInmueble *ControladorInmueble::getInstance()
{
    if (instancia == NULL)
        instancia = new ControladorInmueble();
    return instancia;
}

std::set<DTPublicacion> ControladorInmueble::listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble)
{
    ManejadorInmueble *manejador = ManejadorInmueble::getInstance();
    return manejador->getPublicaciones(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
}

std::set<DTInmuebleListado> ControladorInmueble::listarInmuebles()
{
    ManejadorInmueble *manejador = ManejadorInmueble::getInstance();
    return manejador->darInmuebles();
}

// OPERACIONES ALTAPUBLICACION
bool ControladorInmueble::altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio)
{
    ManejadorUsuario *manejador = ManejadorUsuario::getInstance();
    return manejador->darInmobiliaria(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
}

std::set<DTInmuebleAdministrado> ControladorInmueble::listarInmueblesAdministrados(std::string nicknameInmobiliaria)
{
    return ManejadorUsuario::getInstance()->listarInmueblesAdministrados(nicknameInmobiliaria);
}
s