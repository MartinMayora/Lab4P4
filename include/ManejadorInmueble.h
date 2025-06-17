#ifndef MANEJADORINMUEBLE_H
#define MANEJADORINMUEBLE_H

#include <map>
#include <string>
#include "TipoTecho.h"
#include "Inmueble.h"
#include "DTPublicacion.h"
#include "TipoInmueble.h"
#include "Publicacion.h"
#include "DTInmuebleListado.h"
#include "DTInmueble.h"


class Inmueble;
class Casa;
class Apartamento;
class Propietario;

class ManejadorInmueble
{
private:
    static ManejadorInmueble *instancia;
    std::map<int, Inmueble *> inmuebles;
    std::set<Publicacion *> publicaciones;
    int codInc;

    ManejadorInmueble();
    ~ManejadorInmueble();

public:
    static ManejadorInmueble *getInstance();
    static void deleteInstance();

    //CASO DE USO ALTA USUARIO 
    void crearCasa(std::string direccion, int numeroPuerta, int superficie, int anioConstruccion,
                   bool esPH, TipoTecho techo, Propietario *propietario);

    void crearApartamento(std::string direccion, int numeroPuerta, int superficie, int anioConstruccion,
                          int piso, bool tieneAscensor, float gastosComunes, Propietario *propietario);

    //CASO DE USO ALTAPUBLICACION

    void agregarPub(Publicacion *aAgregar);
    //CASO DE USO CONSULTA DE NOTIFICACIONES
    std::set<DTPublicacion> getPublicaciones(TipoPublicacion tipoPublicacion, float precionMinimo, float precioMaximo, TipoInmueble tipoInmueble);
    DTInmueble* detalleInmueble(int codigo);

    //CASO DE USO ELIMINAR INMUEBLE
    std::set<DTInmuebleListado> darInmuebles();
    void eliminarInmueble(int codigoInmueble);
    Inmueble *getInmueble(int codigoInmueble);
    

};

#endif
