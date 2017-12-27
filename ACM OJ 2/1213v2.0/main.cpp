#include <iostream>

using namespace std;

int Right[200000],Left[200000],Weight[200000]={0};
int Right2[200000],Left2[200000],Weight2[200000]={0};

bool isSame(int root1,int root2)
{
    if(root1==0&&root2==0){return true;}
    if(Weight[root1]!=Weight2[root2]){return false;}
    if(Right[root1]==0&&Right2[root2]!=0){return false;}
    if(Right[root1]!=0&&Right2[root2]==0){return false;}
    if(Left[root1]==0&&Left2[root2]!=0){return false;}
    if(Left[root1]!=0&&Left2[root2]==0){return false;}
    return isSame(Left[root1],Left2[root2])&&isSame(Right[root1],Right2[root2]);
}

int main()
{
    int num,num2,i,sum=0,root,root2;
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
    sum=0;
    cin >> num2;
    for(i=1;i<=num2;i++)
    {
        cin >> Left2[i];
        sum+=Left2[i];
        cin >> Right2[i];
        sum+=Right2[i];
        cin >> Weight2[i];
    }
    root2=(1+num2)*num2/2-sum;
    if(isSame(root,root2)){cout << "Y";}
    else{cout << "N";}
    return 0;
}
