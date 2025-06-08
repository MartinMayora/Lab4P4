#ifndef IALTAADMINISTRACIONPROPIEDAD_H
#define IALTAADMINISTRACIONPROPIEDAD_H
#include "DTUsuario.h"
#include "DTInmuebleListado.h"
#include <string>
#include <set>

class IAltaAdministracionPropiedad {
    //en las interfaces agregamos todas las operaciones que corresponden al caso de uso 
    public:
    virtual std::Set<DTUsuario> listarInmobiliarias() = 0;

    virtual void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble) = 0;

    virtual std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria) = 0;
}