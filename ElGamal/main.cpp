#include <iostream>
#include <ctime>
#include <map>
#include <math.h>
#include <chrono>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/time.h>
#include <stdint.h>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
typedef long long ll;
typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;
typedef std::chrono::duration<float> fsec;
typedef pair <ZZ,ZZ> pii;
//#include "funciones.h"
//#include "xorshift.h"
//#include "miller_rabin.h"
//#include "bbs.h"
int tam=64;
//#include "gordon.h"
//#include "pollar.h"
//#include "gamal.h"

string diccionario=" ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 ,.";

ZZ xorshift_x, xorshift_y, xorshift_z, xorshift_w;
ZZ n_bbs,xi_bbs;
ZZ MAX=conv<ZZ> (1000000000);




ZZ XorShift(ZZ MAX_XOR)
{
  ZZ tmp;
  tmp = xorshift_x^(xorshift_x<<11);
  xorshift_x = xorshift_y;
  xorshift_y = xorshift_z;
  xorshift_z = xorshift_w;
  xorshift_w = xorshift_w ^ (xorshift_w>>19)^(tmp^(tmp>>8));
  return xorshift_w % MAX_XOR;
}

ZZ k_q(ZZ q)
{
  ZZ k;
  q--;
  k=0;
  while((q&1)==0)
  {
    q=q>>1;
    k++;
  }
  return q;
}

ZZ MultMod(ZZ a,ZZ b,ZZ c)
{
  ZZ ans,e;
  if(b==0)
  {
    ans=0;
    return ans;
  }
  ans=0;
  while(b!=1)
  {
    e=b&1;
    if(e==1) ans=(ans+a) % c;
    a=(a+a) % c;
    b=b>>1;
  }
  return (ans+a) % c;
}

ZZ MultMod(ZZ a,ZZ b)
{
  ZZ ans,e;
  if(b==0)
  {
    ans=0;
    return ans;
  }
  ans=0;
  while(b!=1)
  {
    e=b&1;
    if(e==1) ans=(ans+a);
    a=(a+a);
    b=b>>1;
  }
  return (ans+a);
}

ZZ ExpMod(ZZ a,ZZ b)
{
  ZZ ans,e;
  if(a==0)
  {
    ans=0;
    return ans;
  }
  if(b==0)
    return to_ZZ("1");
  ans=1;
  while (b != 1)
  {
    e = b&1;
    if(e == 1) ans = ans*a;
    a = a*a;
    b = b>>1;
  }
  return MultMod(ans,a);
}

ZZ ExpMod(ZZ a,ZZ b,ZZ c)
{
  ZZ ans,e;
  if(a==0)
  {
    ans=0;
    return ans;
  }
  if(b==0)
  {
    ans=1;
    return ans;
  }
  ans=1;
  while(b != 1)
  {
    e=b & 1;
    if(e == 1) ans = MultMod(ans,a,c);
    a = MultMod(a,a,c);
    b = b>>1;
  }
  return MultMod(ans,a,c);
}

bool m_r(ZZ n,int max)
{
  ZZ e,a,temp,r;
  ZZ q=k_q(n);
  for(int i=0;i<max;i++)
  {
    a=XorShift(n-1)+1;
    temp = q;
    r=ExpMod(a,temp,n);
    while(temp != n-1 && r!=1 && r!=n-1)
    {
      r = MultMod(r,r,n);
      temp = temp << 1;
    }
    e=temp & 1;
    if(r!=n-1 && e== 0)
      return false;
  }
  return true;
}

ZZ GPrimeXor()
{
  ZZ P,e;
  P = XorShift(MAX);
  e = P & 1;
  if(e==0) P++;
  while(!m_r(P,5))
  {
    P+=2;
  }
  return P;
}


void SeedBBS()
{
  ZZ p,q,seed;
  p = GPrimeXor();
  q = GPrimeXor();
  n_bbs = p*q;
  seed = XorShift(MAX);
  xi_bbs = MultMod(seed,seed,n_bbs);
}




ZZ BlumBlumShub(int tam)
{
  ZZ res,e,aux;
  aux = 1;
  res = 0;
  for(int i=tam-1;i>=0;i--)
  {
    xi_bbs = ExpMod(xi_bbs,conv<ZZ>(2),n_bbs);
    e = xi_bbs & 1;
    if(e==1) res+=aux;
    aux=aux<<1;
  }
  return res;
}

ZZ BlumBlumShub(ZZ MAX_BBS)
{
  ZZ res,e,aux;
  aux=1;
  res=0;
  while(res<MAX_BBS)
  {
    xi_bbs=ExpMod(xi_bbs,conv<ZZ>(2),n_bbs);
    e=xi_bbs & 1;
    if(e==1) res+=aux;
    aux=aux<<1;
  }
  aux=aux>>1;
  res-=aux;
  return res;
}
ZZ GPrime(int tam)
{
  ZZ P = BlumBlumShub(tam);
  ZZ e = P & 1;
  if(e==0) P++;
  while(!m_r(P,5))
  {
    P+=2;
  }
  return P;
}





bool even(ZZ& x)
{
  ZZ e=x & 1;
  if(e==0)return true;
  return false;
}

ZZ gcd(ZZ u,ZZ v)
{
  if(u<0) u*=-1;
  ZZ a,b,t,aux;
  ZZ s;
  a = u;
  b = v;
  if(a<b)
  {
    aux = a;
    a = b;
    b = aux;
  }
  while(b!=0)
  {
    s = 1;
    while((b*s)<=a)
    {
      s=s<<1;
    }
    s=s>>1;
    t=min(a-b*s,b*(s<<1)-a);
    a=b;
    b=t;
    if(a<b)
    {
      aux=a;
      a=b;
      b=aux;
    }
  }
  return a;
}

pii ext(ZZ& x,ZZ& y)
{
  ZZ u,v,A,B,C,D;
  A=1,B=0,C=0,D=1;
  while((even(x)) && (even(y)))
  {
    x = x>>1;
    y = y>>1;
  }
  u=x;v=y;
  while(u!=0)
  {
    while(even(u))
    {
      u=u >> 1;
      if((even(A)) && (even(B)))
      {
        A=A >> 1;
        B=B >> 1;
      }
      else
      {
        A=(A+y) >> 1; B=(B-x) >> 1;
      }
    }
    while(even(v))
    {
      v=v >> 1;
      if((even(C)) && (even(D)))
      {
        C=C >> 1;
        D=D >> 1;
      }
      else
      {
        C = (C+y) >> 1; D = (D-x) >> 1;
      }
    }
    if(u>=v)
    {
      u-=v;A-=C;B-=D;
    }
    else
    {
      v-=u;C-=A;D-=B;
    }
  }
  return make_pair(C,D);
}

ZZ inv(ZZ& n,ZZ& m)
{
  return ext(n,m).first % m;
}




string leer(string in)
{
  string st;
  ifstream LeerArc;
  LeerArc.open(in);
  char c;
  while(LeerArc.get(c))
  {
    st.push_back(c);
  }
  LeerArc.close();
  return st;
}

int ele(ZZ &a)
{
  stringstream stream;
  stream << a;
  string cadena = stream.str();
  return cadena.size();
}

void copiar(string out,string mns)
{
  ofstream CopArc(out,ios::out);
  CopArc << mns;
  CopArc.close();

}

string ToString(ZZ a)
{
  stringstream stream;
  stream.str();
  stream << a;
  string cadena=stream.str();
  return cadena;
}

string (ZZ a,int tam)
{
  stringstream stream;
  stream.str();
  stream << a;
  string cadena=stream.str();
  string ans(tam-cadena.size(),'0');
  return ans+cadena;
}




void SeedXorShift()
{
  srand(time(NULL));
  time_t timer = time(NULL);
  struct tm y2k;
  y2k.tm_hour = 0;
  y2k.tm_min = 0;
  y2k.tm_sec = 0;
  y2k.tm_year = 100;
  y2k.tm_mon = 0;
  y2k.tm_mday = 1;
  ZZ seconds = conv<ZZ> (difftime(timer,mktime(&y2k)));
  xorshift_x = seconds;
  xorshift_y = seconds ^ 123456789;
  xorshift_z = seconds << 31;
  xorshift_w = seconds >> 28321;
}


ZZ Gordon(int tam)
{
  ZZ p=GPrime(tam);
  ZZ q=GPrime(tam),e,a,b,p1,mod,P,ans;
  a = 4;
  p1 = p*a+1;
  while(!m_r(p1,5))
  {
    a+=2;
    p1=a*p+1;
  }
  mod=q*p1;
  P=ExpMod(q,p1-1,mod)-ExpMod(p1,q-1,mod);
  e=P&1;
  if(e==0) P+=mod;
  a=2;
  ans=P+a*mod;
  while(!m_r(ans,5))
  {
    a+=2;
    ans=P+a*mod;
  }
  return ans;
}

ZZ c_brent;

ZZ f(ZZ x)
{
  return x*x+c_brent;
}

ZZ pollar(ZZ n)
{
  ZZ x,y,d;
  c_brent=1;
  x=2;
  y=2;
  d=1;
  while(d==1)
  {
    x=f(x)%n;
    y=f(f(y))%n;
    d=gcd(x-y,n);
  }
  return d;
}

inline bool isPowerOf2(ZZ i)
{
  ZZ aux=(i-1)&i;
  return aux==0?1:0;
}

ZZ brent(ZZ n)
{
  ZZ x,y,d,r,q,k,ys,m;
  y=XorShift(n-2)+1;
  c_brent=XorShift(n-2)+1;
  m=XorShift(n-2)+1;
  d=1;
  r=1;
  q=1;
  while(d==1)
  {
    x=y;
    for(ZZ i = to_ZZ("0");i<r;i++)
    {
      y=f(y)%n;
    }
    k = 0;
    while(k<r && d==1)
    {
      ys = y;
      for(ZZ i = to_ZZ("0");i<min(m,r-k);i++)
      {
        y=f(y)%n;
        q=(q*(abs(x-y)))%n;
      }
      d=gcd(q,n);
      k+=m;
    }
    r=r*2;
  }
  if(d==n)
  {
    while(d<2)
    {
      ys=f(ys)%n;
      d=gcd(x-ys,n);
    }
  }
  return d;
}

void factorization_pollar(ZZ N,map<ZZ,int>&M)
{
  if(N==1)
    return;
  if(m_r(N,5))
  {
    M[N]++;
    return;
  }
  ZZ factor=pollar(N);
  factorization_pollar(factor,M);
  factorization_pollar(N/factor,M);
  return;
}

void factorization_brent(ZZ N,map<ZZ,ZZ>&M)
{
  if(N==1)
    return;
  if(m_r(N,5))
  {
    M[N]++;
    return;
  }
  ZZ factor=brent(N);
  factorization_brent(factor,M);
  factorization_brent(N/factor,M);
  return;
}

ZZ phiEuler(ZZ N)
{
  ZZ ans;
  ans = 1;
  map<ZZ,ZZ> M;
  while((N&1)==0)
  {
    M[to_ZZ("2")]++;
    N>>=1;
  }
  factorization_brent(N,M);
  for(auto it = M.begin();it!=M.end();it++)
  {
    ZZ aux=ExpMod(it->first,it->second)-ExpMod(it->first,it->second-1);
    ans*=aux;
  }
  return ans;
}

bool esRP(ZZ g,ZZ n)
{
  ZZ m=phiEuler(n);
  map<ZZ,ZZ>M;
  factorization_brent(m,M);
  for(auto it=M.begin();it!=M.end();it++)
  {
    ZZ mi = m/it->first;
    if(ExpMod(g,mi,n)==1)
    {
      return false;
    }
  }
  return true;
}

ZZ RaizPrimitiva(ZZ p)
{
  ZZ rand = BlumBlumShub(p-1)+1;
  ZZ phi = phiEuler(p);
  while(!esRP(rand,p))
  {
    rand=BlumBlumShub(p-1)+1;
  }
  return rand;
}

class Gamal
{
  private:
    ZZ d;
  public:
    string diccionario;
    ZZ p;
    ZZ e1,e2;
    ZZ c1,km,c2;
    ZZ r;
    Gamal(string diccionario)
    {
      this->diccionario=diccionario;
      p=GPrime(tam/2);
      e1=RaizPrimitiva(p);
      d=BlumBlumShub(p-1)+1;
      e2=ExpMod(e1,d,p);
    }

    Gamal(string diccionario,ZZ e1,ZZ e2,ZZ p,ZZ d)
    {
      this->diccionario=diccionario;
      this->e1=e1;
      this->e2=e2;
      this->p=p;
      this->d=d;
    }

    void darDatos()
    {
      ifstream darDatos("Recuperacion",ios::in);
      darDatos >> e1;
      darDatos >> e2;
      darDatos >> p;
      darDatos >> d;
    }

    string encriptar(string mns,ZZ E1,ZZ E2,ZZ P)
    {
      r  = BlumBlumShub(P-2)+1;
      c1 = ExpMod(E1,r,P);
      km = ExpMod(E2,r,P);
      string encriptar;
      for(int i=0;i<mns.size();i++)
      {
        encriptar+=(to_ZZ(diccionario.find(mns[i])),2);
      }
      int tam = ele(P)-1;
      while(encriptar.size()%tam)
      {
        encriptar.push_back('0');
      }
      string C2;
      for(int i=0;i<encriptar.size();i+=tam)
      {
        string aux(encriptar,i,tam);
        ZZ pos(INIT_VAL,aux.c_str());
        pos = (pos*km)%P;
        C2+=((pos,tam+1));
      }
      return (c1,tam+1)+C2;
    }

    string desencriptar(string mns)
    {
      string C1(mns,0,ele(p));
      c1 = to_ZZ(C1.c_str());
      km = ExpMod(c1,d,p);
      km = inv(km,p);
      string aux;
      for(int i=ele(p);i<mns.size();i+=ele(p))
      {
        string pos(mns,i,ele(p));
        ZZ c(INIT_VAL,pos.c_str());
        aux+=((c*km)%p,ele(p)-1);
      }
      string ans;
      for(int i=0;i<aux.size();i+=2)
      {
        string pos(aux,i,2);
        ans.push_back(diccionario[stoi(pos)]);
      }
      return ans;
    }
};


int main(){
  SeedXorShift();
  SeedBBS();

  Gamal A(diccionario);
  ZZ e_1,e_2,p_a;
  e_1 = A.e1;
  e_2 = A.e2;
  p_a = A.p;

  cout <<"e1: "<< e_1 << endl;
  cout <<"e2: "<< e_2 << endl;
  cout <<"p: "<< p_a << endl;


  string mensaje;
  cout<<"Mensaje: ";
  getline(cin,mensaje);

  string encriptar=A.encriptar(mensaje,e_1,e_2,p_a);
  cout <<"Mensaje encriptado: "<< encriptar << endl;
	string des =  A.desencriptar(encriptar) ;
  cout <<"Mensaje desencriptado: "<<des<< endl;
  return 0;
}
