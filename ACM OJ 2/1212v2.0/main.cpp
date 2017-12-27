#include <iostream>

using namespace std;

int Right[200000],Left[200000],Weight[200000];
int Q[200000];
int begin=0,end=0;

int main()
{
    int num,i,sum=0,root,tmp;
    cin >> num;
    for(i=1;i<=num;i++)
    {
        cin >> Left[i];
        sum+=Left[i];
        cin >> Right[i];
        sum+=Right[i];
        cin >> Weight[i];
    }
    root=(1+num)*num/2-sum;
    Q[end]=root;
    end++;
    while(begin!=end)
    {
        tmp=Q[begin];
        begin++;
        cout << Weight[tmp] << " ";
        if(Left[tmp]!=0){Q[end]=Left[tmp];end++;}
        if(Right[tmp]!=0){Q[end]=Right[tmp];end++;}
    }
    return 0;
}
