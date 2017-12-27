#include <iostream>
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

struct Node{
	Node *left,*right;  //左子右子 
	int data;
	Node():left(NULL),right (NULL){}
	Node (int item,Node *L=NULL,Node *R=NULL){
		data = item;left=L;right=R;
	}
	~Node() {}
};

template <class Type>
class BinaryTree{
	private:		
		Node *root;  //根节点 	
	public:
		BinaryTree(){
			root = NULL;
		}
		
		BinaryTree(const Type &x){
			root = new Node(x);
		}
		BinaryTree(Node *P){
			root = P;
		}
		~BinaryTree(){
			
		}
		
		bool isCBT(){
			linkQueue <Node *> que;
			linkQueue <int> qnum;
			Node * cur,child;
			int count = 1;
			int last = 1;
			
			if (root==NULL) return true;
			cur = root;
			que.enQueue(cur);
			qnum.enQueue(1);
			while (!que.isEmpty()){
				cur = que.deQueue();
				int t = qnum.deQueue();
				if (cur->left!=NULL){
					++count;
					que.enQueue(cur->left);
					qnum.enQueue(2*t);
					last = 2*t;
				}
				if (cur->right!=NULL){
					++count;
					que.enQueue(cur->right);
					qnum.enQueue(2*t+1);
					last = 2*t+1;
				}
			}
			return count==last;
		} 
};

Node list[200000];
int main(){		
	Node * root;
	int flag=0;int sum=0;
	int N;cin>>N;
	for (int i=0;i<N;++i){
		int p,q;
		cin>>p>>q;sum=sum+p+q;
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
	
	if (tree.isCBT()){
		cout<<"Y";
	}
	else {
		cout<<"N";
	}
	return 0;
}

