#include <iostream>
#include <cstring>

using namespace std;

class BinarySearchTree{
private:
    struct node{
        int data;
        node *left,*right;
        node(int d,node *l=NULL,node *r=NULL):data(d),left(l),right(r){}
    };
    node *root;
public:
    BinarySearchTree(node *r=NULL){root=r;}
    void insert(const int &x);
    void remove(const int &x);
    bool find(const int &x);
    void delLess(const int &x);
    void delMore(const int &x);
    void delRange(int x,int y);
    void findKth(int i,int &x){
        if(!findKth(i,x,root)){cout << "N" <<endl;}
        else{cout << x << endl;}
    }
private:
    void clear(node *r)
    {
        if(r==NULL) return;
        if(r->left!=NULL) clear(r->left);
        if(r->right!=NULL) clear(r->right);
        delete r;
    }
    int size(node* &r)
    {
        if(r==NULL) return 0;
        return 1+size(r->left)+size(r->right);
    }
    void insert(const int &x,node* &r);
    void remove(const int &x,node* &r);
    bool find(const int &x,node* &r);
    void delLess(const int &x,node* &r);
    void delMore(const int &x,node* &r);
    void delRange(int x,int y,node* &r);
    bool findKth(int i,int &x,node* &r);
};

bool BinarySearchTree::findKth(int i,int &x,node* &r)
{
    if(r==NULL) return false;
    int rs=size(r->left);
    if(rs==i-1){
        x=r->data;
        return true;
    }
    if(rs>=i){return findKth(i,x,r->left);}
    else{return findKth(i-rs-1,x,r->right);}
}

void BinarySearchTree::delRange(int x,int y)
{
    if(x<=y)delRange(x,y,root);
}

void BinarySearchTree::delRange(int x,int y,node* &r)
{
    if(r==NULL) return;
    if(r->data<=x){delRange(x,y,r->right);}
    else if(r->data>=y){delRange(x,y,r->left);}
        else{
            remove(r->data,r);
            delRange(x,y,r);
        }
}

void BinarySearchTree::delLess(const int &x)
{
    delLess(x,root);
}

void BinarySearchTree::delLess(const int &x,node* &r)
{
    if(r==NULL) return;
    if(r->data<x){
        node *tmp=r;
        r=r->right;
        clear(tmp->left);
        delete tmp;
        delLess(x,r);
    }
    else{
        delLess(x,r->left);
    }
}

void BinarySearchTree::delMore(const int &x)
{
    delMore(x,root);
}

void BinarySearchTree::delMore(const int &x,node* &r)
{
    if(r==NULL) return;
    if(r->data>x){
        node *tmp=r;
        r=r->left;
        clear(tmp->right);
        delete tmp;
        delMore(x,r);
    }
    else{
        delMore(x,r->right);
    }
}

bool BinarySearchTree::find(const int &x)
{
    return find(x,root);
}

bool BinarySearchTree::find(const int &x,node* &r)
{
    if(r==NULL) return false;
    if(x==r->data) return true;
    if(x<r->data) return find(x,r->left);
    if(x>r->data) return find(x,r->right);
}

void BinarySearchTree::insert(const int &x)
{
    insert(x,root);
}

void BinarySearchTree::insert(const int &x,node* &r)
{
    if(r==NULL){r=new node(x);}
    else{
        if(x<=r->data){insert(x,r->left);}
        else{
            if(x>r->data){insert(x,r->right);}
        }
    }
}

void BinarySearchTree::remove(const int &x)
{
    remove(x,root);
}

void BinarySearchTree::remove(const int &x,node* &r)
{
    if(r==NULL) return;
    if(x<r->data){remove(x,r->left);}
    else if(r->data<x){remove(x,r->right);}
        else if(r->left!=NULL&&r->right!=NULL){
            node *tmp=r->right;
            while(tmp->left!=NULL){tmp=tmp->left;}
            r->data=tmp->data;
            remove(r->data,r->right);
        }
            else{
                node *tmp2=r;
                r=(r->left!=NULL)?r->left:r->right;
                delete tmp2;
            }
}

int main()
{
    BinarySearchTree tree;
    int num,tmp1,tmp2,result;
    bool flag;
    char ch[20];
    cin >> num;
    while(num>0)
    {
        cin >> ch;
        if(ch[0]=='f'&&(strlen(ch)==4)){
            cin >> tmp1;
            flag=tree.find(tmp1);
            if(flag==true){cout << "Y" << endl;}
            else{cout << "N" << endl;}
        }
        if(ch[0]=='f'&&(strlen(ch)==8)){
            cin >> tmp1;
            tree.findKth(tmp1,result);
        }
        if(ch[0]=='d'&&(strlen(ch)==6)){cin >> tmp1;tree.remove(tmp1);}
        if(ch[0]=='d'&&(strlen(ch)==19)){cin >> tmp1;tree.delMore(tmp1);}
        if(ch[0]=='d'&&(strlen(ch)==16)){cin >> tmp1;tree.delLess(tmp1);}
        if(ch[0]=='d'&&(strlen(ch)==15)){cin >> tmp1;cin >> tmp2;tree.delRange(tmp1,tmp2);}
        if(ch[0]=='i'){cin >> tmp1;tree.insert(tmp1);}
        num--;
    }
    return 0;
}
