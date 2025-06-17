#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "ISuscribirseANotificaciones.h"
#include "IAltaUsuario.h"
#include "IEliminarSuscripciones.h"
#include "IAltaAdministracionPropiedad.h"
#include "IConsultaDeNotificaciones.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include <string>
#include <map>


class ControladorUsuario : public IAltaUsuario, public ISuscribirseANotificaciones, public IAltaAdministracionPropiedad, public IEliminarSuscripciones, public IConsultaDeNotificaciones{
private:
    static ControladorUsuario *instancia;
    Propietario *propietarioRecordado;
    Inmobiliaria *inmobiliariaRecordada;
    ControladorUsuario();

public:
    static ControladorUsuario *getInstance();
    virtual ~ControladorUsuario();
    static void deleteInstance();

    //CASO DE USO ALTA USUARIO
    bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
    bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
    bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
    void altaCasa(std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo);
    void altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes);
    std::set<DTUsuario> listarPropietarios();
    bool representarPropietario(std::string nicknamePropietario);
    void finalizarAltaUsuario();
    
    //CASO DE USO ALTA DE ADMINISTRACION DE PROPIEDAD 
    std::set<DTUsuario> listarInmobiliarias();
    void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble);
    std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria);

    // OPERACION CONSULTA NOTIFICAIONES
     std::set<DTNotificacion> consultaNotificaciones(std::string nickname);

    //CASO DE USO SUSCRIBIRSE A NOTIFICACIONES 
    std::set<std::string> listarInmobiliariasNoSuscriptas(std::string nicknameUsuario);
    void suscribirseAInmobiliaria(std::string nicknameUsuario, std::string nicknameInmobiliaria);

    //CASO DE USO ELIMINAR SUSCRIPCIONES
    std::set<std::string> listarSuscripciones(std::string nickname);
    void eliminarSuscripcion(std::string nicknameUsuario, std::string nicknameInmobiliaria);
};

#endif
