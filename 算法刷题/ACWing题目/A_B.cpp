#include<iostream>
#include<vector>

using namespace std;

// 判断是否有 A >= B
bool cmp(vector<int> &A, vector<int> &B)
{
    // 此时的数组低位存储 个位 
    // 长度不一致
    if(A.size() != B.size())
    {
        return A.size() > B.size();
    }

    // 长度一致  从最高位开始比较  987 986 
    // 数组中这两个数组应该是：789 689
    for(int i = A.size() - 1; i >= 0; i--)
    {
        // 从最高位开始比较
        if(A[i] != B[i])
        {
            return A[i] > B[i];
        }
    }
    return true;
}

// C = A - B
vector<long long> sub(vector<int> &A, vector<int> &B)
{
    vector<long long> C;

    // C = 976 - 967  6 -7 不够减  t < 0 
    for(int i = 0,t = 0; i < A.size(); i++)
    {
        t = A[i] - t;

        if(i < B.size()) t -= B[i];

        // 如果 t < 0 那么借位 + 10 ， 如果t > 0，+ 10 之后% 10 不影响
        // 不管t 是否大于0 还是小于0 这种情况都包含
        C.push_back((t + 10) % 10); 

        //  t < 0 说明有借位
        if(t < 0) t = 1;  
        else t = 0;  // 没有借位
    }

     while(C.size() > 1 && C.back() == 0)
     {
         C.pop_back();// 如果最后结果是 3 0 0  那么去掉高位的两个0 留下最低为3 
         // 这里的3 0 0 是3 这个数字在数组中的存储形式
     }

    return C;
}


int main()
{
    string a,b;
    vector<int>A,B;

    cin>>a>>b;

    // 9 6 7 存储在数组中是：7 6 9
    // 也就是数组低位存储数字低位  数组高位存储数字高位
    for(int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }


    for(int i = b.size() - 1; i >= 0; i--)
    {
        B.push_back(b[i] - '0');
    }

    // for(int i = B.size() - 1; i >= 0; i--)
    // {
    //     printf("%d",B[i]);
    // }
    // cout<<endl;

    if(cmp(A,B))
    {
        vector<long long> C = sub(A,B);
        // 数组低位存储数字低位 数组高位存储数字高位  倒着打印
        for(int i = C.size() - 1; i >= 0; i--)
        {
            printf("%d",C[i]);
        }
    }
    else{

        vector<long long> C = sub(A,B);
        printf("-");
        for(int i = C.size() - 1; i >= 0; i--)
        {
            printf("%d",C[i]);
        }

    }


    
}

