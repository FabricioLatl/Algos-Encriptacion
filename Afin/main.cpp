#include <iostream>
#include <Afin.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;


int main()
{
    srand(time(NULL));

    string mensaje = "Sebastian Pumacayo Campos 181-10-42378 estudio ciencias de la computacion y soy de Arequipa";

    Afin mensajero;






    string mc = mensajero.encriptar(mensaje);
    cout << mc << endl;

    string md = mensajero.desencriptar(mc);
    cout << md << endl;










}
