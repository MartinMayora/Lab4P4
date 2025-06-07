#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        std::set<AdministraPropiedad*> administraPropiedad;

    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        ~Inmueble();
        void agregarAdministraPropiedad(Propietario* p);
        std::set<Propietario*> getAdministraPropiedad();

        //getters
        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnoConstruccion();

        // para func listarInmueblesNoAdministradosInmobiliaria
        bool esAdministrado(Inmobiliaria* i);
};

#endif