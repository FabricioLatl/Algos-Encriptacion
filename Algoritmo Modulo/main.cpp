#include <iostream>
#include <cmath>

using namespace std;

int modulo(int a, int b){
    int aux = a + ((abs(a/b)+1)*b);
    return aux - ((aux/b)*b);
}

int main()
{
    cout << modulo(11, 2) << "\n";
    cout << modulo(255, 11) << "\n";
    cout << modulo(324, 17) << "\n";
    cout << modulo(32123, 321) << "\n";
    return 0;
}
