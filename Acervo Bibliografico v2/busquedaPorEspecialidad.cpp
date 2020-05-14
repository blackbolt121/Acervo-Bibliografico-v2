#include "busquedaPorEspecialidad.h"

void busquedaPorEspecialidad::insertar(libro h, string par)
{
	par = h.getTema();
	busquedaLibro::insertar(h, par);
}
