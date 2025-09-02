#include"all.h"
double numberadd(double x,double y){
    return x+y;
}
int main(){
    printf("输入需要相加的两个数，使用空格隔开\n");
    double num1,num2;
    scanf("%lf %lf",&num1,&num2);
    printf("结果是%lf",numberadd(num1,num2));
    return 0;
}