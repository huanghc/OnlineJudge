#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
   string content[500];
   int LineNumber=0,s=0,number_if=0,number_else=0;
   int Stack[500]={0};
   while(true)
   {
       getline(cin,content[LineNumber]);
       if(content[LineNumber]=="") break;
       ++LineNumber;
   }
   for(int i=0;i<LineNumber;i++)
   {
        if(content[i].find("begin")!=-1){Stack[s]=1;s++;}
        if(content[i].find("end")!=-1){
            if(Stack[s-1]!=1||s==0){cout<<"Error!";return 0;}
            else{s--;Stack[s]=0;}
        }
        if(content[i].find("if")!=-1){Stack[s]=2;s++;number_if++;}
        if(content[i].find("then")!=-1){
           if(Stack[s-1]!=2||s==0){cout<<"Error!";return 0;}
           else{s--;Stack[s]=0;}
        }
        if(content[i].find("else")!=-1){
            number_else++;
            if(number_else>number_if){cout<<"Error!";return 0;}
        }
   }
   if(s==0){cout<<"Match!";}
   else{cout<<"Error!";}
   return 0;
}


