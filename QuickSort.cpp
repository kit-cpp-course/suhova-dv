//QuickSort.cpp

#include "QuickSort.h"
using namespace colorsort;
void QuickSort::sort(COLORREF* array, int left, int right) {
	int i = left, j = right;
	int tmp;
	int p = array[(left + right) / 2]; 									
	while (i <= j)
	{
		while (array[i] < p) i++;
		while (array[j] > p) j--;
		if (i <= j)
		{
			tmp = array[i]; array[i] = array[j]; array[j] = tmp;
			i++; j--;
		}
	};
	if (left < j) sort(array, left, j);
	if (i < right) sort(array, i, right);
}