#ifndef ICONSULTADEPUBLICACIONES_H
#define ICONSULTADEPUBLICACIONES_H

#include <set>
#include <string>
#include "DTInmueble.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"


class IConsultaDePublicaciones{
    //en las interfaces agregamos todas las operaciones que corresponden al caso de uso 
    public:
    virtual std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble) = 0;
    virtual DTInmueble* detalleInmueblePublicacion(int codigoPublicacion) = 0;
};

#endif