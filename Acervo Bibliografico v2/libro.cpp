#include "libro.h"
#include <algorithm>
bool libro::isEmpty() //Verifica si el libro esta vacio
{
	if (this->Anio_de_Edición.compare("") == 0 or this->Autor.compare("") == 0 or this->Clave_o_ISBN.compare("") == 0 or this->Tema.compare("") == 0 or this->Titulo.compare("") == 0)
		return true;
	else
		return false;
}

libro libro::crearLibro() //Crea un libro
{
	libro book;
	std::string aux;
	std::cout << "Digite el nombre del libro: ";
	std::getline(std::cin, aux, '\n');
	book.setTitulo(aux);
	std::cout << "Digite el ISBN del libro: ";
	std::getline(std::cin, aux, '\n');
	book.setClave_o_ISBN(aux);
	std::cout << "Digite el anio del libro: ";
	std::getline(std::cin, aux, '\n');
	book.setAnio_de_Edicion(aux);
	std::cout << "Digite el tema del libro: ";
	std::getline(std::cin, aux, '\n');
	book.setTema(aux);
	std::cout << "Digite el nombre del autor del libro: ";
	std::getline(std::cin, aux, '\n');
	book.setAutor(aux);
	return book;
}

libro::libro() {

}
void libro::setTitulo(const std::string& titulo)
{
	this->Titulo = titulo;
}

std::string libro::getTitulo()
{
	return this->Titulo;
}

void libro::setAutor(const std::string& autor) 
{
	this->Autor = autor;
}

std::string libro::getAutor()
{
	return this->Autor;
}

void libro::setTema(const std::string& tema)
{
	this->Tema = tema;
}

std::string libro::getTema()
{
	return this->Tema;
}

void libro::setAnio_de_Edicion(const std::string& anio)
{
	this->Anio_de_Edición = anio;
}

std::string libro::getAnio_de_Edicion()
{
	return this->Anio_de_Edición;
}

void libro::setClave_o_ISBN(const std::string& clave)
{
	this->Clave_o_ISBN = clave;
}

std::string libro::getClave_o_ISBN()
{
	return this->Clave_o_ISBN;
}

std::string libro::createFilePath() //Crea una ruta
{
	std::string retorno;
	retorno = this->Clave_o_ISBN + "_" + this->Titulo + "_" + this->Autor + "_" + this->Anio_de_Edición + ".txt";
	std::for_each(retorno.begin(), retorno.end(), [](char &c) {
		if (c == ':' or c == '/' or c == '\\' or c == '?' or c == '¿' or c == 'ñ' or c == '*' or c == '<' or c == '>' or c == '|' or c == '\"') {
			c = '_';
		}
	});
	return retorno;
}

libro libro::crearLibroConArchivo(const std::string &path)
{
	std::fstream arch;
	libro lib;
	arch.open(path.c_str(), std::ios::in);
	if (!arch.fail()) {
		std::list<std::string> list;
		std::string aux;
		while (!arch.eof()) {
			std::getline(arch, aux);
			list.push_back(aux);
		}
		if (list.size()== 5) {
			int count = 0;
			for (std::string it : list) {
				switch (count) {
				case 0:
					lib.setClave_o_ISBN(it);
					break;
				case 1:
					lib.setTitulo(it);
					break;
				case 2:
					lib.setAutor(it);
					break;
				case 3:
					lib.setAnio_de_Edicion(it);
					break;
				case 4:
					lib.setTema(it);
					break;
				}
				count++;
			}	
		}
		list.clear();
		arch.close();
	}
		else
			std::cout << "No se pudo abrir el archivo" << std::endl;
	
	return lib;
}

void libro::crearArchivoConLibro(libro &lib) {
	std::cout << lib.createFilePath().c_str();
	std::ofstream arch = std::ofstream(lib.createFilePath().c_str());
	if (!arch.fail()) {
		arch << lib.getClave_o_ISBN() << std::endl << lib.getTitulo() << std::endl << lib.getAutor() << std::endl << lib.getAnio_de_Edicion() << std::endl << lib.getTema();
		if (arch.fail()) {
			std::cout << "Fallo en escritura" << std::endl;
		}
		arch.close();
	}
	else {
		std::cout << "Fallo en escritura" << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream &out, const libro& book)
{
	out << "ISBN: " << book.Clave_o_ISBN << "\nTitulo: " << book.Titulo << "\nAutor: " << book.Autor << " \nA"<< char(164) << "o de Edicion: " << book.Anio_de_Edición << " \nTema: " << book.Tema;
	return out;
	// TODO: Insertar una instrucción "return" aquí
}

bool operator==(const libro& book1, const libro& book2)
{
	bool var = false;
	if (book1.Clave_o_ISBN.compare(book2.Clave_o_ISBN.c_str()) == 0) {
		std::cout << "Son los mismos libros" << std::endl;
		return true;
	}
	else {
		return false;
	}
	// TODO: Insertar una instrucción "return" aquí
}

bool operator<(const libro& book1, const libro& book2)
{
	return (book1.Clave_o_ISBN < book2.Clave_o_ISBN)? true : false;
	
}

bool operator>(const libro& book1, const libro& book2)
{
	return (book1.Clave_o_ISBN > book2.Clave_o_ISBN)? true : false;
}
