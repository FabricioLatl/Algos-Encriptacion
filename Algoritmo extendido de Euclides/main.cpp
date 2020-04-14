#include <iostream>

using namespace std;

int* euclidesExtendido(long a, long b)
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
cout << r1 << " " << s1 << " " << t1 << endl;
int arr[] = {r1, s1, t1};
return arr;
}

int main()
{
    int *arr2 = euclidesExtendido(97, 20);
    cout << endl;
    cout << arr2[0] << " " << arr2[1] << " " << arr2[2];
    return 0;
}
