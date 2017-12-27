#include <iostream>

using namespace std;

int Brother[200000]={0},Left[200000]={0},Weight[200000]={0};
int Q[200000];
int begin=0,end=0;

void preOrder(int root)
{
    if(root==0){return;}
    cout << Weight[root] << " ";
    int tmp=Left[root];
    preOrder(tmp);
    tmp=Brother[tmp];
    while(tmp!=0)
    {
        preOrder(tmp);
        tmp=Brother[tmp];
    }

}

void postOrder(int root)
{
    if(root==0){return;}
    int tmp=Left[root];
    while(tmp!=0)
    {
        postOrder(tmp);
        tmp=Brother[tmp];
    }
    cout << Weight[root] << " ";
}

void levelOrder(int root)
{
    Q[end]=root;
    end++;
    int tmp;
    while(begin!=end)
    {
        tmp=Q[begin];
        begin++;
        cout << Weight[tmp] << " ";
        tmp=Left[tmp];
        while(tmp!=0){Q[end]=tmp;end++;tmp=Brother[tmp];}
    }
}

int main()
{
    int num,i,sum=0,root,tmp;
    cin >> num;
    for(i=1;i<=num;i++)
    {
        cin >> Left[i];
        sum+=Left[i];
        cin >> Brother[i];
        sum+=Brother[i];
        cin >> Weight[i];
    }
    root=(1+num)*num/2-sum;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    levelOrder(root);
    return 0;
}

