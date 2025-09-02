#include "all.h"
// 堆的结构体定义
//git测试
typedef struct
{
    int *data;    // 存储堆元素的数组
    int size;     // 当前堆中元素的数量
    int capacity; // 堆的最大容量
} Heap;
/*对于数组模拟二叉树堆的每一个元素，它的孩子相当于2i+1和2i+2，父相当于(i-1)/2  */
// 初始化动态数组
Heap *createHeap()
{
    int capacity = 0;
    Heap *arr = (Heap *)malloc(sizeof(Heap));
    if (arr == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }

    arr->capacity = capacity;
    arr->size = 0;
    arr->data = (int *)malloc(capacity * sizeof(int));
    if (arr->data == NULL)
    {
        printf("内存分配失败\n");
        free(arr);
        return NULL;
    }

    return arr;
}

// 扩容动态数组（通常扩容为原来的2倍）
void resize(Heap *arr)
{
    if (arr == NULL)
        return;

    // 计算新容量
    int newCapacity = arr->capacity + 1;
    // 重新分配内存
    int *newData = (int *)realloc(arr->data, newCapacity * sizeof(int));

    if (newData == NULL)
    {
        printf("内存分配失败，无法扩容\n");
        return;
    }

    arr->data = newData;
    arr->capacity = newCapacity;
    printf("数组已扩容，新容量: %d\n", newCapacity);
}
void floatdata(Heap *heap)
{
    int i = heap->size - 1;
    if (heap == NULL || heap->size == 0)
    {
        return;
    }
    while (i != 0 && heap->data[i] > heap->data[(i - 1) / 2])
    {
        int swap = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = swap;
        i = (i - 1) / 2;
    }
}
void addnewdata(Heap *heap, int x)
{
    if (heap == NULL)
    {
        return;
    }
    heap->size++;
    if (heap->capacity < heap->size)
    {
        resize(heap);
    }
    heap->data[heap->size - 1] = x;

    floatdata(heap);
}
void sink(Heap *heap)
{
    if (heap == NULL || heap->size == 0)
    {
        return;
    }
    int i = 0;
    while (i < heap->size)
    {
        if ((2 * i + 1) >= heap->size - 1)
        { // 没有left孩子节点
            break;
        }
        if ((2 * i + 2) >= heap->size - 1)
        { // 没有right孩子节点
            if (heap->data[i] < heap->data[2 * i + 1])
            {
                int swap = heap->data[i];
                heap->data[i] = heap->data[2 * i + 1];
                heap->data[2 * i + 1] = swap;
                i = 2 * i + 1;
                continue;
            }
            break;
        }
        if (heap->data[i] < heap->data[2 * i + 1] && heap->data[2 * i + 1] > heap->data[2 * i + 2])
        {
            int swap = heap->data[i];
            heap->data[i] = heap->data[2 * i + 1];
            heap->data[2 * i + 1] = swap;
            i = 2 * i + 1;
            continue;
        }

        if (heap->data[i] < heap->data[2 * i + 2])
        {
            int swap = heap->data[i];
            heap->data[i] = heap->data[2 * i + 2];
            heap->data[2 * i + 2] = swap;
            i = 2 * i + 2;
            continue;
        }
        i=2*i+1;
    }
}
void dataout(Heap *heap)
{
    if (heap == NULL || heap->size == 0)
    {
        printf("堆为空\n");
        return ;
    }
    int top = heap->data[0];                    // 保存堆顶值
    heap->data[0] = heap->data[heap->size - 1]; // 最后一个元素移到堆顶
    heap->size--;                               // 堆大小减1
    sink(heap);
    printf("最大数%d\n", top);
}
int main()
{
    Heap *heap = createHeap(1);
    printf("1入堆,2出堆,0退出\n");
    int x;
    scanf("%d", &x);
    while (x != 0)
    {
        if (x == 1)
        {
            printf("输入入堆数字\n");
            int input;
            scanf("%d", &input);
            addnewdata(heap, input);
        }
        if (x == 2)
        {
             dataout(heap);
            
        }
        printf("1入堆,2出堆,0退出\n");
        scanf("%d", &x);
    }
}