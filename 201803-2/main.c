#include <stdio.h>

int main(void)
{
    int n, L, t;
    int i;
    int j;
    scanf("%d%d%d", &n, &L, &t);
    int a[n];
    int idx[n];
    int dir[n];
    for(i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for(i = 0; i < n; ++i)
        idx[i] = i;

    int tmp;
    for(i = n - 1; i > 0; --i)
        for(j = 0; j < i; ++j)
        {
            int cur = j;
            if(a[idx[cur]] > a[idx[cur + 1]])
            {
                tmp = idx[cur];
                idx[cur] = idx[cur + 1];
                idx[cur + 1] = tmp;
            }
        }


    for(i = 0; i < n; ++i)
    {
        dir[i] = 1;//1:right, -1:left
    }
    for(i = 0; i < t; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            if(dir[idx[j]] == 1)
            {
                if((j < n-1 && a[idx[j+1]] == a[idx[j]]) || (j == n-1 && a[idx[j]] == L))
                    dir[idx[j]] = -dir[idx[j]];
            }
            else
            {
                if((j > 0 && a[idx[j-1]] == a[idx[j]]) || (j == 0 && a[idx[j]] == 0))
                    dir[idx[j]] = -dir[idx[j]];
            }
        }
        for (j = 0; j < n; ++j)
        {
            a[j] += dir[j];
        }
    }
    for(i = 0; i < n; ++i)
        printf("%d ", a[i]);
    return 0;
}
