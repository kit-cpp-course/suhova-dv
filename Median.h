//Median.h

#pragma once
#include <atlimage.h>
#include "Filter.h"
#include "QuickSort.h"
namespace filters {
	/*
	* Класс, реализующий медианную фильтрацию
	*/
	class Median :public Filter {
	protected:
		/*
		* Параметры изображения:
		* p - половина ширины окна фильтра
		* size - размер окна фильтра
		* mediana - индекс медианы в массиве окна
		*/
		size_t p = 0, size = 0, mediana = 0;
		/*
		* Возвращет массив цветов исходного изображения
		*/
		COLORREF * * const Arrarator(HDC hdc, size_t X, size_t Y);
		/* 
		* Заменяет цвет пикселя изображения hdc с координами [i,j] на медианный
        */
		void Window(HDC hdc, int i, int j, COLORREF** const arr);
	public:
		/* 
		* Обрабатывает исходное изображение CImage img медианным фильтром.
		* size_t power - мощность фильтрации (половина ширины окна фильтра)
		* LPCSTR output - путь сохранения результата
		*/
		const void filtration(CImage img, size_t power, LPCSTR output);
	};
}
