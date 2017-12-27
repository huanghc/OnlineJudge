#include <iostream>

using namespace std;

void way1(int i);void way2(int i);void way3(int i);
void way4(int i);void way5(int i);void way6(int i);
void way7(int i);void way8(int i);void way9(int i);

void back1(int i);void back2(int i);void back3(int i);
void back4(int i);void back5(int i);void back6(int i);
void back7(int i);void back8(int i);void back9(int i);

int clocks[9],tmp[9],result[9];

int main()
{
    int min=500,value;
    for(int i=0;i<9;++i){cin >> clocks[i];}
    for(int i1=0;i1<4;++i1){
        way1(i1);
        for(int i2=0;i2<4;++i2){
            way2(i2);
            for(int i3=0;i3<4;++i3){
                way3(i3);
                for(int i4=0;i4<4;++i4){
                    way4(i4);
                    for(int i5=0;i5<4;++i5){
                        way5(i5);
                        for(int i6=0;i6<4;++i6){
                            way6(i6);
                            for(int i7=0;i7<4;++i7){
                                way7(i7);
                                for(int i8=0;i8<4;++i8){
                                    way8(i8);
                                    for(int i9=0;i9<4;++i9){
                                        way9(i9);
                                        bool flag=true;
                                        value=0;
                                        for(int j=0;j<9;j++){
                                            value+=tmp[j];
                                            if(clocks[j]%12!=0){flag=false;break;}
                                        }
                                        if(flag){
                                            if(value<min){
                                                min=value;
                                                for(int k=0;k<9;++k){
                                                    result[k]=tmp[k];
                                                }
                                            }
                                        }
                                        back9(i9);
                                    }
                                    back8(i8);
                                }
                                back7(i7);
                            }
                            back6(i6);
                        }
                        back5(i5);
                    }
                    back4(i4);
                }
                back3(i3);
            }
            back2(i2);
        }
        back1(i1);
    }
    for(int p=0;p<9;++p){
        for(int q=0;q<result[p];q++){
            cout << p+1 << " ";
        }
    }
    return 0;
}

void way1(int i){
	clocks[0]=(clocks[0]+3*i);
	clocks[1]=(clocks[1]+3*i);
	clocks[3]=(clocks[3]+3*i);
	clocks[4]=(clocks[4]+3*i);
	tmp[0]=i;
}

void way2(int i){
	clocks[0]=(clocks[0]+3*i);
	clocks[1]=(clocks[1]+3*i);
	clocks[2]=(clocks[2]+3*i);
	tmp[1]=i;
}

void way3(int i){
	clocks[1]=(clocks[1]+3*i);
	clocks[2]=(clocks[2]+3*i);
	clocks[4]=(clocks[4]+3*i);
	clocks[5]=(clocks[5]+3*i);
	tmp[2]=i;
}

void way4(int i){
	clocks[0]=(clocks[0]+3*i);
	clocks[3]=(clocks[3]+3*i);
	clocks[6]=(clocks[6]+3*i);
	tmp[3]=i;
}

void way5(int i){
	clocks[1]=(clocks[1]+3*i);
	clocks[3]=(clocks[3]+3*i);
	clocks[4]=(clocks[4]+3*i);
	clocks[5]=(clocks[5]+3*i);
	clocks[7]=(clocks[7]+3*i);
	tmp[4]=i;
}

void way6(int i){
	clocks[2]=(clocks[2]+3*i);
	clocks[5]=(clocks[5]+3*i);
	clocks[8]=(clocks[8]+3*i);
	tmp[5]=i;
}

void way7(int i){
	clocks[3]=(clocks[3]+3*i);
	clocks[4]=(clocks[4]+3*i);
	clocks[6]=(clocks[6]+3*i);
	clocks[7]=(clocks[7]+3*i);
	tmp[6]=i;
}

void way8(int i){
	clocks[6]=(clocks[6]+3*i);
	clocks[7]=(clocks[7]+3*i);
	clocks[8]=(clocks[8]+3*i);
	tmp[7]=i;
}

void way9(int i){
	clocks[4]=(clocks[4]+3*i);
	clocks[5]=(clocks[5]+3*i);
	clocks[7]=(clocks[7]+3*i);
	clocks[8]=(clocks[8]+3*i);
	tmp[8]=i;
}

void back1(int i){
	clocks[0]=(clocks[0]-3*i);
	clocks[1]=(clocks[1]-3*i);
	clocks[3]=(clocks[3]-3*i);
	clocks[4]=(clocks[4]-3*i);
}

void back2(int i){
	clocks[0]=(clocks[0]-3*i);
	clocks[1]=(clocks[1]-3*i);
	clocks[2]=(clocks[2]-3*i);
}

void back3(int i){
	clocks[1]=(clocks[1]-3*i);
	clocks[2]=(clocks[2]-3*i);
	clocks[4]=(clocks[4]-3*i);
	clocks[5]=(clocks[5]-3*i);
}

void back4(int i){
	clocks[0]=(clocks[0]-3*i);
	clocks[3]=(clocks[3]-3*i);
	clocks[6]=(clocks[6]-3*i);
}

void back5(int i){
	clocks[1]=(clocks[1]-3*i);
	clocks[3]=(clocks[3]-3*i);
	clocks[4]=(clocks[4]-3*i);
	clocks[5]=(clocks[5]-3*i);
	clocks[7]=(clocks[7]-3*i);
}

void back6(int i){
	clocks[2]=(clocks[2]-3*i);
	clocks[5]=(clocks[5]-3*i);
	clocks[8]=(clocks[8]-3*i);
}

void back7(int i){
	clocks[3]=(clocks[3]-3*i);
	clocks[4]=(clocks[4]-3*i);
	clocks[6]=(clocks[6]-3*i);
	clocks[7]=(clocks[7]-3*i);
}

void back8(int i){
	clocks[6]=(clocks[6]-3*i);
	clocks[7]=(clocks[7]-3*i);
	clocks[8]=(clocks[8]-3*i);
}

void back9(int i){
	clocks[4]=(clocks[4]-3*i);
	clocks[5]=(clocks[5]-3*i);
	clocks[7]=(clocks[7]-3*i);
	clocks[8]=(clocks[8]-3*i);
}

