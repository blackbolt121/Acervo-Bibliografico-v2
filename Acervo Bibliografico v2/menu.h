#pragma once
#include <iostream>
#include "libro.h"
namespace menu {
	void iniciar(List<libro>& list, const std::string& ruta);
	void menu(List<libro>& list, const std::string& ruta);
	List <libro> buscar(List<libro>& list, const std::string& parametro, const int& tipo);
	void insertarLibro(List<libro> &list, const std::string& ruta);
	void imprimirListado(List<libro>& list, int& i);
	void imprimirTodos(List<libro>& list);
}

