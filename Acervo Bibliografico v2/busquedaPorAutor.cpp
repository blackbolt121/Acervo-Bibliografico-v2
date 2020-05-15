#include "busquedaPorAutor.h"

void busquedaPorAutor::insertar(libro h, string par)
{
	busquedaLibro::insertar(h, h.getAutor());
}


