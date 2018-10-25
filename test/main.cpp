#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool srch(vector<vector<vector<int> > > &table, vector<int> &newp, const vector<int> &initp, int v = 0)//assume size >= 3
{
    if(v == 0)
    {
        for(int i = 1; i < 2 * initp[v]; ++i)
        {
            newp[v] = i;
            if(srch(table, newp, initp, v+1))
                return true;
        }
        return false;
    }
    else if(v == 1)
    {
        int m = 2 * initp[v-1] - newp[v-1];
        for(int i = max(m,1); i < m+2; ++i)
        {
            if(table[v][i][newp[v-1]])
                continue;
            newp[v] = i;
            if(srch(table, newp, initp, v+1))
                return true;
            else
                table[v][i][newp[v-1]] = 1;
        }
        return false;
    }
    else if(v == initp.size()-1)
    {
        int m = 3 * initp[v-1] - newp[v-1] - newp[v-2];
        for(int i = max(m,1); i < m+3; ++i)
        {
            newp[v] = i;
            if((newp[v] + newp[v-1]) / 2 == initp[v])
                return true;
        }
        return false;
    }
    else
    {
        int m = 3 * initp[v-1] - newp[v-1] - newp[v-2];
        for(int i = max(m,1); i < m+3; ++i)
        {
            if(table[v][i][newp[v-1]])
                continue;
            newp[v] = i;
            if(srch(table, newp, initp, v+1))
                return true;
            else
                table[v][i][newp[v-1]] = 1;
        }
        return false;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> init_price;
    int tmp;
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp;
        init_price.push_back(tmp);
    }
    if(init_price.size() == 1)
    {
        cout << init_price[0] << endl;
        return 0;
    }
    if(init_price.size() == 2)
    {
        cout << 1 << " " << 2 * init_price[0] - 1 << endl;
        return 0;
    }
    vector<int> new_price(n);
    vector<vector<vector<int> > > table(n, vector<vector<int> > (300, vector<int>(300, 0)));//n * 300* 300
    srch(table, new_price, init_price);
    for(vector<int>::iterator p = new_price.begin(); p != new_price.end(); ++p)
    {
        if(p == new_price.end()-1)
            cout << *p << endl;
        else
            cout << *p << " ";
    }
    return 0;
}
