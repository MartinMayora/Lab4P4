#ifndef IELIMINARSUSCRIPCIONES_H
#define IELIMINARSUSCRIPCIONES_H

#include <set>
#include <string>

class IEliminarSuscripciones{
    //en las interfaces agregamos todas las operaciones que corresponden al caso de uso 
    public:
        virtual std::set<std::string> listarSuscripciones(std::string nicknameUsuario) = 0;
        virtual void eliminarSuscripcion(std::string nicknameUsuario, std::string nicknameInmobiliaria) = 0 ;
};

#endif