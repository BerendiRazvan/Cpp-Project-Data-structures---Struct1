#include <iostream>

#include "TestExtins.h"
#include "TestScurt.h"

using namespace std;


int main() {
	
	testAll();
	testAllExtins();

	cout << "Teste trecute\n";
	return 0;
}


/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------

Sa se implementeze în C++ un anumit container de date (TAD) folosind o anumita
reprezentare (indicata) si un vector dinamic ca structura de date. Se va folosi implementare
proprie pentru vectorul dinamic.

--------------------------------------------------------------------------------------------------------------------------------------------------------------

P9. TAD Colectie cu elemente de tip comparabil (TElement=TComparabil)– reprezentare folosind
un vector dinamic cu elementele ordonate in raport cu relatia de ordine R = (<= mai mic sau egal).

--------------------------------------------------------------------------------------------------------------------------------------------------------------
*/