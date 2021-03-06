// MyLibrary.cpp : Defines the exported functions for the DLL.
#include "stdafx.h"
#include "iostream"
#include "stdarg.h"
#include "MyLibrary.h"

using namespace std;

void test() {
	cout << "ok" << endl;
}
void wypisz(const char *type, ...) {
	va_list args;
	va_start(args, type);

	while (*type != '\0') {
		if (*type == 'd') {
			int i = va_arg(args, int);
			cout << i << '\n';
		}
		else if (*type == 's') {
			char * s = va_arg(args, char*);
			cout << s << '\n';
		}
		++type;
	}

	va_end(args);

}

