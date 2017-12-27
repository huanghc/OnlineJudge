#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
using namespace std;
enum token {ADD,SUB,MUL,DIV,LKH,RKH,TIM,VAL,EOL};
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
		seqStack(int init=10){
			elem = new elemType[init];
			maxSize = init;
			top_p=-1;
		}
		~seqStack(){
			delete []elem;
		};
		bool isEmpty() const {return top_p==-1;}
		void push(const elemType &x){
			if (top_p==maxSize-1) doubleSpace();
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
		void push(elemType &x){
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

token getexpr(long long &value,char  *&expr){
	while (*expr){
		while (*expr==' '){
			++expr;
		}
		if (*expr<='9' && *expr>='0'){
			value=0;
			while (*expr<='9' && *expr>='0'){
				value = value*10+*expr-'0';
				++expr;
			}
			//cout<<"val: "<<value<<endl;
			return VAL;
		}
		switch (*expr){
			case '(':++expr;return LKH;
			case ')':++expr;return RKH;
			case '+':++expr;return ADD;
			case '-':++expr;return SUB;
			case '*':++expr;return MUL;
			case '/':++expr;return DIV;
			case '^':++expr;return TIM;
		}
	}
	return EOL; 
}
void tmpcal(seqStack<long long> &numstack,token tmpop){
	long long tmp2 = numstack.pop();
	long long tmp1 = numstack.pop();

	switch(tmpop){
		case ADD:
			numstack.push(tmp1+tmp2);break;
		case SUB:
			numstack.push(tmp1-tmp2);break;
		case MUL:
			numstack.push(tmp1*tmp2);break;
		case DIV:
			numstack.push(tmp1/tmp2);break;
		case TIM:
			numstack.push(pow(tmp1,tmp2));break;
	}		
}

int main(){
    char *expr=new char [100];
    cin.getline(expr,100);

    //cout<<expr;
    token tmp;
    
    seqStack<token> opstack;
    seqStack<long long> numstack;
    
    while (1){
	    long long value=0;
	    tmp=getexpr(value,expr);
	    
	    //cout<<"fuhao: "<<tmp<<endl;
	    token tmpop;
	    if (tmp==EOL) break;    
		switch (tmp){
			case VAL:
				numstack.push(value);break;
			case LKH:
				opstack.push(LKH);break;			
			case RKH:
				tmpop = opstack.pop();
				while (tmpop!=LKH && ! opstack.isEmpty()){
					tmpcal(numstack,tmpop);
					tmpop = opstack.pop();
				}
				if (tmpop!=LKH){
					cout<<"Error";
					return 0;
				}
				break;				
			case TIM:
				opstack.push(TIM);break;
			case MUL:case DIV:
				while (!opstack.isEmpty() && opstack.top()==TIM){
					tmpcal(numstack,tmp);
				}
				opstack.push(tmp);
				break;
			case ADD:case SUB:
				while (!opstack.isEmpty() && opstack.top()!=LKH){
					tmpcal(numstack,tmp);
				}
				opstack.push(tmp);				
		}
	}

	while (!opstack.isEmpty()){
		tmpcal(numstack,opstack.pop());
	}
	long long ans = numstack.pop();
	if (!numstack.isEmpty() || !opstack.isEmpty()){
		cout<<"Error";return 0;
	}
	cout<<ans;
    
} 
