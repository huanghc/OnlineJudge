#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int maxchar(int character[]){
	int num = 0;
	for(int i=0;i<26;++i){
		num = max(num, character[i]);
	}
	return num;
}

int longstsub(string s, int k) {
	int len = s.length();
	int start = 0, end = 0;
	int character[26] = {0};
	int res = 0;
		
	while(end < len){
		int tmp = s[end] - 'A';	
		++character[tmp];
		++end;
		while(end-start-maxchar(character) > k){			
			int tmp = s[start] - 'A';	
			--character[tmp];
			++start;
		}
		res = max(res, end-start);
	}
	return res;
}

int main(){
	string s = "AABABBA";
	int k=1;
	cout<<longstsub(s, k);
} 

