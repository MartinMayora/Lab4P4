#ifndef PUBLICACION_H
#define PUBLICACION_H

#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "DTPublicacion.h"
#include "AdministraPropiedad.h"
#include <string>
#include "Suscriptor.h"
class AdministraPropiedad;

class Publicacion
{private:
    int codigo;
    DTFecha *fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad *admin;

public:
    Publicacion(int codigo, DTFecha *fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa);
    ~Publicacion();

    int getCodigo() const;
    DTFecha *getFecha() const;
    TipoPublicacion getTipoPublicacion() const;
    std::string getTexto() const;
    float getPrecio() const;
    bool getEstaActiva() const;
    //AdministraPropiedad *getAdministraPropiedad(); //saque el const, posiblemente error sacarlo

    DTPublicacion getDataPublicacion(std::string nombreInmobiliaria) const;
};

#endif
