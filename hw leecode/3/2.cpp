int strParti(string s){
	int ls = s.length(); 
	if (ls <= 1){
		return 0;
	} 
	int p[100][100];  //true or false
	memset(p,0,sizeof(p));
	int *numP = new int [100];
	for (int i=0; i<ls; ++i){
		numP[i] = ls - i -1;        //max all partition
	}
	for (int i=ls-1; i>=0; --i){
		for (int j=i; j<ls; ++j){
			if ((p[i+1][j-1] && s[i] == s[j]) 
			or (i==j-1 && s[i] == s[j])
			or (i==j)){
				p[i][j] = 1;    //is Palindrome 
				numP[i] = min(numP[i], numP[j+1]+1);  
			}
		}		
	}	
	return numP[0];  //the whole string
}


