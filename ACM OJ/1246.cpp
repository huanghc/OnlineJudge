#include <iostream>
#include <stdio.h>
//#include <string.h>
using namespace std;
 
int p[1200][1200];
int sum[1200][1200]={0};
 
int sumx[1200][1200]={0};
 
int main(){
	int m, n, a, b, c , d;
	scanf("%d%d%d%d%d%d",&m,&n,&a,&b,&c,&d);
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			scanf("%d",&p[i][j]);
		}
	}
	for (int i=0;i<b;++i){
		for (int j=0;j<a;++j){
			sum[0][0]=sum[0][0]+p[i][j];
		}
	}
 
	for (int i=0;i<d;++i){
		for (int j=0;j<c;++j){
			sumx[0][0]=sumx[0][0]+p[i][j];
		}
	}
		
	for (int i=0;i<=n-b;++i){
		for (int j=1;j<=m-a;++j){
			sum[i][j]=sum[i][j-1];
			for (int k=0;k<b;++k){
				sum[i][j]=sum[i][j]-p[i+k][j-1]+p[i+k][j-1+a];
			}
		}
		sum[i+1][0]=sum[i][0];
		for (int t=0;t<a;++t){
			sum[i+1][0]=sum[i+1][0]-p[i][t]+p[i+b][t];
		}		
	}
	
	for (int i=0;i<=n-d;++i){
		for (int j=1;j<=m-c;++j){
			sumx[i][j]=sumx[i][j-1];
			for (int k=0;k<d;++k){
				sumx[i][j]=sumx[i][j]-p[i+k][j-1]+p[i+k][j-1+c];
			}
		}
		sumx[i+1][0]=sumx[i][0];
		for (int t=0;t<c;++t){
			sumx[i+1][0]=sumx[i+1][0]-p[i][t]+p[i+d][t];
		}		
	}
	
	int min = -1;
	int mini=0,minj=0,mi=0,mj=0;
	int tmp1=0,tmp2=0;
	for (int i=0;i<=n-b;++i){
		for (int j=0;j<=m-a;++j){
			tmp1 = sum[i][j];			
			for (int k=i+1;k<i+b-d;++k){
				for (int t=j+1;t<j+a-c;++t){					
					tmp2 = tmp1-sumx[k][t];					
					if (tmp2>min){
						min = tmp2;
						mini = i;
						minj = j;
						mi = k;
						mj = t;
						//cout<<i<<" "<<j<<" "<<k<<" "<<t<<" "<<"min: "<<min<<endl;
					}					
				}
			}
		//	cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
		}
	}
 
	cout<<minj+1<<" "<<mini+1<<endl<<mj+1<<" "<<mi+1;
	
}