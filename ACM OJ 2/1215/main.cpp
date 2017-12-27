#include <iostream>
using namespace std;

struct node
{
    int data;
    node *son,*brother;
    node():data(0),son(NULL),brother(NULL){}
    node(int d,node *s=NULL,node *b=NULL):data(d),son(s),brother(b){}
};

class Binomial
{
private:
    node **forest;
    node* merge(node *t1,node *t2);
    int findMin();
public:
    Binomial(){
        forest=new node*[200];
        for(int i=0;i<200;++i){forest[i]=NULL;}
    }
    void merge(int a);
    void min();
    void deleteTree();
};

void Binomial::deleteTree()
{
    int p=findMin(),q,r;
    q=0;
    node *tmp=forest[p]->son,*carry;
    forest[p]=NULL;
    while(q<p){
        carry=tmp;
        tmp=tmp->brother;
        carry->brother=NULL;
        r=q;
        while(1){
            if(forest[r]==NULL){forest[r]=carry;break;}
            else{
                carry=merge(forest[r],carry);
                forest[r]=NULL;
            }
            r++;
        }

        q++;
    }
}

void Binomial::min()
{
    int i=findMin();
    cout << forest[i]->data << endl;
}

int Binomial::findMin()
{
    int Min=-1000;
    int ID=0;;
    for(int i=0;i<200;++i)
    {
        if(forest[i]!=NULL){
            if(forest[i]->data<Min||Min==-1000){ID=i;Min=forest[i]->data;}
        }
    }
    return ID;
}

void Binomial::merge(int a)
{
    node *carry;
    carry=new node(a);
    int i=0;
    while(1){
        if(forest[i]==NULL){forest[i]=carry;break;}
        else{
            carry=merge(forest[i],carry);
            forest[i]=NULL;
        }
        i++;
    }
}

node* Binomial::merge(node *t1,node *t2)
{
    node *min,*max;
    if(t1->data>t2->data){min=t2;max=t1;}
    else{min=t1;max=t2;}
    if(min->son==NULL){min->son=max;}
    else{
        node *b=min->son;
        while(b->brother!=NULL){b=b->brother;}
        b->brother=max;
    }
    return min;
}

int main()
{
    int num,tmp;
    char ch[20];
    cin >> num;
    Binomial b1;
    while(num>0)
    {
        cin >> ch;
        if(ch[0]=='i') {cin >>tmp;b1.merge(tmp);}
        if(ch[0]=='m') {b1.min();}
        if(ch[0]=='d') {b1.deleteTree();}
        num--;
    }
    return 0;
}
