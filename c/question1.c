#include"all.h"/*
#define MAX 100
char ai[MAX];
char bi[MAX];
char* addtogether(int* a,int* b,int alength,int blength){
    char* answer[MAX+1]={0};
    int x;
    int answeri=MAX;
    if(a[0]=='-'&&b[0]=='-'){
        for(int i=alength,j=blength;i!=0&&j!=0;i--,j--){
            x=a[i]+b[i]-'0';
            if(x>9){
                answer[answeri-1]=x/10;
            }
            answer[answeri]=x%10;
            answeri--;
        }
        answer[answeri]='-';
    }
    if(a[0]=='-'){

    }
    return answer;
}
    */
   #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// 移除字符串前面的前导零
void removeLeadingZeros(char *num) {
    int len = strlen(num);
    int firstNonZero = 0;
    
    // 找到第一个非零字符
    while (firstNonZero < len && num[firstNonZero] == '0') {
        firstNonZero++;
    }
    
    // 如果全是零，保留一个零
    if (firstNonZero == len) {
        strcpy(num, "0");
        return;
    }
    
    // 移动非零部分到字符串开头
    for (int i = 0; i <= len - firstNonZero; i++) {
        num[i] = num[firstNonZero + i];
    }
}

// 比较两个正数的大小（字符串形式）
int comparePositive(const char *a, const char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    
    if (lenA > lenB) return 1;
    if (lenA < lenB) return -1;
    
    // 长度相等时逐位比较
    for (int i = 0; i < lenA; i++) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    
    return 0; // 相等
}

// 两个正数相加
char* addPositive(const char *a, const char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = (lenA > lenB) ? lenA : lenB;
    int resultLen = maxLen + 1; // 最多进位1位
    
    char *result = (char*)malloc(resultLen + 1); // +1 用于存放'\0'
    result[resultLen] = '\0';
    
    int carry = 0;
    int i, j, k;
    
    // 从末尾开始逐位相加
    for (i = lenA - 1, j = lenB - 1, k = resultLen - 1; i >= 0 || j >= 0; i--, j--, k--) {
        int digitA = (i >= 0) ? (a[i] - '0') : 0;
        int digitB = (j >= 0) ? (b[j] - '0') : 0;
        
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result[k] = (sum % 10) + '0';
    }
    
    // 如果还有进位
    if (carry > 0) {
        result[k] = carry + '0';
    } else {
        // 没有进位，将结果向前移动一位
        memmove(result, result + 1, resultLen);
        resultLen--;
    }
    
    return result;
}

// 两个正数相减（假设a >= b）
char* subtractPositive(const char *a, const char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA;
    
    char *result = (char*)malloc(maxLen + 1);
    result[maxLen] = '\0';
    
    int borrow = 0;
    int i, j, k;
    
    // 从末尾开始逐位相减
    for (i = lenA - 1, j = lenB - 1, k = maxLen - 1; i >= 0 || j >= 0; i--, j--, k--) {
        int digitA = (i >= 0) ? (a[i] - '0') : 0;
        int digitB = (j >= 0) ? (b[j] - '0') : 0;
        
        digitA -= borrow;
        borrow = 0;
        
        if (digitA < digitB) {
            digitA += 10;
            borrow = 1;
        }
        
        result[k] = (digitA - digitB) + '0';
    }
    
    // 移除前导零
    removeLeadingZeros(result);
    
    return result;
}

// 主函数：计算两个大整数的和
char* addBigNumbers(const char *a, const char *b) {
    bool aNegative = (a[0] == '-');
    bool bNegative = (b[0] == '-');
    
    const char *aNum = aNegative ? a + 1 : a;
    const char *bNum = bNegative ? b + 1 : b;
    
    // 移除前导零
    char *aClean = strdup(aNum);
    char *bClean = strdup(bNum);
    removeLeadingZeros(aClean);
    removeLeadingZeros(bClean);
    
    char *result;
    
    // 四种情况：正负组合
    if (!aNegative && !bNegative) {
        // 两个正数相加
        result = addPositive(aClean, bClean);
    } 
    else if (aNegative && bNegative) {
        // 两个负数相加，相当于它们的绝对值相加后加负号
        result = addPositive(aClean, bClean);
        char *temp = (char*)malloc(strlen(result) + 2);
        temp[0] = '-';
        strcpy(temp + 1, result);
        free(result);
        result = temp;
    } 
    else if (aNegative && !bNegative) {
        // a负b正，相当于b - |a|
        int cmp = comparePositive(bClean, aClean);
        if (cmp >= 0) {
            result = subtractPositive(bClean, aClean);
        } else {
            result = subtractPositive(aClean, bClean);
            char *temp = (char*)malloc(strlen(result) + 2);
            temp[0] = '-';
            strcpy(temp + 1, result);
            free(result);
            result = temp;
        }
    } 
    else { // !aNegative && bNegative
        // a正b负，相当于a - |b|
        int cmp = comparePositive(aClean, bClean);
        if (cmp >= 0) {
            result = subtractPositive(aClean, bClean);
        } else {
            result = subtractPositive(bClean, aClean);
            char *temp = (char*)malloc(strlen(result) + 2);
            temp[0] = '-';
            strcpy(temp + 1, result);
            free(result);
            result = temp;
        }
    }
    
    free(aClean);
    free(bClean);
    return result;
}

// 验证输入是否为有效的整数
bool isValidNumber(const char *num) {
    int len = strlen(num);
    if (len == 0) return false;
    
    // 检查负号
    int start = 0;
    if (num[0] == '-') {
        if (len == 1) return false; // 只有负号不是有效数字
        start = 1;
    }
    
    // 检查所有字符是否都是数字
    for (int i = start; i < len; i++) {
        if (num[i] < '0' || num[i] > '9') {
            return false;
        }
    }
    
    return true;
}

int main() {
    char a[1024], b[1024];
    
    printf("请输入第一个数: ");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0'; // 移除换行符
    
    printf("请输入第二个数: ");
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = '\0'; // 移除换行符
    
    // 验证输入
    if (!isValidNumber(a) || !isValidNumber(b)) {
        printf("输入无效，请输入有效的整数！\n");
        return 1;
    }
    
    // 计算并输出结果
    char *sum = addBigNumbers(a, b);
    printf("两数之和为: %s\n", sum);
    
    free(sum);
    return 0;
}
