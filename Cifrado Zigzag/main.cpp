#include <iostream>
#include <string>
#include <Zigzag.h>

using namespace std;

vector <string> arr;

void mostrar(vector<string> arr){
    for(int i=0; i<arr.size(); i++)
        cout <<arr[i]<<endl;
     cout <<endl<<endl<<endl;
}


string desencrip(string enMsg, int key){
    int k = -1, fila = 0, col = 0, m = 0;
    string rpt;

    for(int i = 0; i < key; ++i)
        for(int j = 0; j < enMsg.size(); ++j)
            arr[i][j] = '\n';

    for(int i = 0; i < enMsg.size(); ++i){
        arr[fila][col++] = '*';

        if(fila == 0 || fila == key-1)
            k= k * (-1);

        fila = fila + k;
    }

    for(int i = 0; i < key; ++i)
        for(int j = 0; j < enMsg.size(); ++j)
            if(arr[i][j] == '*')
                arr[i][j] = enMsg[m++];


    fila = col = 0;
    k = -1;

    for(int i = 0; i < enMsg.size(); ++i){
        rpt += arr[fila][col++];
        if(fila == 0 || fila == key-1)
            k= k * (-1);

        fila = fila + k;
    }
    return rpt;
}


string encrip(string msg,int key){
    string rpt;
    int  k = -1, fila = 0, colum = 0;
    for(int i=0; i<key; i++){
        string a;
        for(int j=0; j<msg.size(); j++){
                a +="*";
        }
        arr.push_back(a);
       }

        for(int i=0; i<msg.size(); ++i){
            arr[fila][colum++] = msg[i];
            if(fila == 0 || fila == key-1)
                k= k * (-1);
            fila = fila + k;
         }

        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<msg.size(); j++){
                if(arr[i][j] != '*'){
                   rpt += arr[i][j];
                }
            }
        }

    mostrar(arr);
    return rpt;
}


int main(){

    int key = 3;
    string msg = "hola mundo";
    ///<functions>



    string encriptado = encrip(msg,key);
    cout <<encriptado<<endl;


    string desencri = desencrip(encriptado,key);
    cout <<desencri<<endl;

    return 0;
}
