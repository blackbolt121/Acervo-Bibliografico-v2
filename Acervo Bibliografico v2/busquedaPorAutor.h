#include <iostream>
#include "busquedaLibro.h"
using namespace std;
class busquedaPorAutor : public busquedaLibro {
public:
	void insertar(libro h, string par);
};