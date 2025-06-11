#include "../include/ManejadorUsuario.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"

ManejadorUsuario *ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario() {}

ManejadorUsuario *ManejadorUsuario::getInstance()
{
    if (instancia == NULL)
        instancia = new ManejadorUsuario();
    return instancia;
}

// OPERACIONES CASO DE USO ALTA USUARIO
bool ManejadorUsuario::existeUsuario(std::string nickname)
{
    return (this->usuarios.find(nickname) != this->usuarios.end());
}

bool ManejadorUsuario::crearCliente(std::string nickname, std::string contrasena, std::string nombre,
                                    std::string email, std::string apellido, std::string documento)
{
    if (existeUsuario(nickname))
        return false;
    else
    {
        Cliente *c = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
        usuarios[nickname] = c;
        clientes[nickname] = c;
        return true;
    }
}

bool ManejadorUsuario::crearPropietario(std::string nickname, std::string contrasena, std::string nombre,
                                        std::string email, std::string cuentaBancaria, std::string telefono)
{
    if (existeUsuario(nickname))
        return false;
    else
    {
        Propietario *p = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        usuarios[nickname] = p;
        propietarios[nickname] = p;
        return true;
    }
}

bool ManejadorUsuario::crearInmobiliaria(std::string nickname, std::string contrasena, std::string nombre,
                                         std::string email, std::string direccion, std::string url, std::string telefono)
{
    if (existeUsuario(nickname))
        return false;
    else
    {
        Inmobiliaria *i = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        usuarios[nickname] = i;
        inmobiliarias[nickname] = i;
        return true;
    }
}

std::set<DTUsuario> ManejadorUsuario::listarPropietarios()
{
    std::set<DTUsuario> resu;
    // recorremos todo el mapa de propietarios y para cada uno creamos un DTUsuario y agregamos al resultado
    for (std::map<std::string, Propietario *>::iterator i = propietarios.begin(); i != propietarios.end(); i++)
    {
        Propietario *propietario = i->second;
        std::string nickname = propietario->getNickname();
        std::string nombre = propietario->getNombre();
        // creamos el DTUsuario
        DTUsuario dtUsuario = DTUsuario(nickname, nombre);
        resu.insert(dtUsuario);
    }
    return resu;
}

void ManejadorUsuario::representarPropietario(std::string nicknamePropietario, Inmobiliaria *inmobiliariaRecordada)
{
    std::map<std::string, Propietario *>::iterator p = propietarios.find(nicknamePropietario);
    if (p != propietarios.end())
    {
        Propietario *propietario = p->second;
        propietario->agregarInmobiliaria(inmobiliariaRecordada);
    }
}

Propietario *ManejadorUsuario::getPropietario(std::string nickname)
{
    std::map<std::string, Propietario *>::iterator iter = this->propietarios.find(nickname);
    if (iter != this->propietarios.end())
        return iter->second;
    else
        return NULL;
}

Inmobiliaria *ManejadorUsuario::getInmobiliaria(std::string nicknameInmobiliaria)
{
    std::map<std::string, Inmobiliaria *>::iterator iter = this->inmobiliarias.find(nicknameInmobiliaria);
    if (iter != this->inmobiliarias.end())
        return iter->second;
    else
        return NULL;
}

// OPERACIONES CASO DE USO ALTA DE ADMINISTRA PROPIEDAD

std::map<std::string, Inmobiliaria *> &ManejadorUsuario::getInmobiliarias()
{
    return this->inmobiliarias;
}

// OPERACIONES CASO DE USO ALTA PUBLICACION
bool ManejadorUsuario::existeInmobiliaria(std::string nicknameInmobiliaria)
{
    if (this->inmobiliarias.find(nicknameInmobiliaria) != this->inmobiliarias.end())
    {
        return true;
    }
    return false;
}

bool ManejadorUsuario::darInmobiliaria(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio)
{
    if (!this->existeInmobiliaria(nicknameInmobiliaria))
    {
        return false;
    }
    std::map<std::string, Inmobiliaria *>::iterator inm;
    for (inm = this->inmobiliarias.begin(); inm != this->inmobiliarias.end(); ++inm)
    {
        Inmobiliaria *inmobiliariaAux = inm->second;
        inmobiliariaAux->publicarInmueble();
    }
}

// OPERACIONES CASO DE USO SUSCRIBIRSE A NOTIFICACIONES

std::set<std::string> ManejadorUsuario::listarInmobiliariasNoSuscriptas(std::string nicknameUsuario)
{
    std::set<std::string> resultado;
    std::map<std::string, Inmobiliaria *>::iterator inm;
    // la visibilidad es desde inmobiliaria hacia suscriptores, buscamos para cada inmobiliaria si contiene o no al suscriptor
    for (inm = this->inmobiliarias.begin(); inm != this->inmobiliarias.end(); inm++)
    {
        Inmobiliaria *inmo = inm->second;
        if (!inmo->tieneSuscriptor(nicknameUsuario))
        {
            resultado.insert(inmo->getNickname());
        }
    }
    return resultado;
}


void ManejadorUsuario::suscribirseAInmobiliaria(std::string nicknameUsuario, std::string nicknameInmobiliaria) {
    Usuario* usuario = NULL;
    //buscamos al usuario que quiere suscribirse entre clientes o propietarios para chequear 
    if (this->clientes.find(nicknameUsuario) != this->clientes.end())
        usuario = this->clientes[nicknameUsuario];
    else 
        if (this->propietarios.find(nicknameUsuario) != this->propietarios.end())
            usuario = this->propietarios[nicknameUsuario];
    //queremos que nos devuelva un puntero al suscriptor para poder agregarlo al set de suscriptores de la inm
    Suscriptor* suscriptor = dynamic_cast<Suscriptor*>(usuario);
    Inmobiliaria* inmobiliaria = getInmobiliaria(nicknameInmobiliaria);
    if (suscriptor != NULL && inmobiliaria != NULL && !inmobiliaria->estaSuscripto(suscriptor)) {
        inmobiliaria->agregarSuscriptor(suscriptor);
    }
}



