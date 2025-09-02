#include"all.h"
#define MAX 1000
int charquantity(char* chars){
    char s[MAX];
    if(chars[0]=='\0'){
        return 0;
    }
    int consecutive_length=1;
    int snumber=0;
    for(int i=1;chars[i-1]!='\0';i++){
        if(chars[i-1]==chars[i]){
            consecutive_length++;
        }
        else{
            s[snumber++]=chars[i-1];//先把字母复制
            if(consecutive_length!=1){//如果有长度需要存储
                sprintf(s+snumber,"%d",consecutive_length);
                snumber=snumber+1+log10(consecutive_length);//偷个懒（）直接log10获取位数
                consecutive_length=1;
            }
        }
    }
    strcpy(chars,s);
    return snumber;
}
int main(){
    char chars[MAX];
    printf("输入字符串(最长999)\n");
    scanf("%s",chars);
    printf("长度是%d,修改后字符串%s",charquantity(chars),chars);
    return 0;
}