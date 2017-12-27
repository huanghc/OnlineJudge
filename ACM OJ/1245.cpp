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
 
seqStack<string> houzhui;  
token getexpr(int &value,char  *&expr){
	int flag=0;
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
			if (flag==1){
				value=value*(-1);
			}
			//cout<<"val: "<<value<<endl;
			stringstream ss;
			string s2;
			ss<<value;
			ss>>s2;
			houzhui.push(s2);
			return VAL;
		}
		switch (*expr){
			case '(':++expr;return LKH;
			case ')':++expr;return RKH;
			case '+':++expr;return ADD;
			case '-':{
//				if (doop==1){
//					++expr;flag=1;break;
//				}
//				else {
					++expr;return SUB;
//				}				
			}
			case '*':++expr;return MUL;
			case '/':++expr;return DIV;
			case '^':++expr;return TIM;
		}
	}
	return EOL; 
}
void tmpcal(seqStack<int> &numstack,token tmpop,int &divtmp){
	int tmp2 = numstack.pop();
	int tmp1 = numstack.pop();
	//cout<<tmp1<<" "<<tmp2; 
	string tp2=houzhui.pop();
	string tp1=houzhui.pop();
 
	string ans;
 
	switch(tmpop){
		case ADD:
			ans.append("+");
			numstack.push(tmp1+tmp2);break;
		case SUB:
			ans.append("-");
			numstack.push(tmp1-tmp2);break;
		case MUL:
			ans.append("*");
			numstack.push(tmp1*tmp2);break;
		case DIV:{
			ans.append("/");
			numstack.push(tmp1/tmp2);			
			break;
		}
		case TIM:
			ans.append("^");
			numstack.push(pow(tmp1,tmp2));break;
	}
	ans.append(" ");ans.append(tp1);ans.append(" ");ans.append(tp2);
	//cout<<endl<<"ans: "<<ans;	
	houzhui.push(ans);
}
 
int main(){
    char *expr=new char [10000];
    cin.getline(expr,10000);
 
    //cout<<expr;
    token tmp;
    int divtmp=0;
    seqStack<token> opstack;
    seqStack<int> numstack;
 
    while (1){
	    int value=0;
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
					tmpcal(numstack,tmpop,divtmp);
					tmpop = opstack.pop();
				}
//				if (tmpop!=LKH){
//					cout<<"Error";
//					return 0;
//				}
				break;				
			case TIM:
				opstack.push(TIM);break;
			case MUL:
				while (!opstack.isEmpty() && opstack.top()==TIM){					
					tmpop = opstack.pop();
					tmpcal(numstack,tmpop,divtmp);					
				}
				opstack.push(tmp);
				break;
			case DIV:
				while (!opstack.isEmpty() && opstack.top()==TIM){					
					tmpop = opstack.pop();
					tmpcal(numstack,tmpop,divtmp);				
				}
				opstack.push(tmp);
				break;
			case ADD:case SUB:
				while (!opstack.isEmpty() && opstack.top()!=LKH){
					tmpop = opstack.pop();
					tmpcal(numstack,tmpop,divtmp);					
				}
				opstack.push(tmp);//cout<<": "<<tmp<<endl;				
		}
		//cout<<"op: "<<opstack.top()<<endl;
		//cout<<"nu: "<<numstack.top()<<endl;
	}
 
	while (!opstack.isEmpty()){
		tmpcal(numstack,opstack.pop(),divtmp);
		if (divtmp==-1) return 0;
	}
//	if (numstack.isEmpty()){
//		cout<<"Error";return 0;
//	}
	int ans = numstack.pop();
//	if (!numstack.isEmpty() || !opstack.isEmpty()){
//		cout<<"Error";return 0;
//	}
	string tmpp=houzhui.pop();//cout<<tmpp.substr(0, tmpp.length()-1)<<endl;
	if (& tmpp[tmpp.length()-1]==" ") tmpp=tmpp.substr(0, tmpp.length()-1);
	cout<<tmpp<<endl;
	cout<<ans;
    
}
