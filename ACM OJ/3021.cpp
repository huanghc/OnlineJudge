#include <iostream>
using namespace std;
void merge(int a[], int p, int q, int r);
void mergeSort1(int a[], int p, int r);
long count=0;    
int L[100000];  
int R[100000]; 

int main(){
	int n,i;
	cin>>n;
	int num[100000];
	for (i=0;i<n;++i){
		cin>>num[i];
	}
	mergeSort1(num,0,n-1);
	cout<<count;
} 

void merge(int a[], int p, int q, int r){   
    int n1 = q-p+1;  
    int n2 = r-q;  
 
    int i,j,k;  
    for (i=0; i<n1; ++i){  
        L[i] = a[p+i];  
    }  
    for (j=0; j<n2; ++j){  
        R[j] = a[q+j+1];  
    }
    
	i=0;j=0;k=p;   
    while (i < n1 && j < n2){       
        if (L[i] <= R[j]){
        	a[k] = L[i]; ++i;
		}               
        else{
        	a[k] = R[j]; ++j;
        	count += n1-i;
		}            			
		++k; 
    }  
      
    while (i < n1){
    	a[k++] = L[i++];
	}  
                
    while (j < n2){
    	a[k++] = R[j++];
	}       
}  
  
void mergeSort1(int a[], int p, int r){    
    if (p<r){       
        int q = (p+r)/2;  
        mergeSort1(a, p, q);  
        mergeSort1(a, q+1, r);  
        merge(a, p, q, r);  
    }  
} 


