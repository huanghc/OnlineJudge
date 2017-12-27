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

class BinaryTree{
private:
    struct Node{
        Node *left,*right;
        int data;
        Node():left(NULL),right(NULL),data(0){}
        Node(int item, Node *l=NULL,Node *r=NULL):data(item),left(l),right(r){}
        ~Node(){}
    };
    Node *root;
public:
    BinaryTree():root(NULL){}
    BinaryTree(const int &value){root=new Node(value);}
    void depthTraverse();
};

void BinaryTree::depthTraverse()
{
    int num,p=0,sum=0,root_number;
    cin >> num;
    int nodelist[num][3];
    Node list[num];
    while(p<num)
    {
        cin >> nodelist[p][0] >> nodelist[p][1] >> nodelist[p][2];
        list[p].data=nodelist[p][2];
        if(nodelist[p][0]!=0) list[p].left=&list[nodelist[p][0]-1];
        if(nodelist[p][0]==0) list[p].left=NULL;
        if(nodelist[p][1]!=0) list[p].right=&list[nodelist[p][1]-1];
        if(nodelist[p][1]==0) list[p].right=NULL;
        sum=sum+nodelist[p][0]+nodelist[p][1];
        p++;
    }
    root_number=(num+1)*num/2-sum;
    root=&list[root_number-1];


    linkQueue<Node *> queue;
    Node *cur;
    if(root==NULL) return;
    queue.enQueue(root);
    while(!queue.isEmpty())
    {
        cur=queue.deQueue();
        if(cur->left!=NULL){
            queue.enQueue(cur->left);
        }
        if(cur->right!=NULL){
            queue.enQueue(cur->right);
        }
        cout << cur->data <<" ";
    }
}

int main()
{
    BinaryTree tree;
    tree.depthTraverse();
    return 0;
}
