#ifndef PUBLICACION_H
#define PUBLICACION_H

#include "DTFecha.h"
#include "DTDato.h"
#include "TipoPublicacion.h"
#include "DTPublicacion.h"
#include "AdministraPropiedad.h"
#include <string>
#include "Suscriptor.h"

class AdministraPropiedad;

class Publicacion
{
private:
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

    // CASO DE USO ALTA PUBLICACION
    bool existeFecha(DTFecha *fechaActual);
    bool existeTipoPub(TipoPublicacion TipoPublicacion);
    void actiualizarActivo(bool nuevoEstado);

    DTDato getDataPublicacion() const;
    void setAdministra(AdministraPropiedad *a);
    int getCodigoInmueble() const;

};

#endif
