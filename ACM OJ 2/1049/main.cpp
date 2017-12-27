#include <iostream>

class linkStack
{
private:
    struct node{
        int data;
        node *next;
        node():data(0),next(NULL){}
        node(int d, node* n=NULL):data(d),next(n){}
        ~node(){}
    };
    node *elem;
    int size;
public:
    linkStack(){elem=NULL;size=0;}
    bool isEmpty(){return elem==NULL;}
    int top(){return elem->data;}
    void push(const int &x){node* tmp=new node(x,elem);elem=tmp;size++;}
    int pop(){
        node *tmp=elem;
        int x=tmp->data;
        elem=elem->next;
        delete tmp;
        size--;
        return x;
    }
    int deepth(){return size;}
};

using namespace std;

int main()
{
    int times,number,capacity,p=0,q=0,No,tmp;
    int i;
    bool flag;
    cin >> times;
    linkStack stack[times];
    while(q<times)
    {
        cin >> number >> capacity;
        p=0;
        tmp=0;
        flag=true;
        while(p<number){
            cin >> No;
            if(flag==false){p++;continue;}
            if(tmp==No){tmp++;p++;continue;}
                else if(tmp>No){
                    if(!stack[q].isEmpty()&&stack[q].top()==No){stack[q].pop();p++;continue;}
                    else{flag=false;p++;continue;}
                }
                        else if(tmp<No){
                            for(i=tmp;i<No;i++){stack[q].push(i);tmp++;}
                            if(stack[q].deepth()>capacity){flag=false;p++;continue;}
                            tmp++;
                        }
            p++;
        }
        if(flag==true){cout << "YES" << endl;}
        if(flag==false){cout << "NO" << endl;}
        q++;
    }
    return 0;
}
