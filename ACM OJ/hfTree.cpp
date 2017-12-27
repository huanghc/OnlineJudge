#include <iostream>
#include <string>
using namespace std;

template <class Type>
class hfTree{
	private:
		struct Node{
			Type data;  //shu zu  yuan su  lei xing
			int weight; // jie dian quan zhi
			int parent,left,right;
		};
		
		Node *elem;  //shu zu 
		int length;
	public:
		struct hfCode{
			Type data;  //bian ma zi fu
			string code;  //dui ying bian ma
		};
		
		hfTree(const Type *v,const int *w, int size){
			const int MAX_INT = 32767;
			int min1,min2;  //zui xiao shu  quan zhi
			int x,y;  //zui xiao shu  xia biao
			
			length = 2*size;
			elem = new Node[length];
			
			for (int i=size;i<length;++i){
				elem[i].weight = w[i-size];
				elem[i].data = v[i-size];
				elem[i].parent = elem[i].left = elem[i].right = 0;
			}
			
			for (int i=size-1;i>0;--i){
				min1 = min2 = MAX_INT;
				x = y = 0;  //y<x     //min1<min2
				for (int j=i+1;j<length;++j){
					if (elem[j].parent==0){
						if (elem[j].weight<min1){
							min2=min1;min1=elem[j].weight;x=y;y=j;
						}
						else if (elem[j].weight<min2){
							min2 = elem[j].weight;
							x=j;
						}
					}
				}
				elem[i].weight = min1+min2;
				elem[i].left=x;elem[i].right=y;elem[i].parent=0; 
				elem[x].parent=i;elem[y].parent=i;
			}			
		}
		void getCode(hfCode result[]){   //hfman bianma
			int size=length/2;
			int p,s;//p:s' parent; s:jie dian dealing with 
			for (int i=size;i<length;++i){
				result[i-size].data=elem[i].data;
				result[i-size].code="";
				p=elem[i].parent;
				s=i;
				while (p!=0){
					if (s==elem[p].left){
						result[i-size].code="0"+result[i-size].code;
					}
					else{
						result[i-size].code="1"+result[i-size].code;
					}
					s=p;
					p=elem[p].parent;
				}
				
			} 
			
		}	
		~hfTree() {
			delete [] elem;
		}
}; 

int main(){
	char ch[] = {"aeistdn"};
	int w[] = {10,15,12,3,4,13,1};
	
	hfTree <char> tree(ch,w,7);
	hfTree <char> :: hfCode result[7];
	
	tree.getCode(result);
	
	for (int i=0;i<7;++i){
		cout<<result[i].data<<" "<<result[i].code<<endl;
	}
	
	return 0;
}
