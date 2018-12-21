#include "Median.h"
#include "QuickSort.h"

using namespace filters;
using namespace colorsort;

void Median::filtration(CImage img, size_t p, LPCSTR output) {
		
	size_t X, Y, size, mediana, imax,jmax;
	X = img.GetWidth();
	Y = img.GetHeight();
	size = (2 * p + 1)*(2 * p + 1);
	if (size < X * Y) {
		mediana = size / 2 + 1;
		imax = X - p;
		jmax = Y - p;
		HDC hdc = img.GetDC();
		QuickSort qs;
		COLORREF** arr = Arrarator(hdc, X, Y);
		COLORREF* array = new COLORREF[size + 1];

		for (int i = p;i < imax; i++)
		{
			for (int j = p;j < jmax;j++)
			{
				int l = i - p, r = i + p, f = j + p, c = j - p;
				int count = 0;
				for (int n = l;n <= r;n++)
					for (int k = c;k <= f;k++) {
						array[count] = arr[n][k];
						count++;
					}
				qs.sort(array, 0, count);
				img.SetPixel(i, j, array[mediana]); 
			}
		}

		img.Save(output);

		for (int i = 0; i < X; i++) { delete[] arr[i]; }
		delete[] arr;
		delete[] array;
		img.ReleaseDC();
		img.Destroy();
	}
}


COLORREF** Median::Arrarator(HDC hdc, size_t X, size_t Y) {
	COLORREF** arr = new COLORREF*[X];
	for (int i = 0; i < X; i++) arr[i] = new COLORREF[Y];
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y;j++) {
			arr[i][j] = GetPixel(hdc, i, j);
		}
	}
	return arr;
}
