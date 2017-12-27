int Pro3(int A[], int N) {  
    int * num = new int[N];  
    int ans =N;  
    for(int i=1;i<N;++i){  
        if(A[i] > A[i-1]){  
            num[i] = num[i-1]+1;
        }  
        else  
            num[i] = 1;  
    }  
    for(int i = N-2;i>=0;i--){  
        if(A[i] > A[i+1]){
		num[i] = max(num[i], num[i+1]+1);
	}             
    }  
    for(int i=0;i<N;i++){  
        ans += num[i];  
    }  
    return ans;  
}  
