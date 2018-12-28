﻿//Filter.h

#pragma once
#include <atlimage.h>

namespace filters {
	/*
	* Абстракный класс над всевозможными алгоритмами фильтрации изображений
	*/
	class Filter {
	public:
		/*
		* Виртуальная функция, фильтрующая изображение img с мощностью p.
		* LPCSTR output - путь сохранения результата
		*/
		virtual const void filtration(CImage img, size_t p, LPCSTR output) = 0;
	};
}