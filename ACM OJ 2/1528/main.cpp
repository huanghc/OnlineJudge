#include<iostream>
using namespace std;

int n,p,tmp=1;
int head[102000]={0};
long long ans;
struct edge{
    int l,to,next;
}a[205000];
bool visit[102000]={0};

bool DFS(int x)
{
    if (x==p) return true;
    while (1) {
        int e=head[x],q;
        long long min=9999999999;
        while (e!=0)
        {
            if (!visit[a[e].to])
                if (a[e].l<min || (a[e].l==min && a[e].to<q))
                {
                    min=a[e].l;
                    q=a[e].to;
                }
            e=a[e].next;
        }
        if (min==9999999999) return 0;
        visit[q]=1;
        ans+=min;
        if (DFS(q)) return true;
        else ans+=min;
    }
}

int main()
{
    int i,s,t,l;
    cin>>n>>p;
    for (i=1;i<n;i++)
    {
        cin>>s>>t>>l;
        a[tmp].to=t;
        a[tmp].next=head[s];
        a[tmp].l=l;
        head[s]=tmp++;
        a[tmp].to=s;
        a[tmp].next=head[t];
        a[tmp].l=l;
        head[t]=tmp++;
    }
    visit[0]=1;
    DFS(0);
    cout<<ans;
}
