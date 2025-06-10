#include "../include/Inmueble.h"
#include "../include/AdministraPropiedad.h"


Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion):
codigo(codigo),direccion(direccion),numeroPuerta(numeroPuerta),superficie(superficie),anoConstruccion(anoConstruccion){

}

Inmueble::~Inmueble(){
    
}

//getters

int Inmueble::getCodigo() {
    return codigo;
}

std::string Inmueble::getDireccion() {
    return direccion;
}

int Inmueble::getNumeroPuerta() {
    return numeroPuerta;
}

int Inmueble::getSuperficie() {
    return superficie;
}

int Inmueble::getAnoConstruccion() {
    return anoConstruccion;
}

std::set<AdministraPropiedad*> Inmueble::getAdministraPropiedad(){
    return admprop;
}

bool Inmueble::esAdministrado(Inmobiliaria* i){
    std::set<AdministraPropiedad*>::iterator it;
    bool administra = false;
    for(it = admprop.begin(); it != admprop.end() && !administra; ++it){
        AdministraPropiedad* ap = *it;
        administra = ap->inmobiliariaAsociada(i);
    }
    return administra;
}

void Inmueble::asociarAdministracionPropiedad(AdministraPropiedad* ap){
    this->admprop.insert(ap);
}