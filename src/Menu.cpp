#include <iostream>
#include "../include/Menu.h"
#include "../include/CargaDatos.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoTecho.h"
#include "../include/Factory.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTFecha.h"
#include "../include/DTInmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include "../include/ManejadorInmueble.h"
#include "../include/ManejadorUsuario.h"
#include "../include/IEliminarInmueble.h"
#include "../include/Convertir.h"
#include <string>
#include <set>
#include <cstdlib>

void mostrarMenu()
{
    std::cout << "=== Menu de Operaciones ===" << std::endl;
    std::cout << "1. Alta de Usuario" << std::endl;
    std::cout << "2. Alta de Publicacion" << std::endl;
    std::cout << "3. Consulta de Publicaciones" << std::endl;
    std::cout << "4. Eliminar Inmueble" << std::endl;
    std::cout << "5. Suscribirse a Notificaciones" << std::endl;
    std::cout << "6. Consulta de Notificaciones" << std::endl;
    std::cout << "7. Eliminar Suscripciones" << std::endl;
    std::cout << "8. Alta de Administracion de Propiedad" << std::endl;
    std::cout << "9. Cargar Datos" << std::endl;
    std::cout << "10. Ver fecha actual" << std::endl;
    std::cout << "11. Asignar fecha actual" << std::endl;
    std::cout << "12. Liberar memoria" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese el codigo de operacion: ";
}

int obtenerOpcion()
{
    int opcion;
    std::cin >> opcion;
    std::cin.ignore();
    return opcion;
}

void ejecutarOpcion(int opcion)
{
    switch (opcion)
    {
    case 1:
        std::cout << " - ALTA DE USUARIO - " << std::endl;
        altaUsuario();
        break;
    case 2:
        std::cout << " - ALTA DE PUBLICACION - " << std::endl;
        altaPublicacion();
        break;
    case 3:
        std::cout << " - CONSULTA DE PUBLICACIONES - " << std::endl;
        consultaPublicaciones();
        break;
    case 4:
        std::cout << " - ELIMINAR INMUEBLE - " << std::endl;
        eliminarInmueble();
        break;
    case 5:
        std::cout << " - SUSCRIBIRSE A NOTIFICACIONES - " << std::endl;
        suscribirseNotificaciones();
        break;
    case 6:
        std::cout << " - CONSULTAR NOTIFICACIONES - " << std::endl;
        consultaNotificaciones();
        break;
    case 7:
        std::cout << " - ELIMINAR SUSCRIPCIONES - " << std::endl;
        eliminarSuscripciones();
        break;
    case 8:
        std::cout << " - ALTA ADMINISTRACION DE PROPIEDAD - " << std::endl;
        altaAdministracionPropiedad();
        break;
    case 9:
        std::cout << " - CARGAR DATOS - " << std::endl;
        cargarDatos();
        break;
    case 10:
        std::cout << " - VER FECHA ACTUAL - " << std::endl;
        verFechaActual();
        break;
    case 11:
        std::cout << " - ASIGNAR FECHA ACTUAL - " << std::endl;
        asignarFechaActual();
        break;
    case 0:
        std::cout << "Saliendo del programa..." << std::endl;
        exit(0);
    case 12:
        Factory::getInstance()->eliminarControladores();
        ManejadorUsuario::deleteInstance();
        ManejadorInmueble::deleteInstance();
        Factory::deleteInstance();
        std::cout << "Memoria liberada correctamente." << std::endl;
        exit(0);
        break;
    default:
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void altaUsuario()
{

    Factory *factory = Factory::getInstance();
    IAltaUsuario *ci = factory->getAltaUsuario();

    std::cout << "Ingrese el tipo de usuario (0: Cliente, 1: Inmobiliaria, 2: Propietario): ";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();
    if (tipoUsuario < 0 || tipoUsuario > 2)
    {
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }

    bool usuarioOk = false;

    std::string nickname;
    std::string contrasena;
    std::string nombre;
    std::string email;
    std::string apellido;
    std::string documento;
    std::string url;
    std::string telefono;
    std::string direccion;
    std::string cuentaBancaria;

    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    if (tipoUsuario == 0)
    {
        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);
        std::cout << "Documento: ";
        std::getline(std::cin, documento);
        usuarioOk = ci->altaCliente(nickname, contrasena, nombre, email, apellido, documento);
    }
    else if (tipoUsuario == 1)
    {
        std::cout << "Direccion: ";
        std::getline(std::cin, direccion);
        std::cout << "URL: ";
        std::getline(std::cin, url);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = ci->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    }
    else if (tipoUsuario == 2)
    {
        std::cout << "Cuenta Bancaria: ";
        std::getline(std::cin, cuentaBancaria);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = ci->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    }
    if (usuarioOk)
    {
        if (tipoUsuario == 1 || tipoUsuario == 2)
        {
            int salir = 1;
            std::cout << "¿Quiere ingresar los datos relacionados? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
            std::string inmuebleDireccion;
            int numeroPuerta;
            int superficie;
            int anoConstruccion;
            while (salir != 0)
            {
                if (tipoUsuario == 1)
                {
                    std::cout << "Lista de Propietarios:\n";
                    std::set<DTUsuario> propietarios = ci->listarPropietarios();
                    if (propietarios.empty())
                    {
                        std::cout << "No hay propietarios registrados. No se puede representar a ninguno.\n";
                    }
                    else
                    {
                        for (std::set<DTUsuario>::iterator it = propietarios.begin(); it != propietarios.end(); ++it)
                        {
                            std::cout << "- Nickname: " << it->getNickname() << ", Nombre: " << it->getNombre() << std::endl;
                        }
                        std::cout << "Nickname propietario a representar: ";
                        std::string nicknamePropietario;
                        std::getline(std::cin, nicknamePropietario);
                        if (ci->representarPropietario(nicknamePropietario))
                        {
                            std::cout << "Propietario representado con exito.\n";
                        }
                    }
                }
                else if (tipoUsuario == 2)
                {
                    int tipoInmueble;
                    std::cout << "Indique el tipo de inmueble (1: Casa, 0: Apartamento): ";
                    std::cin >> tipoInmueble;
                    std::cin.ignore();

                    std::cout << "Direccion: ";
                    std::getline(std::cin, inmuebleDireccion);
                    std::cout << "Numero de Puerta: ";
                    std::cin >> numeroPuerta;
                    std::cin.ignore();
                    std::cout << "Superficie: ";
                    std::cin >> superficie;
                    std::cin.ignore();
                    std::cout << "Ano de Construccion: ";
                    std::cin >> anoConstruccion;
                    std::cin.ignore();

                    if (tipoInmueble == 1)
                    {
                        std::cout << "Es PH (1 para si, 0 para no): ";
                        int inEsPH;
                        std::cin >> inEsPH;
                        bool esPH = (inEsPH == 1);
                        std::cin.ignore();
                        std::cout << "Tipo de Techo (0: Liviano 1: A dos aguas, 2: Plano): ";
                        int inTipoTecho;
                        std::cin >> inTipoTecho;
                        std::cin.ignore();
                        TipoTecho techo = Liviano;
                        if (inTipoTecho == 1)
                        {
                            techo = A_dos_aguas;
                        }
                        else if (inTipoTecho == 2)
                        {
                            techo = Plano;
                        }
                        ci->altaCasa(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                    }
                    else
                    {
                        int piso;
                        std::cout << "Piso: ";
                        std::cin >> piso;
                        std::cin.ignore();
                        std::cout << "Tiene Ascensor (1 para si, 0 para no): ";
                        int inTieneAscensor;
                        std::cin >> inTieneAscensor;
                        bool tieneAscensor = (inTieneAscensor == 1);
                        std::cin.ignore();
                        std::cout << "Gastos Comunes: ";
                        float gastosComunes;
                        std::cin >> gastosComunes;
                        std::cin.ignore();
                        ci->altaApartamento(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
                    }
                }
                std::string inputSalir;
                std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
                std::getline(std::cin, inputSalir);
                salir = (inputSalir == "1") ? 1 : 0;
                if (salir == 0)
                {
                    std::cout << "\n--- Inmuebles registrados hasta el momento ---\n";
                }
            }
        }
        ci->finalizarAltaUsuario();
        std::cout << "Usuario dado de alta con exito." << std::endl;
    }
    else
    {
        std::cout << "Error al crear el usuario, el usuario ya existe o la contrasena ingresada es menor de 6 caracteres" << std::endl;
    }
}

void altaPublicacion()
{

    Factory *factory = Factory::getInstance();
    IAltaPublicacion *controlador = factory->getAltaPublicacion();

    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario> Usuarios = controlador->listarInmobiliarias();
    // Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
    std::set<DTUsuario>::iterator it;
    for (it = Usuarios.begin(); it != Usuarios.end(); ++it)
    {
        std::cout << "Nickname: " << (*it).getNickname() << ", Nombre: " << (*it).getNombre() << std::endl;
    }
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    std::cout << std::endl;
    std::set<DTInmuebleAdministrado> listaInmAdm = controlador->listarInmueblesAdministrados(nicknameInmobiliaria);
    if (listaInmAdm.empty()) {
        std::cout << "La inmobiliaria no tiene inmuebles administrados.\n";
        return;
    }
    std::cout << "Cantidad de inmuebles administrados: " << listaInmAdm.size() << std::endl;    
    std::set<DTInmuebleAdministrado>::iterator ite;
    for (ite = listaInmAdm.begin(); ite != listaInmAdm.end(); ++ite)
    {
        std::cout << "Codigo:" << (*ite).getCodigo() << ", Direccion: " << (*ite).getDireccion() << ", Fecha comienzo: " << (*ite).getFechaComienzo() << std::endl;
    }
    int codigoInmueble;
    bool encontrado = false;
    while (!encontrado) {
        std::cout << "Ingrese el codigo del inmueble a publicar: ";
        std::cin >> codigoInmueble;
        std::cin.ignore();
        for (ite = listaInmAdm.begin(); ite != listaInmAdm.end(); ++ite) {
            if ((*ite).getCodigo() == codigoInmueble) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            std::cout << "Codigo invalido. Por favor intente de nuevo.\n";
        }
    }
    int inTipoPublicacion=-1;
    while (inTipoPublicacion != 0 && inTipoPublicacion != 1){
        std::cout << "\nTipo de Publicacion: (1: Venta, 0: Alquiler): ";
        std::cin >> inTipoPublicacion;
        if (std::cin.fail() || (inTipoPublicacion != 0 && inTipoPublicacion != 1)){
            std::cout << "Entrada invalida. Intente de nuevo." << std::endl;
            std::cin.clear();   
            std::cin.ignore(); 
            inTipoPublicacion = -1; 
        }
    }
    std::cin.ignore(); 
    TipoPublicacion tipoPublicacion = (inTipoPublicacion == 1) ? Venta : Alquiler;
    std::cout << "Texto: ";
    std::string texto;
    std::getline(std::cin, texto);
    float precio = -1;
    bool precioValido = false;
    while (!precioValido) {
        std::cout << "Precio: ";
        std::cin >> precio;
        if (std::cin.fail()) {
            std::cout << "Entrada invalida. Ingrese un numero para el precio.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        } else {
            precioValido = true;
            std::cin.ignore();
        }
    }
    bool ok =controlador->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
    if (ok)
        std::cout << "Publicacion registrada con exito." << std::endl;
    else
     std::cout << "Error: no se pudo registrar la publicacion." << std::endl;
}

void consultaPublicaciones()
{
    Factory *factory = Factory::getInstance();
    IConsultaDePublicaciones *consultaCtrl = factory->getConsultaDePublicaciones();

    int inTipoPublicacion = -1;
    while (inTipoPublicacion != 0 && inTipoPublicacion != 1)
    {
        std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler): ";
        std::cin >> inTipoPublicacion;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            inTipoPublicacion = -1;
        }
    }
    TipoPublicacion tipoPublicacion = (inTipoPublicacion == 1) ? Venta : Alquiler;

    float precioMinimo = 0.0f;
    std::cout << "Precio (Min): ";
    while (!(std::cin >> precioMinimo))
    {
        std::cout << "Entrada invalida. Ingrese un número para Precio (Min): ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    float precioMaximo = 0.0f;
    std::cout << "Precio (Max): ";
    while (!(std::cin >> precioMaximo))
    {
        std::cout << "Entrada invalida. Ingrese un número para Precio (Max): ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    int inTipoInmueble = -1;
    while (inTipoInmueble != 0 && inTipoInmueble != 1 && inTipoInmueble != 2)
    {
        std::cout << "Tipo de Inmueble: (1: Casa, 2: Apartamento, 0: Todos): ";
        std::cin >> inTipoInmueble;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            inTipoInmueble = -1;
        }
    }
    std::set<DTPublicacion> publicaciones;
   //TipoInmueble tipoInmueble = Todos;
    if (inTipoInmueble == 1)
    {
         publicaciones = consultaCtrl->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, TipoCasa);
    }
    else if (inTipoInmueble == 2)
    {
        publicaciones = consultaCtrl->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, TipoApartamento);
        //tipoInmueble = TipoApartamento;
    }else if (inTipoInmueble == 0){
    std::set<DTPublicacion> casa = consultaCtrl->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, TipoCasa);
    std::set<DTPublicacion> apto = consultaCtrl->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, TipoApartamento);

    publicaciones = casa; // Copiar publicaciones de casa
    publicaciones.insert(apto.begin(), apto.end()); // Unir con publicaciones de apartamento9
    }


    if (publicaciones.empty())
    {
        std::cout << "No se encontraron publicaciones que coincidan con los filtros.\n";
        return;
    }

    std::cout << "Publicaciones encontradas:\n";
    for (std::set<DTPublicacion>::const_iterator it = publicaciones.begin(); it != publicaciones.end(); ++it)
    {
        const DTPublicacion &pub = *it;
        std::cout << "- Codigo: " << pub.getCodigo()
                  << ", Fecha: " << pub.getFecha().toString()
                  << ", Texto: " << pub.getTexto()
                  << ", Precio: " << pub.getPrecio()
                  << ", Inmobiliaria: " << pub.getInmobiliaria()
                  << std::endl;
    }

    int verDetalle = -1;
    while (verDetalle != 0 && verDetalle != 1)
    {
        std::cout << "Ver detalle de la publicacion: (1: Si, 0: No): ";
        std::cin >> verDetalle;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            verDetalle = -1;
        }
    }

    if (verDetalle == 1)
    {
        std::cout << "Codigo de publicacion: ";
        int codigoPublicacion;
        while (!(std::cin >> codigoPublicacion))
        {
            std::cout << "Entrada invalida. Ingrese un código valido: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        DTInmueble *inmuebleDetalle = consultaCtrl->detalleInmueblePublicacion(codigoPublicacion);

        if (!inmuebleDetalle)
        {
            std::cout << "No se encontro el inmueble." << std::endl;
            return;
        }

        std::cout << "Detalle del inmueble:\n";
        std::cout << "Codigo: " << inmuebleDetalle->getCodigo()
                  << ", Direccion: " << inmuebleDetalle->getDireccion()
                  << ", Nro. puerta: " << inmuebleDetalle->getNumeroPuerta()
                  << ", Superficie: " << inmuebleDetalle->getSuperficie() << " m2"
                  << ", Construccion: " << inmuebleDetalle->getAnioConstruccion();

        DTCasa *casa = dynamic_cast<DTCasa *>(inmuebleDetalle);
        if (casa)
        {
            std::cout << ", PH: " << (casa->getEsPH() ? "Si" : "No")
                      << ", Tipo de techo: " << casa->getTecho()
                      << std::endl;
        }
        else
        {
            DTApartamento *apto = dynamic_cast<DTApartamento *>(inmuebleDetalle);
            if (apto)
            {
                std::cout << ", Piso: " << apto->getPiso()
                          << ", Ascensor: " << (apto->getTieneAscensor() ? "Si" : "No")
                          << ", Gastos comunes: " << apto->getGastosComunes()
                          << std::endl;
            }
        }
         delete inmuebleDetalle;
    }
}

void eliminarInmueble()
{
    Factory *factory = Factory::getInstance();
    IEliminarInmueble *ci = factory->getEliminarInmueble();
    std::cout << "Listado de inmuebles:\n";
    std::set<DTInmuebleListado> inmuebles = ci->listarInmuebles();

    if (inmuebles.empty())
    {
        std::cout << "No hay inmuebles disponibles.\n";
        return;
    }

    for (std::set<DTInmuebleListado>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it)
    {
        std::cout << "- Codigo: " << it->getCodigo()
                  << ", Direccion: " << it->getDireccion()
                  << ", Propietario: " << it->getPropietario() << std::endl;
    }
    std::cout << "Codigo del inmueble a eliminar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    
    std::cout << "Detalle del inmueble:\n";
    DTInmueble *detalle = ci->detalleInmueble(codigoInmueble);

    if (!detalle)
    {
        std::cout << "Codigo no valido. No se encontro el inmueble.\n";
        return;
    }

    DTCasa *casa = dynamic_cast<DTCasa *>(detalle);
    if (casa)
    {
        std::cout << "Codigo: " << casa->getCodigo()
                  << ", Direccion: " << casa->getDireccion()
                  << ", Nro. puerta: " << casa->getNumeroPuerta()
                  << ", Superficie: " << casa->getSuperficie() << " m2"
                  << ", Construccion: " << casa->getAnioConstruccion()
                  << ", PH: " << (casa->getEsPH() ? "Si" : "No")
                  << ", Tipo de techo: " << casa->getTecho() << std::endl;
    }
    else
    {
        DTApartamento *apto = dynamic_cast<DTApartamento *>(detalle);
        if (apto)
        {
            std::cout << "Codigo: " << apto->getCodigo()
                      << ", Direccion: " << apto->getDireccion()
                      << ", Nro. puerta: " << apto->getNumeroPuerta()
                      << ", Superficie: " << apto->getSuperficie() << " m2"
                      << ", Construccion: " << apto->getAnioConstruccion()
                      << ", Piso: " << apto->getPiso()
                      << ", Ascensor: " << (apto->getTieneAscensor() ? "Si" : "No")
                      << ", Gastos comunes: " << apto->getGastosComunes() << std::endl;
        }
    }

    delete detalle;
    int deseaEliminar;
    std::cout << "¿Desea eliminar?: (1: Si, 0: No): ";
    std::cin >> deseaEliminar;
    std::cin.ignore();
    if (deseaEliminar == 1)
    {
        ci->eliminarInmueble(codigoInmueble);
        std::cout << "Inmueble eliminado con exito.\n";
    }
}

void suscribirseNotificaciones()
{
    Factory *factory = Factory::getInstance();
    ISuscribirseANotificaciones *controlador = factory->getSuscribirseANotificaciones();

    std::string nicknameUsuario;
    std::cout << "Ingrese su nickname (cliente o propietario): ";
    std::getline(std::cin, nicknameUsuario);

    int salir = 1;
    while (salir != 0)
    {
        std::set<std::string> inmobiliarias = controlador->listarInmobiliariasNoSuscriptas(nicknameUsuario);

        if (inmobiliarias.empty())
        {
            std::cout << "No hay mas inmobiliarias disponibles para suscribirse." << std::endl;
            return;
        }

        std::cout << "Inmobiliarias disponibles para suscribirse:\n";
        for (std::set<std::string>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it)
        {
            std::cout << "- " << *it << std::endl;
        }

        std::cout << "Ingrese el nickname de la inmobiliaria a la que desea suscribirse: ";
        std::string nicknameInmobiliaria;
        std::getline(std::cin, nicknameInmobiliaria);

        if (inmobiliarias.count(nicknameInmobiliaria) == 0)
        {
            std::cout << "Nickname invalido o ya estas suscripto a esta inmobiliaria." << std::endl;
        }
        else
        {
            controlador->suscribirseAInmobiliaria(nicknameUsuario, nicknameInmobiliaria);
            std::cout << "Suscripcion realizada con exito." << std::endl;
        }

        std::cout << "¿Desea seguir suscribiendose? (1: Sí, 0: No): ";
        std::string input;
        std::getline(std::cin, input);
        salir = (input == "1") ? 1 : 0;
        std::cout << std::endl;
    }
}

void consultaNotificaciones()
{
    Factory *factory = Factory::getInstance();
    IConsultaDeNotificaciones *controlador = factory->getConsultaDeNotificaciones();
    std::set<std::string> nicknames = controlador->listarSuscriptos();
        if (!nicknames.empty()) {
        std::cout << "Nicknames disponibles para consultar notificaciones:\n";
        std::set<std::string>::const_iterator it;
        for (it = nicknames.begin(); it != nicknames.end(); ++it) {
            std::cout << "- " << *it << "\n";
        }
        std::cout << "\n";
    } else {
        std::cout << "No hay usuarios suscriptos disponibles.\n";
        return;
    }
    std::string nicknameUsuario;
    std::cout << "Ingrese su nickname (cliente o propietario): ";
    std::getline(std::cin, nicknameUsuario);

    std::set<DTNotificacion> notificaciones = controlador->listarNotificaciones(nicknameUsuario);
    std::set<DTNotificacion>::iterator it;
    if (notificaciones.empty()) {
        std::cout << "No hay mas notificaciones sin consultar.\n";
    } else {
        std::cout << "\nNotificaciones:\n";
        for(it = notificaciones.begin(); it != notificaciones.end(); ++it){
            std::cout<< "Nickname inmobliaria: " << (*it).getNickname()  << std::endl << "Codigo: " << (*it).getCodigo() << std::endl << "Tipo de inmueble: " << tipoInmuebleATexto((*it).getInmueble()) << std::endl << "Tipo de publicacion: " << tipoPublicacionATexto((*it).getTipo()) << std::endl << "Texto: " << (*it).getTexto() << std::endl << " \n";
        }
    }
    controlador->eliminarNotificaciones(nicknameUsuario);
}

void eliminarSuscripciones()
{
    Factory *factory = Factory::getInstance();
    IEliminarSuscripciones *controlador = factory->getEliminarSuscripciones();

    std::string nicknameUsuario;
    std::cout << "Ingrese su nickname (cliente o propietario): ";
    std::getline(std::cin, nicknameUsuario);

    int salir = 1;
    while (salir != 0)
    {
        std::set<std::string> inmobiliarias = controlador->listarSuscripciones(nicknameUsuario);

        if (inmobiliarias.empty())
        {
            std::cout << "No estas suscripto a ninguna inmobiliaria." << std::endl;
            return;
        }

        std::cout << "Inmobiliarias a las que estas suscripto:\n";
        for (std::set<std::string>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it)
        {
            std::cout << "- " << *it << std::endl;
        }

        std::cout << "Ingrese el nickname de la inmobiliaria de la que desea eliminar la suscripcion: ";
        std::string nicknameInmobiliaria;
        std::getline(std::cin, nicknameInmobiliaria);

        if (inmobiliarias.count(nicknameInmobiliaria) == 0)
        {
            std::cout << "Nickname invalido o no estas suscripto a esta inmobiliaria." << std::endl;
        }
        else
        {
            controlador->eliminarSuscripcion(nicknameUsuario, nicknameInmobiliaria);
            std::cout << "Suscripcion eliminada con exito." << std::endl;
        }

        std::cout << "¿Desea eliminar otra suscripcion? (1: Si, 0: No): ";
        std::string input;
        std::getline(std::cin, input);
        salir = (input == "1") ? 1 : 0;
        std::cout << std::endl;
    }
}

void altaAdministracionPropiedad()
{
    Factory *factory = Factory::getInstance();
    IAltaAdministracionPropiedad *iap = factory->getAltaAdministracionPropiedad();
    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario> inmobiliarias = iap->listarInmobiliarias();
    
    std::set<DTUsuario>::iterator it;
    for (it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it)
    {
        std::cout << "- Nickname: " << it->getNickname() << ", Nombre: " << it->getNombre() << std::endl;
    }
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    std::set<DTInmuebleListado> inmuebles = iap->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
    if (inmuebles.empty()) {
        std::cout << "No hay mas inmuebles sin administrar para esta inmobiliaria.\n";
        return;
    }
    std::set<DTInmuebleListado>::iterator itInmuebles;
    for (itInmuebles = inmuebles.begin(); itInmuebles != inmuebles.end(); ++itInmuebles)
    {
        std::cout << "- Codigo " << itInmuebles->getCodigo() << ", Direccion: " << itInmuebles->getDireccion() << ", Propietario: " << itInmuebles->getPropietario() << std::endl;
    }

    std::cout << "Codigo del inmueble a administrar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    
    iap->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
}

void cargarDatos()
{
    CargaDatos::getInstance();
    std::cout << "Se cargaron los datos\n";
}

void verFechaActual()
{
    Factory *factory = Factory::getInstance();
    IControladorFechaActual *cfecha = factory->getControladorFechaActual();
    DTFecha *fechaActual = cfecha->getFechaActual();
    std::cout << "fecha actual: " << fechaActual;
    delete fechaActual;
}

void asignarFechaActual()
{
    Factory *factory = Factory::getInstance();
    IControladorFechaActual *cfecha = factory->getControladorFechaActual();
    std::cout << "dia: ";
    int dia;
    std::cin >> dia;
    std::cin.ignore();
    std::cout << "mes: ";
    int mes;
    std::cin >> mes;
    std::cin.ignore();
    std::cout << "ano: ";
    int ano;
    std::cin >> ano;
    std::cin.ignore();
    cfecha->setNewFechaActual(dia, mes, ano);
}
