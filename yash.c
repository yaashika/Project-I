#include<stdio.h>
#include<stdlib.h>

int main()
{
	float Base;
	int i,j,Process;
	//Process Number input
	printf("Enter the number of processes:-\n");
	scanf("%d",&Process);
	float Recent[Process],NewRecent[Process],New[Process];
	float previous[Process];
	
	//Base input
	printf("Enter the base:-\n");
	scanf("%f",&Base);
	//system("pause");
	//system("cls");
	
	//Recent CPU Usage
	for(i=0;i<Process;i++)
	{
		printf("Enter the recent CPU Usage for %d process:-\n",i+1);
		scanf("%f",&Recent[i]);
		previous[i]=Recent[i];
		//system("pause");
		//system("cls");
	}
	//Previous priority Higher the CPU Usage higher the priority
	for (i=0;i<(Process-1);i++)
  	{
  		float temp;
    	for (j=0;j<Process-i-1;j++)
    	{
    	  if (previous[j]<previous[j+1])
    	  {
    	    temp=previous[j];
    	    previous[j]=previous[j+1];
    	    previous[j+1]=temp;
    	  }
    	}
  	}
  	printf("\nPrevious priorty order:-\n");
	for(i=0;i<Process;i++)
	{
		for(j=0;j<Process;j++)
		{
			if(Recent[i]==previous[j])
			{
				printf("P[%d]\t",j+1);
			}
		}
	}
	
	//New Priority order
	for(i=0;i<Process;i++)
	{
		NewRecent[i]=(Recent[i]/2)+Base;
		New[i]=NewRecent[i];
	}
	for (i=0;i<(Process-1);i++)
  	{
  		float temp;
    	for (j=0;j<Process-i-1;j++)
    	{
    	  if (NewRecent[j]>NewRecent[j+1])
    	  {
    	    temp=NewRecent[j];
    	    NewRecent[j]=NewRecent[j+1];
    	    NewRecent[j+1]=temp;
    	  }
    	}
  	}
	printf("\nNew priorty order:-\n");
	for(i=0;i<Process;i++)
	{
		for(j=0;j<Process;j++)
		{
			if(New[i]==NewRecent[j])
			{
				printf("P[%d]\t",j+1);
			}
		}
	}
	printf("\n \nThe scheduler lowers the relative priority of CPU bound process");
	return 0;
}
