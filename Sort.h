#pragma once
#include <atlimage.h>

namespace colorsort {

	class Sort {
	public:
		virtual void sort(COLORREF * array, int left, int right) = 0;
	};
}
