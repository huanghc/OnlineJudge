#include <iostream>

using namespace std;

int Right[200000],Left[200000];
int Q[200000];
int begin=0,end=0;

int main()
{
    int num,i,sum=0,root,tmp,max=1,cnt=0;
    cin >> num;
    for(i=1;i<=num;i++)
    {
        cin >> Left[i];
        sum+=Left[i];
        cin >> Right[i];
        sum+=Right[i];
    }
    root=(1+num)*num/2-sum;
    Q[end]=root;
    end++;
    while(begin!=end)
    {
        tmp=Q[begin];
        begin++;
        cnt++;
        if(Left[tmp]!=0){max=2*cnt;Q[end]=Left[tmp];end++;}
        if(Right[tmp]!=0){max=2*cnt+1;Q[end]=Right[tmp];end++;}
    }
    if(cnt==max){cout << "Y";}
    else{cout <<"N";}
    return 0;
}
