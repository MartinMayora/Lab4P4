#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"

class AdministraPropiedad {
    private:
        DTFecha* fecha;

    public:
        AdministraPropiedad(DTFecha* fecha);
        ~AdministraPropiedad();

        // para func listarInmueblesNoAdministradosInmobiliaria
        bool inmobiliariaAsociada(Inmobiliaria* i);
};

#endif