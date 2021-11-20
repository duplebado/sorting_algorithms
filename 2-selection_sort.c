#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i, j, index_of_smallest;
	int temp, smallest_changed = 0;

	for (i = 0; i < size; i++)
	{
		index_of_smallest = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[index_of_smallest] > array[j])
			{
				index_of_smallest = j;
				smallest_changed = 1;
			}
		}

		if (smallest_changed)
		{
			temp = array[i];
			array[i] = array[index_of_smallest];
			array[index_of_smallest] = temp;
			print_array(array, size);
		}

		smallest_changed = 0;
	}
}
