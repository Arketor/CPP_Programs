#include<bits/stdc++.h>
using namespace std;
int n;

void swap(char *a,char *b)
{
    char temp=*a;
    *a=(*b);
    *b=temp;
}

void per(char *x, int level)
{
    if(level==(n-1))
    {
        cout<<x<<endl;
        return;
    }
    for(int i=level;i<n;i++)
    {
        swap(x+i,x+level);
        per(x,level+1);
        swap(x+i,x+level);
    }
}
int main()
{
    char x[]="abc";
    n=3;
    per(x,0);

    return 0;
}
