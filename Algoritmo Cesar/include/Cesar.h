#ifndef CESAR_H
#define CESAR_H
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Cesar
{
    public:
        Cesar(int);
        int modulo(int, int);
        string encriptar(string );
        string desencriptar(string );

    private:
    int clave;
    string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-"; //64
    int tam = alfabeto.size();



};

#endif // CESAR_H
