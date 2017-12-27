#include <iostream>
using namespace std;

struct node{
    int data;
    node *next,*prev;
    node():data(0),next(NULL),prev(NULL){}
    node(int a,node *n=NULL,node *p=NULL):data(a),next(n),prev(p){}
};

class seqList{
    friend bool isBigger(const seqList &s1,const seqList &s2);
private:
    node *first, *rear;
    int currentSize;
public:
    seqList(){
        first=new node;
        rear=new node;
        first->next=rear;
        rear->prev=first;
        currentSize=0;
    }
    void insert(int a){
        node *tmp;
        tmp=new node(a,rear,rear->prev);
        rear->prev->next=tmp;
        rear->prev=tmp;
        currentSize++;
    }
    void print(){
        node *t;
        t=first->next;
        if(t==rear){cout << 0;}
        while(t!=rear){
            cout << t->data;
            t=t->next;
        }
    }
    void sub(const seqList &s){
        int carry=0,result;
        bool flag=true;
        node *p1,*p2;
        p1=rear->prev;
        p2=s.rear->prev;
        while(p1!=first&&p2!=s.first){
            result=p1->data+(-1)*p2->data+carry;
            if(result<0){p1->data=10+result;carry=-1;}
            if(result>=0){p1->data=result;;carry=0;}
            p1=p1->prev;
            p2=p2->prev;
        }
        if(p1!=first){
            while(p1!=first){
                result=p1->data+carry;
                if(result<0){p1->data=10+result;carry=-1;}
                if(result>=0){p1->data=result;;carry=0;}
                p1=p1->prev;
            }
        }
        while(first->next->data==0&&first->next!=rear){first=first->next;}
        print();
    }
};

bool isBigger(const seqList &s1,const seqList &s2)
{
    if(s1.currentSize>s2.currentSize){return true;}
    if(s1.currentSize<s2.currentSize){return false;}
    node *tmp1,*tmp2;
    tmp1=s1.first->next;tmp2=s2.first->next;
    while((tmp1->data==tmp2->data)&&tmp1->next!=NULL){tmp1=tmp1->next;tmp2=tmp2->next;}
    if(tmp1==s1.rear){return true;}
    if(tmp1->data>tmp2->data){return true;}
    return false;
}

int main()
{
    char ch;
    seqList list1,list2;
    ch=cin.get();
    while(ch<='9'&&ch>='0'){list1.insert(ch-'0');ch=cin.get();}
    while(!(ch<='9'&&ch>='0')){ch=cin.get();}
    while(ch<='9'&&ch>='0'){list2.insert(ch-'0');ch=cin.get();}
    if(isBigger(list1,list2)) {list1.sub(list2);}
    else{cout <<"-";list2.sub(list1);}
    return 0;
};
