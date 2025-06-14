#include "../include/ManejadorInmueble.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTInmueble.h"
#include "../include/DTCasa.h"
#include "../include/DTApartamento.h"
#include <iostream>





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

void ManejadorInmueble::listarInmuebles() {
    if (inmuebles.empty()) {
        std::cout << "No hay inmuebles registrados." << std::endl;
        return;
    }

    std::cout << "Lista de inmuebles registrados:\n";

    for (std::map<int, Inmueble*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        Inmueble* inmu = it->second;

        std::cout << "Código: " << it->first
                  << ", Dirección: " << inmu->getDireccion()
                  << ", Nro Puerta: " << inmu->getNumeroPuerta()
                  << ", Superficie: " << inmu->getSuperficie();
                  

        // Verificamos si es una Casa
        Casa* casa = dynamic_cast<Casa*>(inmu);
        if (casa != NULL) {
            std::cout << " [Casa] - PH: " << (casa->getEsPH() ? "Sí" : "No");
                      
        } else {
            // Verificamos si es un Apartamento
            Apartamento* apto = dynamic_cast<Apartamento*>(inmu);
            if (apto != NULL) {
                std::cout << " [Apartamento] - Piso: " << apto->getPiso()
                          << ", Ascensor: " << (apto->getTieneAscensor() ? "Sí" : "No")
                          << ", GC: " << apto->getGastosComunes();
            } else {
                std::cout << " [Tipo desconocido]";
            }
        }

        std::cout << std::endl;
    }
}

Inmueble *ManejadorInmueble::getInmueble(int codigoInmueble)
{
    std::map<int, Inmueble *>::iterator iter = this->inmuebles.find(codigoInmueble);
    if (iter != this->inmuebles.end())
        return iter->second;
    else
        return NULL;
}

/*std::set<DTPublicacion> ManejadorInmueble::getPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble)
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
    */

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

std::set<DTPublicacion> ManejadorInmueble::getPublicaciones(
    TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInmueble) {

    std::set<DTPublicacion> resultado;
    return resultado;
}

DTInmueble* ManejadorInmueble::detalleInmueble(int codigo) {
    for (unsigned int i = 0; i < inmuebles.size(); ++i) {
        Inmueble* in = inmuebles[i];
        if (in->getCodigo() == codigo) {
            // comunes
            int cod = in->getCodigo();
            std::string dir = in->getDireccion();
            int puerta = in->getNumeroPuerta();
            int superficie = in->getSuperficie();
            int anio = in->getAnoConstruccion();

            // Casa
            Casa* casa = dynamic_cast<Casa*>(in);
            if (casa != NULL) {
                return new DTCasa(cod, dir, puerta, superficie, anio,
                                  casa->getEsPH(), casa->getTecho());
            }

            // Apartamento
            Apartamento* apto = dynamic_cast<Apartamento*>(in);
            if (apto != NULL) {
                return new DTApartamento(cod, dir, puerta, superficie, anio,
                                         apto->getPiso(), apto->getTieneAscensor(), apto->getGastosComunes());
            }
        }
    }
}