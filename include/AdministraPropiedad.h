#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"
#include "Inmobiliaria.h"
#include "Publicacion.h"

class Inmobiliaria;
class Inmueble;

class AdministraPropiedad {
    private:
        DTFecha* fecha;
        Inmobiliaria* inmobiliaria;
        Inmueble* inmueble;
        Publicacion* publicacion;

    public:
        AdministraPropiedad(Inmobiliaria* i, Inmueble* inm, DTFecha* fecha);
        ~AdministraPropiedad();

        //getters
        DTFecha* getFecha();
        Inmobiliaria* getInmobiliaria();
        Inmueble* getInmueble();
        Publicacion* getPub();

        // para func listarInmueblesNoAdministradosInmobiliaria
        bool inmobiliariaAsociada(Inmobiliaria* i);

};

#endif