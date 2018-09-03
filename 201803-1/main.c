#include <stdio.h>

int main(void)
{
    int jump;
    int scores = 0;
    int cur = 1;
    while(scanf("%d", &jump) && jump)
    {
        if(jump == 2)
        {
            if(cur == 1)
                cur = 2;
            else
                cur += 2;
        }
        else
        {
            cur = 1;
        }
        scores += cur;
    }
    printf("%d\n", scores);
    return 0;
}
