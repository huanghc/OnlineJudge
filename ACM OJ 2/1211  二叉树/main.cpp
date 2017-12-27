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
    Node *left,*right;
    int data;
    Node():left(NULL),right(NULL),data(0){}
    Node(int item, Node *l=NULL,Node *r=NULL):data(item),left(l),right(r){}
    ~Node(){}
};

class BinaryTree{
private:
    Node *root;
public:
    BinaryTree():root(NULL){}
    BinaryTree(Node *s):root(s){}
    BinaryTree(const int &value){root=new Node(value);}
    void isCompleteTree();
};

void BinaryTree::isCompleteTree()
{
    linkQueue<Node *> queue;
    Node *cur;
    int count=1,last=1;
    if(root==NULL) return;
    root->data=1;
    queue.enQueue(root);
    while(!queue.isEmpty())
    {
        cur=queue.deQueue();
        if(cur->left!=NULL){
            ++count;
            last=cur->left->data=(cur->data)*2;
            queue.enQueue(cur->left);
        }
        if(cur->right!=NULL){
            ++count;
            last=cur->right->data=(cur->data)*2+1;
            queue.enQueue(cur->right);
        }
    }
    if(count==last) cout << "Y";
    if(count!=last) cout << "N";
}

int main()
{
    int num,p=0,sum=0,root_number;
    cin >> num;
    int nodelist[num][2];
    Node list[num],*rt;
    while(p<num)
    {
        cin >> nodelist[p][0] >> nodelist[p][1];
        list[p].data=0;
        if(nodelist[p][0]!=0) list[p].left=&list[nodelist[p][0]-1];
        if(nodelist[p][1]!=0) list[p].right=&list[nodelist[p][1]-1];
        sum=sum+nodelist[p][0]+nodelist[p][1];
        p++;
    }
    root_number=(num+1)*num/2-sum;
    rt=&list[root_number-1];

    BinaryTree tree(rt);
    tree.isCompleteTree();
    return 0;
}
