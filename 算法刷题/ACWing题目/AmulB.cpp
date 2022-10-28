#include<iostream>
#include<vector>

using namespace std;


vector<long long> mul(vector<long long> &A,long long b)
{
    vector<long long> C;

    int t = 0;//进位
    for(int i = 0; i < A.size(); i++)
    {
        if(i < A.size())
        {
            t += A[i] * b;
        }

        C.push_back(t % 10);
        t = t  / 10;  // 这里的t 进位就不是1了
    }

    if(t != 0)
    {
        C.push_back(t);
    }

    return C;
}


int main()
{
    string a;
    long long b;
    cin>>a>>b;

    vector<long long> A;
    for(int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }

    vector<long long> C = mul(A,b);

    for(int i = C.size() - 1; i>= 0; i--)
    {
        printf("%d",C[i]);
    }

    return 0;

}
