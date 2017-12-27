#include <iostream>

using namespace std;

int main()
{
    long salary;
    int i=0;
    cin >> salary;
    double rate[7]={0.03,0.1,0.2,0.25,0.30,0.35,0.45},tax=0;
    int range[7]={0,1500,4500,9000,35000,55000,80000};
    salary-=3500;
    while(salary>0&&i<6)
    {
        if(salary+range[i]>range[i+1]){
            tax+=(range[i+1]-range[i])*rate[i];
            salary-=(range[i+1]-range[i]);
            i=i+1;
        }
        else{tax+=salary*rate[i];break;}
    }
    if(i==6){tax+=salary*rate[i];}
    cout << long(tax);
    return 0;
}
