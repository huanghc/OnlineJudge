double Median(int nums1[], int m, int nums2[], int n){  
	if((n+m)%2 ==0){   
		return (calMid(nums1,m,nums2,n, (m+n)/2) + 
		calMid(nums1,m,nums2,n, (m+n)/2+1))/2.0;  
	}  
	else  
		return calMid(nums1,m,nums2,n, (m+n)/2+1);        
}

int calMid(int a[], int n, int b[], int m, int k){  	    
    if (n <= 0) return b[k-1];  
    if (m <= 0) return a[k-1];  
    if (k == 1) return a[0]<b[0] ? a[0] : b[0];
	
    if (b[m/2] >= a[n/2]){  	  
        if ((n/2 + 1 + m/2) >= k){
            return calMid(a, n, b, m/2, k);
        }  			  
        else{
            return calMid(a+n/2+1, n-(n/2+1), b, m, k-(n/2+1));
        }		  
    }
    else{ 	  
        if ((m/2 + 1 + n/2) >= k){
            return calMid( a, n/2,b, m, k);
        }			  
        else{
            return calMid(a, n, b+m/2+1, m-(m/2+1), k-(m/2+1));
        }  			  
    }  
}  
