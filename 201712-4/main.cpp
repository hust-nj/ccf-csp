#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const unsigned long long INF = 0x7f7f7f7f7f7f7f7f;
const unsigned long long MAXSIZE = 501;
unsigned long long sroad[MAXSIZE][MAXSIZE];
unsigned long long broad[MAXSIZE][MAXSIZE];
unsigned long long sdist[MAXSIZE];
unsigned long long bdist[MAXSIZE];
bool sflag[MAXSIZE];
bool bflag[MAXSIZE];
int n, m;

void process_sroad()
{//using floyd
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(sroad[i][j] > sroad[i][k] + sroad[k][j])
                    sroad[i][j] = sroad[i][k] + sroad[k][j];
    for(int i = 1; i<= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(sroad[i][j] != INF)
                sroad[i][j] = sroad[i][j] * sroad[i][j];
}

void dijkstra()
{
    sdist[1] = bdist[1] = 0;
    for(int cnt = 0; cnt < 2 * n; ++cnt)
    {
        unsigned long long svtx = 0, sdistl = INF;
        for(int i = 1; i <= n; ++i)//find in small
        {
            if(!sflag[i] && sdist[i] < sdistl)
            {
                sdistl = sdist[i];
                svtx = i;
            }
        }
        unsigned long long bvtx = 0, bdistl = INF;
        for(int i = 1; i <= n; ++i)
        {
            if(!bflag[i] && bdist[i] < bdistl)
            {
                bdistl = bdist[i];
                bvtx = i;
            }
        }
        if(sdistl < bdistl)
        {
            sflag[svtx] = true;
            for(int i = 1; i <= n; ++i)//update
                bdist[i] = min(bdist[i], sdistl + broad[svtx][i]);
        }
        else
        {
            bflag[bvtx] = true;
            for(int i = 1; i <= n; ++i)
            {
                bdist[i] = min(bdist[i], bdistl + broad[bvtx][i]);
                sdist[i] = min(sdist[i], bdistl + sroad[bvtx][i]);
            }
        }
        if(sflag[n] && bflag[n])
            break;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    memset(sroad, INF, sizeof(sroad));
    memset(broad, INF, sizeof(broad));
    memset(sdist, INF, sizeof(sdist));
    memset(bdist, INF, sizeof(bdist));
    unsigned long long t, a, b, c;
    for(int i = 0; i < m; ++i)
    {
        cin >> t >> a >> b >> c;
        if(t == 1)
            sroad[a][b] = sroad[b][a] = min(c, sroad[a][b]);
        else
            broad[a][b] = broad[b][a] = min(c, broad[a][b]);
    }
    process_sroad();
    dijkstra();
    cout << min(sdist[n], bdist[n]) << endl;
    return 0;
}
