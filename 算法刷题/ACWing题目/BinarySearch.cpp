#include<iostream>
using namespace std;

const int N = 1e5 + 10;

int n,m;
int q[N];

int main()
{
    scanf("%d%d",&n,&m);

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&q[i]);
    }

    while(m--)
    {
        int x;
        scanf("%d",&x);

        int l = 0,r = n -1;

        while(l < r)
        {
            // 认为你要查找的数字在左边  那么使用模板二
            int mid = l + r >> 1;
            if(q[mid] >= x)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        if(q[l] != x)
        {
            //说明没找到，并且q[l] 是第一个大于x的数字
            cout<<"-1 -1"<<endl;
        }
        else
        {
            cout<<l<<" ";  // 查找到数字 
            // 但是使用模板二是从左往右查找的第一个大于或者等于x的数字 偏向于x
            // 这只从左边找到一个数字，但是 这道题要查找的数字是多个的
            // 这就意味着我还要从右往左在查找一次数字  这样就找到一个数字的下标范围
            
            int l = 0, r = n - 1;

            while(l < r)
            {
                int mid = l + r + 1>> 1;// 第二个模板  加一！

                if(q[mid] <= x)
                {
                    l = mid;
                }
                else{
                    r = mid - 1;
                }
            }

            cout<<l<<endl;  // 这里输出的l 是从右往左找第一个小于或者等于x的数字

        }
    }

    return 0;
}