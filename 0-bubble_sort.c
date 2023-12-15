#include "sort.h"
/**
 * swap_ints - Swaps 2 Integers in an Array.
 * @a: 1st Integer to Swap.
 * @b: 2nd Integer to Swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an Array of Integers in Ascending Order.
 * @array: An Array of Integers to Sort.
 * @size: The Size of the Array.
 * Description: Prints Array After Each Swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
