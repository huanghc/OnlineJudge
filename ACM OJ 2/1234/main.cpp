#include <iostream>

using namespace std;

int joint[100001]={0},map[100001][3];

void swap(int &x,int &y)
{
    int tmp=x;
    x=y;
    y=tmp;
}

void qsort(int low,int high)
{
    int l=low,h=high,mid=map[(low+high)/2][2];
    if(l>=h) {return;}
    while(l<=h)
    {
        while(map[h][2]>mid){h--;}
        while(map[l][2]<mid){l++;}
        if(l<=h){
            swap(map[l][0],map[h][0]);
            swap(map[l][1],map[h][1]);
            swap(map[l][2],map[h][2]);
            l++;
            h--;
        }
    }
    qsort(low,h);
    qsort(l,high);
}

int find(int x)
{
    if(joint[x]==0){return x;}
    else return joint[x]=find(joint[x]);
}

void uni(int x,int y)
{
    if(x==y){return;}
    int a=x,b=y;
    if(a<b){joint[b]=a;}
    if(a>b){joint[a]=b;}
}

int main()
{
    int n,m,j,u,v;
    int result=0,edge=0;
    cin >> n >> m;
    int begin,end,weight;
    for(j=1;j<m+1;j++)
    {
        cin >> begin >> end >> weight;
        map[j][0]=begin;
        map[j][1]=end;
        map[j][2]=weight;
    }
    qsort(1,m);
    int i=1;
    while (edge<n-1)
    {
        u = find(map[i][0]);
        v = find(map[i][1]);
        if (u == v) {++i;}
        else{
            uni(u,v);
            result += map[i][2];
            ++i;
            ++edge;
        }
    }
    cout << result;
    return 0;
}
