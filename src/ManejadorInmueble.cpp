#include "../include/ManejadorInmueble.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/Propietario.h"

ManejadorInmueble* ManejadorInmueble::instancia = nullptr;

//ManejadorInmueble::ManejadorInmueble() {
  //  codInc = 1;
//}

ManejadorInmueble* ManejadorInmueble::getInstance() {
    if (instancia == NULL)
        instancia = new ManejadorInmueble();
    return instancia;
}

void ManejadorInmueble::crearCasa(std::string direccion, int numeroPuerta, int superficie,
                                  int anioConstruccion, bool esPH, TipoTecho techo,
                                  Propietario* propietario) {
    //int codigo = codInc++;
    Casa* casa = new Casa(codigo, direccion, numeroPuerta, superficie, anioConstruccion, esPH, techo);
    //aca tengo q crear en propietario un set de inmuebles y hacer q la casa esa se agregue a ese set 
    
}

