#include "BusquedaPorTitulo.h"

void BusquedaPorTitulo::insertar(libro h, string par = "")
{
	string par = h.getTitulo();
	busquedaLibro::insertar(h, par);

}
