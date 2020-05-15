#include "busquedaPorEspecialidad.h"

void busquedaPorEspecialidad::insertar(libro h, string par)
{
	busquedaLibro::insertar(h, h.getTema());
}
