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
template <class TypeOfEdge>
class graph {
	public:
		virtual bool insert(int u, int v, TypeOfEdge w) = 0;
		virtual bool remove(int u, int v) = 0;
		virtual bool exist(int u, int v) const = 0;
		virtual numOfVer() const {return Vers;}
		virtual numOfEdge() const {return Edges;}
	protected:
		int Vers, Edges;
}; 
template <class TypeOfVer, class TypeOfEdge>
class adjListGraph:public graph<TypeOfEdge> {
    public:
        adjListGraph(int vSize, const TypeOfVer d[]);
		bool insert(int u, int v, TypeOfEdge w);
		bool remove(int u, int v);
		bool exist(int u, int v) const;
		~adjListGraph() ;
		void dfs() const;
		void dfs(int start, bool *visited) const;
		void bfs() const;
	
		int Vers, Edges;	
	private:
        struct edgeNode {//�ڽӱ��д洢�ߵĽ����
			int end; //�յ���
			TypeOfEdge weight;  //�ߵ�Ȩֵ
			edgeNode *next;
			edgeNode(int e, TypeOfEdge w, edgeNode *n = NULL) 
				{ end = e; weight = w; next = n;}
		};
		struct verNode{ //���涥�������Ԫ������
			TypeOfVer ver;  //����ֵ
			edgeNode *head;  //��Ӧ�ĵ������ͷָ��
			verNode( edgeNode *h = NULL)  { head = h ;}
		};
		verNode *verList;
}; 
template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::adjListGraph(int vSize, const TypeOfVer d[]){
	Vers = vSize;Edges = 0;
	verList = new TypeOfVer[vSize];
	for (int i=0;i<vSize;++i){
		verList[i].ver = d[i];
	} 
}
template <class TypeOfVer,class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::~adjListGraph(){
	Vers = 0;Edges = 0;	
	for (int i=0;i<Vers;++i){
		edgeNode *tmp=verList[i].head;
		edgeNode *t2;
		while(tmp!=NULL){
			t2 = tmp;
			tmp=tmp->next;
			delete t2;
		}
	}
	delete []verList;
}
template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::insert(int u, int v, TypeOfEdge w){
   verList[u].head = new edgeNode(v, w, verList[u].head );
    ++Edges;
   return true;
}
template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::remove(int u, int v){
	edgeNode *tmp = verList[u].head,*q;
	if (tmp==NULL) return false;

	q=tmp;
	while(tmp!=NULL){
		if (tmp->end==v){
			tmp=tmp->next;
			delete q;
			--Edges;
			return true;
		}
		else{
			tmp=tmp->next;
			q=tmp;
		}
	}
	return false;
}                      //��̫һ���������Բ��� 
template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(int u, int v) const{ 
    edgeNode *p = verList[u].head;
    while (p !=NULL && p->end != v) p = p->next;
    if (p == NULL) return false; else  return true;
} 
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs() const{
	bool *visited = new bool[Vers];
	for (int i=0;i<Vers;++i){
		visited[i] = false;
	}
	for (int i=0;i<Vers;++i){
		if (!visited[i]){
			dfs(i,visited);
			cout<<endl;
		}
	}
}
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start, bool *visited) const{
	edgeNode *p=verList[start].head;
	cout<<verList[start].ver<<" ";
	visited[start] = true;

	while (p!=NULL){
		if (!visited[p->end]){
			dfs(p->end,visited);
		}
		p=p->next;
	} 
}
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::bfs() const{
	bool *visited = new bool[Vers];
	for (int i=0;i<Vers;++i){
		visited[i] = false;
	}
	linkQueue<int> q;
	for (int i=0;i<Vers;++i){
		if (visited[i]==1) continue;
		q.enQueue(i);
		while (!q.isEmpty()){
			int tmp = q.deQueue();
			if (visited[tmp]==1) continue;			
			cout<<verList[tmp]->ver<<" ";
			visited[tmp] = 1;
			edgeNode *p = verList[tmp]->head;
			while(p!=NULL){
				if (visited[p->end]==0) q.enQueue(p->end);
				p=p->next;
				
			}
		}
		cout<<endl;
	}
}
int main(){
	cout<<2<<endl;
}
