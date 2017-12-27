#include <iostream>
using namespace std;
 
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
		
		bool isEmpty() const {return elem==NULL;	}
 
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
		
		eType top() const{return elem->data;	}
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
		struct Node{
			Node *left,*right;  //左子右子 
			Type data;
			Node():left(NULL),right (NULL){}
			Node (Type item,Node *L=NULL,Node *R=NULL){
				data = item;left=L;right=R;
			}
			~Node() {}
		};
		
		Node *root;  //根节点 
	
	public:
		BinaryTree():root(NULL){}
		BinaryTree(const Type &x){
			root = new Node(x);
		}
		BinaryTree(const Node *P){
			root=P;
		}
		~BinaryTree(){
			clear();
		}
		
		Type getRoot() const{return root->data;}
		Type getLeft() const{return root->left->data;}
		Type getRight() const{return root->right->data;} 
		
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
		
		int size() const {return size(root);}
		int size(Node *t) const{
			if (t==NULL) return 0;
			return size(t->left)+size(t->right)+1;
		}
		
		int height() const {return height(root);}
		int height(Node *t) const {
			if (t==NULL) return 0;
			int lt=height(t->left);
			int rt=height(t->right);
			return 1+((lt>rt)? lt:rt);
		}
		
		void preOrder() const{
			linkStack <Node *> s;
			Node *current;
			if (!root) return;
			s.push(root);
			while (!s.isEmpty()){
				current = s.pop();
				cout<<current->data<<" ";
				if (current->right!=NULL) s.push(current->right);
				if (current->left!=NULL) s.push(current->left);
			}
			cout<<endl;			
		}
		
		void postOrder() const{
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
					cout<<p->data<<" ";
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
		
		void midOrder() const{
			linkStack <Node *> s;
			Node *p;
			if (!root) return;
			s.push(root);
			p=root->left;
			while (p){
				s.push(p);
				p=p->left;
			}
			while (!s.isEmpty()){
				p = s.pop();
				cout<<p->data<<" ";
				if (p->right){
					p=p->right;
					s.push(p);
					while(p->left){
						s.push(p->left);
						p=p->left;
					}
				}
			}
			cout<<endl;	
		}
		
		void createTree(Type flag){ //flag=???
			linkQueue<Node *> que;
			Node *tmp;
			Type x,ldata,rdata;
			cin>>x;//输入根节点
			root = new Node(x);
			que.enQueue(root);
			
			while(!que.isEmpty()){
				tmp=que.deQueue();
				cin>>ldata>>rdata;//输入左右data？？flag?? 
				if (ldata!=flag){
					que.enQueue(tmp->left = new Node(ldata));
				}
				if (rdata!=flag){
					que.enQueue(tmp->right = new Node(rdata));
				}
			} 			
		}
			
};
//BinaryTree() BinaryTree(const Type &x) BinaryTree(const Node *P)
//getRoot() getLeft() getRight()
//makeTree(const Type &x,BinaryTree &lt,BinaryTree &rt)
//delLeft() delRight() clear()
//isEmpty() size() height()
//preOrder() postOrder() midOrder()

int main(){
	BinaryTree <char> tree,tree1('M'),tree2;
	tree.createTree('@');
	cout<<tree.height()<<endl;
	cout<<tree.size()<<endl;
	tree.preOrder();
	tree.midOrder();
	tree.postOrder();
	
	tree2.makeTree('Y',tree,tree1);
	cout<<tree2.height()<<endl;
	cout<<tree2.size()<<endl;
	tree2.preOrder();
	tree2.midOrder();
	tree2.postOrder();
	
	return 0;
	
}

