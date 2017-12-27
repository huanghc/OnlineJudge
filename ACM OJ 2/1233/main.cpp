#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next;
    node ():data(0),next(NULL){}
    node(int d, node* n=NULL):data(d),next(n){}
};

node **map;
int sum=0;
bool visited[100000]={false};

void DFS(int start,int p,int limit)
{
    if(p==limit){sum++;return;}
    visited[start]=true;
    node *t=map[start]->next;
    int x=p+1,y=limit;
    while(t!=NULL)
    {
        if(visited[t->data]==false){DFS(t->data,x,y);}
        t=t->next;
    }
    visited[start]=false;
}

int main()
{
    int n,m,head,length;
    cin >> n >> m >> head >> length;
    int p=0,begin,end;
    node *tmp,*tmp2;
    map=new node*[n+1];
    for(int i=0;i<n+1;i++)
    {
        map[i]=new node;
    }
    while(p<m)
    {
        cin >> begin >> end;
        tmp2=map[begin];
        while(tmp2->next!=NULL&&tmp2->next->data<=end){tmp2=tmp2->next;}
        if(tmp2->data!=end){tmp=new node(end,tmp2->next);tmp2->next=tmp;}
        p++;
    }
    DFS(1,0,length);
    cout << sum;
    return 0;
}
