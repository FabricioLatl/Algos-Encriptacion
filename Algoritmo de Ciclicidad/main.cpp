#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ mod(ZZ a, ZZ n)
{
    if(a >= 0)
        return (a - (a/n)* n);
    else
        return (a - ((a/n)-1)*n);
}

ZZ ExponenciacionModular(ZZ base, ZZ exp, ZZ m)
{
    ZZ result;
    result = 1;
    ZZ dos;
    dos=2;
    while (exp != 0) {
        if (mod(exp,dos)!= 0)
            result = mod((result * base) , m);
        exp = exp/ 2;
        base = mod((base * base) , m);
    }
    return result;
}

ZZ Generador(ZZ p,long bit,long ElementoEscogido){
    ZZ Dos=ZZ(2);

    ZZ q=(p-1)/2;

    ZZ g=power(Dos,bit-1);
    ZZ


    =power(Dos,bit)-1;

    long Contador=0;
    cout<<g<<endl;
    cout<<Maximo<<endl;

    while(g!=Maximo && Contador!=ElementoEscogido-1){
        if(ExponenciacionModular(g,ZZ(2),p)!=1 && (ExponenciacionModular(g,q,p)!=1)){
            Contador++;
           }
        g++;
        }
    return g;
}

int main()
{
    ZZ prime;
    prime = 45737;
    Generador(prime, 16, 3342);
    return 0;
}
