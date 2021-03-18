#include <stdio.h>
#include <stdlib.h>

int max(int temp);
int main(void)
{
	//get input
	int n = 0;
	scanf("%d",&n);
	//create the array
	int* w = (int*)malloc( n*sizeof(int) ) ;
	int* score = (int*)malloc( n*sizeof(int) ) ;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&w[i],&score[i]);
	}
	//figure out
	int temp = 0;
	for(int i=0;i<n;i++)
	{
		temp += w[i]*score[i];
	}
	
	int result = max(temp);
	printf("%d",result);
}

int max(int temp)
{
	return temp>0 ? temp : 0 ; 
}	
