#include "Afin.h"

Afin::Afin()
{
    A = claveA();
    B = claveB();
}

/*
Afin::Afin(int a, int b)
{
    A = inversa(a);
    B = b;
}
*/

int Afin::modulo(int a, int b)
{
    int aux = a + ((abs(a/b)+1)*b);
    return aux - ((aux/b)*b);
}

int Afin::gcd(int m, int n)
{
    if(n == 0)
        return m;
    else
        return gcd(n, modulo(m,n));
}

int Afin::euclides_ext(int a, int b)
{
    int r1 = a;
    int r2 = b;
    int s1 = 1;
    int t1 = 0;
    int s2 = 0;
    int t2 = 1;

    while(r2>0)
    {
        int q = (r1/r2);
        int r = r1 - q*r2;
        r1=r2;
        r2=r;
        int s = s1 - q*s2;
        s1= s2;
        s2=s;
        int t = t1-q*t2;
        t1=t2;
        t2=t;
    }
return s1;
}

string Afin::encriptar(string mensaje)
{
    for (unsigned int i = 0; i < mensaje.size(); i++){
        int idx = alfabeto.find(mensaje[i]);
        idx = A*idx + B%tam;

        if(idx >= tam){
            idx = modulo(idx, tam);
        }
        mensaje[i] = alfabeto[idx];
    }
    return mensaje;
}

string Afin::desencriptar(string mensaje)
{
    int A2 = inversa(A);
    for (unsigned int i = 0; i < mensaje.size(); i++){
        int idx = alfabeto.find(mensaje[i]);
        idx = A2*(idx - B);

        if(idx > tam || idx < 0){
            idx = modulo(idx, tam);
        }
        mensaje[i] = alfabeto[idx];
    }
    return mensaje;
}

int Afin::claveA()

{
    int var =1+rand()%tam;
    int A = gcd(var, tam);
    if(A == 1)
        return var;
    else return claveA();

}

int Afin::claveB()
{
    int B = rand()%tam;
    return B;
}

int Afin::inversa(int A)
{
    A = euclides_ext(A, tam);
}
