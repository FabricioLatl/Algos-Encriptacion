#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
/*
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

string ToString(ZZ a,int tam)
{
  stringstream stream;
  stream.str();
  stream << a;
  string cadena=stream.str();
  string ans(tam-cadena.size(),'0');
  return ans+cadena;
}
*/
