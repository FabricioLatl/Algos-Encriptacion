#ifndef RSA_H
#define RSA_H

#include <NTL/ZZ.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <vector>

using namespace std;
using namespace NTL;


class RSA
{
    public:
        RSA();
        ZZ modulo(ZZ, ZZ);
        ZZ gcd(ZZ, ZZ);
        ZZ claveN();
        ZZ clave_publica();
        ZZ clave_privada();
        ZZ exponenciacion_modular(ZZ, ZZ, ZZ);
        ZZ inversa(ZZ, ZZ);
        vector<ZZ> encriptar(string);
        string desencriptar(vector<ZZ>);

        vector<ZZ> almacenar;
        ZZ N;
        ZZ PhiN;
        ZZ E;
        ZZ C;
        ZZ D;

    private:

    string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-"; //64
    int tam = alfabeto.size();
};

#endif // RSA_H
