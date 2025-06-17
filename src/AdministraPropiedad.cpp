#include "../include/AdministraPropiedad.h"
#include "../include/Inmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/Publicacion.h"

AdministraPropiedad::~AdministraPropiedad() {
  
}
AdministraPropiedad::AdministraPropiedad(Inmobiliaria* i, Inmueble* inm, DTFecha* fecha) {
    this->inmobiliaria = i;
    this->inmueble = inm;
    this->fecha = fecha;
}

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

bool AdministraPropiedad::inmobiliariaAsociada(Inmobiliaria* i){
    return (i == inmobiliaria);
}

void AdministraPropiedad::eliminarLinkPublicacion() {
    for (std::set<Publicacion*>::iterator it = this->publicaciones.begin(); it != this->publicaciones.end(); ++it) {
        Publicacion* pub = *it;
        delete pub;
    }
    this->publicaciones.clear();
}

//ALTAPUBLICACION
bool AdministraPropiedad::tieneInmueble(int codigoInmueble){
    int codigo = this->inmueble->getCodigo();
    return codigoInmueble == codigo;
}

void AdministraPropiedad::agregarPublicacion(Publicacion* aAgregar){
    this->publicaciones.insert(aAgregar);
}
