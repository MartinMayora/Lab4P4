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

        //Getters
        DTFecha* getFecha();
        Inmobiliaria* getInmobiliaria();
        Inmueble* getInmueble();
        std::set<Publicacion*> getPubublicaciones();
        std::set<Publicacion*>& getPublicaciones();

        //CASO DE USO ALTA ADMINISTRACION PROPIEDAD
        bool inmobiliariaAsociada(Inmobiliaria* i);
    
        //CASO DE USO ELIMINAR INMUEBLE
        void eliminarLinkPublicacion();
        
        //CASO DE USO ALTA PUBLICACION
        bool tieneInmueble(int codigoInmueble);

};

#endif