#include "../include/ManejadorInmueble.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/Propietario.h"

ManejadorInmueble* ManejadorInmueble::instancia = nullptr;

ManejadorInmueble::ManejadorInmueble() {
    codInc = 0; 
}


ManejadorInmueble* ManejadorInmueble::getInstance() {
    if (instancia == NULL)
        instancia = new ManejadorInmueble();
    return instancia;
}

void ManejadorInmueble::crearCasa(std::string direccion, int numeroPuerta, int superficie,
                                  int anioConstruccion, bool esPH, TipoTecho techo, Propietario* propietario) {
    int codigo=codInc++;
    Casa* casa = new Casa(codigo,direccion, numeroPuerta, superficie, anioConstruccion, esPH, techo);
    //agregamos casa al set de inmuebles para propietario
    propietario->agregarInmueble(casa);
    //agregamos casa al map de inmuebles del manejador
    inmuebles[codigo]=casa;
}

void ManejadorInmueble::crearApartamento(std::string direccion, int numeroPuerta, int superficie,
                                  int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes,
                                   Propietario* propietario) {
    int codigo=codInc++;
    Apartamento* apto = new Apartamento(codigo,direccion, numeroPuerta, superficie, anioConstruccion,piso, tieneAscensor,gastosComunes);
    //agregamos casa al set de inmuebles para propietario
    propietario->agregarInmueble(apto);
    //agregamos casa al map de inmuebles del manejador
    inmuebles[codigo]=apto;

}

Inmueble* ManejadorInmueble::getInmueble(int codigoInmueble) {
    std::map<int, Inmueble*>::iterator iter = this->inmuebles.find(codigoInmueble);
    if (iter != this->inmuebles.end())
        return iter->second;
    else
        return NULL;
}
