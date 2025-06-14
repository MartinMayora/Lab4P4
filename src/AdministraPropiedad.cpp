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
Publicacion* AdministraPropiedad::getPub(){
    return publicacion;
}

bool AdministraPropiedad::inmobiliariaAsociada(Inmobiliaria* i){
    return (i == inmobiliaria);
}