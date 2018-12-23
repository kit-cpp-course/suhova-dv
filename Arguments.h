#pragma once
#include "Config.h"
#include <fstream>
#include <exception>
#include <regex>

namespace cmd {
	/*
	*  ласс дл€ проверки коррекности аргументов из командной строки
	*/
	class arguments {
		size_t count; //число аргументов
		char ** args; //аргументы командной строки
	protected:
		/*
		* ѕребразовывает первый аргумент (адрес исходного изображени€) к типу LPCSTR.
		* ≈сли адрес указан некорректно, программа завершаетс€.
		*/
		LPCSTR check_input() const {
		string in = args[1];
			ifstream f(args[1]);
			if (!f.good() && !regex_match(in.begin(), in.end(), regex{ R"([^\s]+((jpg|png|gif|bmp))$)" }))
			{
				cout << endl << "Error." << endl;
				system("pause");
				exit(0);
			}
			LPCSTR input(args[1]);
			return input;
		}
		/*
		* ѕребразовывает второй аргумент (путь сохранени€) к типу LPCSTR.
		* ≈сли путь указан некорректно, возвращает значение по умолчанию.
		*/
		LPCSTR check_output() const {
		string out = args[2];
			if (!regex_match(out.begin(), out.end(),regex{ R"([^\s]+((jpg|png|gif|bmp))$)" }))
			{
				cout << endl << "Error. New output path: output.jpg" << endl;
				system("pause");
				LPCSTR output= "output.jpg";
				return output;
			}
			LPCSTR output(args[2]);
			return output;
		}
		/*
		* ѕребразовывает третий аргумент (мощность фильтрации) к типу size_t.
		* ≈сли данные некорректны, возвращает значение по умолчанию.
		*/
		size_t check_power() const {
		    string in = args[3];
			size_t power = strtol(args[3],0,0);
			if (power<0) {
				return 1;
			}
			return power;
		}

	public:
		/*
		* ќсновной конструктор класса.
		*/
		arguments(size_t count, char * arguments[]): count(count), args(arguments) {};
		/*
		* ”становка новых значений аргументов командной строки
		*/
		void ArgControl(config & cfg) const {
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
	};
}
