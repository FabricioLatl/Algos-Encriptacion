#include "RSA.h"

RSA::RSA()
{
    N = claveN();
    //E = clave_publica();
}

ZZ RSA::modulo(ZZ a, ZZ b)
{
    ZZ aux = a + ((abs(a/b)+1)*b);
    return aux - ((aux/b)*b);
}

ZZ RSA::gcd(ZZ m, ZZ n)
{
    if(m==0)
        return n;
    while(n!=0)
        {
        if (n>=m)
            n=n-m;
        else
            m=m-n;
        }
    return m;
}

ZZ RSA::exponenciacion_modular(ZZ base, ZZ exponent, ZZ mod)
{
ZZ result;
    result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent >>= 1;
        base = (base * base) % mod;
    }
    return result;
}



vector<ZZ> RSA::encriptar(string mensaje)
{
    for (unsigned int i = 0; i < mensaje.size(); i++){
        int idx = alfabeto.find(mensaje[i]);
        ZZ encriptado;
        encriptado = idx;
        encriptado = exponenciacion_modular(encriptado, E, N);
        almacenar[i] = encriptado;
    }
    return almacenar;
}


string RSA::desencriptar(vector<ZZ> mensaje)
{
    string mensa;
    for(int i = 0; i < almacenar.size(); i++){
        ZZ descifrado;
        descifrado = exponenciacion_modular(almacenar[i], D, N);
        int temp = 0;
        for(int j = 0; i <= descifrado; j++){
            temp++;
        }
        //int idx = alfabeto.find(mensa[temp]);
        mensa += alfabeto[temp];
    }
    return mensa;
}

ZZ RSA::clave_publica()
{
    SetSeed(ZZ::zero());
    ZZ var = conv<ZZ>(RandomBits_long(16));
    ZZ aux = gcd(var, PhiN);
    while(aux != 1)
    {
        var = conv<ZZ>(RandomBits_long(16));
        ZZ aux = gcd(var, PhiN);
    }
    E = var;

}

ZZ RSA::claveN()
{
    ZZ p1;
    ZZ p2;
    p1 = RandomPrime_ZZ(1, 100);
    p2 = RandomPrime_ZZ(1, 100);
    N = p1*p2;
    PhiN = (p1-1)*(p2-1);
}

ZZ RSA::clave_privada()
{
    D = inversa(E,this->PhiN);
}

ZZ RSA::inversa(ZZ num, ZZ mod)
{
    ZZ i;
    num = num%mod;
    for (i=1; i<mod; i++)
       if ((num*i) % mod == 1)
          return i;
}
