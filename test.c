#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	int t=10;
	printf("%d\n",t);
	int n,m,u,v,w;
	while(t--)
	{
		n=(rand()%100)+1;
		m=(rand()%1000)+1;
		printf("%d %d\n",n,m);
		for(i=1;i<=m;i++)
		{
			u=(rand()%n+1);
			v=(rand()%n+1);
			if(u==v)
				w=0;
			else
				w=(rand()%100);
			printf("%d %d %d\n",u,v,w);
		}
	}
	return 0;
}
