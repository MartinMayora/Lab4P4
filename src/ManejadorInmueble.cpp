#include "../include/ManejadorInmueble.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTInmuebleListado.h"

ManejadorInmueble *ManejadorInmueble::instancia = NULL;

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
    propietario->agregarInmueble(casa);
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

    std::set<Publicacion *>::iterator it;
    for (it = publicaciones.begin(); it != publicaciones.end(); ++it)
    {
        Publicacion *p = *it;

        if (p->getEstaActiva() && p->getTipoPublicacion() == tipoPublicacion)
        {
            float precio = p->getPrecio();
            if (precio >= precioMinimo && precio <= precioMaximo)
            {
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

std::set<DTInmuebleListado> ManejadorInmueble::darInmuebles()
{
    std::set<DTInmuebleListado> resultado;

    std::map<int, Inmueble *>::iterator it;
    for (it = inmuebles.begin(); it != inmuebles.end(); ++it)
    {
        Inmueble *in = it->second;

        int codigo = in->getCodigo();
        std::string direccion = in->getDireccion();
        std::string propietario = in->getPropietario()->getNickname();

        DTInmuebleListado dtil(codigo, direccion, propietario);
        resultado.insert(dtil);
    }

    return resultado;
}
