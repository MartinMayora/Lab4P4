#ifndef CARGADATOS_H
#define CARGADATOS_H
#include "Factory.h"
#include "ControladorFechaActual.h"

class CargaDatos {
    private:
        static CargaDatos* instance;
        CargaDatos();

    public:
        static CargaDatos* getInstance();
        ~CargaDatos();
};

#endif