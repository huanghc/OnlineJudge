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

bool checkEqual(Node *n1,Node *n2)
{
    if(n1==NULL&&n2==NULL) return true;
    if(n1==NULL||n2==NULL) return false;
    if(n1!=NULL&&n2!=NULL)
    {
        if(n1->data!=n2->data) return false;
        return checkEqual(n1->left,n2->left)&&checkEqual(n1->right,n2->right);
    }
}

class BinaryTree{
    friend bool operator==(const BinaryTree &t1,const BinaryTree &t2);
private:
    Node *root;
public:
    BinaryTree():root(NULL){}
    BinaryTree(Node *s):root(s){}
    BinaryTree(const int &value){root=new Node(value);}
    bool checkEqual(Node *n1,Node *n2);
};

bool operator==(const BinaryTree &t1,const BinaryTree &t2)
{
    return checkEqual(t1.root,t2.root);
}

int main()
{
    int num1,p1=0,sum1=0,root_number1;
    cin >> num1;
    int nodelist1[num1][3];
    Node list1[num1],*rt1;
    while(p1<num1)
    {
        cin >> nodelist1[p1][0] >> nodelist1[p1][1] >> nodelist1[p1][2];
        list1[p1].data=nodelist1[p1][2];
        if(nodelist1[p1][0]!=0) list1[p1].left=&list1[nodelist1[p1][0]-1];
        if(nodelist1[p1][1]!=0) list1[p1].right=&list1[nodelist1[p1][1]-1];
        sum1=sum1+nodelist1[p1][0]+nodelist1[p1][1];
        p1++;
    }
    root_number1=(num1+1)*num1/2-sum1;
    rt1=&list1[root_number1-1];
    BinaryTree tree1(rt1);

    int num2,p2=0,sum2=0,root_number2;
    cin >> num2;
    int nodelist2[num2][3];
    Node list2[num2],*rt2;
    while(p2<num2)
    {
        cin >> nodelist2[p2][0] >> nodelist2[p2][1] >> nodelist2[p2][2];
        list2[p2].data=nodelist2[p2][2];
        if(nodelist2[p2][0]!=0) list2[p2].left=&list2[nodelist2[p2][0]-1];
        if(nodelist2[p2][1]!=0) list2[p2].right=&list2[nodelist2[p2][1]-1];
        sum2=sum2+nodelist2[p2][0]+nodelist2[p2][1];
        p2++;
    }
    root_number2=(num2+1)*num2/2-sum2;
    rt2=&list2[root_number2-1];
    BinaryTree tree2(rt2);

    if(tree1==tree2) {cout << "Y";}
    else{cout << "N";}
    return 0;
}
