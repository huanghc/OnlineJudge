bool subeql(int * A,int N) {
	int sum=0,half = 0;
	for (int i=0; i<N; ++i){
		sum += A[i];
	}
	if (sum%2==1) return false;
	else half = sum/2;
	
	bool * dp = new bool [sum];	
	for (int i=0; i<sum; ++i){
		dp[i] = false;
	}
	dp[0] = 1;
	
	for (int i=0; i<N; ++i){
	        for (int j = half; j >= A[i]; --j) {
	            dp[j] = dp[j] || dp[j - A[i]];
	        }
	}
	
	return dp[half];	
}

