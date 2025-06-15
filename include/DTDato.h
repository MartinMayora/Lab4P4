#ifndef DTDATO_H
#define DTDATO_H
#include <string>

#include "TipoInmueble.h"

class DTDato {
    private:
        std::string nombre;
        TipoInmueble ti;

    public:
        DTDato(std::string nombre, TipoInmueble ti);
        std::string getNombre() const;
        TipoInmueble getTi() const;
        bool operator<(const DTDato& other) const;
};
#endif