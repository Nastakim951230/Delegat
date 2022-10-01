#include <stdio.h>
#include <malloc.h>

int intfuc;
int Summ(int a, int b)
{
	return a + b;
}
int Razn(int a, int b)
{
	return a - b;
}
int Ymn(int a, int b)
{
	return a * b;
}

typedef int (*fpoin)(int, int);
typedef fpoin* delegate;

delegate intgelegat()
{
	delegate g = calloc(1, sizeof(fpoin));
	return g;
}

void addFun(delegate g, fpoin f)
{
	g[intfuc] = f;
	intfuc++;
	g = realloc(g, (intfuc + 1) * sizeof(fpoin));
}

void removeFun(delegate g, fpoin f, char type)
{
	for (size_t i = 0; i < intfuc; i++)
	{
		if (g[i]==f)
		{
			intfuc--;
			for (size_t j = i; j < intfuc; j++)
			{
				g[j] = g[j + 1];
			}
			g = realloc(g, (intfuc + 1) * sizeof(fpoin));
			if (type)
			{
				break;
			}
		}
	}
}

void removePovtor(delegate g)
{
	int k = 0;
	int p = 0;
	int l = 0;
	do
	{
		int s = 0;
		int r = 0;
		int y = 0;
		for (size_t i = 0; i < intfuc; i++)
		{

			if (g[i])
			{
				if (g[i] == Summ)
				{
					s++;
					if (s > 1)
					{
						intfuc--;
						for (size_t j = i; j < intfuc; j++)
						{
							g[j] = g[j + 1];
						}
					}
				}
				else if (g[i] == Razn)
				{
					r++;
					if (r > 1)
					{
						intfuc--;
						for (size_t j = i; j < intfuc; j++)
						{
							g[j] = g[j + 1];
						}
					}
				}
				else if (g[i] == Ymn)
				{
					y++;
					if (y > 1)
					{
						intfuc--;
						for (size_t j = i; j < intfuc; j++)
						{
							g[j] = g[j + 1];
						}
					}
				}
				g = realloc(g, (intfuc + 1) * sizeof(fpoin));

			}

		}
		k = s;
		p = r;
		l = y;
	} while ((k > 1) || (p > 1) || (l > 1));

}

void Show(delegate g, int a, int b)
{
	for (size_t i = 0; i < intfuc; i++)
	{
		if (g[i])
		{
			printf("%d ", g[i](a, b));
		}
	}
	printf("\n");
}

int main()
{
	delegate g = intgelegat();
	addFun(g, Summ);
	addFun(g, Razn);
	addFun(g, Ymn);
	addFun(g, Ymn);
	addFun(g, Razn);
	addFun(g, Summ);
	addFun(g, Summ);
	addFun(g, Razn);
	addFun(g, Ymn);
	addFun(g, Ymn);
	addFun(g, Razn);
	addFun(g, Summ);


	Show(g, 8, 2);
	removePovtor(g);
	Show(g, 8, 2);

	return 0;
}
