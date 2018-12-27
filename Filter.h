//Filter.h

#pragma once
#include <atlimage.h>
namespace filters {
	/*
	* ���������� ����� ��� ������������� ����������� ���������� �����������
	*/
	class Filter {
	public:
		/*
		* ����������� �������, ����������� ����������� img � ��������� p.
		* LPCSTR output - ���� ���������� ����������
		*/
		virtual void filtration(CImage img, size_t p, LPCSTR output) = 0;
	};
}