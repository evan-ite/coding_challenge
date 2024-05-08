// C program to find Maximum Product Subarray
#include <stdio.h>
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)


/* Returns the product of max product subarray. */
int maxProductSubarray(int arr[], int n)
{
	if (n < 1) {
		return 0;
	}
	// max positive product
	// ending at the current position
	int max_ending_here = arr[0];

	// min negative product ending
	// at the current position
	int min_ending_here = arr[0];

	// Initialize overall max product
	int max_so_far = arr[0];
	/* Traverse through the array.
	the maximum product subarray ending at an index
	will be the maximum of the element itself,
	the product of element and max product ending previously
	and the min product ending previously. */
	for (int i = 1; i < n; i++) {
		int temp
			= MAX(MAX(arr[i], arr[i] * max_ending_here),
				arr[i] * min_ending_here);
		min_ending_here
			= MIN(MIN(arr[i], arr[i] * max_ending_here),
				arr[i] * min_ending_here);
		max_ending_here = temp;
		max_so_far = MAX(max_so_far, max_ending_here);
	}
	return max_so_far;
}
