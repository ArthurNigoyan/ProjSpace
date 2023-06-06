#include "new_new_operator_i.h"
int sum_of_num_under_diag(int** ptr,int n)
{
	int sum=0;
	for (int i=1; i<n; i++)
	{
		for (int j=0; j<i; j++)
		{
			sum=sum+ptr[i][j];
		}
	}
	return sum;
}