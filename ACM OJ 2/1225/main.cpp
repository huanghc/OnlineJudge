#include <iostream>

using namespace std;

int divide(int a[],int low,int high)
{
    int tmp=a[low];
    while(low!=high)
    {
        while(low<high&&a[high]>=tmp){high--;}
        if(low<high){a[low]=a[high];low++;}
        while(low<high&&a[low]<=tmp){low++;}
        if(low<high){a[high]=a[low];high--;}
    }
    a[high]=tmp;
    return high;
}

void quickSort(int a[],int low,int high)
{
    int mid;
    if(low>=high) return;
    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}

void quickSort(int a[],int size)
{
    quickSort(a,0,size-1);
}

int main()
{
    int num,a=0;
    cin >> num;
    int tmp[num];
    while(a<num)
    {
        cin >> tmp[a];
        a++;
    }
    quickSort(tmp,num);
    a=0;
    int b=tmp[a],sum=1;
    while(a<num)
    {
        if(tmp[a]!=b){b=tmp[a];sum++;}
        a++;
    }
    cout << sum;
    return 0;
}
