#include "../include/ControladorInmueble.h"
#include "../include/ManejadorInmueble.h"
#include "../include/ManejadorUsuario.h"
#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include "../include/AdministraPropiedad.h"
#include "../include/DTInmuebleListado.h"
#include <string>
#include <map>
#include <set>


ControladorInmueble* ControladorInmueble::instancia = NULL;

ControladorInmueble* ControladorInmueble::getInstance() {
    if (instancia == NULL)
        instancia = new ControladorInmueble();
    return instancia;
}

std::set<DTInmuebleListado> ControladorInmueble::listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria){
    std::set<DTInmuebleListado> listInmuebles;
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    Inmobiliaria* ci = m->getInmobiliaria(nicknameInmobiliaria);
    listInmuebles = ci->getInmueblesNoAdminPropietario();
    return listInmuebles;
}

std::set<DTPublicacion> ControladorInmueble::listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble) {
    ManejadorInmueble* manejador = ManejadorInmueble::getInstance();
    return manejador->getPublicaciones(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
}

bool ControladorInmueble::altaPublicacion(std::string nicknameInmobiliaria,int codigoInmueble,TipoPublicacion tipoPublicacion, std::string texto, float precio){
    ManejadorInmueble* manejador = ManejadorInmueble::getInstance();
    return  manejador->darInmobiliaria(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto);

}