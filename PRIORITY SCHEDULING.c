#include<stdio.h>
int main()
{
	int n,i,j,temp,temp1;
	float avgwt=0,avgtt=0;
	printf("enter no of processors :");
	scanf("%d",&n);
	int processor[n],burst[n],gantchart[n],priority[n];
	for(i=0;i<n;i++)
	{
		processor[i]=i+1;
		printf("enter the burst time and priority of %d processor :",processor[i]);
		scanf("%d%d",&burst[i],&priority[i]);
		gantchart[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(priority[i]>priority[j])
			{
				temp=priority[i];
				priority[i]=priority[j];
				priority[j]=temp;
				
				temp1=burst[i];
				burst[i]=burst[j];
				burst[j]=temp1;
			}
		}
	}
	for(i=0;i<n;i++)
    {
		if(i==0)
		{
			gantchart[i]=gantchart[i]+burst[i];
			avgwt=0;
			avgtt=gantchart[i];
		}
		else
		{
			gantchart[i]=gantchart[i-1]+burst[i];
			avgwt=avgwt+gantchart[i-1];
			avgtt=avgtt+gantchart[i];
		}
	}
	printf("average waiting time :%f",avgwt/n);
	printf("\naverage turn around time :%f",avgtt/n);
    return 0;
}