// C program to find Maximum Product Subarray
#include <stdio.h>

// Find maximum between two numbers.
int max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

// Find minimum between two numbers.
int min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

/* Returns the product of max product subarray. */
int maxSubarrayProduct(int arr[], int n)
{
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
			= max(max(arr[i], arr[i] * max_ending_here),
				arr[i] * min_ending_here);
		min_ending_here
			= min(min(arr[i], arr[i] * max_ending_here),
				arr[i] * min_ending_here);
		max_ending_here = temp;
		max_so_far = max(max_so_far, max_ending_here);
	}
	return max_so_far;
}

// Driver code
int main()
{
	int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Maximum Sub array product is %d",
		maxSubarrayProduct(arr, n));
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
