#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

struct tok
{	enum token_type{
        NUMBER = 1,
		OP=2
    }type_;
    long long num;
    string str;
    int fst;
};

vector<tok> tk;
stack<long long> num_;
stack<tok> sta;

 bool cal(tok str){
    long long a, b;
    if((str.str=="$" and num_.empty())||(str.str!="$" and num_.size()<2)) return false;
    if(str.str == "$"){
        a = num_.top();
        num_.pop();
        num_.push(-1*a);
    }else if(str.str=="+"){
        a = num_.top();
        num_.pop();
        b = num_.top();
        num_.pop();
        num_.push(b+a);
    }else if(str.str=="-"){
        a = num_.top();
        num_.pop();
        b = num_.top();
        num_.pop();
        num_.push(b-a);
    }else if(str.str=="*"){
        a = num_.top();
        num_.pop();
        b = num_.top();
        num_.pop();
        num_.push(b*a);
    }else if(str.str=="/"){
        a = num_.top();
        num_.pop();
        b = num_.top();
        num_.pop();
        if(a==0)
            return false;
        num_.push(b/a);
    }else if(str.str=="^"){

        a = num_.top();
        num_.pop();
        b = num_.top();
        num_.pop();
        num_.push((long long)pow(b, a));
    }
    return true;
}

bool bd(){
    for (int i = 0; i < tk.size() ; ++i) {
        if(tk[i].type_ == tok::OP){
            if(tk[i].str=="(") sta.push(tk[i]);
            else if(tk[i].str==")"){
                while( !sta.empty() and sta.top().str != "("){
                    if(!cal(sta.top()))   return false;
                    sta.pop();
                }
                if(sta.empty()) return false;
                if(sta.top().str == "(") sta.pop();
            }else{
                if(sta.empty()) sta.push(tk[i]);
                else{
                    int top_pr = sta.top().fst;
                    int cur_pr = tk[i].fst;
                    if( cur_pr > top_pr or (tk[i].str =="^" and sta.top().str=="^")){
                        sta.push(tk[i]);
                    }else{
                        while(cur_pr <= top_pr){
                            if(!cal(sta.top()))   return false;
                            sta.pop();
                            if(sta.empty())
                                break;
                            top_pr = sta.top().fst;
                        }
                        sta.push(tk[i]);
                    }
                }
            }
        }else if(tk[i].type_==tok::NUMBER) num_.push(tk[i].num);
    }

    while (!sta.empty()){
        if(sta.top().str=="(") return false;
        if(!cal(sta.top()))    return false;
        sta.pop();
    }
    return (num_.size()==1);
}

int main(){
    string input;
    getline(cin,input);
    string xpr = "";
    for (int i = 0; i < input.length(); ++i) {
        if(input[i]!=' ') xpr+=input[i];
    }
    tok tmp;
    for (int i = 0; i < xpr.length(); ++i){
        switch(xpr[i]){
            case ' ':
                continue;
                break;
            case '+':
                tmp.type_ = tok::OP;
                tmp.str = "+";
                tmp.fst = 1;
                break;
            case '-':
                if(i>=1 and (xpr[i-1]==')' or isdigit(xpr[i-1])))
                {
                    tmp.type_ = tok::OP;
                    tmp.str = "-";
                    tmp.fst = 1;
                }else{
                    tmp.type_ = tok::OP;
                    tmp.str = "$";
                    tmp.fst = 10;
                }
                break;
            case '*':
                tmp.type_ = tok::OP;
                tmp.str = "*";
                tmp.fst = 2;
                break;
            case '/':
                tmp.type_ = tok::OP;
                tmp.str = "/";
                tmp.fst = 2;
                break;
            case '^'://
                tmp.type_ = tok::OP;
                tmp.str = "^";
                tmp.fst= 3;
                break;
            case '(':
                tmp.type_ = tok::OP;
                tmp.str = "(";
                tmp.fst = 0;
                break;
            case ')':
                tmp.type_ = tok::OP;
                tmp.str = ")";
                tmp.fst = 4;
                break;
            default:
                string num = "";
                while( i < xpr.length()&& isdigit(xpr[i]))
                    num += xpr[i++];
                --i;
                stringstream ss;
                ss<<num;
                ss>>tmp.num;
                tmp.type_ = tok::NUMBER;
                tmp.str = "";
                break;
        }
        tk.push_back(tmp);
    }
    if(bd()) cout<<num_.top();
    else cout<<"Error"<<endl;
}


