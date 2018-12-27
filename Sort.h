//Sort.h

#pragma once
#include <atlimage.h>
namespace colorsort {
	/*
	* Абстракный класс над всевозможными сортировками цветов
	*/
	class Sort {
	public:
		/*
		* Сортировка одномерного массива COLORREF * array
		* left - индекс первого элемента сортировки
		* right - индекс последнего элемента сортировки
		*/
		virtual void sort(COLORREF * array, int left, int right) = 0;
	};
}
