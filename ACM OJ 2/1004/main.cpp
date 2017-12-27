#include <iostream>

using namespace std;

int main()
{
    int max_time,t,u,f,d;
    cin >> max_time >> t >> u >> f >> d;
    char ch;
    bool flag=false;
    int i=1,way[3]={0},time,step,tmp;
    while(i<t+1)
    {
        cin >> ch;
        if(flag==true){i++;continue;}
        if(ch=='u'){way[0]++;}
        if(ch=='f'){way[1]++;}
        if(ch=='d'){way[2]++;}
        tmp=(way[0]+way[2])*(u+d)+way[1]*f*2;
        if(tmp<=max_time){step=i;}
        if(tmp>max_time){
            flag=true;
        }
        i++;
    }
    cout << step;
    return 0;
}
