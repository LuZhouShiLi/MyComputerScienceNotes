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
        return ;
    }

    int mid = l + r >> 1;

    // 先划分  然后再归并
    merge_sort(q,l,mid);
    merge_sort(q,mid + 1,r);

    int k = 0;
    // 这里的i j 设置不同于快速排序
    int i = l;
    int j = mid + 1;

    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j])
        {
            tmp[k] = q[i];
            i++;
            k++;
        }
        else{
            tmp[k] = q[j];
            j++;
            k++;
        }
    }

    while(i <= mid)
    {
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


    for(int i = 0,j = l; j <= r; j++,i++)
    {
        q[j] = tmp[i];
    }

}


int main()
{
    // scanf("%d",&n);
    int n = 3;

    for(int i = 0; i < 3; i++)
    {
        scanf("%d",&q[i]);
    }

    merge_sort(q,0,n - 1);

    for(int i = n - 1; i >= 0; i--)
    {
        printf("%d ",q[i]);
    }
}





