#include <iostream>
using namespace std;
int M;int ans=0;
template <class TypeOfEdge>
class graph {
	public:
		virtual bool insert(int u, int v, TypeOfEdge w) = 0;
		virtual bool remove(int u, int v) = 0;
		virtual bool exist(int u, int v) const = 0;
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
		void dfs(int start) const;
		void dfs(int start, bool *visited,int num) const;
	
		int Vers, Edges;	
	private:
        struct edgeNode {//邻接表中存储边的结点类
			int end; //终点编号
			TypeOfEdge weight;  //边的权值
			edgeNode *next;
			edgeNode(int e, TypeOfEdge w, edgeNode *n = NULL) 
				{ end = e; weight = w; next = n;}
		};
		struct verNode{ //保存顶点的数据元素类型
			TypeOfVer ver;  //顶点值
			edgeNode *head;  //对应的单链表的头指针
			verNode( edgeNode *h = NULL)  { head = h ;}
		};
		verNode *verList;
}; 
template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::adjListGraph(int vSize, const TypeOfVer d[]){
	Vers = vSize;Edges = 0;
	verList = new verNode[vSize];
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
}                      //不太一样，看看对不对 
template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(int u, int v) const{ 
    edgeNode *p = verList[u].head;
    while (p !=NULL && p->end != v) p = p->next;
    if (p == NULL) return false; else  return true;
} 
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start) const{
	bool *visited = new bool[Vers];
	for (int i=0;i<Vers;++i){
		visited[i] = false;
	}	
	int num=0;
	dfs(start-1,visited,num);
	//cout<<"num: "<<num;
}
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start, bool *visited,int num) const{
	edgeNode *p=verList[start].head;
	//cout<<verList[start].ver<<" ";
	visited[start] = true;
	num=num+1;//cout<<"num: "<<num<<endl;
	if (num == M+1) { ++ans; visited[start] = false; return; }
	while (p!=NULL){
		if (!visited[p->end]){
			dfs(p->end,visited,num);
		}
		p=p->next;
	} 
	visited[start] = false;
}

int main(){
	int n,m,start;cin>>n>>m>>start>>M;
	int a,b;
	int d[n];
	for (int i=0;i<n;++i){
		d[i] = i+1;
	}
	adjListGraph<int,int> G(n,d);
	for (int i=0;i<m;++i){
		cin>>a>>b;
		G.insert(a-1,b-1,1);
	}
	G.dfs(start);
	cout<<ans;	
}
