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

std::set<DTInmuebleListado> ControladorInmueble:: listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria){
    std::set<DTInmuebleListado> listInmuebles;
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    Inmobiliaria* ci = m->getInmobiliaria(nicknameInmobiliaria);
    listInmuebles = ci.getInmueblesNoAdminPropietario();
    return listInmuebles;
}