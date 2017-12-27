#include <iostream>
#include <algorithm> 
using namespace std;
 
struct node{
	int data;
	node *pre,*next;
	node(){
		data = 0;
		pre=NULL;next=NULL;
	}
	node (int a,node *p=NULL,node *q=NULL){
		data=a;pre=p;next=q;
	}
};
 
class set{
	private:
		node *front,*rear;
	public:
		set(){
			front=new node;rear=new node;
			front->next=rear;rear->pre=front;
		}
		void print(){
			node *tmp=front->next;
			while (tmp!=rear){
				cout<<tmp->data<<" ";
				tmp = tmp->next;
			}
			cout<<endl;
		}
		void add(int a){
			node *tmp = front->next;
			while (tmp!=rear&&tmp->data<a){
				tmp = tmp->next;
			}
			if (tmp->data==a) return;
			node *n = new node (a,tmp->pre,tmp);
			tmp->pre->next = n;
			tmp->pre = n;
		}
		void sub(int a){
			node *tmp = front->next;
			while (tmp!=rear&&tmp->data<a){
				tmp = tmp->next;
			}
			if (tmp->data==a){
				tmp->pre->next = tmp->next;
				tmp->next->pre = tmp->pre;
			}		
		}
		void mul(){
			int mnum[120]={0},num=0;
			int t;cin>>t;
			for (int tt=0;tt<t;++tt){
				int f;cin>>f;mnum[num]=f;++num;
			}
			sort(mnum,mnum+num); 
			node *tmp = front->next;
 
			while(tmp!=rear){//cout<<tmp->data<<endl;
				bool flag=0;
				for (int i=0;i<num;++i){
					if (tmp->data<mnum[i]) continue;
					//cout<<tmp->data<<" "<<mnum[i]<<endl;
					if (tmp->data==mnum[i]){
						flag = 1;
					}
				}
				
				if (flag == 0){
					tmp->pre->next = tmp->next;
					tmp->next->pre = tmp->pre;
				}	
				tmp=tmp->next;								
			}
					
		}
};
 
int main(){
	int n;cin>>n;
	char t;
	set s;	//s.add(5);s.print();s.add(7);s.print();
	for (int i=0;i<n;++i){
		cin>>t;
		if (t=='+'){
			int tmp;cin>>tmp;
			for (int tt=0;tt<tmp;++tt){
				int f;cin>>f;s.add(f);
			}
			s.print();
		}
		if (t=='-'){
			int tmp;cin>>tmp;
			for (int tt=0;tt<tmp;++tt){
				int f;cin>>f;s.sub(f);
			}
			s.print();
		}
		if (t=='*'){
			s.mul();
			s.print();
		}		
	}
 
}
