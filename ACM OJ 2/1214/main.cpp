#include <iostream>

using namespace std;

template<class T>
class linkQueue
{private:
    struct node{
        T data;
        node *next;
        node(const T &x,node *N=NULL){data=x;next=N;}
        node():next(NULL){}
        ~node(){}
    };
    node *front,*rear;
public:
    linkQueue(){front=rear=NULL;}
    ~linkQueue();
    bool isEmpty(){return front==NULL;}
    void enQueue(const T &x);
    T deQueue();
    T getHead(){return front->data;}
};

template<class T>
void linkQueue<T>::enQueue(const T &x)
{
    if(rear==NULL) {front=rear=new node(x);}
    else{rear->next=new node(x);rear=rear->next;}
}

template<class T>
linkQueue<T>::~linkQueue()
{
    node *tmp;
    while(front!=NULL)
    {
        tmp=front;
        front=front->next;
        delete tmp;
    }
}

template<class T>
T linkQueue<T>::deQueue()
{
    T value=front->data;
    front=front->next;
    if(front==NULL) front=rear=NULL;
    return value;
}

struct Node{
    Node *left,*bro;
    int data;
    Node():left(NULL),bro(NULL),data(0){}
    Node(int item, Node *l=NULL,Node *r=NULL):data(item),left(l),bro(r){}
    ~Node(){}
};

class BinaryTree{
private:
    Node *root;
public:
    BinaryTree():root(NULL){}
    BinaryTree(Node *s):root(s){}
    void depthTraverse();
    void preOrder()const{
        if(root!=NULL) preOrder(root);
    }
    void postOrder()const{
        if(root!=NULL) postOrder(root);
    }
private:
    void preOrder(Node *n)const{
        if(n!=NULL){
            cout << n->data << " ";
            preOrder(n->left);
            preOrder(n->bro);
        }
    }
    void postOrder(Node *n)const{
        if(n!=NULL){
            postOrder(n->left);
            cout << n->data << " ";
            postOrder(n->bro);
        }
    }
};

void BinaryTree::depthTraverse()
{
    linkQueue<Node *> queue;
    Node *cur;
    if(root==NULL) return;
    queue.enQueue(root);
    while(!queue.isEmpty())
    {
        cur=queue.deQueue();
        cout << cur->data <<" ";
        if(cur->left!=NULL){
            queue.enQueue(cur->left);
            cur=cur->left;
            while(cur->bro!=NULL){
                queue.enQueue(cur->bro);
                cur=cur->bro;
            }
        }
    }
}

int main()
{
    int num,p=0,sum=0,root_number;
    cin >> num;
    int nodelist[num][3];
    Node list[num],*rt;
    while(p<num)
    {
        cin >> nodelist[p][0] >> nodelist[p][1] >> nodelist[p][2];
        list[p].data=nodelist[p][2];
        if(nodelist[p][0]!=0) list[p].left=&list[nodelist[p][0]-1];
        if(nodelist[p][1]!=0) list[p].bro=&list[nodelist[p][1]-1];
        sum=sum+nodelist[p][0]+nodelist[p][1];
        p++;
    }
    root_number=(num+1)*num/2-sum;
    rt=&list[root_number-1];

    BinaryTree tree(rt);

    tree.preOrder();cout << endl;
    tree.postOrder();cout << endl;
    tree.depthTraverse();

    return 0;
}
