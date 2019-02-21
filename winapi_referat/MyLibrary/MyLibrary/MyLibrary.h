#pragma once

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif


extern "C" MYLIBRARY_API void wypisz(char *type ...);
extern "C" MYLIBRARY_API void test();

