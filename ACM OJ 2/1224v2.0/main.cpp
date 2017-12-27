#include <iostream>
#include <cstdlib>

using namespace std;

class openHashTable{
private:
    struct node{
        int data;
        int times;
        node *next;
        node():data(0),times(0),next(NULL){}
        node(int d,int t=1,node *n=NULL):data(d),times(t),next(n){}
    };
    node **array;
    int size;
    int (*key)(int &x);
public:
    openHashTable(int length,int (*f)(int &x));
    int find(int x);
    void insert(int x);
};

openHashTable::openHashTable(int length,int (*f)(int &x))
{
    size=length;
    array=new node*[size];
    key=f;
    for(int i=0;i<size;i++){array[i]=new node;}
}

void openHashTable::insert(int x)
{
    int pos;
    pos=abs(key(x)%size);
    node *tmp,*p=array[pos];
    while(p->next!=NULL){
        if(p->data==x){break;}
        p=p->next;
    }
    if(p->next==NULL){
        tmp=array[pos];
        array[pos]=new node(x);
        array[pos]->next=tmp;
    }
    else{p->times++;}
}

int openHashTable::find(int x)
{
    int pos,num=0;
    pos=abs(key(x)%size);
    node *p;
    p=array[pos];
    while(p->next!=NULL){
        if(p->data==x){num+=p->times;break;}
        p=p->next;
    }
    return num;
}

int myHash(int &x)
{
    return x;
}

int main()
{
    int num,a=0,sum=0;
    cin >> num;
    int A[num],B[num],C[num],D[num];
    while(a<num){
        cin >> A[a];cin >> B[a];
        cin >> C[a];cin >> D[a];
        a++;
    }
    openHashTable hash(3997,myHash);
    for(int i=0;i<num;++i){
        for(int j=0;j<num;++j){
            hash.insert(A[i]+B[j]);
        }
    }
    for(int p=0;p<num;++p){
        for(int q=0;q<num;++q){
            sum+=hash.find(-(C[p]+D[q]));
        }
    }
    cout << sum << endl;
    return 0;
}
