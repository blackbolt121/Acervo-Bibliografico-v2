#include "BusquedaPorTitulo.h"

void BusquedaPorTitulo::insertar(libro h, string par)
{
	busquedaLibro::insertar(h, h.getTitulo());

}
