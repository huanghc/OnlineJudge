#include <iostream>

using namespace std;

int main()
{
    int L;
    cin >> L;
    int petri[L][L],i,j,p=0,rest=0,q=1;
    for(i=0;i<L;i++){
        for(j=0;j<L;j++){
            cin >> petri[i][j];
            if(petri[i][j]==0){rest++;}
        }
    }
    while(true)
    {
        for(i=0;i<L;i++){
            for(j=0;j<L;j++){
                if(petri[i][j]==q){
                    if(i-1>=0&&petri[i-1][j]==0){petri[i-1][j]=3*q;rest--;}
                    if(i+1<=L-1&&petri[i+1][j]==0){petri[i+1][j]=3*q;rest--;}
                    if(j-1>=0&&petri[i][j-1]==0){petri[i][j-1]=3*q;rest--;}
                    if(j+1<=L-1&&petri[i][j+1]==0){petri[i][j+1]=3*q;rest--;}
                }
            }
        }
        q=3*q;
        p++;
        if(rest==0){break;}
    }
    cout << p;
    return 0;
}
