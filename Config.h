//config.h

#pragma once
#include <string>
#include <atlimage.h>
using namespace std;
namespace cmd {
	class arguments;
}
/*
* Singleton класс для хранения аргументов программы
*/
class config {
	friend class cmd::arguments;
	static config m_instance;
	LPCSTR m_input; // адрес исходного изображения
	LPCSTR m_output; // путь сохранения
	size_t m_power; // мощность фильтрации

	config() {};
public:
	/*
	* Возвращает конфигурации
	*/
	static config & instance() {
		return m_instance;
	}
	/*
	* Возвращает адрес исходного изображения
	*/
	const LPCSTR & input() const {
		return m_input;
	}
	/*
	* Возвращает путь сохранения
	*/
	const LPCSTR & output() const {
		return m_output;
	}
	/*
	* Возвращает мощность фильтрации
	*/
	const size_t & power() const {
		return m_power;
	}
};
config config::m_instance = config();
