#include <iostream>

using namespace std;
class DisjointSet{
	private:
		int size;
		int *parent;
	public:
		DisjointSet(int s){
			size = s;
			parent = new int [s+2];
			for (int i=0;i<s+2;++i){
				parent[i] = -1;
			}
		}
		~DisjointSet(){
			delete [] parent;
		} 
		void Union(int root1,int root2){
			if (root1==root2) return;
			if (parent[root1]<parent[root2]){
				parent[root1] += parent[root2];
				parent[root2] = root1;				
			}
			else{
				parent[root2] += parent[root1];
				parent[root1] = root2;								
			}
		}
		int Find(int x){
			if (parent[x]<0) return x;
			while(parent[x]>0){
				x=parent[x];//cout<<" "<<x<<" ";
			}
			return x;
		}
		void show(){cout<<endl;
			for (int i=0;i<size+2;++i){
				cout<<parent[i]<<" ";
			}	cout<<endl;		
		}	
};

int joint[100001]={0},map[100001][3];

void swap(int &x,int &y)
{
    int tmp=x;
    x=y;
    y=tmp;
}

void qsort(int low,int high)
{
    int l=low,h=high,mid=map[(low+high)/2][2];
    if(l>=h) {return;}
    while(l<=h)
    {
        while(map[h][2]>mid){h--;}
        while(map[l][2]<mid){l++;}
        if(l<=h){
            swap(map[l][0],map[h][0]);
            swap(map[l][1],map[h][1]);
            swap(map[l][2],map[h][2]);
            l++;
            h--;
        }
    }
    qsort(low,h);
    qsort(l,high);
}

int main()
{
    int n,m,j,u,v;
    int result=0,edge=0;
    cin >> n >> m;
    int begin,end,weight;
    DisjointSet ds(n);
    //cout<<n;
    for(j=1;j<m+1;j++)
    {
        cin >> begin >> end >> weight;
        map[j][0]=begin;
        map[j][1]=end;
        map[j][2]=weight;
    }
    qsort(1,m);
    int i=1;
    while (edge<n-1 )
    {//cout<<edge<<map[i][0]<<map[i][1]<<endl;
        u = ds.Find(map[i][0]);
        v = ds.Find(map[i][1]);
        //cout<<u<<" "<<v<<endl;
        if (u == v) {++i;}
        else{
            ds.Union(u,v);
            //ds.show();
            result += map[i][2];
            ++i;
            ++edge;           
        }
    }
    cout << result;
    return 0;
}
