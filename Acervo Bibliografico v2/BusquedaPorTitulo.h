#pragma once
#include <iostream>
#include "busquedaLibro.h"
using namespace std;
class BusquedaPorTitulo : public busquedaLibro
{
public:
	void insertar(libro h, string par);
};

