#include<iostream>
#include<cstdio>
using namespace std;

int n,k,a[30],m=0;
int b[4]={0};

bool check() {return b[0] && b[1] && b[2] && b[3]; }

void print()
{
    for (int i=1;i<=n;i++) cout<<a[i];
}

bool make(int p)
{
    if (p==n+1)
    {
        m+=check();
        if (m==k) {print();return 1;}
        return 0;
    }
    for (int i=0;i<4;i++)
    {
        a[p]=i;
        if ((b[1] && i==0) || (b[3] && i==2)) continue;
        else {
            b[i]+=1;
            if(make(p+1)) return 1;
            b[i]-=1;
        }
    }
}

int main()
{
    cin>>n>>k;
    a[1]=2;
    b[2]=1;
    make(2);
    return 0;
}
