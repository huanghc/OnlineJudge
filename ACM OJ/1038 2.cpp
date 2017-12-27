#include <iostream>
#include <cstring>
using namespace std;
 
class OutOfBound{};
class IllegalSize{};
template <class elemType>
class linkList{
public:
    struct node{
    	elemType data;
    	node *next;
   		node(const elemType &x, node *p=NULL){
    		data=x;
    		next=p;
		}
		node(){
			next = NULL; 
		}
	    ~node() {}
	}; 
    node *head;
	
    linkList(){
    	head=new node;
    	head->next = head;
	}
    ~linkList()  {clear();delete head;}
    int length() const ;
    int search(const elemType &x) const ;
    elemType visit(int i) const;
    void insert(int i, const elemType &x); 
    void remove(int i);  
    void clear();
    void traverse() const ;
};

template <class elemType>
int linkList <elemType> :: length() const{
	node *p = head;int len=0;
	while (p->next!=head){
		++len;
		p=p->next;
	}
	return len;
}
 
template <class elemType>
int linkList <elemType> :: search(const elemType &x) const{
	node *p=head;int j=0;
	while (p){
		if (p->data==x) return j;
		j+=1;
		p=p->next;		
	}
	return -1;
} 
 
template <class elemType>
elemType linkList <elemType> :: visit(int i) const{
	if (i<0) throw OutOfBound();
	node *p=head->next;int j=0;
	while(p){
		if (j==i){
			return p->data;
		}
		p=p->next;
		j++;
	}
	if (!p) throw OutOfBound();
}
 
template <class elemType>
void linkList <elemType> :: insert(int i, const elemType &x){
	node *p=head,*q;int j=0;
	if (i<0) throw OutOfBound();
	while(p){
		if (i==j){
			q=new node(x,p->next);
			p->next=q;			
		}
		j++;
		p=p->next;
	}
}
 
template <class elemType>
void linkList <elemType> :: remove(int i){
	if (i<0) throw OutOfBound();
	node *p=head;int j=0;
	while(p){
		if (j==i-1){
			p->next=p->next->next;
			delete p->next;
		}
		j++;
		p=p->next; 
	}
}
 
template <class elemType>
void linkList <elemType> :: clear(){
	node *p=head->next,*q;
	while(p){
		q=p->next;
		delete p;
		p=q;		
	}
	head->next=NULL;
}
 
template <class elemType>
void linkList <elemType> :: traverse() const{
	node *p=head->next;
	while (p){
		cout<<(p->data);
		p=p->next;
	}
}
 
int main(){
    int K[10000]={0};
    int n,i,ans = 0;
    cin>>n;
    for (i=0;i<n-1;++i){
        cin>>K[i];
    }
    linkList<int> monk;
    for (i=0;i<n;++i){
    	monk.insert(i,i);
	}
	for (i=0;i<n-1;++i){
		monk.remove((K[i]+n)%n);
	}
	monk.traverse();
//    for (i=2;i<=n;++i){   
//        ans = (ans+K[n-i+1]) % i;      
//    }    
//    cout<<ans+1;
    return 0;
}
