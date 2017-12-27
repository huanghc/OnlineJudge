#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1010
#define inf 0x3f3f3f3f
using namespace std;
int map[N][N],f[N][N];

struct Data
{
    int H,h; // 最高距离、最近白点
    int l,r; // 左右有效距离
}s[N];

int ansa,ansb=inf;
int q[N];

int getans(int a,int b,int c,int d){
	return f[d][b]-f[d][a]-f[c][b]+f[c][a];
}

int getarea(int a,int b,int c,int d)
{
    int l=c,r=d,mid,ans;
    while(l<=r)
    {
        if(r-l<=3)
        {
            ans=l;
            for(int i=r;i>=l;i--)
                if(getans(a,b,c,i)==0)
                    {ans=i;break;}
            break;  
        }
        mid=l+r>>1;
        if(getans(a,b,c,mid)==0)l=mid;
        else r=mid-1;
    }
    return (b-a-1)*(d-ans-1);
}

int main()
{
    int i,j,k;
    int a,b,c;
    cin>>c;
    char ss[5];
    for (int i=0;i<c;++i)
    {
        scanf("%d%d%s",&a,&b,ss),a++,b++;
        if(ss[0]=='H') map[a][b]=1; 
        else map[a][b]=2; 
    }
    for(i=1;i<=1001;i++)
    {
        int temp=0;
        for(j=1;j<=1001;j++)
        {
            if(map[i][j]==1) temp++;
            f[i][j]=f[i-1][j]+temp;
        }
    }
    for(i=1;i<=1001;i++)s[i].h=inf;
    int l,r;
    for(i=1;i<=1001;i++)
    {
        for(j=1;j<=1001;j++)
        {
            if(map[i][j]==2)s[j].H=0,s[j].h=inf;
            else {
                s[j].H++;
                if(map[i][j]==1)s[j].h=1;
                else s[j].h++;
            }
            s[j].l=s[j].r=j;
        }
        l=1,r=0;
        for(j=1;j<=1001;j++)
        {
            while(l<=r&&s[q[r]].H>=s[j].H) s[j].l=s[q[r--]].l;
            while(s[j].l<j&&s[s[j].l].h>s[j].H) s[j].l++;
            q[++r]=j;
        }
        l=1,r=0;
        for(j=1001;j;j--)
        {
            while(l<=r&&s[q[r]].H>=s[j].H) s[j].r=s[q[r--]].r;
            while(s[j].r>j&&s[s[j].r].h>s[j].H) s[j].r--;
            q[++r]=j;
        }
        for(j=1;j<=1001;j++)
        {
            int ret=getans(s[j].l-1,s[j].r,i-s[j].H,i);
            if(ret>=ansa)
            {
                int temp=getarea(s[j].l-1,s[j].r,i-s[j].H,i);
                if(ret==ansa) ansb=min(ansb,temp);
                else ansa=ret,ansb=temp;
            }
        }
    }
    cout<<ansa<<" "<<ansb;
    return 0;
}
