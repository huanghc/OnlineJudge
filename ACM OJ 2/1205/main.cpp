#include <iostream>

using namespace std;

int Ackerman(int m,int n)
{
    if(m!=0&&n!=0) return Ackerman(m-1,Ackerman(m,n-1));
    if(m!=0&&n==0) return Ackerman(m-1,1);
    return n+1;
}

int main()
{
    int x,y,result;
    cin >> x >> y;
    result=Ackerman(x,y);
    cout << result ;
    return 0;
}
