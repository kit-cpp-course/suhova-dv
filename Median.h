//Median.h

#pragma once
#include <atlimage.h>
#include "Filter.h"
#include "QuickSort.h"
namespace filters {
	class Median :public Filter {
	protected:
		/*
		* ��������� �����������:
		* p - �������� ������ ���� �������
		* size - ������ ���� �������
		* mediana - ������ ������� � ������� ����
		*/
		size_t p = 0, size = 0, mediana = 0;
		/*
		* ��������� ������ ������ ��������� �����������
		*/
		COLORREF * * const Arrarator(HDC hdc, size_t X, size_t Y);
		/* 
		* �������� ���� ������� ����������� hdc � ���������� [i,j] �� ���������
        */
		void Window(HDC hdc, int i, int j, COLORREF** const arr);
	public:
		/* 
		* ������������ �������� ����������� CImage img ��������� ��������.
		* size_t power - �������� ���������� (�������� ������ ���� �������)
		* LPCSTR output - ���� ���������� ����������
		*/
		void filtration(CImage img, size_t power, LPCSTR output);
	};
}
