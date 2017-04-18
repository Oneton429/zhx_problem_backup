#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>

using namespace std;

#define problem "J"
#define prename "J"

char djm[1000];

int z[100010];

int cases=10;

int mode=1;

int getrand()
{
	return (rand()<<16)+rand();
}

void make_data(int test)
{
	int t=1;
	for (;t--;)
	{
		int n=getrand()%100000+1;
		printf("%d\n",n);
		for (int a=1;a<=n;a++)
		{
			if (rand()%2) printf("-");
			printf("%lf",rand()+(double)rand()/RAND_MAX);
			if (a==n) printf("\n");
			else printf(" ");
		}
		for (int a=1;a<=n;a++)
		{
			printf("%lf",rand()+(double)rand()/RAND_MAX);
			if (a==n) printf("\n");
			else printf(" ");
		}
	}
}

int main()
{
	//srand(time(0));

	for (int a=1;a<=cases;a++)
	{
		fprintf(stderr,"%d\n",a);
		if (mode == 1)
		{
			sprintf(djm,problem "%d.in",a);
			freopen(djm,"w",stdout);

			make_data(a);

			fclose(stdout);

#ifdef unix
			sprintf(djm,"./" problem " < " problem "%d.in > " problem "%d.out",a,a);
#else
			sprintf(djm,problem ".exe < " problem "%d.in > " problem "%d.out",a,a);
#endif
			system(djm);
		}
		if (mode == 2)
		{
#ifdef unix
			sprintf(djm,"mv " prename "%d.in " problem "%d.in",a,a);
#else
			sprintf(djm,"rename " prename "%d.in " problem "%d.in",a,a);
#endif
			system(djm);

#ifdef unix
			sprintf(djm,"mv " prename "%d.out " problem "%d.out",a,a);
#else
			sprintf(djm,"rename " prename "%d.out " problem "%d.out",a,a);
#endif
			system(djm);
		}
	}

	return 0;
}
