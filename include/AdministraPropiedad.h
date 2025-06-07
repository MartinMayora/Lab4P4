#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"
#include "Inmueble.h"
#include "Inmobiliaria.h"
#include "Publicacion.h"

class AdministraPropiedad {
    private:
        DTFecha* fecha;
        Inmobiliaria* inmobiliaria;
        Inmueble* inmueble;
        Publicacion* publicacion;

    public:
        AdministraPropiedad(DTFecha* fecha);
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