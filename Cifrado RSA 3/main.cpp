#include <iostream>
#include <cstdlib>
#include <NTL/ZZ.h>
#include <RSA.h>
#include "string"

using namespace std;
using namespace NTL;

int main()
{

    string mensaje = "hola mundo";
    cout << mensaje << endl;


    RSA emisor;
    vector<ZZ> codigo;
    string descifrado;
    //codigo = emisor.encriptar(mensaje);
    int len = codigo.size();
    for(int i = 0; i < len; i++)
        cout << codigo[i] << ",";
    //cout << emisor.desencriptar(codigo);




    return 0;
}
