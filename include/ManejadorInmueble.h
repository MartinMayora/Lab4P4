#ifndef MANEJADORINMUEBLE_H
#define MANEJADORINMUEBLE_H

#include <map>
#include <string>
#include "TipoTecho.h"
#include "Inmueble.h"


class Inmueble;
class Casa;
class Apartamento;
class Propietario;

class ManejadorInmueble {
private:
    static ManejadorInmueble* instancia;
    std::map<int, Inmueble*> inmuebles;
    //contador incremental no se si tendria q ser algo asi int codInc;

    ManejadorInmueble();
    ~ManejadorInmueble();

public:
    static ManejadorInmueble* getInstance();
    static void deleteInstance();

    void crearCasa(int codigo,std::string direccion, int numeroPuerta, int superficie, int anioConstruccion,
                   bool esPH, TipoTecho techo, Propietario*propietario);

    void crearApartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion,
                          int piso, bool tieneAscensor, float gastosComunes,Propietario*propietario);
    
    Inmueble* getInmueble(int codigoInmueble);
};

#endif
