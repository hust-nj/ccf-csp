#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<bool> v(n, true);
    int del = 0;
    int num = 1, cur = 0;
    while(del != n-1)
    {
        cur %= n;
        if(v[cur] == false)
            ++cur;
        else if(num % k == 0 || num % 10 == k)
        {
            v[cur] = false;
            ++del;
            ++num;
            ++cur;
        }
        else
        {
            ++num;
            ++cur;
        }
    }
    cout << find(v.begin(), v.end(), true) - v.begin() + 1 << endl;
    return 0;
}
