#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
 
using namespace std;
template <class elemType>
class stack{
	public :
		virtual bool isEmpty() const =0;
		virtual void push(const elemType &x)=0;
		virtual elemType pop()=0;
		virtual elemType top() const =0;
		virtual ~stack(){}
}; 
template <class elemType>
class seqStack: public stack <elemType>{
	private:
		elemType *elem;
		int top_p;
		int maxSize;
		
		void doubleSpace();
	public:
		seqStack(int init=30){
			elem = new elemType[init];
			maxSize = init;
			top_p=-1;
		}
		~seqStack(){
			delete []elem;
		};
		bool isEmpty() const {return top_p==-1;}
		void push(const elemType &x){
			if (top_p>=maxSize-2) doubleSpace();
			top_p++;
			elem[top_p]=x;
		}
		elemType pop(){
			if (top_p!=-1){
				top_p--;
				return elem[top_p+1];
			}
//			else{
//				return;cout<<"Error";
//				
//			}
		}
		elemType top() const{
//			if (top_p==-1){
//				cout<<"none";
//			}
			return elem[top_p];
		}		
};
template <class elemType>
void seqStack<elemType>::doubleSpace(){
	elemType *tmp= elem; 
	elem = new elemType[2*maxSize];
	for (int i=0;i<maxSize;++i){
		elem[i] = tmp[i];
	}
	maxSize*=2;
	delete [] tmp;
}
 
template <class elemType>
class linkStack:public stack <elemType>{
	private:
		struct node{
			elemType data;
			node *next;
			node (const elemType &x,node *N=NULL){
				data=x;
				next = N;
			}
			node():next(NULL){}
			
			~node(){}		
		}; 
		
		node *elem;
 
	public:
		linkStack(){
			elem = NULL;
		}
		~linkStack(){
			node * tmp;
			while (elem!=NULL){
				tmp = elem;
				elem = elem->next;
				delete [] tmp;				
			}
		}
		bool isEmpty() const {
			return elem==NULL;
		}
		void push(const elemType &x){
			node *tmp= new node (x,elem);
			elem=tmp;			
		}
		elemType pop(){
			node *tmp = elem;
			elemType x=tmp->data;
			
			elem = elem->next;
			delete tmp;
			return x;
		}
		elemType top() const{
			return elem->data;
		}
	 
};

int main(){
	string inpt;
	getline(cin,inpt);
	
	seqStack<int> color;//y:0 r:1 b:2
	int ans[3]={0};
	for (int i=0;i<inpt.length();++i){
		//cout<<endl<<"ansi: "<<inpt.substr(i,6)<<endl;
		if (inpt[i]=='<'){
			if (inpt.substr(i,8)=="<yellow>"){
				color.push(0);
				i=i+7;
				//cout<<"s: "<<inpt[i]<<endl;
			}
			else if (inpt.substr(i,9)=="</yellow>"){
				int tmp=color.pop();				
				//cout<<"tmp: "<<tmp;
				i=i+8;
			}
			else if (inpt.substr(i,5)=="<red>"){
				color.push(1);
				i=i+4;
				//cout<<"s: "<<inpt[i]<<endl;
			}
			else if (inpt.substr(i,6)=="</red>"){
				int tmp=color.pop();				
				//cout<<tmp;
				i=i+5;
			}
			else if (inpt.substr(i,6)=="<blue>"){
				color.push(2);
				i=i+5;
				//cout<<"s: "<<inpt[i]<<endl;
			}
			else if (inpt.substr(i,7)=="</blue>"){
				int tmp=color.pop();				
				//cout<<"pop: "<<tmp;
				i=i+6;
			}			
		}
		else {
			if ((inpt[i]>='a' && inpt[i]<='z') || (inpt[i]>='A' && inpt[i]<='Z')){
				if (!color.isEmpty()){
					//cout<<"top: "<<color.top()<<endl; 
					ans[color.top()]++;
				}				
			}
			else {
				//cout<<endl<<"fuhao: "inpt[i]<<endl;
			}
		}
	}
	cout<<ans[1]<<" "<<ans[0]<<" "<<ans[2];
} 
