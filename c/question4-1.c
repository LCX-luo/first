#include "all.h"
#define MAX 1000

int find(int x, int *parent)
{
    if (parent[x] != x)
    {                                        // 若x不是根节点，递归找父节点
        parent[x] = find(parent[x], parent); 
    }
    return parent[x]; // 返回根节点
}
void unite(int x, int y, int *parent, int *rank)
{
    int rootX = find(x, parent); // 找x的根
    int rootY = find(y, parent); // 找y的根
    if (rootX == rootY)
        return; // 已同组，无需合并

    // 按秩合并：秩小的根指向秩大的根
    if (rank[rootX] < rank[rootY])
    {
        parent[rootX] = rootY;
    }
    else
    {
        parent[rootY] = rootX;
        if (rank[rootX] == rank[rootY])
        {
            rank[rootX]++; // 秩相等时，合并后秩+1
        }
    }
}
int testall(int childrennumber, int *parent)
{
    if (childrennumber == 0)
    {
        return 1;
    }
    int root = find(0, parent); // 第一个孩子的根节点
    for (int i = 1; i < childrennumber; i++)
    {
        if (find(i, parent) != root)
        { // 有孩子根节点不同
            return -1;
        }
    }
    return 1; // 所有孩子根节点相同，即同组
}
int makefriend(int childrennumber, int Day, int *parent, int *rank)
{ // 使ai，bi的数相等
    int ai, bi;
    int i = 0;
    for (; i < Day; i++)
    {
        if (testall(childrennumber, parent) == 1)
        { // 所有人都成朋友之后返回天数
            return i;
        }
        scanf("%d %d", &ai, &bi);
        ai--;
        bi--;
        unite(ai, bi, parent, rank);
    }
    return -1;
}

int main()
{
    int Day, childrennumber;
    scanf("%d %d", &childrennumber, &Day);
    int parent[MAX], rank[MAX];
    for (int i = 0; i < childrennumber; i++)
    {
        parent[i] = i; // 每个孩子初始为自己的父节点（自成一组）
        rank[i] = 1;   // 初始秩为1（或用size[i] = 1）
    }
    printf("%d\n", makefriend(childrennumber, Day, parent, rank));
}