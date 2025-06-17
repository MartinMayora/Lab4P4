#ifndef IALTAPUBLICACION_H
#define IALTAPUBLICACION_H

#include "DTInmuebleAdministrado.h"
#include "DTUsuario.h"
#include <set>
#include <string>
#include "TipoPublicacion.h"

class IAltaPublicacion {
    public:
        virtual std::set<DTUsuario> listarInmobiliarias() = 0;
        virtual std::set<DTInmuebleAdministrado> listarInmueblesAdministrados(std::string nicknameInmobiliaria) = 0;
        virtual bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio) = 0;
        virtual ~IAltaPublicacion(){};
};


#endif
