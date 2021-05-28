#include <iostream>
#include "IteratorColectie.h"
#include "Colectie.h"
using namespace std;


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	/* Complexitate: 0(1) */

	//setare iterator pe prima pozitite
	pozCurenta = 0;
}

TElem IteratorColectie::element() const{
	/* Complexitate: 0(1) */

	if (valid() == false)
		throw exception();
	else
		return col.element[pozCurenta];
}

bool IteratorColectie::valid() const {
	/* Complexitate: 0(1) */

	//verificam daca iteratorul mai este valid
	if (pozCurenta < col.dim())
		return true;
	return false; 
}

void IteratorColectie::urmator() {
	/* Complexitate: 0(1) */

	if (valid() == false)
		throw exception();
	pozCurenta++;

}

void IteratorColectie::prim() {
	/* Complexitate: 0(1) */

	//resetare iterator pe prima pozitie
	pozCurenta = 0;
}
