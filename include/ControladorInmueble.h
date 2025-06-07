#ifndef CONTROLADORINMUEBLE_H
#define CONTROLADORINMUEBLE_H

#include "Propietario.h"
#include "Inmobiliaria.h"
#include "Inmueble.h"
#include "Publicacion.h"


class ControladorUsuario : public IAltaUsuario {
private:
    static ControladorInmueble* instancia;

    ControladorInmueble();

public:
    static ControladorInmueble* getInstance();

    std::Set<DTInmuebleAdministrado> listarInmueblesAdministrados(nicknameInmobiliaria:String);

    bool altaPublicacion(nicknameInmobiliaria: String, codigoInmueble: int, tipoPublicacion: TipoPublicacion, texto: String, precio: float);

    std::Set<DTPublicacion> listarPublicacion(tipoPublicacion: TipoPublicacion, precionMinimo: float, precioMaximo: float,tipoInmueble: TipoInmueble);
    
    void eliminarInmueble(codigoInmueble: int);

    std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria: String);
};

#endif