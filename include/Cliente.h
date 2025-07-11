#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include <string>
#include "Suscriptor.h"
class Cliente : public Usuario, public Suscriptor{
    private:
        std::string apellido;
        std::string documento;

    public:
        Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
        ~Cliente();
        std::string getNickname();
    
};

#endif