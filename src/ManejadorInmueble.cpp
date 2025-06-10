#include "../include/ManejadorInmueble.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/Propietario.h"

ManejadorInmueble *ManejadorInmueble::instancia = nullptr;

ManejadorInmueble::ManejadorInmueble()
{
    codInc = 0;
}

ManejadorInmueble *ManejadorInmueble::getInstance()
{
    if (instancia == NULL)
        instancia = new ManejadorInmueble();
    return instancia;
}

void ManejadorInmueble::crearCasa(std::string direccion, int numeroPuerta, int superficie,
                                  int anioConstruccion, bool esPH, TipoTecho techo, Propietario *propietario)
{
    int codigo = codInc++;
    Casa *casa = new Casa(codigo, direccion, numeroPuerta, superficie, anioConstruccion, esPH, techo);
    // agregamos casa al set de inmuebles para propietario
    propietario->agregarInmueble(casa);
    // agregamos casa al map de inmuebles del manejador
    inmuebles[codigo] = casa;
}

void ManejadorInmueble::crearApartamento(std::string direccion, int numeroPuerta, int superficie,
                                         int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes,
                                         Propietario *propietario)
{
    int codigo = codInc++;
    Apartamento *apto = new Apartamento(codigo, direccion, numeroPuerta, superficie, anioConstruccion, piso, tieneAscensor, gastosComunes);
    // agregamos casa al set de inmuebles para propietario
    propietario->agregarInmueble(apto);
    // agregamos casa al map de inmuebles del manejador
    inmuebles[codigo] = apto;
}

Inmueble *ManejadorInmueble::getInmueble(int codigoInmueble)
{
    std::map<int, Inmueble *>::iterator iter = this->inmuebles.find(codigoInmueble);
    if (iter != this->inmuebles.end())
        return iter->second;
    else
        return NULL;
}

std::set<DTPublicacion> ManejadorInmueble::getPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble)
{
    std::set<DTPublicacion> resultado;

    for (Publicacion *p : publicaciones)
    {
        if (p->getEstaActiva() && p->getTipoPublicacion() == tipoPublicacion)
        {
            float precio = p->getPrecio();
            if (precio >= precioMinimo && precio <= precioMaximo)
            {
                // Acceder al inmueble a través de AdministraPropiedad
                AdministraPropiedad *admin = p->getAdministraPropiedad();
                Inmueble *inmueble = admin->getInmueble();
                if (inmueble->getTipoInmueble() == tipoInmueble)
                {
                    std::string nombreInmobiliaria = admin->getInmobiliaria()->getNombre();
                    DTPublicacion dt = p->getDataPublicacion(nombreInmobiliaria);
                    resultado.insert(dt);
                }
            }
        }
    }

    return resultado;
}
