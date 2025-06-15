#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"
#include <set>

#include "Inmobiliaria.h"
#include "Publicacion.h"
class Publicacion;
class Inmobiliaria;
class Inmueble;

class AdministraPropiedad {
    private:
        DTFecha* fecha;
        Inmobiliaria* inmobiliaria;
        Inmueble* inmueble;
        std::set<Publicacion*> publicaciones;

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
        void eliminarLinkPublicacion();
        std::set<Publicacion*>& getPublicaciones();


};

#endif