#include "../include/Convertir.h"

std::string tipoInmuebleATexto(TipoInmueble tipo) {
    switch (tipo) {
        case Todos: return "Todos"; //esta no deberia nunca imprimirse
        case TipoCasa: return "Casa";
        case TipoApartamento: return "Apartamento"; 
        default: return "Desconocido";
    }
}

std::string tipoPublicacionATexto(TipoPublicacion tipo) {
    switch (tipo) {
        case Venta: return "Venta";
        case Alquiler: return "Alquiler";  
        default: return "Desconocido";
    }
}