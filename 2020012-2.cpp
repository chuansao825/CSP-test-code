//本题写法错误，导致复杂度过高引起超时
#include <stdio.h>
#include <stdlib.h>

//predict function , return the prediction
int predict( int seita, int* y , int i );
//figure the match number of y[i] and return it
int figure( int* y , int i , int* result);
//find the seita from all of the y[i]
int find( int* y, int m , int* result );


int main(void)
{
	
	//get input
	int m = 0;
	scanf("%d",&m);
	int* y = (int*)malloc(sizeof(int)*m);
	int* result = (int*)malloc(sizeof(int)*m);
	for( int i=0 ; i<m ; i++ )
	{
		scanf("%d%d",&y[i],&result[i]);
	}
	//end input
	
	//figure out
	int bestseita = find( y , m , result );
	printf("%d",bestseita);
}



int predict( int seita, int* y , int i )
{
	// just show 
	return y[i]>=seita ? 1 : 0 ;
}


int figure( int* y , int i , int* result , int m )
{
	int seita = y[i];
	int temp = 0;
	for(int k = 0 ; k<m ; k++)
	{
		predict( seita , y , k ) == result[k] ? temp=temp+1 : temp=temp ;
	}
	return temp;
}


int find( int* y, int m , int* result )
{
	int* matchnum = (int*)malloc(sizeof(int)*m);
	
	for( int i=0 ; i<m ; i++ )
	{
		matchnum[i] = figure( y , i , result , m );
	}
	
	int indexofmax = 0 ; 
	for(int i=0 ; i<m ; i++)
	{
		if( matchnum[indexofmax] <= matchnum[i] )
		{
			if( matchnum[indexofmax] < matchnum[i] )
				indexofmax = i;
			else
			{
				if( y[indexofmax]>=y[i] )
					;
				else
					indexofmax = i;
			}
		}
		
			
	}
	
	return y[indexofmax];
}
