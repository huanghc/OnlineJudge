#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *son,*bro;
	Node(){
		data = 0;son = NULL; bro = NULL;
	}
	Node (int t,Node *a=NULL,Node *b=NULL){
		data = t;son = a; bro = b;
	}
};
 
class Bernoulli{
	private:
		Node **forest;
		
	public:
		Bernoulli(){
			forest = new Node*[100];
			for (int i=0;i<100;++i){
				forest[i] = NULL;
			}
		}
		Node * merge(Node *a,Node *b){
			if (a->data<b->data){
				if (a->son!=NULL){
					Node *t = a->son;
					while (t->bro!=NULL){
						t=t->bro;
					}
					t->bro = b;
				}
				else {
					a->son = b;
				}
				return a;
			}
			else {
				if (b->son!=NULL){
					Node *t = b->son;
					while (t->bro!=NULL){
						t=t->bro;
					}
					t->bro = a;
				}
				else {
					b->son = a;
				}
				return b;				
			}
		}
		void merge(int t){
			Node * m = new Node(t);
			for (int i=0;i<100;++i){
				if (forest[i]==NULL){
					forest[i] = m;
					break;
				}
				else{
					m=merge(m,forest[i]);
					forest[i] = NULL;
				}
			} 
			//show();
		}
		int min(){
			int min=99999999,tmp=-1;
			for (int i=0;i<100;++i){
				if (forest[i]==NULL) continue;
				else {
					if (forest[i]->data<min || min==99999999){
						min = forest[i]->data;
						tmp = i;
					}
				}
			}
			//cout<<2<<endl;
			return tmp;
		}
		
		void min2(){
			int tmp = min();
			cout<<forest[tmp]->data<<endl;
		}
		
		void del(){
		    int p=min(),q,r;
		    q=0;
		    Node *tmp=forest[p]->son,*carry;
		    forest[p]=NULL;
		    while(q<p){
		        carry=tmp;
		        tmp=tmp->bro;
		        carry->bro=NULL;
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
		
		void show(){
			for (int i=0;i<100;++i){
				if (forest[i]==NULL) continue;
				else{
					cout<<endl<<i<<": ";
					cout<<forest[i]->data;
					Node *p = forest[i]->son;
					while(p){
						cout<<p->data;
						p=p->bro;
					}
				}
			}
			cout<<endl;
		}
};
int main(){
	int n;cin>>n;
	char input[10];
	int num = 0;
	Bernoulli fore;
	for (int i=0;i<n;++i){
		cin>>input;
		if (input[0]=='i'){
			cin>>num;
			fore.merge(num);//fore.show();
		}
		if (input[0]=='d'){
			fore.del();//fore.show();
		}
		if (input[0]=='m'){
			fore.min2();//fore.show();
		}
	}
}
