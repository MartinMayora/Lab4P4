#include "../include/ManejadorUsuario.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ManejadorInmueble.h"
#include <iostream>

ManejadorUsuario *ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario() : ultimaPub(0) {}

ManejadorUsuario *ManejadorUsuario::getInstance()
{
    if (instancia == NULL)
        instancia = new ManejadorUsuario();
    return instancia;
}

ManejadorUsuario::~ManejadorUsuario(){
    //Eliminar clientes
    std::map<std::string, Cliente *>::iterator itC;
    for (itC = clientes.begin(); itC != clientes.end(); itC++){
        delete itC->second;
    }
    //Eliminar propietarios
    std::map<std::string, Propietario *>::iterator itP;
    for (itP = propietarios.begin(); itP != propietarios.end(); itP++){
        delete itP->second;
    }
    //Eliminar inmobiliarias
    std::map<std::string, Inmobiliaria *>::iterator itI;
    for (itI = inmobiliarias.begin(); itI != inmobiliarias.end(); itI++){
        delete itI->second;
    }
    usuarios.clear();
    clientes.clear();
    propietarios.clear();
    inmobiliarias.clear();
}

void ManejadorUsuario::deleteInstance(){
    if (instancia != NULL)
    {
        delete instancia;
        instancia = NULL;
    }
}

// CASO DE USO ALTA USUARIO
bool ManejadorUsuario::existeUsuario(std::string nickname){
    return (this->usuarios.find(nickname) != this->usuarios.end());
}

bool ManejadorUsuario::crearCliente(std::string nickname, std::string contrasena, std::string nombre,
                                    std::string email, std::string apellido, std::string documento){
    if (existeUsuario(nickname) || contrasena.length()<6)
        return false;
    else{
        Cliente *c = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
        usuarios[nickname] = c;
        clientes[nickname] = c;
        return true;
    }
}

bool ManejadorUsuario::crearPropietario(std::string nickname, std::string contrasena, std::string nombre,
                                        std::string email, std::string cuentaBancaria, std::string telefono){
    if (existeUsuario(nickname) || contrasena.length()<6)
        return false;
    else{
        Propietario *p = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        usuarios[nickname] = p;
        propietarios[nickname] = p;
        return true;
    }
}

bool ManejadorUsuario::crearInmobiliaria(std::string nickname, std::string contrasena, std::string nombre,
                                         std::string email, std::string direccion, std::string url, std::string telefono){
    if (existeUsuario(nickname) || contrasena.length()<6)
        return false;
    else{
        Inmobiliaria *i = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        usuarios[nickname] = i;
        inmobiliarias[nickname] = i;
        return true;
    }
}

std::set<DTUsuario> ManejadorUsuario::listarPropietarios(){
    std::set<DTUsuario> resu;
    // recorremos todo el mapa de propietarios y para cada uno creamos un DTUsuario y agregamos al resultado
    for (std::map<std::string, Propietario *>::iterator i = propietarios.begin(); i != propietarios.end(); i++){
        Propietario *propietario = i->second;
        std::string nickname = propietario->getNickname();
        std::string nombre = propietario->getNombre();
        // creamos el DTUsuario
        DTUsuario dtUsuario = DTUsuario(nickname, nombre);
        resu.insert(dtUsuario);
    }
    return resu;
}

bool ManejadorUsuario::representarPropietario(std::string nicknamePropietario, Inmobiliaria *inmobiliariaRecordada){
    std::map<std::string, Propietario *>::iterator p = propietarios.find(nicknamePropietario);
    if (p != propietarios.end()){
        Propietario *propietario = p->second;
        propietario->agregarInmobiliaria(inmobiliariaRecordada);
        inmobiliariaRecordada->agregarPropietario(propietario);
        return true;
    }
    else
        return false;
    
}

Propietario *ManejadorUsuario::getPropietario(std::string nickname){
    std::map<std::string, Propietario *>::iterator iter = this->propietarios.find(nickname);
    if (iter != this->propietarios.end())
        return iter->second;
    else
        return NULL;
}

Inmobiliaria *ManejadorUsuario::getInmobiliaria(std::string nicknameInmobiliaria){
    std::map<std::string, Inmobiliaria *>::iterator iter = this->inmobiliarias.find(nicknameInmobiliaria);
    if (iter != this->inmobiliarias.end())
        return iter->second;
    else
        return NULL;
}

// CASO DE USO ALTA PUBLICACION
std::set<DTUsuario> ManejadorUsuario::listarInmobiliarias()
{
    std::set<DTUsuario> toReturn;
    std::map<std::string, Inmobiliaria *>::iterator inm;
    for (inm = this->inmobiliarias.begin(); inm != this->inmobiliarias.end(); ++inm)
    {
        Inmobiliaria *inmobiliariaAux = inm->second;
        std::string nickname = inmobiliariaAux->getNickname();
        std::string nombre = inmobiliariaAux->getNombre();
        DTUsuario toAdd = DTUsuario(nickname, nombre);
        toReturn.insert(toAdd);
    }
    return toReturn;
}

std::set<DTInmuebleAdministrado> ManejadorUsuario::listarInmueblesAdministrados(std::string nicknameInmobiliaria)
{
    Inmobiliaria *i = findInmobiliaria(nicknameInmobiliaria);
    std::cout << nicknameInmobiliaria;
    std::set<DTInmuebleAdministrado> adm = (*i).getAdministrados();
    return adm;
}

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
    std::set<AdministraPropiedad *> admins;
    std::set<AdministraPropiedad *>::iterator administraAux;
    bool encontrado = false;
    AdministraPropiedad *ap = NULL;
    for (inm = this->inmobiliarias.begin(); inm != this->inmobiliarias.end() && !encontrado; ++inm)
    {
        Inmobiliaria *inmobiliariaAux = inm->second;
        admins = inmobiliariaAux->getAdmins();
        for (administraAux = admins.begin(); administraAux != admins.end() && !encontrado; ++administraAux)
        {
            ap = *administraAux;
            if (ap->tieneInmueble(codigoInmueble))
            {
                encontrado = true;
                if (inmobiliariaAux->getNickname() == nicknameInmobiliaria) {
                inmobiliariaAux->agregarNotificacion(nicknameInmobiliaria, codigoInmueble, texto, tipoPublicacion, ap->getInmueble()->getTipoInmueble());
                }
            }
        }
    }
    DTFecha *fechaActual = ControladorFechaActual::getInstance()->getFechaActual();
    std::set<Publicacion *> publicacion = ap->getPublicaciones();
    std::set<Publicacion *>::iterator publicacionAux;
    for (publicacionAux = publicacion.begin(); publicacionAux != publicacion.end(); ++publicacionAux)
    {
        Publicacion *pub = *publicacionAux;
        bool e1 = pub->existeFecha(fechaActual);
        bool e2 = pub->existeTipoPub(tipoPublicacion);
        if (e1 && e2)
        {
            return false;
        }
    }
    bool pactivo = true;
    for (publicacionAux = publicacion.begin(); publicacionAux != publicacion.end(); ++publicacionAux)
    {
        Publicacion *pu = *publicacionAux;
        TipoPublicacion puTipo = pu->getTipoPublicacion();
        bool puActivo = pu->getEstaActiva();
        if (puTipo == tipoPublicacion && puActivo)
        {
            if (pu->getFecha()->operator<(fechaActual))
            {
                pu->actiualizarActivo(false);
                pactivo = true;
            }
            else
                pactivo = false;
        }
    }

    int ultimaPublicacion = this->ultimaPub + 1;
    this->ultimaPub += 1;
    Publicacion *pubAgregar = new Publicacion(ultimaPublicacion, fechaActual, tipoPublicacion, texto, precio, pactivo);
    pubAgregar->setAdministra(ap);
    ManejadorInmueble *manejador = ManejadorInmueble::getInstance();
    manejador->agregarPub(pubAgregar);
    ap->agregarPublicacion(pubAgregar);
    return true;
}

Inmobiliaria *ManejadorUsuario::findInmobiliaria(std::string nicknameInmobiliaria)
{
    std::map<std::string, Inmobiliaria *>::iterator inm;
    for (inm = this->inmobiliarias.begin(); inm != this->inmobiliarias.end(); ++inm)
    {
        Inmobiliaria *inmobiliariaAux = inm->second;
        if (inmobiliariaAux->getNickname() == nicknameInmobiliaria)
        {
            return inmobiliariaAux;
        }
    }
    return NULL;
}

bool ManejadorUsuario::darInmobiliaria2(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio, int activo)
{
    if (!this->existeInmobiliaria(nicknameInmobiliaria))
    {
        return false;
    }

    std::map<std::string, Inmobiliaria *>::iterator inm;
    std::set<AdministraPropiedad *> admins;
    std::set<AdministraPropiedad *>::iterator administraAux;
    bool encontrado = false;
    AdministraPropiedad *ap = NULL;
    for (inm = this->inmobiliarias.begin(); inm != this->inmobiliarias.end() && !encontrado; ++inm)
    {
        Inmobiliaria *inmobiliariaAux = inm->second;
        admins = inmobiliariaAux->getAdmins();
        for (administraAux = admins.begin(); administraAux != admins.end() && !encontrado; ++administraAux)
        {
            ap = *administraAux;
            if (ap->tieneInmueble(codigoInmueble))
            {
                encontrado = true;
                if (inmobiliariaAux->getNickname() == nicknameInmobiliaria) {
                inmobiliariaAux->agregarNotificacion(nicknameInmobiliaria, codigoInmueble, texto, tipoPublicacion, ap->getInmueble()->getTipoInmueble());
                }
            }
        }
    }
    DTFecha *fechaActual = ControladorFechaActual::getInstance()->getFechaActual();
    std::set<Publicacion *> publicacion = ap->getPublicaciones();
    std::set<Publicacion *>::iterator publicacionAux;
    for (publicacionAux = publicacion.begin(); publicacionAux != publicacion.end(); ++publicacionAux)
    {
        Publicacion *pub = *publicacionAux;
        bool e1 = pub->existeFecha(fechaActual);
        bool e2 = pub->existeTipoPub(tipoPublicacion);
        if (e1 && e2)
        {
            return false;
        }
    }
    bool pactivo = activo;
    int ultimaPublicacion = this->ultimaPub + 1;
    this->ultimaPub += 1;
    Publicacion *pubAgregar = new Publicacion(ultimaPublicacion, fechaActual, tipoPublicacion, texto, precio, pactivo);
    pubAgregar->setAdministra(ap);
    ManejadorInmueble *manejador = ManejadorInmueble::getInstance();
    manejador->agregarPub(pubAgregar);
    ap->agregarPublicacion(pubAgregar);
    return true;
}

//CONSULTA DE NOTIFICACION
std::set<DTNotificacion> ManejadorUsuario::obtenerNotificaciones(std::string nickname){
    std::set<DTNotificacion> resultado;
    Suscriptor *suscriptor = NULL;
    if (clientes.find(nickname) != clientes.end())
    {
        suscriptor = clientes[nickname];
    }
    else if (propietarios.find(nickname) != propietarios.end())
    {
        suscriptor = propietarios[nickname];
    }
    resultado = suscriptor->getNotificaciones();
    return resultado;
}   

void ManejadorUsuario::borrarNotificaciones(std::string nickname) {
    Suscriptor* suscriptor = NULL;
    if (clientes.find(nickname) != clientes.end()){
        suscriptor = clientes[nickname];
    }else 
        if (propietarios.find(nickname) != propietarios.end()){
            suscriptor = propietarios[nickname];
    }
    if (suscriptor != NULL){
        suscriptor->borrarNotificaciones();
    }
}

// CASO DE USO ALTA DE ADMINISTRA PROPIEDAD
std::map<std::string, Inmobiliaria *> &ManejadorUsuario::getInmobiliarias()
{
    return this->inmobiliarias;
}

// CASO DE USO SUSCRIBIRSE A NOTIFICACIONES
std::set<std::string> ManejadorUsuario::listarInmobiliariasNoSuscriptas(std::string nicknameUsuario){
    std::set<std::string> resultado;
    Suscriptor *suscriptor = NULL;
    if (clientes.find(nicknameUsuario) != clientes.end()){
        suscriptor = clientes[nicknameUsuario];
    }
    else 
        if (propietarios.find(nicknameUsuario) != propietarios.end()){
            suscriptor = propietarios[nicknameUsuario];
        }
    std::map<std::string, Inmobiliaria *>::iterator it;
    for (it = inmobiliarias.begin(); it != inmobiliarias.end(); it++){
        Inmobiliaria *inmo = it->second;
        if (!inmo->estaSuscripto(suscriptor)){
            resultado.insert(inmo->getNickname());
        }
    }
    return resultado;
}

void ManejadorUsuario::suscribirseAInmobiliaria(std::string nicknameUsuario, std::string nicknameInmobiliaria){
    Suscriptor *suscriptor = NULL;
    // buscamos al usuario que quiere suscribirse entre clientes o propietarios
    if (this->clientes.find(nicknameUsuario) != this->clientes.end())
        suscriptor = this->clientes[nicknameUsuario];
    else 
        if (this->propietarios.find(nicknameUsuario) != this->propietarios.end())
            suscriptor = this->propietarios[nicknameUsuario];
    Inmobiliaria *inmobiliaria = getInmobiliaria(nicknameInmobiliaria);
    if (suscriptor != NULL && inmobiliaria != NULL && !inmobiliaria->estaSuscripto(suscriptor)){
        inmobiliaria->agregarSuscriptor(suscriptor);
    }
}

// CASO DE USO ELIMINAR SUSCRIPCIONES
std::set<std::string> ManejadorUsuario::listarSuscripciones(std::string nickname)
{
    std::set<std::string> resultado;
    std::map<std::string, Inmobiliaria *>::iterator inm;
    for (inm = this->inmobiliarias.begin(); inm != this->inmobiliarias.end(); inm++)
    {
        Inmobiliaria *inmo = inm->second;
        if (inmo->tieneSuscriptor(nickname))
        {
            resultado.insert(inmo->getNickname());
        }
    }
    return resultado;
};

void ManejadorUsuario::eliminarSuscripcion(std::string nicknameUsuario, std::string nicknameInmobiliaria)
{
    Usuario *usuario = NULL;
    // buscamos al usuario que quiere desuscribirse entre clientes o propietarios para chequear
    if (this->clientes.find(nicknameUsuario) != this->clientes.end())
        usuario = this->clientes[nicknameUsuario];
    else if (this->propietarios.find(nicknameUsuario) != this->propietarios.end())
        usuario = this->propietarios[nicknameUsuario];
    // queremos que nos devuelva un puntero al suscriptor para poder agregarlo al set de suscriptores de la inm
    Suscriptor *suscriptor = dynamic_cast<Suscriptor *>(usuario);
    Inmobiliaria *inmobiliaria = getInmobiliaria(nicknameInmobiliaria);
    if (suscriptor != NULL && inmobiliaria != NULL && inmobiliaria->estaSuscripto(suscriptor))
    {
        inmobiliaria->eliminarSuscriptor(suscriptor);
    }
}
