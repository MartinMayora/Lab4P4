
#ifndef AGENDA_H
#define AGENDA_H

#include "DTFecha.h"
#include <string>
#include "Cliente.h" 

class Agenda {
private:
    DTFecha fecha;
    std::string formaContacto;
    Cliente* cliente; 

public:
    Agenda(Cliente* cliente, DTFecha fecha, std::string formaContacto);

    ~Agenda();

    Cliente* getCliente() const;
    DTFecha getFecha() const;
    std::string getFormaContacto() const;
};

#endif
