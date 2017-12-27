#include <iostream>
#include <cmath>
#include <stdio.h>
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
	int n;cin>>n;
	linkQueue <int> ke;
	linkQueue <int> huo;
	int tmp=0,tmptime=0;
	int keshu=0,huoshu=0;
	for (int i=0;i<n;++i){
		cin>>tmp;cin>>tmptime;
		if (tmp==0){			
			ke.enQueue(tmptime);
			keshu++;
		}
		else {
			huo.enQueue(tmptime);
			huoshu++;
		} 
	}
	int kewaittm=0,huowaittm=0,tm=0;
	for (tm=0;tm<=(keshu+huoshu)*10;tm=tm+10){
		//cout<<endl<<tm<<endl;
		int ship=0;
		while (ship<8 && !ke.isEmpty() && ke.getHead()<=tm){
			//cout<<endl<<"ke: "<<ke.getHead();
			kewaittm+=tm-ke.deQueue();
			++ship;
		}
		while (!huo.isEmpty() && ship<10 && huo.getHead()<=tm){
			//cout<<endl<<"huo: "<<huo.getHead();
			huowaittm+=tm-huo.deQueue();
			++ship;
		}
		while (ship<10 && !ke.isEmpty() && ke.getHead()<=tm){
			//cout<<endl<<"ke: "<<ke.getHead();
			kewaittm+=tm-ke.deQueue();
			++ship;
		}
	}
	printf("%.3lf",kewaittm/double(keshu));cout<<" ";
	printf("%.3lf",huowaittm/double(huoshu));
}
