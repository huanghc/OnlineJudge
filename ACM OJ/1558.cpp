#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
int a[100005],b[100005],c[100005],w[1000005];
 
int lower_bound(int *array, int size, int key)
{
    int first = 0, middle;
    int half, len;
    len = size;
 
    while(len > 0) {
        half = len >> 1;
        middle = first + half;
        if(array[middle] < key) {     
            first = middle + 1;          
            len = len-half-1;      
        }
        else
            len = half;            
    }
    return first;
}
 
int main(){
    int n,k;
	memset(w,0,sizeof(w)); 
	cin>>n>>k;
    for (int i=1;i<=n;++i) {
    	cin>>a[i];
    	b[i] = a[i];
	}
    sort(b+1,b+n+1);
	for(int i=1;i<=n;++i){
		c[i]=lower_bound(b+1,b+n+1,a[i])-b-1;
	} 
    int ans=0,num=0,s=1;
    for (int i=1;i<=n;++i){    
		w[c[i]]++;
        if (w[c[i]]==1){
			num++;
			while (num>k+1){
				w[c[s]]--;
				if(!w[c[s]])num--;s++;
				if (s>n) break;
			}
		}
        ans=max(ans,w[c[i]]);
		if (s>n) break;
    }
    cout<<ans;
}