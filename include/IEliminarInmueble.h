#ifndef IELIMINARINMUEBLE_H
#define IELIMINARINMUEBLE_H

#include <set>
#include <string>
#include "DTInmuebleListado.h"
#include "DTInmueble.h"

class IEliminarInmueble {
public:
    virtual std::set<DTInmuebleListado> listarInmuebles() = 0;
    virtual DTInmueble* detalleInmueble(int codigo) = 0;
    virtual void eliminarInmueble(int codigo) = 0;
    virtual ~IEliminarInmueble(){};
};

#endif
