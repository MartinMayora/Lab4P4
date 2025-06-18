#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include "TipoPublicacion.h"
#include "TipoInmueble.h"

class DTNotificacion {
private:
    std::string nickname;
    int codigo;
    std::string texto;
    TipoPublicacion tipo;
    TipoInmueble inmueble;

public:
    // Constructor
    DTNotificacion(std::string nickname, int codigo, std::string texto, TipoPublicacion tipo, TipoInmueble inmueble);

    // Getters
    std::string getNickname()const;
    int getCodigo()const;
    std::string getTexto()const;
    TipoPublicacion getTipo()const;
    TipoInmueble getInmueble()const;
    bool operator<(const DTNotificacion& other) const;

};

#endif
