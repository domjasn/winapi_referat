// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "stdarg.h"

using namespace std;

int mnoz(int pierwszy, ...) //tu coś nie działa
{
	va_list arg;
	int iloczyn = 1, t;
	va_start(arg, pierwszy);
	for (t = pierwszy; t; t = va_arg(arg, int)) {
		iloczyn *= t;
	}
	
	va_end(arg);
	return iloczyn;
}
//tutaj działa
void simple_print(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	while (*fmt != '\0') {
		if (*fmt == 'd') {
			int i = va_arg(args, int);
			cout << i << '\n';
		}
		else if (*fmt == 's') {
			char * s = va_arg(args, char*);
			cout << s << '\n';
		}
		++fmt;
	}

	va_end(args);
}



int main()
{
	cout << "Wynik mnozenia: " << mnoz(1, 2,3); 
	cout << endl;
	/*Żeby funkcja simple_print działała w pierwszym argumencie trzeba podać
	symbole typów argumentów, które występują póżniej, jeśli chce wypisać 4 inty to pierwszy argument
	wygląda tak: "dddd" */
	simple_print("dddd", 10, 20, 30, 40);
	simple_print("ss", "hello", "world");
	simple_print("ds", 23, "kk");
}
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
