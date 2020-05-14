#include "BusquedaPorTitulo.h"
void BusquedaPorTitulo::insertar(libro h)
{
	listaIdString aux(h.getTitulo());
	if (this->entrada.size() > 0) {
		Nodo<listaIdString>*aux2 = this->entrada.buscar(aux); //Busca el nodo en el arbol si existe, en ese caso retorna la referencia
		if (aux2 != nullptr) //En que la busqueda no retorne nulo, entonces inserta el libro en ese nodo
			aux2->getDato()->insertarLibro(h, h.getTitulo());
		else {
			aux.insertarLibro(h, h.getTitulo());
			this->entrada.insertar(aux); //En caso de que no exista inserta un nuevo nodo
		}
			
	}
	else {
		aux.insertarLibro(h, h.getTitulo());
		this->entrada.insertar(aux); //En caso de que el arbol este vacio, inserta el nodo
	}
}

list<libro> BusquedaPorTitulo::getLibros(string titulo)
{
	list<libro> lista;
	listaIdString aux(titulo);
	Nodo<listaIdString> *aux2 = this->entrada.buscar(aux);
	if(aux2 != nullptr)
		 lista = aux2->getDato()->getLista();
	return lista;
}
