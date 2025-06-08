#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include <set>
#include "AdministraPropiedad.h"

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        std::set<AdministraPropiedad*> admprop;

    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        ~Inmueble();
        
        std::set<AdministraPropiedad*> getAdministraPropiedad();

        //getters
        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnoConstruccion();

        // para func listarInmueblesNoAdministradosInmobiliaria
        bool esAdministrado(Inmobiliaria* i);

        void asociarAdministracionPropiedad(AdministraPropiedad* ap);
};

#endif