#include <iostream>
#include <cstring>
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
 
seqStack<char> seqF;
seqStack<int> seqI;   

int cal(string str){
	for (int i=0; i<str.length(); ++i){
		if (str[i] == ' '){++i;}
		if (str[i] == '('){
			seqF.push(str[i]);
		}
		if (str[i] == '+' ){
			seqF.push(str[i]);
		}
		if (str[i] =='-'){
			seqF.push('+');++i;
			while (str[i] == ' ') ++i;
			int tmp = str[i] - '0';
			seqI.push(-tmp);
		}
		else if (str[i] >= '0' and str[i] <= '9'){
			int t = str[i] - '0';
			seqI.push(t);
		}
		if (str[i] == ')'){
			while (1){
				char fuhao = seqF.pop();
				if (fuhao == '('){
					break;
				}
				int a = seqI.pop();
				int b = seqI.pop();
				seqI.push(a+b);
//				cout<<seqI.top()<<endl;
			}
		}
	}
	while (!seqF.isEmpty()){
		char fuhao = seqF.pop();
		int a = seqI.pop();
		int b = seqI.pop();
//		cout<<a<<" + "<<b<<" = "<<a+b;
		seqI.push(a+b);
	}

	return seqI.pop();
}
int main(){
	 string str = "(1 + (4 + 5 + 2) - 3)+(6+8)";
	 cout<<cal(str);
}
