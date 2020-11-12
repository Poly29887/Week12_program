#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Adrian_answer(int);
void Bruno_answer(int);
void Goran_answer(int);
void maxScore();

char ans[1000],ans_Adrian[1000], ans_Bruno[1000], ans_Goran[1000];
int count[3] , max = 0;

int main()
{
	int n,i;
	char* p, * p_ans[3], name[3][100] = {"Adrian","Bruno","Goran"};
	printf("Number of Answer : ");
	scanf("%d", &n);
	printf("Answer : ");
	scanf("%s", ans);
	Adrian_answer(n);
	Bruno_answer(n);
	Goran_answer(n);
	p = ans;
	p_ans[0] = ans_Adrian;
    p_ans[1] = ans_Bruno;
	p_ans[2] = ans_Goran;
	i = 0;
	
	while (i < 3)
	{
		while (*p != '\0')
		{
			if (*p == *p_ans[i])
			{
				count[i]++;
			}
			p++;
			p_ans[i]++;
		}
	 i++;
	 p= ans;
	}
	printf("\n");
	maxScore();
	printf("%d\n",max);
	for (i = 0; i < 3; i++)
	{
		if (count[i] == max)
		{
			printf("%s", name[i]);
			printf("\n");
		}
		
	}

}

void Adrian_answer(int x)
{
	int k;
	char letter = 'A';
	for (k = 0; k < x; k++)
	{
		
		ans_Adrian[k] = letter;
		if (letter=='C')
		{
			letter = 'A';
		}
		else
		{
            letter++;
		}
		
	}
}

void Bruno_answer(int x)
{
	int k,round=1;
	for (k = 0; k < x; k++)
	{
		if (round >4)
		{
			round = 1;
		}
		
		if (round==1||round==3)
		{
			ans_Bruno[k] = 'B';
		}
		else if (round == 2)
		{
			ans_Bruno[k] = 'A';
		}
		else if (round == 4)
		{
			ans_Bruno[k] = 'C';
		}
		round++;

	}
}

void Goran_answer(int x)
{
	
	int k, round = 1,ch=1;
	for (k = 0; k < x; k++)
	{
		
		if (round > 3)
		{
			round = 1;
		}

		if (round == 1 )
		{
			ans_Goran[k] = 'C';
		}
		else if (round == 2 )
		{
			ans_Goran[k] = 'A';
		}
		else if (round == 3)
		{
			ans_Goran[k] = 'B';
		}
		if (ch == 2)
		{
			ch = 1;
			round++;
		}
		else
		{
           ch++;
		}
		
		
	}
}

void maxScore()
{
	int k;
	max = 0;
	for (k = 0; k < 3; k++)
	{
		if (count[k]>max)
		{
			max = count[k];
		}
	}
}

