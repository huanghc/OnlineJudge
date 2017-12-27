#include <iostream>
using namespace std;
int set[10000]; 
int setnum = 0;
int a,b;
 
struct Node{
	Node *left,*right;  //左子右子 
	int data;
	Node():left(NULL),right (NULL){}
	Node (int item,Node *L=NULL,Node *R=NULL){
		data = item;left=L;right=R;
	}
	~Node() {}
};
Node list[200000];

template<class eType>
class stack
{
	public:
		virtual bool isEmpty() const = 0;
		virtual void push(const eType &x) = 0;
		virtual eType pop() = 0;
		virtual eType top() const = 0;
		virtual ~stack(){} 
 };
 
 template<class eType>
 class linkStack:public stack <eType>
 {	private:
 		struct node{	//链接栈的结点类
		 	eType data;
			node *next;
			node(const eType &x,node *N = NULL)
				{data = x; next = N; }
			node():next(NULL){}
			~node(){} 
		 };
		
		node *elem;
	public:
		linkStack(){elem = NULL;}
		
		~linkStack();
		
		bool isEmpty() const {return elem==NULL;}
 
 		void push(const eType &x){
		 	node *tmp = new node(x,elem);
		 	elem = tmp;				
		 }
		 
		eType pop(){
			node *tmp = elem;
			eType x = tmp -> data;
			elem = elem ->next;
			delete tmp;
			return x;
		}
		
		eType top() const{return elem->data;}
};
 
template <class eType>
linkStack<eType>::~linkStack(){
	node *tmp;
	while(elem!=NULL){
		tmp = elem;
		elem = elem -> next;
		delete tmp;
	}
}
 
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

		
template <class Type>
class BinaryTree{
	private:		
		Node *root;  //根节点 
	
	public:
		BinaryTree():root(NULL){}
		BinaryTree(const Type &x){
			root = new Node(x);
		}
		BinaryTree(Node *P){
			root=P;
		}
		~BinaryTree(){
			//clear();
		}
		
		void makeTree(const Type &x,BinaryTree &lt,BinaryTree &rt){
			root = new Node(x,lt.root,rt.root);
			lt.root = NULL;rt.root = NULL;
		}    //x为根节点，lt,rt为左右子树 
		
		void delLeft(){
			BinaryTree tmp=root->left;
			root->left=NULL;
			tmp.clear();
		} 
		
		void delRight(){
			BinaryTree tmp=root->right;
			root->right=NULL;
			tmp.clear();
		}
		
		bool isEmpty() const {
			return root==NULL;
		}
		
		void clear(){
			if (root!=NULL){
				clear(root);
			}
			root = NULL;
		} 		
		void clear(Node *t){
			if (t->left!=NULL){
				clear(t->left);
			}
			if (t->right!=NULL){
				clear(t->right);
			}
			delete t;
		}		
		bool finds(int t){
			for (int i=0;i<setnum;++i){
				if (set[i]==t){
					return true;
				}
			}
			return false;
		}				
		void postOrder() {
			linkStack <Node *> s1;
			linkStack <int> s2;
			Node *p;
			if (!root) return;
			s1.push(root);
			s2.push(0);
			while (!s1.isEmpty()){
				p = s1.pop();
				int flag = s2.pop();
				if (flag==2){
				//	cout<<p->data<<" ";
					levOrder(p->data);
					//cout<<endl;
					if (finds(a) && finds(b)){
						cout<<p->data;//cout<<" end";
						return;
					}
				}
				if (flag==0){
					s1.push(p);
					s2.push(1);
					if (p->left){
						s1.push(p->left);
						s2.push(0);
					}
				}
				if (flag==1){
					s1.push(p);
					s2.push(2);	
					if (p->right){
						s1.push(p->right);
						s2.push(0);						
					}				
				}
			}
			cout<<endl;			
		}

		void levOrder(int t) const{
			setnum=0; 
			linkQueue <Node *> s;
			Node *current;
			Node *tt = &list[t-1];
			//cout<<tt->data;
			if (!tt) return;
			s.enQueue(tt);
			//cout<<endl<<"start: ";
			while (!s.isEmpty()){
				current = s.deQueue();
				//cout<<current->data<<" ";
				set[setnum] = current->data;
				++setnum;
				if (current->left!=NULL) s.enQueue(current->left);
				if (current->right!=NULL) s.enQueue(current->right);				
			}
			//cout<<endl;			
		}
		void levOrders() const{
			linkQueue <Node *> s;
			Node *current;
			if (!root) return;
			s.enQueue(root);
			while (!s.isEmpty()){
				current = s.deQueue();
				cout<<current->data<<" ";
				if (current->left!=NULL) s.enQueue(current->left);
				if (current->right!=NULL) s.enQueue(current->right);				
			}
			//cout<<endl;			
		}
			
};


int main(){		
	Node * root;
	int flag=0;int sum=0;
	int N;cin>>N;cin>>a>>b;
	//cout<<"dsa: "<<a<<b<<endl;
	for (int i=0;i<N;++i){
		int p,q;
		cin>>p>>q;sum=sum+p+q;
		list[i].data=i+1;
		if (p!=0){
			list[i].left=&list[p-1];
			flag = i;
		}
		if (q!=0){
			list[i].right=&list[q-1];
			flag = i;
		}
	}
	root = &list[N*(N+1)/2-sum-1];
	BinaryTree <int> tree(root);	
	//tree.levOrders();
	tree.postOrder();
		
	return 0;
	
}
