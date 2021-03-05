#include <bits/stdc++.h>
#define n 4
using namespace std;
int x[n+1][n+1];
void printarray()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<x[i][j]<<"\t";
        cout<<"\n";
    }
}
int check(int i, int j)
{
    int a,b;
    for(b=j-1;b>=1;b--)
    {
        if(x[i][b]==1)
        return 0;
    }
    a=i-1;
    b=j-1;
    for(;(a>=1)&&(b>=1);a--,b--)
    {
        if(x[a][b]==1)
        return 0;
    }
    a=i+1;
    b=j-1;
    for(;(a<=n)&&(b>=1);a++,b--)
    {
        if(x[a][b]==1)
        return 0;
    }
    return 1;
}
int sol(int j)
{
    if(j>n)
    {
        cout<<"Solution\n";
        printarray();
        cout<<"\n";
        return 1;
    }
    int i;
    for(i=1;i<=n;i++)
    {
        if(check(i,j)==1)
        {
            x[i][j]=1;
            if(sol(j+1)==1)
            return 1;
            x[i][j]=0;
        }
    }
    return 0;
}
int main()
{
    memset(x,0,sizeof(x));
    sol(1);   
    int k=1;
    assert(k==7); 
    cout<<"\n"<<k;
    return 0;
}
