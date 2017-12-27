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
		node():next(NULL) {}
	    ~node() {}
	}; //有2个构造函数
    node *head;
	

    linkList(){
    	head=new node;
	}
    ~linkList()  {clear();delete head;}
    int length() const ;
    int search(const elemType &x) const ;
    elemType visit(int i) const;
    void insert(int i, const elemType &x); 
    void remove(int i);  
    void clear();
    void traverse() const ;
    linkList add(int len,linkList &x); 
    void insertlist(int len,char x[]);
};

template <class elemType>
linkList<elemType> linkList<elemType>::add(int len,linkList <elemType> &x){
	node *p = head->next,*q = x.head->next,*s;
	linkList<int> tmplist;
	node *t = tmplist.head->next;
	int tmp2=0;
	for(int i=0;i<len;++i){
		int tmp=int(p->data)+int(q->data)+tmp2;		
		tmp2=tmp/10;//cout<<"tmp "<<tmp-tmp2*10<<endl;
		s=new node(tmp-tmp2*10,t);
		t=s;p=p->next;q=q->next;		
	}
	if (tmp2!=0){
		s=new node(tmp2,t);
		t=s;
	}
	tmplist.head->next=t;
//	for (int i=0;i<tmplist.length();++i){
//		cout<<tmplist.visit(i);
//	}
	tmplist.traverse();
	
	return tmplist;		
}


template <class elemType>
int linkList <elemType> :: length() const{
	node *p = head->next;int len=0;
	while (p){
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
 
template <class elemType>
void linkList <elemType> :: insertlist(int len,char x[]){
	node *p=head,*q;int j=0;
	for (int i=0;i<len;++i){
		q=new node(int(x[len-1-i])-'0',p->next);
		p->next=q;			
		p=p->next;
	}
} 
 
int main(){	
	int n;
	
	linkList<int> chlist1;
	linkList<int> chlist2;
	linkList<int> chlist3;
	
	char s1[1000000],s2[1000000]; 
	cin.getline(s1,1000000,'\n');
	cin.getline(s2,1000000,'\n');
	
	int len1=strlen(s1);
	int len2=strlen(s2);
	int len = 0;
	
	
	chlist1.insertlist(len1,s1);
	chlist2.insertlist(len2,s2);
	
	if (len1>len2){
		len=len1;
		for (int i=len2;i<len1;++i){
			chlist2.insert(i,0);
		}
	}
	else{
		len=len2;
		for (int i=len1;i<len2;++i){
			chlist1.insert(i,0);
		}		
	} 
	
	//chlist1.traverse();cout<<endl;chlist2.traverse();cout<<endl;
 
	chlist1.add(len,chlist2);
		
}
