#include "Zigzag.h"


Zigzag::Zigzag()
{
    clave = 0;
}

Zigzag::Zigzag(int clave)
{
    this->clave = clave;
}

string Zigzag::cifrado(string mensaje)
{
    string m_cifrado;
	int pos=0;
	for(int i = 1; i <= clave; i++){
		int des1 =(clave-i)*2;
		int des2 = (i-1)*2;
		bool alternador = true;
		int ind = i-1;
		int temp = -1;
		while(ind < mensaje.size()){
			if(temp != ind)
                m_cifrado += mensaje[ind];

			temp = ind;
			if(alternador)
                ind += des1;
            else
                ind += des2;
			alternador = !alternador;
		}
	}
	return m_cifrado;

}

string Zigzag::descifrado(string mensaje)
{
    string m_descifrado;
    m_descifrado = string ("",mensaje.size());
	int pos=0;
	for(int i = 1; i <= clave; i++){
		int des1 =(clave-i)*2;
		int des2 = (i-1)*2;
		bool alternador = true;
		int ind = i-1;
		int temp = -1;
		while(ind < mensaje.size()){
			if(temp != ind){
                m_descifrado[ind] = mensaje[pos++];
			}
			temp = ind;
			if(alternador)
                ind += des1;
            else
                ind += des2;

			alternador = !alternador;
		}
	}
	return m_descifrado;
}

