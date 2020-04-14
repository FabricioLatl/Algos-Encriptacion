#ifndef ZIGZAG_H
#define ZIGZAG_H
#include "string"

using namespace std;


class Zigzag
{
    public:
        Zigzag();
        Zigzag(int clave);
        string cifrado(string);
        string descifrado(string);

    private:
        int clave;
};

#endif // ZIGZAG_H
