#include <iostream>
#include <cmath>
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

int main(){
	int num;cin>>num;
	linkQueue<int> que;
	
	long long onelast[3]={0},onewait=0;
	for (int i=0;i<num;++i){
		int t=0;cin>>t;
		que.enQueue(t);
		onewait+=onelast[i%3];
		onelast[i%3]+=t;		
	}

	long long tq1=0,tq2=0,tq3=0;
	long long last=0,wait=0;
	while (!que.isEmpty()){
		if (tq1<=tq2 && tq1<=tq3){
			int tmp=que.deQueue();
			wait+=tq1;
			tq1=tq1+tmp;			
		}
		else if (tq2<tq1 && tq2<=tq3){
			int tmp=que.deQueue();
			wait+=tq2;tq2=tq2+tmp;
		}
		else if (tq3<tq1 && tq3<tq2){
			int tmp=que.deQueue();
			wait+=tq3;tq3=tq3+tmp;
		}
		else {
			cout<<"??";
		}		
	}

	last=max(max(tq1,tq2),tq3);
	
	long long oneans=max(max(onelast[0],onelast[1]),onelast[2]);
	cout<<onewait<<" "<<oneans<<endl;

	cout<<wait<<" "<<last;
	
}

