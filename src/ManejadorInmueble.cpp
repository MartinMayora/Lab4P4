#include "../include/ManejadorInmueble.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/Propietario.h"

ManejadorInmueble* ManejadorInmueble::instancia = nullptr;


ManejadorInmueble* ManejadorInmueble::getInstance() {
    if (instancia == NULL)
        instancia = new ManejadorInmueble();
    return instancia;
}

void ManejadorInmueble::crearCasa(int codigo,std::string direccion, int numeroPuerta, int superficie,
                                  int anioConstruccion, bool esPH, TipoTecho techo, Propietario* propietario) {
    Casa* casa = new Casa(codigo, direccion, numeroPuerta, superficie, anioConstruccion, esPH, techo);
    //agregamos casa al set de inmuebles para propietario
    propietario->agregarInmueble(casa);
    //agregamos casa al map de inmuebles del manejador
    inmuebles[codigo]=casa;
}

void ManejadorInmueble::crearApartamento(int codigo,std::string direccion, int numeroPuerta, int superficie,
                                  int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes, Propietario* propietario) {
    Apartamento* apto = new Apartamento(codigo, direccion, numeroPuerta, superficie, anioConstruccion,piso, tieneAscensor,gastosComunes);
    //agregamos casa al set de inmuebles para propietario
    propietario->agregarInmueble(apto);
    //agregamos casa al map de inmuebles del manejador
    inmuebles[codigo]=apto;
}
