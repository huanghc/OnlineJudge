#include <iostream>
#include <string.h> 
using namespace std;
int ack[10001][10001];


int Ackmann(int m,int n){
	if(m==0){
		return (n+1);
	}
	else{
		if(m>0 && n==0){
			int tmp=ack[m-1][1];
			if (tmp!=-1){
				return tmp;
			}
			else return Ackmann(m-1,1);			
		}
		else{
			int a1=ack[m][n-1];
			int a2=ack[m-1][a1];
			if (a1>=0 && a1<=10){
				if (a2!=-1) return a2;										
				else{					
					return Ackmann(m-1,a1);
				} 
			}
			else return Ackmann(m-1,Ackmann(m,n-1));
		} 
	} 
}


int main(){
	memset(ack,-1,sizeof(ack));
	int m,n;
	cin>>m>>n;
	for (int i=0;i<=m;++i){
		for (int j=0;j<=n;++j){
			ack[i][j]=Ackmann(i,j);
			//cout<<"d: "<<i<<" "<<j<<" "<<ack[i][j]<<endl;
		}
	}
	cout<<ack[m][n];			
	return 0;
} 
