#include <stdio.h>
#include <string.h>
#define MAX 100

int add(char *a, char *b, char *result)
{
    int la = strlen(a), lb = strlen(b);
    int i = la - 1, j = lb - 1, k = MAX;
    int carry = 0;
    result[MAX + 1] = '\0';

    for (; i >= 0 && j >= 0; i--, j--, k--)
    {
        int sum = (a[i] - '0') + (b[j] - '0') + carry;
        result[k] = sum % 10 + '0';
        carry = sum / 10;
    }

    for (; i >= 0; i--, k--)
    {
        int sum = (a[i] - '0') + carry;
        result[k] = sum % 10 + '0';
        carry = sum / 10;
    }

    for (; j >= 0; j--, k--)
    {
        int sum = (b[j] - '0') + carry;
        result[k] = sum % 10 + '0';
        carry = sum / 10;
    }

    if (carry)
    {
        result[k--] = carry + '0';
    }

    return k + 1; // 返回结果字符串的起始位置
}

int subtraction(char *a, char *b, char *result)
{
    int la = strlen(a), lb = strlen(b);
    int flag = 1; // 标记结果的正负性，1为正，-1为负

    // 比较两个数的大小
    if (la < lb)
    {
        flag = -1;
    }
    else if (la == lb)
    {
        for (int i = 0; i < la; i++)
        {
            if (a[i] < b[i])
            {
                flag = -1;
                break;
            }
            else if (a[i] > b[i])
            {
                break;
            }
        }
    }

    // 如果结果为负数，交换a和b
    if (flag == -1)
    {
        char *temp = a;
        a = b;
        b = temp;
        int t = la;
        la = lb;
        lb = t;
    }

    int i = la - 1, j = lb - 1, k = MAX;
    result[MAX + 1] = '\0';
    int borrow = 0;

    // 从右向左逐位相减
    for (; i >= 0 && j >= 0; i--, j--, k--)
    {
        int sub = (a[i] - '0') - (b[j] - '0') - borrow;
        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result[k] = sub + '0';
    }

    // 处理a中剩余的数字
    for (; i >= 0; i--, k--)
    {
        int sub = (a[i] - '0') - borrow;
        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result[k] = sub + '0';
    }

    // 跳过前导零
    while (k < MAX && result[k + 1] == '0')
    {
        k++;
    }

    // 如果所有位都是0，保留最后一位0
    if (k == MAX)
    {
        k = MAX - 1;
    }

    // 返回结果：正数返回起始位置，负数返回起始位置的负值
    return flag * (k + 1);
}

int main()
{
    char ai[MAX + 1], bi[MAX + 1], result[MAX + 2];
    int k;

    printf("输入第一个数(不超过100位): ");
    scanf("%s", ai);
    printf("输入第二个数(不超过100位): ");
    scanf("%s", bi);

    if (ai[0] == '-' && bi[0] == '-')
    {
        // 两个负数相加
        k = add(ai + 1, bi + 1, result);
        printf("结果为-%s\n", result + k);
    }
    else if (ai[0] == '-')
    {
        // 负数加正数
        int x = subtraction(bi, ai + 1, result);
        if (x < 0)
        {
            printf("结果为-%s\n", result + (-x));
        }
        else
        {
            printf("结果为%s\n", result + x);
        }
    }
    else if (bi[0] == '-')
    {
        // 正数加负数
        int x = subtraction(ai, bi + 1, result);
        if (x < 0)
        {
            printf("结果为-%s\n", result + (-x));
        }
        else
        {
            printf("结果为%s\n", result + x);
        }
    }
    else
    {
        // 两个正数相加
        k = add(ai, bi, result);
        printf("结果为%s\n", result + k);
    }

    return 0;
}