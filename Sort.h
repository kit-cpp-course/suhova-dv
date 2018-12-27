//Sort.h

#pragma once
#include <atlimage.h>
namespace colorsort {
	/*
	* ���������� ����� ��� ������������� ������������ ������
	*/
	class Sort {
	public:
		/*
		* ���������� ����������� ������� COLORREF * array
		* left - ������ ������� �������� ����������
		* right - ������ ���������� �������� ����������
		*/
		virtual void sort(COLORREF * array, int left, int right) = 0;
	};
}
