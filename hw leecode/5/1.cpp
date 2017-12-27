#include <iostream>
using namespace std;

int minreplace(int n){
	int minNum = 0;
    if (n == 1)
        return minNum;
    if (n == 3)
        return minNum+2;
	if (n == INT_MAX)
	    return 32;
	while (n!=1){
		if(n%2 == 0){
			n = n/2;
		}
		else {
			if (n%4 == 1)
				n = n-1;
			else
				n = n+1;
		}
		++minNum;
	    if (n == 3)
	        return minNum+2;
	}
	return minNum;
}

int main(){
	int n = 7;
	cout<<minreplace(n);
}