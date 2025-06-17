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
#include "IAltaPublicacion.h"
#include "IEliminarInmueble.h"


class ControladorInmueble : public IConsultaDePublicaciones, public IEliminarInmueble, public IAltaPublicacion{
private:
    static ControladorInmueble *instancia;
    ControladorInmueble();
public:
    static ControladorInmueble *getInstance();
    virtual ~ControladorInmueble();
    static void deleteInstance();
    
    //CASO DE USO ALTA PUBLICACION
    std::set<DTUsuario> listarInmobiliarias();
    std::set<DTInmuebleAdministrado> listarInmueblesAdministrados(std::string nicknameInmobiliaria);
    bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);

    //CASO DE USO CONSULTA DE PUBLICACIONES   
    std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precionMinimo, float precioMaximo, TipoInmueble tipoInmueble);
    DTInmueble* detalleInmueblePublicacion(int codigoPublicacion);

    //CASO DE USO ELIMINAR INMUEBLE
    std::set<DTInmuebleListado> listarInmuebles();
    DTInmueble* detalleInmueble(int codigo);
    void eliminarInmueble(int codigoInmueble);
    
};
#endif