/* You MUST modify this file */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
	// allocate an arry of n elements
	int * arr = malloc(sizeof(* arr) * n);
	int i;
	int count = 0;
	int remaining = n;
	// check whether memory allocation succeeds.
	// if allocation fails, stop
	if (arr == NULL)
	{
		fprintf(stderr, "malloc fail\n");
		return;
	}
	  
	// Note that from here on, you can access elements of the arr with
	// expressions like a[i]
	  
	// initialize all elements
	// ith index of arr is assigned ith value
	for (i = 0; i < n; i++) 
	{
		arr[i] = i;
	}  

	// reset the index i back to 0
	// to use for the subsequent loop
	i = 0;
	
	// counting to k,
	// mark the eliminated element
	// print the index of the marked element
	// repeat until only one element is unmarked
	while (remaining > 1) 
	{
		if (arr[i] != -1) 
		{
			count++;
			
			if (count == k) 
			{
				arr[i] = -1;
				printf("%d\n", i);

				remaining--;
				count = 0;
			}
		}

		i = (i + 1) % n;
	}
	

	// print the last one
	for (i = 0; i < n; i++) 
	{
		if (arr[i] != -1) 
		{
			printf("%d\n", arr[i]);
			break;
		}
	}	



	// release the memory of the array
	free (arr);
}
#endif
