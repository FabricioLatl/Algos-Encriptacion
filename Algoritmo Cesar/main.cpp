#include <iostream>
#include <Cesar.h>
#include <string>
#include <cmath>
#include <vector>
using namespace std;





int main()
{
    string mensaje = "Sebastian Pumacayo Campos 181-10-42378 estudio ciencias de la computacion y soy de Arequipa";

    Cesar emisor(9);
    Cesar receptor(9);

    cout << mensaje << endl;

    string mc = emisor.encriptar(mensaje);
    cout << mc << endl;

    string md = receptor.desencriptar(mc);
    cout << md << endl;



    return 0;
}
