int Jump2(int A[], int N) {  
	int num=0,curReach=0,curMax=0;  
	for (int i = 0; i < N; ++i) {    
	    if (i > curReach) {  
	        curReach = curMax;  
	        ++num;  
		if (curReach >= N-1) break;	        
	    }  
	    curMax = max(curMax, i+A[i]);    
	}  	
	return num;  
}  


