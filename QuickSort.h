//QuickSort.h

#pragma once
#include "Sort.h"
namespace colorsort {
	/*
	* �����, ����������� ������� ���������� ������
	*/
	class QuickSort :public Sort{
	public:
		/*
		* ������� ���������� ����������� ������� COLORREF * array
		* left - ������ ������� �������� ����������
		* right - ������ ���������� �������� ����������
		*/
		void sort(COLORREF* array, int left, int right);
	};
}
