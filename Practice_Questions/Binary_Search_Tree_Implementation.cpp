#include<bits/stdc++.h>
#define lli long long int
#define n 12
using namespace std;
struct node
{
    struct node *l,*r;
    int value;
};
struct node * root=NULL;
void insert(int k)
{
    struct node *temp =(struct node *)malloc(sizeof(struct node));
    temp->l=temp->r=NULL;
    temp->value=k;
    if(root==NULL)
    {
        root=temp;
        return;
    }
    struct node *t=root;
    while(1)
    {
        if(k<t->value)
        {
            if(t->l==NULL)
            {
                t->l=temp;
                break;
            }
            else
                t=t->l;
        }
        else
        {
            if(t->r==NULL)
            {
                t->r=temp;
                break;
            }
            else
                t=t->r;
        }
    }
}

void inorder(struct node *k)
{
    if(k==NULL)
        return;
    inorder(k->l);
    cout<<k->value<<" ";
    inorder(k->r);
}

void preorder(struct node *k)
{
    if(k==NULL)
        return;
    cout<<k->value<<" ";
    preorder(k->l);
    preorder(k->r);
}

void postorder(struct node *k)
{
    if(k==NULL)
        return;
    postorder(k->l);
    postorder(k->r);
    cout<<k->value<<" ";
}

struct node *q[n*2];
int f,r,c;

void en(struct node *a)
{
    q[r]=a;
    r++;
    c++;
}
struct node * de()
{
    assert(c>0);
    struct node *a=q[f];
    f++;
    c--;
    return a;
}
void levelorder(struct node *k)
{
    if(k==NULL)
        return;
    en(k);
    struct node *a;
    while(c>0)
    {
        a=de();
        cout<<a->value<<" ";
        if(a->l!=NULL)
            en(a->l);
        if(a->r!=NULL)
            en(a->r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    int x[n]={7,3,4,5,2,1,8,9,6,15,10,18};
    for(i=0;i<n;i++)
        insert(x[i]);
    cout<<"In Order Traversal : \n";
    inorder(root);
    cout<<endl;
    cout<<"Pre Order Traversal : \n";
    preorder(root);
    cout<<endl;
    cout<<"Post Order Traversal : \n";
    postorder(root);
    cout<<endl;
    f=r=c=0;
    cout<<"Level Order Traversal : \n";
    levelorder(root);
    cout<<endl;
    return 0;
}
