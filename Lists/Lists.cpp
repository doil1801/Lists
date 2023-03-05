#include <iostream>
struct Element;
using namespace std;

struct List {
	unsigned int amount = 0;
	Element* lastEl = nullptr;
	Element* startEl = nullptr;
};

struct Element {
	int value = 0;
	unsigned int id = 0;
	Element* prev_ptr = nullptr;
	Element* next_ptr = nullptr;
};

void Append(List* lPtr, int val) {
	Element* newElPtr = (Element*) malloc(sizeof(Element));
	if (lPtr->amount == 0) lPtr->startEl = newElPtr;
	newElPtr -> id = lPtr->amount;
	newElPtr->value = val;
	newElPtr->next_ptr = nullptr;
	newElPtr->prev_ptr = lPtr->lastEl;
	if (lPtr->amount != 0) newElPtr->prev_ptr->next_ptr = newElPtr;
	lPtr->lastEl = newElPtr;
	lPtr->amount++;
}

int GetElement(List* lPtr, unsigned int idEl) {
	if (idEl > lPtr->amount) {
		cout << "ЭЭЭ";
	}
	else {
		Element* thisElPtr = lPtr->startEl;
		for (int i = 0; i < idEl; i++) {
			if (thisElPtr != nullptr) thisElPtr = thisElPtr->next_ptr;
			else break;
		}
		return thisElPtr->value;
	}
}

void DelElement(List* lPtr, unsigned int idEl) {
	if (idEl > lPtr->amount || lPtr->amount == 0) {
		cout << "NO";
		return;
	}
	else {
		Element* thisElPtr = lPtr->startEl;
		for (int i = 0; i < idEl; i++) {
			if (thisElPtr != nullptr) thisElPtr = thisElPtr->next_ptr;
			else break;
		}
		if (thisElPtr -> prev_ptr != nullptr  && thisElPtr->next_ptr != nullptr) {
			thisElPtr->prev_ptr->next_ptr = thisElPtr->next_ptr;
			thisElPtr->next_ptr->prev_ptr = thisElPtr->prev_ptr;
		} else if (thisElPtr->prev_ptr != nullptr) {
			thisElPtr->prev_ptr->next_ptr = nullptr;
			lPtr->lastEl = thisElPtr->prev_ptr;
		} else if (thisElPtr->next_ptr != nullptr) {
			thisElPtr->next_ptr->prev_ptr = nullptr;
			lPtr->startEl = thisElPtr->next_ptr;
		}
		lPtr->amount--;
		free(thisElPtr);
	}
}

void PrintList(List* lPtr) {
	Element* thisElPtr = lPtr->startEl;
	for (int i = 0; i < lPtr->amount; i++) {
		cout << i << " - " << thisElPtr->value << endl;
		thisElPtr = thisElPtr->next_ptr;
	}
}

int main() {
	List m;
	Append(&m, 1);
	Append(&m, 2);
	Append(&m, 3);
	Append(&m, 4);
	PrintList(&m);
	DelElement(&m, 0);
	cout << endl << endl;
	PrintList(&m);
	return 0;
}