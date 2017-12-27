#include <iostream>

using namespace std;

int divide(int a[],int low,int high)
{
    int tmp=a[low];
    while(low!=high)
    {
        while(low<high && a[high]>=tmp){high--;}
        if(low<high){
			a[low]=a[high];
			low++;
		}
        while(low<high && a[low]<=tmp){
			low++;
		}
        if(low<high){
			a[high]=a[low];
			high--;
		}
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

int main(){
    int num;
    cin >> num;
    int tmp[num];
    for(int i=0;i<num;++i){
        cin >> tmp[i];
    }
    quickSort(tmp,0,num-1);
    for(int i=0;i<num;++i){
        cout << tmp[i] << " ";
    }

}
