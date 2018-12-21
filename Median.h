#pragma once
#include <atlimage.h>
#include "Filter.h"

namespace filters {

	class Median :public Filter {
	protected:
		COLORREF * * Arrarator(HDC hdc, size_t X, size_t Y);
	public:
		Median() {};
		void filtration(CImage img, size_t p, LPCSTR output);
	};


}
