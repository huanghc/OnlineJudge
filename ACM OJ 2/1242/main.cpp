#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int low,high,sum_number=0;
    cin >> low >> high;
    int p=low,q,i;
    bool flag;
    while(p<=high)
    {
        flag=false;
        if(p==2){sum_number++;p++;continue;}
        if(p%2==0||p==1){p++;continue;}
        q=sqrt(p)+1;
        for(i=3;i<q;i+=2)
        {
            if(p%i==0){flag=true;break;}
        }
        if(flag==false)sum_number++;
        p++;
    }
    cout << sum_number;
}
