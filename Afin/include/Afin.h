#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

class Afin
{
    public:
        Afin();
        Afin(int, int);
        int modulo(int, int);
        int gcd(int, int);
        int euclides_ext(int, int);
        int claveA();
        int claveB();
        int inversa(int);
        string encriptar(string);
        string desencriptar(string);


    private:

    string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-"; //64
    int tam = alfabeto.size();
    int A;
    int B;

};

