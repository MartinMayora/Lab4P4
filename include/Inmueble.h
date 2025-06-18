#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include <set>
#include "AdministraPropiedad.h"
#include "TipoInmueble.h"

class Propietario;
class AdministraPropiedad;
class Inmobiliaria;

class Inmueble
{
private:
    int codigo;
    std::string direccion;
    int numeroPuerta;
    int superficie;
    int anoConstruccion;
    std::set<AdministraPropiedad *> admprop;
    Propietario* propietario;

public:
    Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
    virtual ~Inmueble();

    //Getters
    int getCodigo();
    std::string getDireccion();
    int getNumeroPuerta();
    int getSuperficie();
    int getAnoConstruccion();
    std::set<AdministraPropiedad *> getAdministraPropiedad();
    virtual TipoInmueble getTipoInmueble() = 0;
    Propietario* getPropietario();

    //CASO DE USO ELIMINAR INMUEBLE
    void eliminarLinks();

    //CASO DE USO ALTA ADMINISTRACION PROPIEDAD
    void asociarAdministracionPropiedad(AdministraPropiedad *ap);
    bool esAdministrado(Inmobiliaria *i);

    //CASO DE USO ALTA USUARIO
    void setPropietario(Propietario* p);
};

#endif