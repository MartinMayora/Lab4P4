#ifndef CONTROLADORINMUEBLE_H
#define CONTROLADORINMUEBLE_H
#include "IConsultaDePublicaciones.h"
#include "Inmobiliaria.h"
#include "Inmueble.h"
#include "Publicacion.h"
#include "DTInmuebleAdministrado.h"
#include <string>
#include <map>
#include <set>
#include "DTPublicacion.h"
#include "TipoInmueble.h"
#include "DTInmueble.h"
#include "IEliminarInmueble.h"

class ControladorInmueble : public IConsultaDePublicaciones, public IEliminarInmueble{
private:
    static ControladorInmueble *instancia;

    ControladorInmueble();

public:
    static ControladorInmueble *getInstance();

    std::set<DTInmuebleAdministrado> listarInmueblesAdministrados(std::string nicknameInmobiliaria);

    bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);


    void eliminarInmueble(int codigoInmueble);
    
    DTInmueble* detalleInmueble(int codigo);
    std::set<DTInmuebleListado> listarInmuebles();

    //CASO DE LISTAR PUBLICACION    
    std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precionMinimo, float precioMaximo, TipoInmueble tipoInmueble);
    DTInmueble* detalleInmueblePublicacion(int codigoPublicacion);

    virtual ~ControladorInmueble();
};
#endif