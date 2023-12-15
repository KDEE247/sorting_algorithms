#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps 2 Integers in an Array.
 * @a: 1st Integer Swapped.
 * @b: 2nd Integer Swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 * the Lomuto Partition Scheme (last element as pivot).
 * @array: The array of Integers.
 * @size: The Size of the Array.
 * @left: Starting Index of the Subset to Order.
 * @right: The Ending Index of the Subset to Order.
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the Quicksort Algorithm via recursion.
 * @array: An Array of Integers sorted.
 * @size: The Size of the Array.
 * @left: Starting Index of Array Partition to order.
 * @right: Ending Index of Array Partition to order.
 * Description: Uses the Lomuto Partition Scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an Array of Integers in Ascending
 * Order Using the Quicksort Algorithm.
 * @array: An Array of Integers.
 * @size: The Size of the Array.
 * Description: Uses the Lomuto Partition Scheme.
 * Prints Array After Each Swap of 2 Elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
