#include "menu.h"
#include <string>
#include <algorithm> //Se ocupa para el uso de for_each en el programa
void menu::iniciar(List<libro> &coleccion, const std::string &ruta) //Se ejecuta al iniciar el programa, lee primero las rutas de los archivos guardados en un archivo
//Luego de obtener las rutas, crea los libros con una función estatica de libro y despues guarda el libro en la lista de entrada
{

	List<std::string> lista;
	fstream archivo(ruta.c_str(), std::ios::in);
	if (!archivo.fail()) {
		std::string aux;
		while (!archivo.eof()) {
			getline(archivo, aux);
			lista.insert(aux);
		}
		while (lista.size() > 0) {
			libro lib = libro::crearLibroConArchivo(lista.getHead()->getDato());
			coleccion.insert(lib);
			lista.pop(0);
		}
	}
	else {
		std::cout << "Sin archivos en el acervo..." << std::endl;
	}
}

void menu::menu(List<libro>& list, const std::string& ruta)
{
	//Aquí esta el menu donde se encarga de imprimir todas las opciones y llamar a las funciones correspondientes
	system("cls");
	if (list.size() == 0) //Esto se hace para evitar ingresar en la lista libros duplicados, ya que en ejecución la lista se actualiza sola y crea los archivos, así que no es necesario.
		iniciar(list, ruta);
	int caso;
	std::cout << "(1) Imprimir libros" << std::endl;
	std::cout << "(2) Buscar un libro" << std::endl;
	std::cout << "(3) Insertar un libro" << std::endl;
	std::cout << "(4) Mostrar todos los libros" << std::endl;
	std::cout << "(5) Salir" << std::endl;
	std::cout << "---->";
	std::cin >> caso;
	std::cin.clear();
	std::cin.ignore(100, '\n');
	switch (caso) {
	case 1:
		devuelta2:
		std::cout << "Digite que tipo de listado necesita: " << std::endl;
		std::cout << "(1) Por anio de edicion " << std::endl;
		std::cout << "(2) Por Tema o Especialidad " << std::endl;
		std::cout << "-----> ";
		std::cin >> caso;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		if (caso < 1 or 2 < caso) {
			std::cout << "Lo siento esa no es una opcion" << std::endl; goto devuelta2;
		}
		menu::imprimirListado(list, caso);
		break;
	case 2:
		devuelta:
		std::cout << "De las siguientes parametros de busqueda, digite el  numero de parametro " << std::endl;
		std::cout << "(1) Buscar por Titulo" << std::endl;
		std::cout << "(2) Buscar por Autor" << std::endl;
		std::cout << "(3) Clave o ISBN (mas precisa)" << std::endl;
		std::cin >> caso;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		if (caso < 1 or 3 < caso) {
			std::cout << "Lo siento esa no es una opcion" << std::endl;
			goto devuelta;
		}
		caso += 2;
		menu::imprimirListado(list, caso);
		break;
	case 3:
		menu::insertarLibro(list, ruta);
		break;
	case 4:
		menu::imprimirTodos(list);
		system("Pause");
		break;

	case 5:
		exit(1);
	default:
		std::cout << "Opción invalida...." << std::endl;
	}
	menu::menu(list, ruta);
}

List<libro> menu::buscar(List<libro>& list,const std::string &parametro, const int &tipo) //Esta función es la que se encarga de buscar los libros segun el parametro
// Además de devolver los resultado en una lista
{
	system("cls");
	List<libro> resultados;
	Nodo<libro>* aux = list.getHead();
	while (aux != nullptr) {
		switch (tipo) {
		case 1:
			if (aux->getDato().getTitulo().compare(parametro.c_str()) == 0)
				resultados.insert(aux->getDato());
			break;
		case 2:
			if (aux->getDato().getAutor().compare(parametro.c_str()) == 0)
				resultados.insert(aux->getDato());
			break;
		case 3:
			if (aux->getDato().getClave_o_ISBN().compare(parametro.c_str()) == 0)
				resultados.insert(aux->getDato());
			break;
		case 4:
			if (aux->getDato().getAnio_de_Edicion().compare(parametro.c_str()) == 0)
				resultados.insert(aux->getDato());
			break;
		case 5:
			if (aux->getDato().getTema().compare(parametro.c_str()) == 0)
				resultados.insert(aux->getDato());
		}
		aux = aux->getNext();
	}
	return resultados;
}

void menu::insertarLibro(List<libro>& list, const std::string &ruta) // Inserta un libro a la lista y además crea su archivo para cuando se abra nuevo el programa y lo lea
{
	system("cls");
	libro book = libro::crearLibro();
	if (menu::buscar(list, book.getClave_o_ISBN(), 3).size() == 0) {
		list.insert(book);
		libro::crearArchivoConLibro(book);
		std::fstream archivo = std::fstream(ruta.c_str(), ios::app);
		if (archivo.fail())
			std::cout << "El archivo no se pudo escribir..." << std::endl;
		else {
			archivo << '\n' << book.createFilePath();
		}
		archivo.close();
	}
	else {
		std::cout << "El libro se encuentra en el acervo..." << std::endl;
	}
}

void menu::imprimirListado(List<libro>& list, int& i) //Lo que hace esta funcion es imprimir el resultado de las busquedas
{
	std::string busqueda;
	List<libro> lib;
	switch(i){
	case 1:
		//Año de Edicion
		std::cout << "Digite lo que busca: ";
		std::getline(std::cin, busqueda, '\n');
		lib = menu::buscar(list, busqueda, 4);
		busqueda = "Resultado/s por Anio " + busqueda;
		break;
	case 2:
		//Tema
		std::cout << "Digite lo que busca: ";
		std::getline(std::cin, busqueda, '\n');
		lib = menu::buscar(list, busqueda, 5);
		busqueda = "Resultado/s por Tema \"" + busqueda + "\"\n";
		break;
	case 3:
		//Titulo
		std::cout << "Digite lo que busca: ";
		std::getline(std::cin, busqueda, '\n');
		lib = menu::buscar(list, busqueda, 1);
		busqueda = "Resultado de " + busqueda;
		break;
	case 4:
		//Autor
		std::cout << "Digite lo que busca: ";
		std::getline(std::cin, busqueda, '\n');
		lib = menu::buscar(list, busqueda, 2);
		busqueda = "Resultado de Autor: " + busqueda;
		break;
	case 5:
		std::cout << "Digite lo que busca: ";
		std::getline(std::cin, busqueda, '\n');
		lib = menu::buscar(list, busqueda, 3);
		busqueda = "Resultado de ISBN: " + busqueda;
		//ISBN

		break;
	default:
		std::cout << "Digito una opcion invalida, digite una valida: ";
		std::cout << "Digite que tipo de listado necesita: " << std::endl;
		std::cout << "(1) Por a"<< char(164) << "o de edicion " << std::endl;
		std::cout << "(2) Por Tema o Especialidad " << std::endl;
		std::cout << "(3) Buscar por Titulo" << std::endl;
		std::cout << "(4) Buscar por Autor" << std::endl;
		std::cout << "(5) Clave o ISBN (mas precisa)" << std::endl;
		std::cout << "-----> "; 
		std::cin >> i;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		imprimirListado(list, i);
	}
	if (lib.size() !=  0) {
		std::cout << busqueda;
		menu::imprimirTodos(lib);
	}
	else {
		std::cout << "Sin " << busqueda << std::endl;
	}

	system("Pause");
	system("cls");
}
void menu::imprimirTodos(List<libro> &list) // Imprime una lista de libros
{
	const List<libro> *lista = &list;
	Nodo<libro>* lib = list.getHead();
	while (lib != nullptr) {
		std::cout << std::endl << "-----------" << std::endl << std::endl;
		std::cout << lib->getDato()<<std::endl;
		std::cout << std::endl << "-----------" << std::endl;
		lib = lib->getNext();
	}
}
