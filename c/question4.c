#include "all.h"
#define MAX 1000

// 除了并查集我还有一个想法

int testall(int childrennumber, int *a)//测试是否都是朋友
{
    for (int i = 0; i < childrennumber; i++)
    {
        if (a[i] == 0)
        {
            return -1;//有人依然为0，不是朋友
        }
    }
    for (int i = 1; i < childrennumber; i++)
    {
        if (a[i - 1] != a[i])
        {
            return -1;//有两个人的朋友没有同化
        }
    }
    return 1;
}
int makefriend(int childrennumber, int Day, int *a)
{ // 使ai，bi的数相等
    int ai, bi;
    int i = 0;
    for (; i < Day; i++)
    {
        if (testall(childrennumber, a) == 1)
        { // 所有人都成朋友之后返回天数
            return i;
        }
        scanf("%d %d", &ai, &bi);
        ai--;
        bi--;
        if (a[ai] == 0 && a[bi] == 0)
        { // 00  如果都是独立个体
            a[ai] = i + 1;
            a[bi] = i + 1;
        }
        else if (a[ai] == 0)
        { // 0x
            a[ai] = a[bi];
        }
        else if (a[bi] == 0)
        { // x0
            a[bi] = a[ai];
        }
        else
        { // 如果两个人都有朋友
            int xx = a[bi];//保存，防止被覆盖
            for (int j = 0; j < childrennumber; j++)
            {
                if (a[j] == xx)
                {
                    a[j] = a[ai];//把b朋友都变成a的朋友
                }
            }
        }
    }
    return -1;
}

int main()
{
    int Day, childrennumber;
    scanf("%d %d", &childrennumber, &Day);
    int a[MAX] = {0};
    printf("%d\n", makefriend(childrennumber, Day, a));
}