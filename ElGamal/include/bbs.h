
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
/*
ZZ n_bbs,xi_bbs;
ZZ MAX=conv<ZZ> (1000000000);

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
}*/
