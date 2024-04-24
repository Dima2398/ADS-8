// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
	Cage{ false, nullptr, nullptr };
	countOp = 0;
	first = nullptr;
}
void Train::addCage(bool a) {
	if (!first) {
		first = new Cage;
		first->light = a;
		first->prev = first;
		first->next = first;
	} else {
		Cage* p = first;
		while (p->next != first)
			p = p->next;
		Cage* tmp = new Cage;
		tmp->light = a;
		tmp->prev = tmp->next = nullptr;
		tmp->prev = p;
		p->next = tmp;
		tmp->next = first;
		first->prev = tmp;
	}
}
int Train::getOpCount() {
	return countOp;
}
int Train::getLength() {
	int length = 0;
	int count_steps = 0;
	int count_steps_2 = 0;
	Cage* h = first;
		if (h->light == false) {
			h->light = true;
			h = h->next;
			count_steps++;
			while (true) {
				while (h->light != true) {
					count_steps++;
					h = h->next;
				}
				h = h->prev;
				count_steps_2++;
				while (h->light != true) {
					count_steps_2++;
					h = h->prev;
				}
				if (count_steps_2 == count_steps) {
					countOp = count_steps * 2;
					return count_steps;
				}
		    }
	} else { //if (h->light == true) {
			h->light = false;
			h = h->next;
			count_steps++;
			while (true) {
				while (h->light != false) {
					count_steps++;
					h = h->next;
				}
				h = h->prev;
				count_steps_2++;
				while (h->light != false) {
					count_steps_2++;
					h = h->prev;
				}
				if (count_steps_2 == count_steps) {
					countOp = count_steps * 2;
					return count_steps;
				}
			}
	}
}
