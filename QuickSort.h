#pragma once
#include "Sort.h"

namespace colorsort {

	class QuickSort :public Sort{
	public:
		QuickSort() {};
		void sort(COLORREF* array, int left, int right);
	};
}
