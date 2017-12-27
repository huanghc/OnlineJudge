#include <iostream>

using namespace std;

struct node
{
    int data;
    int value;
    node *next;
    node():data(0),value(0),next(NULL){}
    node(int d, int v,node* n=NULL):data(d),value(v),next(n){}
};

int dist[200001];
int Q[200001],mark[200001]={0},prev[200001]={0};
int front=0,tail=0;
node **map;

void enQueue(int i)
{
    if(mark[i]==true){return;}
    mark[i]=true;
    Q[tail]=i;
    tail++;
}

int deQueue()
{
    int tmp=Q[front];
    front++;
    mark[tmp]=0;
    return tmp;
}

void SPFA()
{
    int begin,end;
    node *tmp;
    while(front<tail)
    {
        begin=deQueue();
        for(tmp=map[begin];tmp!=NULL;tmp=tmp->next){
            end=tmp->data;
            if(dist[end]>dist[begin]+tmp->value){
                dist[end]=dist[begin]+tmp->value;
                enQueue(end);
                prev[end]=begin;
            }
        }
    }
}

int main()
{
    int n,m,start,end;
    cin >> n >> m >>start >> end;
    int p=0,i;
    node *tmp;
    map=new node*[n+1];
    for(int j=0;j<n+1;j++)
    {
        map[j]=NULL;
    }
    int from,to,value;
    while(p<m)
    {
        cin >> from >> to >> value;
        tmp=new node(to,value,map[from]);
        map[from]=tmp;
        p++;
    }
    for(i=0;i<n+1;i++)
    {
        dist[i]=999999;
    }
    dist[start]=0;
    enQueue(start);
    SPFA();
    cout << dist[end] << endl;
    int x=end,path[200001];
    i=0;
    while(x!=0)
    {
        path[i]=x;
        i++;
        x=prev[x];
    }
    i--;
    for(;i>=0;i--)
    {
        cout << path[i] << " ";
    }
    return 0;
}
