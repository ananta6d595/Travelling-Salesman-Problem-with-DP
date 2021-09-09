#include<stdio.h>
int a[10][10],travelled[10],n,cost=0;


void costOutput();
void getValus();
void minimunCost(int r);
int leastCity(int r);


void main()
{
	getValus();
	printf("\n\nThe Path is: \n");
	minimunCost(0);
	costOutput();
}

void getValus()
{
	int i,j;
	printf("Enter No. of Cities: ");
	scanf("%d",&n);
	printf("\nEnter Cost Matrix\n");
	for(i=0; i < n; i++)
	{
		printf("\nEnter Elements of Row # : %d\n",i+1);
		for( j=0;j < n;j++)
			scanf("%d",&a[i][j]);
		travelled[i]=0;
	}
	printf("\n\nThe cost list is:\n");
	for( i=0;i < n;i++)
	{
		printf("\n");
		for(j=0;j < n;j++)
			printf("\t%d",a[i][j]);
	}
}

void minimunCost(int city)
{
	int i,newCity;
	travelled[city] = 1;	
	printf("%d -->",city+1);
	newCity = leastCity(city);
	if(newCity == 999)
	{
		newCity = 0;
		printf("%d",newCity+1);
		cost+=a[city][newCity];
		return;
	}
	minimunCost(newCity);
}

int leastCity(int c)
{
	int i,nc = 999;
	int min = 999, kostMin;
	for(i = 0; i < n; i++)
	{
		if((a[c][i]!=0) && (travelled[i]==0))
			if(a[c][i] < min)
			{
				min=a[i][0]+a[c][i];
				kostMin=a[c][i];
				nc=i;
			}
	}
	if(min!=999)
		cost+=kostMin;
	return nc;
}

void costOutput()
{
	printf("\n\nMinimum cost is ");
	printf("%d",cost);
    printf("\n\n");
}