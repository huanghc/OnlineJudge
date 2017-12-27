#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;
 
template <class elemType>
class queue{
	public:
		virtual bool isEmpty()=0;
		virtual void enQueue(const elemType &x)=0;
		virtual elemType deQueue()=0;
		virtual elemType getHead()=0;
		virtual ~queue(){}
};
 
template <class elemType>
class linkQueue:public queue<elemType>{
	private:
		struct node{
			elemType data;
			node *next;
			node (const elemType &x,node *N=NULL){
				data=x;next=N;
			}
			node(){
				next=NULL;
			}
			~node(){
			}
		};
		
		node *front,*rear;
	
	public:
		linkQueue(){
			front=rear=NULL;
		}
		~linkQueue(){
			node *tmp;
			while (front!=NULL){
				tmp=front;
				front = front->next;
				delete tmp;
			}
		}
		bool isEmpty(){
			return front==NULL;
		}
		void enQueue(const elemType &x){
			if (rear==NULL){
				front=rear=new node(x);
			}
			else{
				rear->next=new node(x);
				rear=rear->next;
			}
		}
		elemType deQueue(){
			node *tmp=front;
			elemType value=front->data;
			front=front->next;
			if (front==NULL) rear=NULL;
			delete tmp;
			return value;
		}
		elemType getHead(){
			return front->data;
		}
};
int bt[20000000],gt[20000000];
int main(){	
	int N,song[2000000],M;scanf("%d",&N);
	for (int i=0;i<N;++i){
		scanf("%d",&song[i]);
	} 	
	scanf("%d",&M);
	linkQueue<int> boyque;
	linkQueue<int> girlque;
	int bnum=0,gnum=0;
		
	for (int i=0;i<M;++i){
		int t,tim=0;scanf("%d%d",&t,&tim);
		if (t==1){
			bt[bnum] = tim;
			//boyque.enQueue(tim);
			++bnum;
		}
		if (t==2){
			gt[gnum] = tim;
			//girlque.enQueue(tim);
			++gnum;
		}
	}
	//cout<<endl;
	sort(bt,bt+bnum);sort(gt,gt+gnum);
	for (int i=0;i<bnum;++i){
		//cout<<bt[i]<<" ";
		boyque.enQueue(bt[i]);
	}
	for (int i=0;i<gnum;++i){
		girlque.enQueue(gt[i]);
	}
	
	long long tim=0,bwatim=0,gwatim=0,ttmp=0;;
	for (int i=0;i<N;++i){
		while(!boyque.isEmpty() && !girlque.isEmpty() && 
		boyque.getHead()<=tim && girlque.getHead()<=tim){
			int bt=boyque.deQueue(); 
			int gt=girlque.deQueue();
			//cout<<"bt,gt: "<<bt<<" "<<gt<<endl; 
			bwatim = tim-bt+ bwatim;
			gwatim = gwatim + tim-gt;									
		}
		ttmp=song[i];
		tim+=song[i];//cout<<"zj: "<<bwatim<<" "<<gwatim<<endl;
		if (boyque.isEmpty() || girlque.isEmpty()){
			break;
		}
	}
	tim -= ttmp;
	for(; !boyque.isEmpty();)
		bwatim += tim - boyque.deQueue();
	for(; !girlque.isEmpty();)
		gwatim += tim - girlque.deQueue();
		
	printf("%.2lf",bwatim/double(bnum));cout<<" ";
	printf("%.2lf",gwatim/double(gnum));
}
