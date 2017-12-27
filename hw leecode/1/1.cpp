bool Jump(int A[],int N) {  
    int range = 0;  
    for (int i=0; i < N && i <= range; ++i) {  
        range = max(range, i + A[i]);
	if (range>=N) return true;
    }  
    return false;  
}  

