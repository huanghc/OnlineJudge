#include <iostream>
using namespace std;

template <class elemType>
class linkStack{
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
		int nodes;
		linkStack(){
			elem = NULL;
			nodes = 0;
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
			++nodes;			
		}
		void dele(elemType &x){
			//cout<<"xdel£º"<<x<<endl; 
			node *tmp = elem;
			if (elem){
				if (tmp->data == x){
					elem = elem->next;
				} 
				while (tmp->next){
					node *tmp2 = tmp->next;
					if (tmp2->data == x){
						tmp->next = tmp2->next;
						nodes -=1;
						//cout<<"nodes: "<<nodes<<endl;
						break;
					}
					else {
						tmp = tmp2;
					}				 
				}
			}
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

template <class Type>
class priorityQueue{
	private:
		int currentSize;
		Type *array;
		int maxSize;
		
	public:
		priorityQueue(int capacity = 100000){
			array = new Type[capacity];
			maxSize = capacity;
			currentSize = 0;
		}
		~priorityQueue(){
			delete [] array;
		}
		
		void doubleSpace(){
			Type *tmp=new Type[maxSize*2];
			for (int j = 0; j < currentSize; ++j)  tmp[j] = array[j];
			delete []array;  
			array = tmp; 
		    maxSize = maxSize*2;
		}
		
		bool isEmpty() const {
			return currentSize==0;
		}
		void enQueue(const Type &x){
			if (currentSize==maxSize-1){
				doubleSpace();
			}
			
			int hole = ++currentSize;
			for (;hole>1 && x<array[hole/2];hole/=2){
				array[hole] =array[hole/2];
			}
			array[hole] = x;
		}
		
		Type deQueue(){
			Type minItem;
			minItem = array[1];
			array[1] = array[currentSize--];
			percolateDown(1);
			return minItem;
		}
		
		Type getHead() const {
			return array[1];
		}
		
		void buildHeap(){
			for (int i=currentSize/2;i>0;i--){
				percolateDown();
			}
		}

		void percolateDown(int hole){
			int child;
			Type tmp = array[hole];
			for (;hole*2<=currentSize;hole=child){
				child = hole*2;
				if (child!=currentSize && array[child+1]<array[child]){
					child++;
				}
				if (array[child]<tmp){
					array[hole] = array[child];
				}
				else {
					break;
				}
			}
			array[hole] = tmp;
		}
}; 

linkStack<int> tree[150000];
int tst[150000]={0};
	
int main(){
	linkStack <int> s;
	linkStack <int> input;
	string st;
	getline(cin,st);
	int p=0;
	int tnum = 0;
	priorityQueue <int> pq;
	
	while(p<st.length()){
		//cout<<st[p]<<" ";
		if (st[p]=='(' || st[p]==' '){
			++p;
			continue;
		}
		if (st[p]>='0' && st[p]<='9'){
			char tmp;
			int num = st[p]-'0';
			while (p<st.length()){
				++p;				
				if (!(st[p]>='0' && st[p]<='9')){
					p = p-1;
					break;
				}
				num = num*10+st[p]-'0';									
			}
			input.push(num);
			tst[tnum] = num;
			++tnum;
			//cout<<num;
		}
		if (st[p] == ')'){
			int num1=0,num2=0;
			if (!input.isEmpty()){
				num1 = input.pop();
			}
			else{
				break;
			}
			if (!input.isEmpty()){
				num2 = input.pop();
			}
			else{
				break;
			}
			//tree[num1].linkStack();
			tree[num1].push(num2);
			tree[num2].push(num1);
			input.push(num2);			
		}		
		++p;		
	}
	
	for (int i=0;i<tnum;++i){	
		if (tree[tst[i]].nodes==1){
			//cout<<"a: "<<tst[i]<<endl;
			pq.enQueue(tst[i]);
		}
	}
	
	for (int i=0;i<tnum-1;++i){
		int x = pq.deQueue();
		//cout<<"x: "<<x<<endl;
		if (i>0) cout<<" ";
		int tmp=tree[x].pop();
		cout<<tmp;
		tree[tmp].dele(x);
		//cout<<"yes"<<endl;
		if (tree[tmp].nodes==1){
			if (!pq.isEmpty()){
				pq.enQueue(tmp);
			} 			
		}		
	}
	//cout<<"end"<<endl;
}
