#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "ISuscribirseANotificaciones.h"
#include "IAltaUsuario.h"
#include "IEliminarSuscripciones.h"
#include "IAltaAdministracionPropiedad.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include <string>
#include <map>


class ControladorUsuario : public IAltaUsuario, public ISuscribirseANotificaciones, public IAltaAdministracionPropiedad, public IEliminarSuscripciones{
private:
    static ControladorUsuario *instancia;

    // Referencias temporales para dar de alta los inmuebles y representar propietarios
    Propietario *propietarioRecordado;
    Inmobiliaria *inmobiliariaRecordada;

    ControladorUsuario();

public:
    static ControladorUsuario *getInstance();

    // OPERACIONES CASO DE USO ALTA USUARIO (CATA)
    bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
    bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
    bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
    void altaCasa(std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo);
    void altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes);
    std::set<DTUsuario> listarPropietarios();
    void representarPropietario(std::string nicknamePropietario);
    void finalizarAltaUsuario();
    void mostrarInmuebles();

    // OPERACIONES CASO DE USO ALTA DE ADMINISTRACION DE PROPIEDAD (OLIVIA)
    std::set<DTUsuario> listarInmobiliarias();
    void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble);
    std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria);

    // OPERACIONES CASO DE USO SUSCRIBIRSE A NOTIFICACIONES (CATA)
    std::set<std::string> listarInmobiliariasNoSuscriptas(std::string nicknameUsuario);
    void suscribirseAInmobiliaria(std::string nicknameUsuario, std::string nicknameInmobiliaria);

    // OPERACIONES CASO DE USO Eliminar Suscripciones (marcelo)
    std::set<std::string> listarSuscripciones(std::string nickname);
    void eliminarSuscripcion(std::string nicknameUsuario, std::string nicknameInmobiliaria);
};

#endif
