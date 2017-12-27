#include <iostream>
#include <cstring>
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
class linkStack:public stack <elemType>{
	private:
		struct node{
			elemType data;
			node *next;
			node (const elemType &x,node *N=NULL){
				data=x;
				next = N;
			}
			node(){
				next=NULL;
			}
			~node(){}		
		}; 
		
		node *elem;

	public:
		linkStack(){
			elem = NULL;
		}
		~linkStack(){
			node * tmp;
			while (elem){
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
			elemType tmp = elem->data;
			elem = elem->next;
			return tmp;
		}
		elemType top() const{
			return elem->data;
		}	 
};

int main(){
	linkStack<int> stak;
	string pas;
	while (1){
		getline(cin, pas);
		if (pas.find("begin")!=-1){
			stak.push(1);
		}
		if (pas.find("end")!=-1){
			int t=stak.pop();
			while (t==3){
				t=stak.pop();
			}
			if (t!=1){
				cout<<"Error!";return 0;
			}
		}
		if (pas.find("if")!=-1){
			stak.push(2);
		}
		if (pas.find("then")!=-1){
			if(stak.pop()!=2){
				cout<<"Error!";return 0;
			}
			stak.push(3);
		}
		if (pas.find("else")!=-1){
			int t=stak.pop();
			if (t!=3){
				cout<<"Error!";return 0;
			}
		}
		if (pas=="") break;		
	}
	if (stak.isEmpty()){
		cout<<"Match!";
	}
	else {
		cout<<"Error!";
	}	
	return 0;
} 
