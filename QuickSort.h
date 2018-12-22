#pragma once
#include "Sort.h"

namespace colorsort {
        /*
	* Класс, реализующий быструю сортировку цветов
	*/
	class QuickSort :public Sort{
	public:
		/*
		* Быстрая сортировка одномерного массива COLORREF * array
		* left - индекс первого элемента сортировки
		* right - индекс последнего элемента сортировки
		*/
		void sort(COLORREF* array, int left, int right);
	};
}
