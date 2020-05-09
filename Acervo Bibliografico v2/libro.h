#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include "List.h"
class libro
{
public:
		static libro crearLibro();
		static void crearArchivoConLibro(libro& lib);
		static libro crearLibroConArchivo(const std::string& path);
		libro();
		bool isEmpty();
		std::string createFilePath();
		void setClave_o_ISBN(const std::string&);
		void setAnio_de_Edicion(const std::string&);
		void setTema(const std::string&);
		void setAutor(const std::string&);
		void setTitulo(const std::string&);
		std::string getTitulo();
		std::string getAutor();
		std::string getTema();
		std::string getAnio_de_Edicion();
		std::string getClave_o_ISBN();
		friend std::ostream& operator << (std::ostream &out, const libro& book);
		friend bool operator == (const libro& book1, const libro& book2);
private:
	std::string Titulo;
	std::string Autor;
	std::string Tema;
	std::string Anio_de_Edición;
	std::string Clave_o_ISBN;

};


