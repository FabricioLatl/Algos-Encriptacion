#include <iostream>
#include <fstream>
#include <string>
#include <Zigzag.h>


using namespace std;




int main(){

    Zigzag emisor(4);
    Zigzag receptor(4);
    string mensaje = "hola mundo";
    cout << "mensaje original: " << mensaje << endl;
    string cifrado = receptor.cifrado(mensaje);
    cout << "cifrado: " << cifrado << endl;
    string descifrado = receptor.descifrado(cifrado);
    cout << "descifrado: " << descifrado << endl;




    return 0;
}
