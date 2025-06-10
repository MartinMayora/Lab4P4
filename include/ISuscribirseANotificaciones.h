#ifndef ISUSCRIBIRSEANOTIFICACIONES_H
#define ISUSCRIBIRSEANOTIFICACIONES_H

#include <set>
#include <string>

class ISuscribirseANotificaciones{
    //en las interfaces agregamos todas las operaciones que corresponden al caso de uso 
    public:
        virtual std::set<std::string> listarInmobiliariasNoSuscriptas(std::string nicknameUsuario) = 0;
        virtual void suscribirseAInmobiliaria(std::string nicknameUsuario, std::string nicknameInmobiliaria) = 0 ;
};

#endif