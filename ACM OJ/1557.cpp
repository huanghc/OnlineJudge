#include <iostream>
#include <algorithm> 
using namespace std;
 
struct cow{  
    long long x,h;  
    cow(){}  
    cow(long a,long b){x=a;h=b;}   
};
bool cmp(cow a, cow b)
{
	return a.h<b.h;
}
cow cs[60000];  
 
int main(){
	long long N,D,ans=0;
	cin>>N>>D;
	for (long long i=0;i<N;++i){
		cin>>cs[i].x>>cs[i].h; 
	}
	sort(cs,cs+N,cmp); 
 
	for (long long i=0; i<N;++i){
		int flag1 = 0;//cout<<cs[i].x<<endl;
		int flag2 = 0;
		for (long long j=N-1;;--j){
			if (cs[j].h<2*cs[i].h){
				//cout<<cs[i].h<<" "<<cs[j].h<<endl;
				//cout<<"j: "<<cs[j].h<<endl;
				break;
			}
			//cout<<"j: "<<j<<endl;
			if(cs[i].x-cs[j].x>0 &&  cs[i].x-cs[j].x<=D){
				flag1=1;//cout<<"i: "<<i<<"j: "<<j<<endl;
	
			}
			
			if (cs[i].x-cs[j].x<=0 && cs[j].x-cs[i].x <= D){
				flag2=1;
			}
			if (flag1==1 &&flag2==1){
				++ans;break;
			}
				
		}
	}
	cout << ans;
}
