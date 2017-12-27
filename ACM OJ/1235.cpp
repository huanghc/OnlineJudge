#include <iostream>

using namespace std;

struct edgetable
{
    int a,b;
    int value;
    int next;
}E[200001];

int head[200001]={0},dist[200001],prev[200001]={0};
int Q[200001],mark[200001]={0};
int front=0,tail=0;

void enQueue(int i)
{
    if(mark[i]==true){return;}
    mark[i]=true;
    Q[tail]=i;
    tail++;
}

void SPFA()
{
    int begin,end,i;
    while(front<tail)
    {
        begin=Q[front];
        front++;
        mark[begin]=0;
        for(i=head[begin];i!=0;i=E[i].next){
            end=E[i].b;
            if(dist[end]>dist[begin]+E[i].value){
                dist[end]=dist[begin]+E[i].value;
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
    int i,s,e,v;
    for(i=1;i<m+1;++i)
    {
        cin >> s >> e >> v;
        E[i].a=s;
        E[i].b=e;
        E[i].value=v;
        E[i].next=head[s];
        head[s]=i;
    }
    for(i=0;i<n+1;i++)
    {
        dist[i]=999999;
    }
    dist[start]=0;
    enQueue(start);
    SPFA();
    cout << dist[end] << endl;
    int tmp=end,path[200001];
    i=0;
    while(tmp!=0)
    {
        path[i]=tmp;
        i++;
        tmp=prev[tmp];
    }
    i--;
    for(;i>=0;i--)
    {
        cout << path[i] << " ";
    }
    return 0;
}
