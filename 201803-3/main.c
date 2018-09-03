#include <stdio.h>
#include <ctype.h>

int match(const char*, const char*, char*);

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    char re[n][102];
    char name[n][102];
    char str[102];
    int i;

    for(i = 0; i < n; ++i)
    {
    	scanf("%s%s", re[i], name[i]);
    }

    for(i = 0; i < m; ++i)
    {
    	scanf("%s", str);
    	int j = 0;
    	char success[200];
    	while(!match(str, re[j], success) && j < n)
    		++j;
    	if(j == n)
    		printf("404\n");
    	else
    	{
    		printf("%s %s\n", name[j], success);
    	}
    }
    return 0;
}

int match(const char* str, const char* re, char* success)
{
	const char *p = str, *q = re;
	char *psuc = success;
	while(*p && *q)
	{
		if(*p == *q)
			++p, ++q;
		else if(*q++ == '<')
		{
			if(*q == 's')//str
			{
				while(*p != '/' && *p != '\0')
				{
					*psuc++ = *p++;
				}
				*psuc++ = ' ';
				q = q + 4;//*q == '/'
			}
			else if(*q == 'i')//int
			{
			    int flag = 0;
				while(*p != '/' && *p != '\0')
				{
					if(!isdigit(*p))
						return 0;
					if(*p != '0' || flag == 1)
					{
						flag = 1;
						*psuc++ = *p++;
					}
					else
						p++;
				}
                if(flag == 0)
                    *psuc++ = '0';
				*psuc++ = ' ';
				q = q + 4;
			}
			else//path
			{
				while(*p != '\0')
				{
					*psuc++ = *p++;
				}
				q = q + 5;
			}

		}
		else
			return 0;
	}
	*psuc = '\0';
	if(*p == *q)return 1;
	else return 0;
}
