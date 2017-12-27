#include <iostream>
using namespace std;

int main()
{
    int month,number,day,year1,year2;
    cin >> month >> number >> day >> year1 >> year2;
    int p=year1,tmp;
    bool flag=false;
    while(p<year2+1)
    {
        tmp=(p-1850)*365+(p-1849)/4-((p-1900)>0?1:0);
        switch(month){
            case 1:break;
            case 2:tmp=tmp+31;break;
            case 3:tmp=tmp+31+28;break;
            case 5:tmp=tmp+31+28+31+30;break;
            case 6:tmp=tmp+31+28+31+30+31;break;
            case 7:tmp=tmp+31+28+31+30+31+30;break;
            case 8:tmp=tmp+31+28+31+30+31+30+31;break;
            case 9:tmp=tmp+31+28+31+30+31+30+31+31;break;
            case 10:tmp=tmp+31+28+31+30+31+30+31+31+30;break;
            case 11:tmp=tmp+31+28+31+30+31+30+31+31+30+31;break;
            case 12:tmp=tmp+31+28+31+30+31+30+31+31+30+31+30;break;
        }
        if(p%4==0&&p!=1900&&month>2){tmp=tmp+1;}
        tmp=(tmp%7)+2;
        tmp=((day-tmp)<0?(day+7-tmp):(day-tmp))+1+(number-1)*7;
        switch(month){
            case 1:if(tmp>31){flag=true;}break;
            case 2:if(tmp>28){flag=true;}break;
            case 3:if(tmp>31){flag=true;}break;
            case 4:if(tmp>30){flag=true;}break;
            case 5:if(tmp>31){flag=true;}break;
            case 6:if(tmp>30){flag=true;}break;
            case 7:if(tmp>31){flag=true;}break;
            case 8:if(tmp>31){flag=true;}break;
            case 9:if(tmp>30){flag=true;}break;
            case 10:if(tmp>31){flag=true;}break;
            case 11:if(tmp>30){flag=true;}break;
            case 12:if(tmp>31){flag=true;}break;
        }
        if(p%4==0&&p!=1900&&month==2&&tmp==29){flag=false;}
        if(flag==true){cout << "none" << endl;p++;continue;}
        if(month<10&&tmp<10){cout << p << "/" << "0" << month << "/" << "0" << tmp << endl;}
        if(month<10&&tmp>=10){cout << p << "/" << "0" << month << "/" << tmp << endl;}
        if(month>=10&&tmp<10){cout << p << "/" << month << "/" << "0" << tmp << endl;}
        if(month>=10&&tmp>=10){cout << p << "/" << month << "/" << tmp << endl;}
        p++;
    }
    return 0;
}
