// Acervo Bibliografico v2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Arbol.h"
#include "libro.h"
int main()
{
    Arbol<libro> s;
    libro aux = libro::crearLibroConArchivo("9682426561_EL CONDE DE MONTECRISTO_ALEJANDRO DUMAS_1990.txt");
    libro aux2 = libro::crearLibroConArchivo("1491957662_Python for Data Analysis_ Data Wrangling with Pandas, Numpy, and Ipython_Wes McKinney_2017.txt");
    cout << aux << endl;
    cout << aux2 << endl;
    if (aux > aux2) {
        cout << "Aux es de mayor jerarquia" << endl;
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
