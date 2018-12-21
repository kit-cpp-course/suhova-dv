#include "Median.h"
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace filters;
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	
	std::string out, in;

	cout << " Enter the source image address: ";
	getline(cin, in);
	char const * c_in=in.c_str();
	ifstream f(c_in);
	if (f.good()) {
		if (!regex_match(in.begin(), in.end(), regex{ R"([^\s]+((jpg|png|gif|bmp))$)" }))
		{
			cout << endl << "Error.";
			system("pause");
			return 0;
		}
	}else {
		cout << endl << "Error."<<endl;
		system("pause");
		return 0;
	}
	LPCSTR input(c_in);

	cout << endl << " Enter the save path: ";
	getline(cin, out);
	char const * c_out = out.c_str();
	if (!regex_match(out.begin(), out.end(), regex{ R"([^\s]+((jpg|png|gif|bmp))$)" }))
	{
		cout << endl << "Error.";
		system("pause");
		return 0;
	}
	LPCSTR output(c_out);

	size_t p=0;
	cout << endl << " Enter filtering power (1 - 10) : ";
	cin >> p;
	if (!p) {
		cout << endl << "Error.";
		system("pause");
		return 0;
	}

	CImage img;
	img.Load(input);
	Median med;
	med.filtration(img, p, output);
		
	return 0;
}