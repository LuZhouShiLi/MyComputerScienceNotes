#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int q[N];
int tmp[N];
int n;

void merge_sort(int q[],int l,int r)
{
    if(l >= r)
    {
        return;// 只有一个数 或者没有 不需要排序
    }
    int mid = l + r>> 1;

    // 先划分
    merge_sort(q,l,mid);
    merge_sort(q,mid + 1,r);

    int k = 0,i = l, j = mid + 1;
    // 将数组分为两段  开始两两比较

    // 开始归并
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j])
        {
            tmp[k] = q[i];
            k++;
            i++;
        }
        else
        {
            tmp[k] = q[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        // 还有剩余的数字 这些数都比j那一半的数字大
        tmp[k] = q[i];
        k++;
        i++;
    }

    while(j <= r)
    {
        tmp[k] = q[j];
        k++;
        j++;
    }
    
}


int main()
{
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&q[i]);
    }
    
    merge_sort(q,0,n - 1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ",q[i]);
    }


    return 0;
}

