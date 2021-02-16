#include<iostream>
using namespace std;
int fact(int n)
{
  if(n<0)
  return -1000000007;
  int ans=1;
  while(n>1)
  {
    ans=ans*n;
    n--;
  }
  return ans;
}

