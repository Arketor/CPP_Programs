#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int x[100004];
int tree[300004];
void build(int node, int s, int e)
{
    if(s==e)
    tree[node]=x[s];
    else
    {
        int m=(s+e)/2;
        build(2*node,s,m);
        build((2*node)+1,m+1,e);
        tree[node]=min(tree[2*node],tree[(2*node)+1]);
    }
}
void update(int node,int s,int e,int id, int val)
{
    if(s==e)
    {
        tree[node]=x[s]=val;
    }
    else
    {
        int m=(s+e)/2;
        if(id<=m)
        {
            update(2*node,s,m,id,val);
        }
        else
        {
            update((2*node)+1,m+1,e,id,val);
        }
        tree[node]=min(tree[2*node],tree[(2*node)+1]);
    }
}
int query(int node,int s,int e, int l, int r)
{
    if((l<=s)&&(r>=e))
    return tree[node];
    if((e<l)||(s>r))
    return 1000000007;
    int m=(s+e)/2;
    return min(query(2*node,s,m,l,r),query((2*node)+1,m+1,e,l,r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,q,l,r;
    char c;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    cin>>x[i];
    build(1,1,n);
    while(q--)
    {
        cin>>c>>l>>r;
        if(c=='q')
        {
            cout<<query(1,1,n,l,r)<<"\n";
        }
        else
        {
            update(1,1,n,l,r);
        }
    }
    return 0;
}
