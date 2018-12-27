//config.h

#pragma once
#include <string>
#include <atlimage.h>
using namespace std;
namespace cmd {
	class arguments;
}
/*
* Singleton ����� ��� �������� ���������� ���������
*/
class config {
	friend class cmd::arguments;
	static config m_instance;
	LPCSTR m_input; // ����� ��������� �����������
	LPCSTR m_output; // ���� ����������
	size_t m_power; // �������� ����������

	config() {};
public:
	/*
	* ���������� ������������
	*/
	static config & instance() {
		return m_instance;
	}
	/*
	* ���������� ����� ��������� �����������
	*/
	const LPCSTR & input() const {
		return m_input;
	}
	/*
	* ���������� ���� ����������
	*/
	const LPCSTR & output() const {
		return m_output;
	}
	/*
	* ���������� �������� ����������
	*/
	const size_t & power() const {
		return m_power;
	}
};
config config::m_instance = config();
