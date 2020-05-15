#include "menu.h"

void menu::iniciar(busquedaLibro& a, busquedaPorAutor& b, busquedaPorEspecialidad& c, BusquedaPorTitulo& d)
{
	ifstream inicio("ruta.txt");
	if (inicio.is_open()) {
		string aux;
		int i = 1;
		while (!inicio.eof()) {
			getline(inicio, aux, '\n');
			libro lib = libro::crearLibroConArchivo(aux);
			cout << i << ".-" << lib << endl<<endl;
			a.insertar(lib, lib.getClave_o_ISBN());
			b.insertar(lib);
			c.insertar(lib);
			d.insertar(lib);
			i++;
		}
		
	}
	inicio.close();

}
