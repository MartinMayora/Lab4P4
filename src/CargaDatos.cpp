#include "../include/CargaDatos.h"
#include <cstddef>
#include <iostream>

CargaDatos* CargaDatos::instance = NULL;

CargaDatos::CargaDatos() {
    Factory* f = Factory::getInstance();
    IAltaUsuario* altaUsuario= f->getAltaUsuario();
    IAltaAdministracionPropiedad* altaAdministraPropiedad=f->getAltaAdministracionPropiedad();
    //IAltaPublicacion* altaPublicacion = f->getAltaPublicacion();
    ControladorFechaActual* controladorFecha = ControladorFechaActual::getInstance();
    ISuscribirseANotificaciones* suscripcionCtrl = f->getSuscribirseANotificaciones();


    // CLIENTES
    altaUsuario->altaCliente("luisito23", "qweasd12", "Luis", "luisito23@gmail.com", "Pérez", "46859342");
    altaUsuario->altaCliente("anarojo88", "claveAna1", "Ana", "anarojo88@hotmail.com", "Rojo", "31287465");

    //PROPIETARIOS
    altaUsuario->altaPropietario("marcelom", "banco123", "Marcelo", "marcelo.m@gmail.com", "123456789012", "099876543");
    altaUsuario->altaCasa("Av. Rivera", 1011, 120, 1995, true, Plano);
    altaUsuario->altaApartamento("Av. Brasil", 2031, 75, 1980, 5, true, 3500);
    altaUsuario->finalizarAltaUsuario();

    altaUsuario->altaPropietario("robertarce", "pass456", "Roberto", "roberto.a@yahoo.com", "987654321001", "091234567");
    altaUsuario->altaCasa("Camino Maldonado", 1540, 95, 1988, false, Plano);
    altaUsuario->finalizarAltaUsuario();

    altaUsuario->altaPropietario("soledadf", "sole789", "Soledad", "soledad.f@gmail.com", "654321987654", "092345678");
    altaUsuario->altaApartamento("Colonia", 1542, 60, 1978, 12, true, 2800);
    altaUsuario->finalizarAltaUsuario();

    altaUsuario->altaPropietario("martagal", "martA01", "Marta", "marta.galvez@outlook.com", "321098765432", "098765432");
    altaUsuario->altaCasa("Juan Paullier", 801, 110, 2000, true, Liviano);
    altaUsuario->finalizarAltaUsuario();

    altaUsuario->altaPropietario("jorge88", "jorgepass88", "Jorge", "jorge.rivera@uy.com", "890123456789", "097654321");
    altaUsuario->altaApartamento("Bulevar Artigas", 871, 68, 2002, 3, false, 2200);
    altaUsuario->altaApartamento("Sarmiento", 1476, 80, 2008, 6, true, 3100);
    altaUsuario->altaCasa("Cno. Carrasco", 1576, 140, 2007, true, Plano);
    altaUsuario->finalizarAltaUsuario();

    //INMOBILIARIAS
    altaUsuario->altaInmobiliaria("casasur123", "casasur99", "Casa Sur", "contacto@casasur.com", "Canelones 2345", "https://casasur.com.uy", "24012345");
    altaUsuario->representarPropietario("marcelom");
    altaUsuario->representarPropietario("jorge88");
    altaUsuario->finalizarAltaUsuario();

    altaUsuario->altaInmobiliaria("idealhome", "home2025", "IHome", "info@idealhome.uy", "Av. Italia 4567", "https://idealhome.uy", "99123456");
    altaUsuario->representarPropietario("marcelom");
    altaUsuario->representarPropietario("martagal");
    altaUsuario->representarPropietario("jorge88");
    altaUsuario->finalizarAltaUsuario();

    altaUsuario->altaInmobiliaria("vivaurbana", "viva4567", "Viva Urbana", "contacto@vivaurbana.com", "18 de Julio 7890", "https://vivaurbana.com", "29109876");
    altaUsuario->representarPropietario("robertarce");
    altaUsuario->representarPropietario("soledadf");
    altaUsuario->representarPropietario("jorge88");
    altaUsuario->finalizarAltaUsuario();

    //ALTA DE ADMINISTRACION DE PROPIEDADES
    controladorFecha->setNewFechaActual(12, 12, 2015);
    altaAdministraPropiedad->altaAdministraPropiedad("casasur123", 2);
    
    controladorFecha->setNewFechaActual(25, 9, 2023);
    altaAdministraPropiedad->altaAdministraPropiedad("idealhome", 1);

    controladorFecha->setNewFechaActual(20, 7, 2022);
    altaAdministraPropiedad->altaAdministraPropiedad("vivaurbana", 3);

    controladorFecha->setNewFechaActual(1, 1, 2022);
    altaAdministraPropiedad->altaAdministraPropiedad("vivaurbana", 4);

    controladorFecha->setNewFechaActual(3, 7, 2010);
    altaAdministraPropiedad->altaAdministraPropiedad("idealhome", 5);

    controladorFecha->setNewFechaActual(4, 11, 2019);
    altaAdministraPropiedad->altaAdministraPropiedad("casasur123", 6);

    controladorFecha->setNewFechaActual(19, 5, 2020);
    altaAdministraPropiedad->altaAdministraPropiedad("vivaurbana", 6);

    controladorFecha->setNewFechaActual(19, 7, 2024);
    altaAdministraPropiedad->altaAdministraPropiedad("idealhome", 6);

    controladorFecha->setNewFechaActual(18, 9, 2023);
    altaAdministraPropiedad->altaAdministraPropiedad("idealhome", 7);

    controladorFecha->setNewFechaActual(19, 5, 2022);
    altaAdministraPropiedad->altaAdministraPropiedad("vivaurbana", 8);

    //GENERACION DE PUBLICACIONES
    /*
     controladorFecha->setNewFechaActual(9, 10, 2011);
    altaPublicacion->altaPublicacion("idealhome", 5, Venta, "Casa al fondo Juan Paullier con 110 m fondo y techo liviano.", 47000);

    controladorFecha->setNewFechaActual(15, 1, 2016);
    altaPublicacion->altaPublicacion("casasur123", 2, Alquiler, "Oportunidad en Av. Brasil: apartamento de 75 m piso 5 con ascensor.", 28000);

    controladorFecha->setNewFechaActual(5, 3, 2019);
    altaPublicacion->altaPublicacion("casasur123", 2, Alquiler, "Apartamento luminoso en Av. Brasil piso alto con excelentes servicios.", 29500);

    controladorFecha->setNewFechaActual(3, 4, 2019);
    altaPublicacion->altaPublicacion("idealhome", 5, Alquiler, "Casa ideal para familia en Juan Paullier barrio tranquilo.", 38500);

    controladorFecha->setNewFechaActual(12, 12, 2019);
    altaPublicacion->altaPublicacion("casasur123", 6, Venta, "Apartamento en Bulevar Artigas piso 3 muy luminoso y moderno.", 375000);

    controladorFecha->setNewFechaActual(12, 6, 2020);
    altaPublicacion->altaPublicacion("casasur123", 2, Venta, "Excelente apartamento en Av. Brasil con 75 m ideal para reforma.", 390000);

    controladorFecha->setNewFechaActual(20, 7, 2020);
    altaPublicacion->altaPublicacion("vivaurbana", 6, Alquiler, "Apartamento 68 m en Bulevar Artigas tercer piso sin ascensor.", 23000);

    controladorFecha->setNewFechaActual(4, 3, 2022);
    altaPublicacion->altaPublicacion("vivaurbana", 4, Alquiler, "Apartamento con ascensor en Colonia 1542 piso 12 excelente conectividad.", 26000);

    controladorFecha->setNewFechaActual(12, 9, 2022);
    altaPublicacion->altaPublicacion("vivaurbana", 3, Alquiler, "Casa excelente en Camino Maldonado de 95 m con patio al fondo.", 27000);

    controladorFecha->setNewFechaActual(1, 10, 2023);
    altaPublicacion->altaPublicacion("idealhome", 1, Venta, "Casa en Av. Rivera de 120 m con techo plano ideal para familia.", 520000);

    controladorFecha->setNewFechaActual(18, 10, 2023);
    altaPublicacion->altaPublicacion("idealhome", 7, Alquiler, "Apartamento amplio en Sarmiento 1476 piso 6 con ascensor.", 32000);

    controladorFecha->setNewFechaActual(19, 10, 2023);
    altaPublicacion->altaPublicacion("idealhome", 7, Venta, "Apartamento de 80 m en Sarmiento excelente estado y vista.", 455000);

    controladorFecha->setNewFechaActual(20, 11, 2023);
    altaPublicacion->altaPublicacion("idealhome", 7, Alquiler, "Apartamento con gran vista a la rambla", 31000);

    controladorFecha->setNewFechaActual(20, 11, 2023);
    altaPublicacion->altaPublicacion("idealhome", 7, Venta, "Aprtamente en excelentes condiciones de 80 m", 450000);

    controladorFecha->setNewFechaActual(8, 3, 2024);
    altaPublicacion->altaPublicacion("vivaurbana", 3, Venta, "Venta de casa en Camino Maldonado 95 m bien distribuidos.", 430000);

    controladorFecha->setNewFechaActual(5, 5, 2024);
    altaPublicacion->altaPublicacion("idealhome", 7, Alquiler, "Alquiler en Sarmiento 80 m piso alto con excelentes terminaciones.", 33000);

    controladorFecha->setNewFechaActual(1, 8, 2024);
    altaPublicacion->altaPublicacion("idealhome", 6, Venta, "A estrenar en Bulevar Artigas 871 apartamento moderno.", 400000);
    */

    suscripcionCtrl->suscribirseAInmobiliaria("luisito23", "casasur123");
    suscripcionCtrl->suscribirseAInmobiliaria("luisito23", "idealhome");
    suscripcionCtrl->suscribirseAInmobiliaria("anarojo88", "casasur123");
    suscripcionCtrl->suscribirseAInmobiliaria("anarojo88", "idealhome");
    suscripcionCtrl->suscribirseAInmobiliaria("anarojo88", "vivaurbana");
    suscripcionCtrl->suscribirseAInmobiliaria("marcelom", "idealhome");
    suscripcionCtrl->suscribirseAInmobiliaria("robertarce", "idealhome");
    suscripcionCtrl->suscribirseAInmobiliaria("soledadf", "vivaurbana");
    suscripcionCtrl->suscribirseAInmobiliaria("martagal", "vivaurbana");
    suscripcionCtrl->suscribirseAInmobiliaria("jorge88", "casasur123");
    suscripcionCtrl->suscribirseAInmobiliaria("jorge88", "idealhome");
    suscripcionCtrl->suscribirseAInmobiliaria("jorge88", "vivaurbana");
}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
}