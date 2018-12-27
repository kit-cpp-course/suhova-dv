//main.cpp

#include "Median.h"
#include <iostream>
#include "Arguments.h"
using namespace filters;
using namespace std;
/*
* Аргументы принимаются из командной строки
* Требуется ввести 3 аргумента: адрес исходного изображения, путь сохранения и мощность фильтраци (натуральное число)
*/
int main(size_t count, char ** args) {
	setlocale(LC_ALL, "ru");
	config conf = config::instance();
	cmd::arguments argcheck(count, args);
	argcheck.ArgControl(conf);

	CImage img;
	img.Load(conf.input());
	Median med;
	med.filtration(img, conf.power(), conf.output());
		
	return 0;
}