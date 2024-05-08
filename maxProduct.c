#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

int	precheck(int arr[], int n, int *res)
{
	register int	negs = 0;
	
	while (n >= 0)
	{
		if (arr[n] == 0)
			return (0);
		else if (arr[n] < 0)
			negs++;
		*res *= arr[n];
		n--;
	}
	if (negs % 2 == 1)
		return (0);
	return (1);
}

int maxProductSubarray(int arr[], int n)
{
	int	res = 1;
	register int temp;
	if (n <= 0)
		return (0);
	if (precheck(arr, n, &res) == 1)
		return (res);
	register int	vars[3] = {arr[0], arr[0], arr[0]};
	while (n >= 0) 
	{
		temp
			= MAX(((vars[1] > 1) ? arr[n] * vars[1] : arr[n]),
				arr[n] * vars[0]);
		vars[0]
			= MIN(((vars[1] < 1) ? arr[n] * vars[1] : arr[n]),
				arr[n] * vars[0]);
		vars[1] = temp;
		vars[2] = MAX(vars[2], vars[1]);
		n--;
	}
	return vars[2];
}

