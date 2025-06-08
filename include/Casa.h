#ifndef CASA_H
#define CASA_H
#include "Inmueble.h"
#include "TipoTecho.h"

class Casa : public Inmueble {
    private:
        bool esPH;
        TipoTecho techo;

    public:
        //modifico el constructor q venia en los zip
        Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion,
            bool esPH, TipoTecho techo);
        ~Casa();
};

#endif