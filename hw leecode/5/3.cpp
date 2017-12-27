#include <iostream>
#include <math.h>
using namespace std;
void num(string str, int &zero, int &one){
	for (int i=0;i<str.length();++i){
		if (str[i] == '0') ++zero;
		else ++one;
	}
}
int macForm(string *array, int N, int m, int n){
	int dp[m+1][n+1] = {0};
	for (int i=0 ; i<=m; ++i){
		for (int j=0; j<=n; ++j)
			dp[i][j] = 0;
	}
	
	for (int k = 0; k<N; ++k){
		int t0 = 0, t1 = 0;
		num(array[k],t0,t1);
//		cout<<t0<<" "<<t1<<endl;	
		for (int i=m; i>=t0; --i){
			for (int j=n; j>=t1; --j){
				dp[i][j] = max(dp[i][j],dp[i-t0][j-t1]+1);
//				cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			}
		}	
	}

	return dp[m][n];
} 

int main(){
	string array[] = {"10", "0001", "111001", "1", "0"};
	int N = 5;
	int m = 5, n = 3;
	cout<<macForm(array, N , m, n);
}  

