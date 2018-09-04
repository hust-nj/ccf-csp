#include <stdio.h>

#define sign(score) (score%2 ? 1 : -1)

int zero_num(int chess[][3])
{
	int sum = 0;
	int i;
	for(i = 0; i < 9; i++)
	{
		if(!chess[0][i]) sum++;
	}
	return sum;
}

int win(int chess[][3])//chess size = 3 x 3
{
	int i;

	int count = 1;
	if(chess[0][0] && chess[0][0] == chess[0][1] && chess[0][1] == chess[0][2] ||
		chess[1][0] && chess[1][0] == chess[1][1] && chess[1][1] == chess[1][2] ||
		chess[2][0] && chess[2][0] == chess[2][1] && chess[2][1] == chess[2][2] ||
		chess[0][0] && chess[0][0] == chess[1][0] && chess[1][0] == chess[2][0] ||
		chess[0][1] && chess[0][1] == chess[1][1] && chess[1][1] == chess[2][1] ||
		chess[0][2] && chess[0][2] == chess[1][2] && chess[1][2] == chess[2][2] ||
		chess[0][0] && chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] ||
		chess[0][2] && chess[0][2] == chess[1][1] && chess[1][1] == chess[2][0]
				)
		{
			for(i = 0; i < 9; i++)
				if(chess[0][i] == 0)
					count += 1;
			return count;
		}
	else return 0;
}

int scores(int chess[][3])
{
	int tmp = win(chess);
	if(tmp!=0 || zero_num(chess) == 0)//end game
	{
		return tmp * sign(tmp);
	}
	else
	{
		int i;
		if(zero_num(chess)%2)//alice's turn
		{
			int max = -10;
			for(i = 0; i < 9; i++)
			{

				if(chess[0][i] == 0)
				{
                    int a[3][3];
                    int j;
                    for(j = 0; j < 9; j++)
                        a[0][j] = chess[0][j];//copy
					a[0][i] = 1;
					int tmp = scores(a);
					max = tmp>max?tmp:max;
				}
			}
			return max;
		}
		else//bob's turn
		{
			int min = 10;
			for(i = 0; i < 9; i++)
			{
				if(chess[0][i] == 0)
				{
					int a[3][3], j;
					for(j = 0; j < 9; j++)
						a[0][j] = chess[0][j];//copy
                    a[0][i] = 2;
                    int tmp = scores(a);
                    min = tmp<min?tmp:min;
				}
			}
			return min;
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	int i;
	for(i = 0; i < T; i++)
	{
		int chess[3][3];
		int j;
		for(j = 0; j < 9; j++)
			scanf("%d", &chess[0][j]);
		printf("%d\n", scores(chess));
	}
	return 0;
}
