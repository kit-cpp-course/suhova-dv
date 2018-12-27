//Median.cpp

#include "Median.h"
using namespace filters;
using namespace colorsort;
void Median::filtration(CImage img, size_t power, LPCSTR output) {
	p = power;
	size = (2 * p + 1)*(2 * p + 1);
	size_t X, Y,imax,jmax;
	X = img.GetWidth();
	Y = img.GetHeight();
	if (size < X * Y) {
		mediana = size / 2 + 1;
		imax = X - p;
		jmax = Y - p;
		HDC hdc = img.GetDC();
		COLORREF** const arr = Arrarator(hdc, X, Y);

		for (int i = p;i < imax; i++)
		{
			for (int j = p;j < jmax;j++)
			{
				Window(hdc, i, j, arr);
			}
		}
		img.Save(output);
		for (int i = 0; i < X; i++) { delete[] arr[i]; }
		delete[] arr;
		img.ReleaseDC();
		img.Destroy();
	}
}
void Median::Window( HDC hdc, int i, int j,  COLORREF** const arr) {
	COLORREF* array = new COLORREF[size + 1];
	QuickSort qs;
	int l = i - p, r = i + p, f = j + p, c = j - p;
	int count = 0;
	for (int n = l;n <= r;n++)
		for (int k = c;k <= f;k++) {
			array[count] = arr[n][k];
			count++;
		}
	qs.sort(array, 0, count);
	SetPixel(hdc, i, j, array[mediana]);
	delete[] array;
}
 COLORREF** const Median::Arrarator(HDC hdc, size_t X, size_t Y) {
	COLORREF** const arr = new COLORREF*[X];
	for (int i = 0; i < X; i++) arr[i] = new COLORREF[Y];
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y;j++) {
			arr[i][j] = GetPixel(hdc, i, j);
		}
	}
	return arr;
}
