#include <bits/stdc++.h>
#include <boost/thread.hpp>
#include <chrono> 
using namespace std;
using namespace std::chrono;
using boost::thread;

int checkprime(int a)
{
  int i;
  for(i=2;(i*i)<=a;++i)
  {
    if((a%i)==0)
    return 0;
  }
  return 1;
}
void sol(int *x,int a,int b)
{
  for(;a<=b;++a)
  {
    x[a]=checkprime(a);
  }
}
int main()
{
  int n,nn,l=99999;
  int x[200000];
  cout<<"Enter number of threads : ";
  cin>>nn;
  auto start = high_resolution_clock::now();
  sol(x, 2,99999);  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"Without Multithreading i.e with Single thread "<<duration.count()<<"\n";
  start = high_resolution_clock::now();
  n=nn;
  boost::thread *t1[n];
  int a=1;
  int e=l/n;
  int b=e;
  for(int i=0;i<n;++i)
  {
    t1[i]=new boost::thread(sol, x, a+1, b);
    a=b;
    b+=e;
  }
  for(int i=0;i<n;++i)
  t1[i]->join();
  for(int i=0;i<n;++i)
  delete t1[i]; 
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"With Multithreading with main not used "<<duration.count()<<"\n";

  start = high_resolution_clock::now();
  n=nn-1;
  boost::thread *t2[n];
  a=1;
  e=l/(n+1);
  b=e;
  sol(x,a+1,b);
  a=b;
  b+=e;
  for(int i=0;i<n;++i)
  {
    t2[i]=new boost::thread(sol, x, a+1, b);
    a=b;
    b+=e;
  }
  for(int i=0;i<n;++i)
  t2[i]->join();
  for(int i=0;i<n;++i)
  delete t2[i];
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"With Multithreading, With main used above threads declaration "<<duration.count()<<"\n";

  start = high_resolution_clock::now();
  n=nn-1;
  boost::thread *t3[n];
  a=1;
  e=l/(n+1);
  b=e;
  for(int i=0;i<n;++i)
  {
    t3[i]=new boost::thread(sol, x, a+1, b);
    a=b;
    b+=e;
  }
  for(int i=0;i<n;++i)
  t3[i]->join();
  sol(x,a+1,b);
  for(int i=0;i<n;++i)
  delete t3[i];
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"With Multithreading, With main thread used below threads declaration and after doing join "<<duration.count()<<"\n";

  start = high_resolution_clock::now();
  n=nn-1;
  boost::thread *t4[n];
  a=1;
  e=l/(n+1);
  b=e;
  for(int i=0;i<n;++i)
  {
    t4[i]=new boost::thread(sol, x, a+1, b);
    a=b;
    b+=e;
  }
  sol(x,a+1,b);
  for(int i=0;i<n;++i)
  t4[i]->join();
  for(int i=0;i<n;++i)
  delete t4[i];
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"With Multithreading, With main thread used below threads declaration and before doing join "<<duration.count()<<"\n";
 
  return 0;
}
