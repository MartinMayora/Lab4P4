#include "../include/Casa.h"

// Preguntar si podemos modificar la firma al estilo de cliente,prop,inm con usuario
Casa::Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion,
           bool esPH, TipoTecho techo) : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion), esPH(esPH), techo(techo)
{
}

Casa::~Casa()
{
}

TipoInmueble Casa::getTipoInmueble()
{
    return TipoCasa;
}
