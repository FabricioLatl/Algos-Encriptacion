#include <iostream>
#include <cmath>

using namespace std;


int modulo(int a, int b){
    int aux = a + ((abs(a/b)+1)*b);
    return aux - ((aux/b)*b);
}

int EuclidianOld(int m,int n){
    if(m == 0)
        return n;
    while(n != 0){
        if(n > m){
            if(m == 0){
                return n;
            }
            else
                n -= m;
        }
        else
            m -= n;
    }
    return m;
}

int EuclidianIterative(int m, int n){
    while(n != 0){
        int t = n;
        n = modulo(m, n);
        m = t;

    }
    return m;
}

int EuclidianRecursive(int m, int n){
    if(n == 0)
        return m;
    else
        return EuclidianRecursive(n, modulo(m,n));
}

int BinaryGCD(int m, int n)
{
    if(m==0 || n==0)
        return 0;
    int s=0;
    while(!(modulo(m, 2)) && !(modulo(n, 2)))
    {
        m /= 2;
        n /= 2;
        s++;
    }
    while(!(modulo(n, 2)))
    {
        n /= 2;
    }
    while(m!=0)
    {
        while(!(modulo(m, 2))){
            m /= 2;
        }
        if(m<n)
            swap(m,n);
        m -= n;
        m /= 2;
    }
    return (pow(2,s)*n);
}
int main()
{
    cout << EuclidianOld(231, 1575) << endl;
    cout << EuclidianIterative(231, 1575) << endl;
    cout << EuclidianRecursive(231, 1575) << endl;
    cout << BinaryGCD(231, 1575) << endl;
    cout << EuclidianOld(35, 14) << endl;
    cout << EuclidianIterative(35, 14) << endl;
    cout << EuclidianRecursive(35, 14) << endl;
    cout << BinaryGCD(35, 14) << endl;

}
