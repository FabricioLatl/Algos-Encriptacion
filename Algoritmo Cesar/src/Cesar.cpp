#include "Cesar.h"

Cesar::Cesar(int clave)
{
    this->clave = clave;
}

int Cesar::modulo(int a, int b){

    int aux = a + ((abs(a/b)+1)*b);
    return aux - ((aux/b)*b);
}

string Cesar::encriptar(string mensaje)
{
    for (unsigned int i = 0; i < mensaje.size(); i++){
        int idx = alfabeto.find(mensaje[i]);
        idx += clave;

        if(idx >= tam){
            idx = modulo(idx, tam);
        }
        mensaje[i] = alfabeto[idx];
    }
    return mensaje;
}

string Cesar::desencriptar(string mensaje)
{
    for (unsigned int i = 0; i < mensaje.size(); i++){
        int idx = alfabeto.find(mensaje[i]);
        idx -= clave;

        if(idx > tam || idx < 0){
            idx = modulo(idx, tam);
        }
        mensaje[i] = alfabeto[idx];
    }
    return mensaje;
}
