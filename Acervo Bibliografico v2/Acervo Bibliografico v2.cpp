// Acervo Bibliografico v2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "menu.h"
using namespace std;
int main()
{
    busquedaLibro a; busquedaPorAutor b; busquedaPorEspecialidad c; BusquedaPorTitulo d;
    system("exit");
    menu::run(a, b, c, d);
}

