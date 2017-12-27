#include <iostream>

using namespace std;

int main()
{
    int number,X,Y,p=1;
    int left,right,tmp;
    cin >> number >> X >> Y;
    int tree[100000]={0},A[100000],B[100000];
    while(p<number+1)
    {
        cin >> left >> right;
        tree[left]=p;
        tree[right]=p;
        p++;
    }
    tmp=X;
    p=1;
    while(true)
    {
        if(tree[tmp]==0){A[p]=tmp;break;}
        A[p]=tmp;
        p++;
        tmp=tree[tmp];
    }
    tmp=Y;
    int q=1;
    while(true)
    {
        if(tree[tmp]==0){B[q]=tmp;break;}
        B[q]=tmp;
        q++;
        tmp=tree[tmp];
    }
    while(A[p]==B[q]&&p>0&&q>0){p--;q--;}
    cout << A[p+1];
    return 0;
}
