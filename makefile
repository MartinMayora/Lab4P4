OBJETOS = build/AdministraPropiedad.o build/Apartamento.o build/CargaDatos.o \
build/Casa.o build/Cliente.o build/ControladorFechaActual.o \
build/ControladorInmueble.o build/ControladorUsuario.o build/DTApartamento.o \
build/DTCasa.o build/DTFecha.o build/DTInmueble.o build/DTInmuebleAdministrado.o \
build/DTInmuebleListado.o build/DTPublicacion.o build/DTUsuario.o build/Factory.o \
build/Inmobiliaria.o build/Inmueble.o build/main.o build/ManejadorInmueble.o \
build/ManejadorUsuario.o build/Menu.o build/Propietario.o build/Usuario.o build/Suscriptor.o \
build/Publicacion.o build/DTNotificacion.o build/Agenda.o


CXX = g++
OPCIONES = -g -Wall -std=c++98

ejec: $(OBJETOS) | build
	$(CXX) $(OPCIONES) $(OBJETOS) -o build/ejec

# CREA .o en Build
build/AdministraPropiedad.o: include/AdministraPropiedad.h src/AdministraPropiedad.cpp | build
	$(CXX) $(OPCIONES) -c src/AdministraPropiedad.cpp -o build/AdministraPropiedad.o

build/Apartamento.o: include/Apartamento.h src/Apartamento.cpp | build
	$(CXX) $(OPCIONES) -c src/Apartamento.cpp -o build/Apartamento.o

build/CargaDatos.o: include/CargaDatos.h src/CargaDatos.cpp | build
	$(CXX) $(OPCIONES) -c src/CargaDatos.cpp -o build/CargaDatos.o

build/Casa.o: include/Casa.h src/Casa.cpp | build
	$(CXX) $(OPCIONES) -c src/Casa.cpp -o build/Casa.o

build/Cliente.o: include/Cliente.h src/Cliente.cpp | build
	$(CXX) $(OPCIONES) -c src/Cliente.cpp -o build/Cliente.o

build/ControladorFechaActual.o: include/ControladorFechaActual.h src/ControladorFechaActual.cpp | build
	$(CXX) $(OPCIONES) -c src/ControladorFechaActual.cpp -o build/ControladorFechaActual.o

build/ControladorInmueble.o: include/ControladorInmueble.h src/ControladorInmueble.cpp | build
	$(CXX) $(OPCIONES) -c src/ControladorInmueble.cpp -o build/ControladorInmueble.o

build/ControladorUsuario.o: include/ControladorUsuario.h src/ControladorUsuario.cpp | build
	$(CXX) $(OPCIONES) -c src/ControladorUsuario.cpp -o build/ControladorUsuario.o

build/DTApartamento.o: include/DTApartamento.h src/DTApartamento.cpp | build
	$(CXX) $(OPCIONES) -c src/DTApartamento.cpp -o build/DTApartamento.o

build/DTCasa.o: include/DTCasa.h src/DTCasa.cpp | build
	$(CXX) $(OPCIONES) -c src/DTCasa.cpp -o build/DTCasa.o

build/DTFecha.o: include/DTFecha.h src/DTFecha.cpp | build
	$(CXX) $(OPCIONES) -c src/DTFecha.cpp -o build/DTFecha.o

build/DTInmueble.o: include/DTInmueble.h src/DTInmueble.cpp | build
	$(CXX) $(OPCIONES) -c src/DTInmueble.cpp -o build/DTInmueble.o

build/DTInmuebleAdministrado.o: include/DTInmuebleAdministrado.h src/DTInmuebleAdministrado.cpp | build
	$(CXX) $(OPCIONES) -c src/DTInmuebleAdministrado.cpp -o build/DTInmuebleAdministrado.o

build/DTInmuebleListado.o: include/DTInmuebleListado.h src/DTInmuebleListado.cpp | build
	$(CXX) $(OPCIONES) -c src/DTInmuebleListado.cpp -o build/DTInmuebleListado.o

build/DTNotificacion.o: include/DTNotificacion.h src/DTNotificacion.cpp | build
	$(CXX) $(OPCIONES) -c src/DTNotificacion.cpp -o build/DTNotificacion.o

build/DTPublicacion.o: include/DTPublicacion.h src/DTPublicacion.cpp | build
	$(CXX) $(OPCIONES) -c src/DTPublicacion.cpp -o build/DTPublicacion.o

build/DTUsuario.o: include/DTUsuario.h src/DTUsuario.cpp | build
	$(CXX) $(OPCIONES) -c src/DTUsuario.cpp -o build/DTUsuario.o

build/Factory.o: include/Factory.h src/Factory.cpp | build
	$(CXX) $(OPCIONES) -c src/Factory.cpp -o build/Factory.o

build/Inmobiliaria.o: include/Inmobiliaria.h src/Inmobiliaria.cpp | build
	$(CXX) $(OPCIONES) -c src/Inmobiliaria.cpp -o build/Inmobiliaria.o

build/Inmueble.o: include/Inmueble.h src/Inmueble.cpp | build
	$(CXX) $(OPCIONES) -c src/Inmueble.cpp -o build/Inmueble.o

build/main.o: src/main.cpp | build
	$(CXX) $(OPCIONES) -c src/main.cpp -o build/main.o

build/ManejadorInmueble.o: include/ManejadorInmueble.h src/ManejadorInmueble.cpp | build
	$(CXX) $(OPCIONES) -c src/ManejadorInmueble.cpp -o build/ManejadorInmueble.o

build/ManejadorUsuario.o: include/ManejadorUsuario.h src/ManejadorUsuario.cpp | build
	$(CXX) $(OPCIONES) -c src/ManejadorUsuario.cpp -o build/ManejadorUsuario.o

build/Menu.o: include/Menu.h src/Menu.cpp | build
	$(CXX) $(OPCIONES) -c src/Menu.cpp -o build/Menu.o

build/Propietario.o: include/Propietario.h src/Propietario.cpp | build
	$(CXX) $(OPCIONES) -c src/Propietario.cpp -o build/Propietario.o

build/Publicacion.o: include/Publicacion.h src/Publicacion.cpp | build
	$(CXX) $(OPCIONES) -c src/Publicacion.cpp -o build/Publicacion.o

build/Usuario.o: include/Usuario.h src/Usuario.cpp | build
	$(CXX) $(OPCIONES) -c src/Usuario.cpp -o build/Usuario.o

build/Suscriptor.o: include/Suscriptor.h src/Suscriptor.cpp | build
	$(CXX) $(OPCIONES) -c src/Suscriptor.cpp -o build/Suscriptor.o

build/Agenda.o: include/Agenda.h src/Agenda.cpp | build
	$(CXX) $(OPCIONES) -c src/Agenda.cpp -o build/Agenda.o



build:
	mkdir -p build

clean:
	rm -rf build

rebuild:
	make clean
	make

run:
	make clean
	make
	./build/ejec

memcheck:
	make clean
	make
	valgrind --leak-check=full ./build/ejec

zip: $(FUENTES) Makefile
	rm -f codigo.tar.gz
	tar -cvf codigo.tar $(FUENTES) Makefile
	gzip codigo.tar