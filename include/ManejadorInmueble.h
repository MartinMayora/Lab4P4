#ifndef MANEJADORINMUEBLE_H
#define MANEJADORINMUEBLE_H

#include <map>
#include <string>
#include "TipoTecho.h"
#include "Inmueble.h"
#include "DTPublicacion.h"
#include "TipoInmueble.h"
#include "Publicacion.h"

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

    void crearCasa(std::string direccion, int numeroPuerta, int superficie, int anioConstruccion,
                   bool esPH, TipoTecho techo, Propietario *propietario);

    void crearApartamento(std::string direccion, int numeroPuerta, int superficie, int anioConstruccion,
                          int piso, bool tieneAscensor, float gastosComunes, Propietario *propietario);

    Inmueble *getInmueble(int codigoInmueble);

    std::set<DTPublicacion> getPublicaciones(TipoPublicacion tipoPublicacion, float precionMinimo, float precioMaximo, TipoInmueble tipoInmueble);

    std::set<DTInmuebleListado> ManejadorInmueble::darInmuebles();

};

#endif
