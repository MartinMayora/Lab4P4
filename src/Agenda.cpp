#include "../include/Agenda.h"

Agenda::Agenda(Cliente* cliente, DTFecha fecha, std::string formaContacto)
    : fecha(fecha), formaContacto(formaContacto) {
    this->cliente = cliente;
}

Agenda::~Agenda() {
}

Cliente* Agenda::getCliente() const {
    return this->cliente;
}

DTFecha Agenda::getFecha() const {
    return this->fecha;
}

std::string Agenda::getFormaContacto() const {
    return this->formaContacto;
}
