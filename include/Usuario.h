#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Suscriptor;

class Usuario {
    private:
        std::string nickname;
        std::string contrasena;
        std::string nombre;
        std::string email;

    public:
        Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email);
        virtual ~Usuario();
        //getters
        std::string getNickname();
        std::string getContrasena();
        std::string getNombre();
        std::string getEmail();

};

#endif