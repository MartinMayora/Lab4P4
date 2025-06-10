#ifndef CONTROLADORINMUEBLE_H
#define CONTROLADORINMUEBLE_H


#include "Inmobiliaria.h"
#include "Inmueble.h"
#include "Publicacion.h"
#include "DTInmuebleAdministrado.h"
#include <string>
#include <map>
#include <set>

class ControladorInmueble  {
private:
    static ControladorInmueble* instancia;

    ControladorInmueble();

public:
    static ControladorInmueble* getInstance();

    std::set<DTInmuebleAdministrado> listarInmueblesAdministrados(std::string nicknameInmobiliaria );

    bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, std::string texto, float precio);

    std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precionMinimo, float precioMaximo,TipoInmueble tipoInmueble);
    
    void eliminarInmueble(int codigoInmueble);

    std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria);
};

#endif