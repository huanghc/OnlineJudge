int subarr(int * A,int N) {
	int sum = INT_MIN, ans = INT_MIN; 
	for (int i=0; i<N; ++i){
		sum = sum>0? A[i]+sum:A[i]; 
		ans = max(sum,ans);
	}
	
	return ans;	
}


