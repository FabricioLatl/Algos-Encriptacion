#ifndef ZIGZAG_H
#define ZIGZAG_H
#include <string>

using namespace std;

class Zigzag
{
    public:
        Zigzag(int);
        string encrip(string msg);
        string desencrip(string enMsg);
        mostrar(string arr);

    private:
        int key;


};

#endif // ZIGZAG_H
