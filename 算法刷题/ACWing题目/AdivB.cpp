#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// A/b 商是C 余数r
vector<int> div(vector<int> &A,int b,int &r)
{
    vector<int> C;
    r = 0;
    for(int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];

        C.push_back(r / b);
        r = r % b;
    }

    reverse(C.begin(),C.end());// 反转数组  数组低位对低位  高位对高位

    // 去除前导0  比如003   0 是低位   3 是高位
    while(C.size() > 1 && C.back() == 0)
    {
        // 数组C的长度大于1  并且C的低位是0
        C.pop_back();// 去除末尾的0   循环该动作 
    }

    return C;
}


int main()
{
    string a;
    int b;
    cin>>a>>b;

    vector<int> A;

    for(int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }

    int r;
    vector<int> C = div(A,b,r);

    for(int i = C.size() - 1; i >= 0; i--)
    {
        printf("%d",C[i]);
    }
    cout<<endl<<r<<endl;
    return 0;
}
