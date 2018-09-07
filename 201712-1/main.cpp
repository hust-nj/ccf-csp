#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    vector<int> num;
    cin >> n;// >= 2
    int tmp, i, minVal = 10000;
    for(i = 0; i < n; i++)
    {
        cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());
    vector<int>::iterator p;
    for(p = num.begin(); p != num.end()-1; p++)
        minVal = min(minVal, *(p+1)-*p);
    cout << minVal << endl;
    return 0;
}
