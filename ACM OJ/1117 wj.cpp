#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;
void InitObj(vector<set<int> > &obj, unsigned int p = 0)
{
	unsigned int x;
	cin>>ws>>x; 
	cout<<"cin: "<<x<<endl;
	
	if(p)
	{
		obj[p].insert(x);
		obj[x].insert(p);
		cout<<"p: "<<p<<" "<<x<<endl;
	}
	while(true)
	{
		char ch;
		cin>>ws>>ch;
		if(ch == ')')
			break;
		cout<<"aa: "<<x<<endl;
		InitObj(obj, x);
		
	}
	return ;
}
 
int main()
{
	char ch;
	while(cin>>ws>>ch)
	{	
		vector<set<int> > obj(100000, set<int>());
		InitObj(obj);	
		priority_queue< int, vector<int>, greater<int> > leafs; //使用方法 
		int n=0;
		for(int i=0; i<obj.size(); i++)
		{
			if(obj[i].size())
			{
				n++;
				if(1 == obj[i].size())
					leafs.push(i);
			}
		}
		//处理优先队列
		for(int i=1; i<n; i++)
		{
			unsigned int x = leafs.top();
			leafs.pop();
			unsigned int p = *(obj[x].begin());
			if(i>1)
				cout<<" ";
			cout<<p;
			obj[p].erase(x);
			if(1 == obj[p].size())
				leafs.push(p);
		}
		cout<<endl; 
	}
	return 0; 
}

