//Argument.h

#pragma once
#include "Config.h"
#include <fstream>
#include <exception>
#include <regex>
namespace cmd {
	/*
	* Класс для проверки коррекности аргументов из командной строки
	*/
	class arguments {
		size_t count; //число аргументов
		char ** args; //аргументы командной строки
	protected:
		/*
		* Пребразовывает первый аргумент (адрес исходного изображения) к типу LPCSTR.
		* Если адрес указан некорректно, программа завершается.
		*/
		LPCSTR check_input() const;
		/*
		* Пребразовывает второй аргумент (путь сохранения) к типу LPCSTR.
		* Если путь указан некорректно, возвращает значение по умолчанию.
		*/
		LPCSTR check_output() const;
		/*
		* Пребразовывает третий аргумент (мощность фильтрации) к типу size_t.
		* Если данные некорректны, возвращает значение по умолчанию.
		*/
		size_t check_power() const;
	public:
		/*
		* Основной конструктор класса.
		*/
		arguments(size_t count, char * arguments[]): count(count), args(arguments) {};
		/*
		* Установка новых значений аргументов командной строки
		*/
		void ArgControl(config & cfg) const;
	};
}

LPCSTR cmd::arguments::check_input() const {
	string in = args[1];
	ifstream f(args[1]);
	if (!f.good() || !regex_match(in.begin(), in.end(), regex{ R"([^\s]+((jpg|png|gif|bmp))$)" }))
	{
		cout << endl << "Error." << endl;
		system("pause");
		exit(0);
	}
	LPCSTR input(args[1]);
	return input;
}

LPCSTR cmd::arguments::check_output() const {
	string out = args[2];
	if (!regex_match(out.begin(), out.end(), regex{ R"([^\s]+((jpg|png|gif|bmp))$)" }))
	{
		cout << endl << "Error. New output path: output.jpg" << endl;
		system("pause");
		LPCSTR output = "output.jpg";
		return output;
	}
	LPCSTR output(args[2]);
	return output;
}

size_t cmd::arguments::check_power() const {
	string in = args[3];
	size_t power = strtol(args[3], 0, 0);
	if (power<0) {
		return 1;
	}
	return power;
}

void cmd::arguments::ArgControl(config & cfg) const {
	if (count> 3) {
		cfg.m_input = check_input();
		cfg.m_output = check_output();
		cfg.m_power = check_power();
	}
	else {
		cout << "Error." << endl;
		exit(0);
	}
}