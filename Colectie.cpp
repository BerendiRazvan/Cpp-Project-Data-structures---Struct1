#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
	/* Complexitate: 0(1) */

	if (e1 <= e2)
		return true;
	return false;
}



void Colectie::redim() {
	/* Complexitate: 0(n) */

	TElem* elemNou = new TElem[2 * capacitate];
	for (int i = 0; i < nrElem; i++) {
		elemNou[i] = element[i];
	}

	delete[] element;
	element = elemNou;

	this->capacitate *= 2;

}


Colectie::Colectie() {
	/* Complexitate: 0(1) */

	this->capacitate = 1; 

	element = new TElem[capacitate];

	this->nrElem = 0;
}

void Colectie::adauga(TElem e) {
	/* Complexitate: O(n) */
	
	//redim daca e cazul
	if (nrElem == capacitate)
		redim();

	int i = 0;
	//cautam pozitia pe care inseram noul element
	while (i < nrElem && rel(element[i], e))
		i++;
	
	//mutam elemente

	int pozIsert = i;
	i = nrElem;
	while (i > pozIsert) {
		element[i] = element[i - 1];
		i--;
	}

	//inseram element
	this->element[pozIsert] = e;
	nrElem++;
}

 
bool Colectie::sterge(TElem e) {
	/* Complexitate: O(n) */

	int Sol = -1, Left = 0, Right = nrElem;
	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;
		if (element[Mid] == e)
		{
			Sol = Mid;
			break;
		}
		if (element[Mid] > e)
			Right = Mid - 1;
		if (element[Mid] < e)
			Left = Mid + 1;
	}
	if (Sol == -1)
		return false;
	else {
		for (int j = Sol; j < nrElem; j++)
			element[j] = element[j + 1];
		nrElem--;
		return true;
	}

}


bool Colectie::cauta(TElem elem) const {
	/* Complexitate: O(log2(n)) */

	int Sol = -1, Left = 0, Right = nrElem;
	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;
		if (element[Mid] == elem)
		{
			Sol = Mid;
			break;
		}
		if (element[Mid] > elem)
			Right = Mid - 1;
		if (element[Mid] < elem)
			Left = Mid + 1;
	}
	if (Sol == -1)
		return false;
	else
		return true;
	
}


int Colectie::nrAparitii(TElem elem) const {
	/* Complexitate: O(n) */


	int contor = 0;

	int Sol = -1, Left = 0, Right = nrElem;
	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;
		if (element[Mid] == elem)
		{
			Sol = Mid;
			break;
		}
		if (element[Mid] > elem)
			Right = Mid - 1;
		if (element[Mid] < elem)
			Left = Mid + 1;
	}
	if (Sol == -1)
		return contor;
	else {
		int i = Sol;
		while (element[Sol] == element[i])
			contor++, i++;
		i = Sol - 1;
		while (element[Sol] == element[i])
			contor++, i--;

		return contor;
	}

}



int Colectie::dim() const {
	/* Complexitate: 0(1) */
	return nrElem;
}


bool Colectie::vida() const {
	/* Complexitate: 0(1) */
	if (nrElem == 0)
		return true;
	return false;
}


IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* Complexitate: 0(1) */
	delete[] element;
}

