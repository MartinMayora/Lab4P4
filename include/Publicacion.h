#ifndef PUBLICACION_H
#define PUBLICACION_H

#include "DTFecha.h"
#include "DTDato.h"
#include "TipoPublicacion.h"
#include "DTPublicacion.h"
#include "AdministraPropiedad.h"
#include <string>
#include "Suscriptor.h"
#include "Agenda.h"
 
class AdministraPropiedad;
class Agenda;

class Publicacion
{private:
    int codigo;
    DTFecha *fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad *admin;
    std::set<Agenda*> agendas;

public:
    Publicacion(int codigo, DTFecha *fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa);
    ~Publicacion();

    int getCodigo() const;
    DTFecha *getFecha() const;
    TipoPublicacion getTipoPublicacion() const;
    std::string getTexto() const;
    float getPrecio() const;
    bool getEstaActiva() const;
    //altapublicacion
    bool existeFecha(DTFecha* fechaActual);
    bool existeTipoPub(TipoPublicacion TipoPublicacion);
    void actiualizarActivo(bool nuevoEstado);

    //AdministraPropiedad *getAdministraPropiedad(); //saque el const, posiblemente error sacarlo

    DTDato getDataPublicacion() const;
    void eliminarLinkAgenda();
};

#endif
