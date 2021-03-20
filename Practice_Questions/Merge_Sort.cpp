#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int n,x[1000004],y[1000004];
void merge(int s1,int e1,int s2,int e2)
{
	int a,b,i;
	a=i=s1;
	b=s2;
	while(1)
	{
		if(x[a]<=x[b])
		{
			y[i]=x[a];
			a++;
			i++;
		}
		else
		{
			y[i]=x[b];
			b++;
			i++;
		}
		if(a>e1)
		{
			for(;b<=e2;b++)
			{
				y[i]=x[b];
				i++;
			}
			break;
		}
		if(b>e2)
		{
			for(;a<=e1;a++)
			{
				y[i]=x[a];
				i++;
			}
		}
	}
}
void mergesort(int s,int e)
{
	if(s==e)
	return;
	int m=(s+e)/2;
	mergesort(s,m);
	mergesort(m+1,e);
	merge(s,m,m+1,e);
	for(int i=s;i<=e;i++)
	x[i]=y[i];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>x[i];
	mergesort(1,n);
	for(i=1;i<=n;i++)
	cout<<x[i]<<" ";
	return 0;
}
