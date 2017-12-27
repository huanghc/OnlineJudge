#include <cstdio>
#include <iostream>
using namespace std; 
int a[1010][1010],s[1010][1010]={{0}},h[1010][1010];
int p,q,n,m,a0,b0,c,d,ans,I,J,K,L;
inline int sum(int i,int j,int x,int y){
    return s[i+x-1][j+y-1]-s[i+x-1][j-1]-s[i-1][j+y-1]+s[i-1][j-1];
}
struct rec{int x,y,z;};
rec f[1010][1010],g[1010][1010],b[1010];
int main(){
    scanf("%d%d%d%d%d%d",&m,&n,&b0,&a0,&d,&c);
    
    for(int i=1;i<=n;i++)//求与左上角所成面积
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j]; 
        }
    for(int i=2;i+c-1<n;i++)
        for(int j=2;j+d-1<m;j++) 
			h[i][j] = sum(i,j,c,d);//以当前位置为墓室左上角的墓室面积 
			
    for(int i=2;i+c-1<n;i++){
        p = 0;
        q = 1;
        for(int j=2;j<=b0-d;j++){//墓室在金字塔的活动范围不出第一个金字塔 
            while(p && h[i][j]<=b[p].z) p--;
            p++;
            b[p].x = i;
            b[p].y = j;
            b[p].z = h[i][j]; 
        }
        f[i][2]=b[1];
        for(int j=b0-d+1;j+d<=m;j++){//墓室在金字塔的活动范围出第一个金字塔
            while(p>=q && h[i][j]<=b[p].z) p--;
            p++;
            b[p].x = i;
            b[p].y = j;
            b[p].z = h[i][j];
            while(b[q].y+b0-1<=j+d) q++;
            f[i][j-b0+d+2]=b[q];
        }
    }
    
    for(int j=2;j+d-1<m;j++){
        p = 0;
        q = 1;
        for(int i=2;i<=a0-c;i++){
            while(p && f[i][j].z<=b[p].z) p--;
            p++;
            b[p] = f[i][j];
        }
        g[2][j] = b[1];
        for(int i=a0-c+1;i+c<=n;i++){
            while(p>=q && f[i][j].z<=b[p].z) p--;
            p++;
            b[p] = f[i][j];
            while (b[q].x+a0-1<=i+c) q++;
            g[i-a0+c+2][j] = b[q];
        }
    }
    
    ans = 0;
    for(int i=1;i+a0-1<=n;i++)
        for(int j=1;j+b0-1<=m;j++) 
			if(sum(i,j,a0,b0)-g[i+1][j+1].z>ans){
	            ans = sum(i,j,a0,b0) - g[i+1][j+1].z;//比较两个墓室大小 
	            I = i;
	            J = j;
	            K = g[i+1][j+1].x;
	            L = g[i+1][j+1].y;
        }
    printf("%d %d\n%d %d\n",J,I,L,K);
}