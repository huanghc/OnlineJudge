#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int maxv(int a[], int n)
{	int re = 0;
	for(int i=0;i<n;++i) re = max(re, a[i]);
	return re;
}

int main()
{		
	string s;
	cin >> s;
	int k;
	int ascii[400];
	int res = 0;
	for(int i=0;i<400;++i) ascii[i] = 0;
	cin >> k;
	int l = s.length();
	int start = 0, end = 0;
	while(end < l)
	{	
		++ascii[s[end]];
		++end;
		while(end-start-maxv(ascii, 400) > k)
		{	--ascii[s[start]];
			++start;
		}
		res = max(res, end-start);
	}
	
	cout << res;
} 
