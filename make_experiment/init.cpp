#include <stdlib.h>
#include "new_new_operator.h"
void initialize_matrix(int** ptr,int n)
{
	for (int i=0; i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			ptr[i][j]=rand()%100;
		}
	}
}