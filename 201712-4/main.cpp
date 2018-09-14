#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n);
    int i;
    for(i = 0; i < m; i++)
    {
        int t, a, b, c;
        cin >> t >> a >> b >> c;
        if(t)c = c*c;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    return 0;
}
