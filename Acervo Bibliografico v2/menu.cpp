#include "menu.h"

void menu::iniciar(busquedaLibro& a, busquedaPorAutor& b, busquedaPorEspecialidad& c, BusquedaPorTitulo& d)
{
	ifstream inicio("ruta.txt");
	if (inicio.is_open()) {
		string aux;
		while (!inicio.eof()) {
			getline(inicio, aux, '\n');
			libro lib = libro::crearLibroConArchivo(aux);
			a.insertar(lib, lib.getClave_o_ISBN());
			b.insertar(lib);
			c.insertar(lib);
			d.insertar(lib);
		}
		
	}
	inicio.close();

}

void menu::imprimirPosiblesBusquedas(int op, busquedaLibro& a, busquedaPorAutor& b, busquedaPorEspecialidad& c, BusquedaPorTitulo& d)
{
	stack<listaIdString> aux;
	switch (op) {
	case 1:
		aux = a.getIDs();
		cout << "Posibles intereses por ISBN" << endl;
		break;
	case 2:
		aux = b.getIDs();
		cout << "Posibles intereses por Autor" << endl;
		break;
	case 3:
		cout << "Posibles intereses por Especialidad" << endl;
		aux = c.getIDs();
		break;
	case 4:
		cout << "Posibles intereses por Titulo" << endl;
		aux = d.getIDs();
		break;
	default:
		system("cls");
		cout << "----Digite una opcion valida----" << endl << "1.- ISBN \n 2.- Autor \n 3.- Especialidad (tema) \n 4.- Titulo \n--->";
		cin >> op;
		cin.ignore(100, '\n');
		fflush(stdin);
		menu::imprimirPosiblesBusquedas(op, a, b, c, d);
		break;
	}
	system("cls");
	if (aux.getSize() > 0) {
		frame<listaIdString>* printer = aux.getPeek();
		while (printer != nullptr) {
			cout << *printer->getItem() << endl;
			printer = printer->getNext();
		}
	}
	else {
		cout << "Sin resultados " << endl;
	}
	system("Pause");
}

void menu::buscar(const string& e, int i, busquedaLibro& a, busquedaPorAutor& b, busquedaPorEspecialidad& c, BusquedaPorTitulo& d)
{
	system("cls");
	string aux = "Resultados de " + e;
	list<libro> res;
	switch (i) {
	case 1:
		aux += " en ISBN";
		res = a.getLibros(e);
		break;
	case 2:
		aux += " en autores";
		res = b.getLibros(e);
		break;
	case 3:
		aux += " en especialidad";
		res = c.getLibros(e);
		break;
	case 4:
		aux += " en titulo";
		res = d.getLibros(e);
		break;
	default:
		system("cls");
		cout << "La opcion digitada no es valida, digite una valida para realizar su busqueda con lo ya introducido: " << endl;
		cin >> i;
		cin.ignore(100, '\n');
		fflush(stdin);
		menu::buscar(e, i, a, b, c, d);
		break;
	}
	if (res.size() > 0) {
		cout << aux << endl;
		for (libro it : res) {
			cout << it << endl << endl;;
		}
	}
	else {
		cout << "Sin " << aux << endl;
	}
	system("Pause");
	system("cls");
}

void menu::run(busquedaLibro& a, busquedaPorAutor& b, busquedaPorEspecialidad& c, BusquedaPorTitulo& d, bool init)
{
	if(init == true)
		menu::iniciar(a, b, c, d);
	int op;
	string aux;
	cout << "Menu:\n1.- Ver todas las opciones segun su categoria \n2.- Buscar un libro por ISBN \n3.- Buscar un libro por Autor \n4.- Buscar un libro por especialidad\n5.- Buscar un libro por titulo\n---->";
	cin >> op;
	cin.ignore(100, '\n');
	switch (op) {
	case 1:
		system("cls");
		cout << "Ver opciones de busqueda segun: \n1.- ISBN \n2.- Autor \n3.- Especialidad \n4.- Titulo\n 5.- Volver a menu \n--->";
		cin >> op;
		cin.ignore(100, '\n');
		if (op < 5) {
			menu::imprimirPosiblesBusquedas(op, a, b, c, d);
		}
		else {
			menu::run(a, b, c, d, false);
		}
		break;
	case 2:
	case 3:
	case 4:
	case 5:

		op--;
		system("cls");
		cout << "Escriba su busqueda: "; getline(cin, aux, '\n');
		if (op < 5) {
			menu::buscar(aux, op, a, b, c, d);
		}
		else {
			menu::run(a, b, c, d, false);
		}
		break;
	default:
		menu::run(a, b, c, d, false);
		break;
	}
	menu::run(a, b, c, d, false);
}

