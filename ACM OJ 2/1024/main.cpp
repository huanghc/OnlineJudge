#include <iostream>

using namespace std;

int divide(int a[],int low,int high)
{
    int k=a[low];
    while(low!=high)
    {
        while(low<high&&a[high]>=k){--high;}
        if(low<high){a[low]=a[high];low++;}
        while(low<high&&a[low]<=k){++low;}
        if(low<high){a[high]=a[low];high--;}
    }
    a[high]=k;
    return high;
}

void quickSort(int a[],int low,int high)
{
    if(low>=high) return;
    int mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}

void quickSort(int a[],int size)
{
    quickSort(a,0,size-1);
}

int main()
{
    int num;
    cin >> num;
    int data[num],p=0;;
    while(p<num)
    {
        cin >> data[p];
        p++;
    }
    quickSort(data,num);
    for(int i=0;i<num;i++){
        cout << data[i] <<" ";
    }
    return 0;
}
