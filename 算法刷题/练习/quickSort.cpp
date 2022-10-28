#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N];
int n;

void quick_sort(int q[],int l,int r)
{
    if(l >= r)
    {
        return ;// 没有元素 或者只有一个元素 不需要排序
    }

    int i = l - 1;
    int j = r + 1;
    int mid = (l + r) / 2;// 只取左边界  或者有边界 容易出现问题 

    while(i < j)
    {
        do i++; while(q[i] < mid);// 直到找到大于或者等于x的 左指针 停下
        do j--; while(q[j] > mid); // 直到找到小于或者等于x的  右指针停下

        if(i < j)
        {
            // 两个指针都停下来
            // 交换数据
            swap(q[i],q[j]);
        }
    }

    quick_sort(q,l,j);
    quick_sort(q,j + 1,r);

}



int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&q[i]);
    }

    quick_sort(q,0,n - 1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ",q[i]);
    }

    return 0;
}