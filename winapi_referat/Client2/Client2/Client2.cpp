// Client2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	
	typedef int(__stdcall *ttest)();
	typedef double(*MYPROC)(const char*,const int);
	HINSTANCE hDll;
	MYPROC Fwypisz;
	hDll = LoadLibrary(L"MyLibrary");
	/*
	Funkcja test wypisuje "ok", to tylko sprawdzenie czy ładowanie biblioteki działa.
	Przy funkcji wypisz(simple_print) niestety nie chce nic wypisać. Być możee problemem jest ta zmienna sygnatura funckji.
	*/
	if (hDll != NULL)
	{
		ttest test = (ttest)GetProcAddress(hDll, "test");
		test();

		Fwypisz = (MYPROC)GetProcAddress(hDll, "wypisz");

		if (Fwypisz!= NULL)
		{
			(Fwypisz)("d",10);
		}
		

		FreeLibrary(hDll);
	}

	return 0;
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
