#include "all.h"
// 存储每个蛋糕结果的结构
typedef struct
{
    int *result;
    int length;
} CakeResult;
void cakecream(CakeResult *results, int index)
{
    int cakenumber;
    scanf("%d", &cakenumber);
    int *cream_thickness = (int *)malloc(cakenumber * sizeof(int));
    int *cakeifcreamdiff = (int *)malloc((cakenumber + 1) * sizeof(int)); // 差分数组长度+1
    int *cakeifcream = (int *)malloc((cakenumber + 1) * sizeof(int));     // 结果数组长度+1
    // 初始化数组
    for (int i = 0; i < cakenumber; i++)
    {
        cream_thickness[i] = 0;
    }
    for (int i = 0; i <= cakenumber; i++)
    {
        cakeifcreamdiff[i] = 0;
        cakeifcream[i] = 0;
    }
    // 读取奶油厚度
    for (int i = 0; i < cakenumber; i++)
    {
        scanf("%d", &cream_thickness[i]);
    }
    // 构建差分数组
    for (int i = 0; i < cakenumber; i++)
    {
        if (cream_thickness[i] != 0)
        {
            int start = i + 1 - cream_thickness[i];
            if (start < 0)
            {
                cakeifcreamdiff[0] = 1;
            }
            else
            {
                cakeifcreamdiff[start] = 1;
            }
            cakeifcreamdiff[i + 1] = -1;
        }
    }
    // 通过差分数组计算结果数组
    for (int i = 1; i <= cakenumber; i++)
    {
        cakeifcream[i] = cakeifcreamdiff[i - 1] + cakeifcream[i - 1];
    }
    // 存储结果
    results[index].length = cakenumber;
    results[index].result = (int *)malloc(cakenumber * sizeof(int));
    for (int i = 0; i < cakenumber; i++)
    {
        results[index].result[i] = cakeifcream[i + 1];
    }
    // 释放内存
    free(cream_thickness);
    free(cakeifcreamdiff);
    free(cakeifcream);
}
int main()
{
    int number;
    scanf("%d", &number);

    // 分配存储所有结果的空间
    CakeResult *results = (CakeResult *)malloc(number * sizeof(CakeResult));
    for (int i = 0; i < number; i++)
    {
        cakecream(results, i);
    }
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < results[i].length; j++)
        {
            printf("%d ", results[i].result[j]);
        }
        printf("\n");
    }
    for (int i = 0; i < number; i++)
    {
        free(results[i].result);
    }
    free(results);
    return 0;
}