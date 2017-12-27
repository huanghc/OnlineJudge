#include <iostream>

using namespace std;

bool isRP(int a,int b)
{
    int t;
    if(a==b) return false;
    if(a==1) return true;
    while(1)
    {
        t=b%a;
        if(t==0) break;
        b=a;
        a=t;
    }
    if(a==1) return true;
    return false;
}

struct node{
    int n;
    int d;
    node *next,*prev;
    node():n(0),d(1),next(NULL),prev(NULL){}
    node(int a,int b,node *p=NULL,node *q=NULL):n(a),d(b),next(p),prev(q){}
};

int main()
{
    int max_deno,deno=2,nume;
    cin >> max_deno;
    cout << "0/1 " << endl;
    node *first,*cur,*tmp;
    first=new node;
    cur=first->next=new node;
    cur->prev=first;
    while(deno<=max_deno)
    {
        for(nume=1;nume<deno;++nume)
        {
            if(isRP(nume,deno)){
                cur=first->next;
                while(((cur->n)*deno<(cur->d)*nume)&&cur->n!=0){cur=cur->next;}
                tmp=new node(nume,deno,cur,cur->prev);
                cur->prev->next=tmp;
                cur->prev=tmp;
            }
        }
        deno++;
    }
    cur=first->next;
    while(cur->n!=0){cout << cur->n << "/" << cur->d << endl; cur=cur->next;}
    cout << "1/1";
    return 0;
}
