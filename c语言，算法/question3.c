#include"all.h"
// 2,4,6,10,16,26
//11100,11101,11110,11111,  01110,\11110,01111,\11111,  00111,10111,\01111,\11111
//这个题...数学难度大于编程难度啊
long long f(long long x){
    if(x==1){
        return 2;
    }
    if(x==2){
        return 4;
    }
    if(x==3){
        return 6;
    }
    if(x>3){
        return f(x-1)+f(x-2);
    }
    if(x<1){
        return 0;
    }
}
int main(){
    long long x;
    printf("输入需要的硬币数:");
    scanf("%lld",&x);
    printf("%lld",((long long)pow(2,(double)x)-f(x))%1000000007);
}