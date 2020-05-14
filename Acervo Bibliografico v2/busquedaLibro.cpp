#include "busquedaLibro.h"
#include "BusquedaPorTitulo.h"
void busquedaLibro::insertar(libro h, string par)
{
	listaIdString aux(par);
	if (this->entrada.size() > 0) {
		Nodo<listaIdString>* aux2 = this->entrada.buscar(aux); //Busca el nodo en el arbol si existe, en ese caso retorna la referencia
		if (aux2 != nullptr) //En que la busqueda no retorne nulo, entonces inserta el libro en ese nodo
			aux2->getDato()->insertarLibro(h, par);
		else {
			aux.insertarLibro(h, par);
			this->entrada.insertar(aux); //En caso de que no exista inserta un nuevo nodo
		}

	}
	else {
		aux.insertarLibro(h, par);
		this->entrada.insertar(aux); //En caso de que el arbol este vacio, inserta el nodo
	}
}

list<libro> busquedaLibro::getLibros(string par)
{
	list<libro> lista;
	listaIdString aux(par);
	Nodo<listaIdString>* aux2 = this->entrada.buscar(aux);
	if (aux2 != nullptr)
		lista = aux2->getDato()->getLista();
	return lista;
}
