#include "../include/AdministraPropiedad.h"
#include "../include/Inmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/Publicacion.h"

AdministraPropiedad::~AdministraPropiedad() {
    this->eliminarLinkPublicacion();
    if (this->fecha != NULL) {
        delete this->fecha;
        this->fecha = NULL;
    }
}
AdministraPropiedad::AdministraPropiedad(Inmobiliaria* i, Inmueble* inm, DTFecha* fecha) {
    this->inmobiliaria = i;
    this->inmueble = inm;
    this->fecha = fecha;
}

//Getters
DTFecha* AdministraPropiedad::getFecha(){
    return fecha;
}

Inmobiliaria* AdministraPropiedad::getInmobiliaria(){
    return inmobiliaria;
}
Inmueble* AdministraPropiedad::getInmueble(){
    return inmueble;
}

std::set<Publicacion*>& AdministraPropiedad::getPublicaciones(){
    return this->publicaciones;
}

//CASO DE USO ALTA ADMINISTRACION PROPIEDAD
bool AdministraPropiedad::inmobiliariaAsociada(Inmobiliaria* i){
    return (i == inmobiliaria);
}

//CASO DE USO ELIMINAR INMUEBLE
void AdministraPropiedad::eliminarLinkPublicacion() {
    for (std::set<Publicacion*>::iterator it = this->publicaciones.begin(); it != this->publicaciones.end(); ++it) {
        Publicacion* pub = *it;
        delete pub;
    }
    this->publicaciones.clear();
}

//CASO DE USO ALTA PUBLICACION
bool AdministraPropiedad::tieneInmueble(int codigoInmueble){
    int codigo = this->inmueble->getCodigo();
    return codigoInmueble == codigo;
}