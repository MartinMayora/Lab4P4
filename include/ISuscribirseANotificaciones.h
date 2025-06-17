#ifndef ISUSCRIBIRSEANOTIFICACIONES_H
#define ISUSCRIBIRSEANOTIFICACIONES_H

#include <set>
#include <string>

class ISuscribirseANotificaciones{
    public:
        virtual std::set<std::string> listarInmobiliariasNoSuscriptas(std::string nicknameUsuario) = 0;
        virtual void suscribirseAInmobiliaria(std::string nicknameUsuario, std::string nicknameInmobiliaria) = 0 ;
        virtual ~ISuscribirseANotificaciones(){};
};

#endif