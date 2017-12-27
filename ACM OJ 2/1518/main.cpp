#include <iostream>

using namespace std;

int preorder[100000],midorder[100000],postorder[100000];

void findorder(int a,int b,int c,int d)
{
    int root=preorder[a];
    if(a<b&&c<d){
        int i=c;
        while(midorder[i]!=root){i++;}
        findorder(a+1,i-c+a,c,i-1);
        findorder(i-c+a+1,b,i+1,d);
        cout << root << " ";
    }
    if(a==b&&c==d){
        cout << root << " ";
    }
}

int main()
{
    int num,i=0;
    cin >> num;

    for(i=0;i<num;++i){cin>>preorder[i];}
    for(i=0;i<num;++i){cin>>midorder[i];}

    findorder(0,num-1,0,num-1);

    return 0;
}
