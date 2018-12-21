#pragma once
#include <atlimage.h>

namespace filters {

	class Filter {
	public:
		virtual void filtration(CImage img, size_t p, LPCSTR output) = 0;
	};
}