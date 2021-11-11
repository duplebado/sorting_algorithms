#include "sort.h"

/**
 * bubble_sort - sorts an array using bubble sort
 * algorithm
 * @array: the array to be sorted
 * @size: size of @array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, loopAgain = 1;
	int temp;

	if (!array)
		return;

	for (i = 0; (i < size - 1) && loopAgain; i++)
	{
		loopAgain = 0;

		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				loopAgain = 1;
				print_array(array, size);
			}
		}
	}
}
