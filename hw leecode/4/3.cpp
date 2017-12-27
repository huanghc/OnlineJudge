#include <iostream>
#include <math.h>
using namespace std;

bool SelfCrossing(int *x, int N) {  
    for(int i=3; i<N; ++i){  
        if(i>=3 && x[i]>=x[i-2] && x[i-1]<=x[i-3])  
            return true;  
        if(i>=4 && x[i-1]==x[i-3] && x[i-2]<=x[i]+x[i-4])  
            return true;  
        if(i>=5 && x[i-2]>x[i-4] && x[i-1]<=x[i-3] 
		&& x[i-1]+x[i-5]>=x[i-3] && x[i]+x[i-4]>=x[i-2])  
            return true;  
    }  
    return false;  
} 

int main(){
	int x[4] = {2, 1, 1, 2};
	int N = 4;
	cout<<SelfCrossing(x,N);
}  

