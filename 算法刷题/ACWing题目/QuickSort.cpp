#include<iostream>

using namespace std;

const int N = 1e5+10;

int n;
int q[N];


void quick_sort(int q[],int l,int r)
{
    //  如果该区间没有数字或者只有一个数字   就不需要进行排序
    if(l >= r)
    {
        return ;
    }

    // 选取中间元素 作为枢轴
    int x = q[(l + r) / 2],i  = l - 1, j = r + 1;//  取左边界
    // 这里之所以i j取边界之外的数字 是为了后面 i ++ j-- 

    while(i < j)
    {
        do i++; while(q[i] < x); // 从左往右找大于或者等于x的数字 找到就停下

        do j--; while(q[j] > x); // 右边找到小于或者等于x的数字 找到就停下

        if(i < j)
        {
            // 交换数字
            swap(q[i],q[j]);
        }
    }

    // 递归处理左右两边  j右边全部都是大于或者等于x的数字
    quick_sort(q,l,j);
    quick_sort(q,j + 1,r);

}


int main()
{
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d",&q[i]);
    }
    
    quick_sort(q,0,n - 1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ",q[i]);
    }
    return 0;
}














