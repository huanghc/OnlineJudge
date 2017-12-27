#include <iostream>

using namespace std;

int result[1000000][2];

void swap(int &x,int &y)
{
    int tmp=x;
    x=y;
    y=tmp;
}

void qsort(int start,int end)
{
    if(start>=end){return;}
    int s=start,e=end,mid=(start+end)/2;
    int mid1=result[mid][0],mid2=result[mid][1];
    while(s<=e)
    {
        while(result[s][0]*mid2<result[s][1]*mid1){s++;}
        while(result[e][0]*mid2>result[e][1]*mid1){e--;}
        if(s<=e)
        {
            swap(result[s][0],result[e][0]);
            swap(result[s][1],result[e][1]);
            s++;
            e--;
        }
    }
    qsort(start,e);
    qsort(s,end);
}

bool isRP(int a,int b)
{
    int t;
    int x=a,y=b;
    while(1)
    {
        t=y%x;
        if(t==0){break;}
        y=x;
        x=t;
    }
    if(x==1){return true;}
    return false;
}

int main()
{
    int num,i,j,tmp=0;
    cin >> num;
    for(i=2;i<=num;i++)
    {
        for(j=1;j<=i-1;j++)
        {
            if(isRP(j,i)){result[tmp][0]=j;result[tmp][1]=i;tmp++;}
        }
    }
    cout << 0 << "/" << 1 << endl;
    qsort(0,tmp-1);
    for(i=0;i<tmp;i++)
    {
        cout << result[i][0] << "/" << result[i][1] <<endl;
    }
    cout << 1 << "/" << 1 << endl;
    return 0;
}
