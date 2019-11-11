//
// Created by alexrush1 on 13.10.2019.
//

#include "tritset.h"
#include "trit.h"
#include <iostream>


tritset::tritset(const int set_value) { //Конструктор
    if (set_value < 0)
		throw std::invalid_argument("parameter set_value cannot be less than 0");
	size_trits = set_value;
	size_chars = (set_value % 4 == 0) ? set_value / 4 : set_value / 4 + 1;
	set.resize(size_chars);
}

tritset operator&(tritset& left, tritset& right) { //оператор "и"
	size_t size = (left.size_trits >= right.size_trits) ? left.size_trits : right.size_trits;
	tritset result(size);
	for (size_t i = 0; i < size; i++) {
		result[i] = left[i] & right[i];
	}
	return result;
}

tritset operator|(tritset& left, tritset& right) { //оператор "или"
	size_t size = (left.size_trits >= right.size_trits) ? left.size_trits : right.size_trits;
	tritset result(size);
	for (size_t i = 0; i < size; i++) {
		result[i] = left[i] | right[i];
	}
	return result;
}

tritset operator!(const tritset& a) { //оператор "не"
	tritset result(a.size_trits);
	for (int i = 0; i < a.size_trits; i++) {
		result[i] = !a[i];
	}
	return result;
}

trit tritset::operator[](int position) const { //оператор []
	if (position < 0)
		throw std::invalid_argument("position cannot be less than zero");
	if (position >= size_trits)
		return trit::Unknown;
	return (trit)((set[position / 4] & (mask << (6 - 2 * (position % 4))))
		>> (6 - 2 * (position % 4))); //доступ к (6 - 2 * position % 4)-му триту
}

trit tritset::getTrit(){
	return trit();
}

void tritset::shrink(){ //уменьшение размера до последнего не "unknown" трита
	size_t length = this->t_length();
	if (length != 0) {
		size_chars = (length - 1) / 4 + 1;
		size_trits = length;
		set.resize(size_chars);
	}
	else {
		size_chars = 0;
		size_trits = 0;
		set.resize(0);
	}
}

int tritset::trit_capacity(){
	return size_trits;
}

int tritset::capacity() {
	return size_chars;
}

size_t tritset::cardinality(trit value){ //подсчёт определенного значения в set
	size_t count = 0;
	for (int i = 0; i < size_trits; i++) {
		if ((*this)[i] == value)
			count++;
	}
	return count;
}

std::unordered_map<trit, int> tritset::cardinality(){
	std::unordered_map<trit, int> count;
	for (int i = 0; i < size_trits; i++) {
		if ((*this)[i] == trit::True) {
			count[trit::True]++;
		}
		else if ((*this)[i] == trit::False) {
				count[trit::False]++;
			} else {
			count[trit::Unknown]++;
			}
	}
	return count;
}

void tritset::trim(size_t lastIndex){ //удаление содержимого от lastIndex и дальше
	if ((lastIndex < 0)||(lastIndex > size_trits)) 
		throw std::invalid_argument("lastIndex error");
	for (int i = lastIndex; i <= size_trits; i++) {
		(*this)[i] = trit::Unknown;
	}
}

size_t tritset::t_length(){ //длина set
	for (size_t i = this->size_trits; i > 0; --i) {
		if ((*this)[i - 1] != trit::Unknown)
			return i;
	}
	return 0;
}

tritset::tritset(const std::initializer_list<trit>& list) : tritset(list.size()) {
	size_t i = 0;
	for (const auto& element : list) {
		(*this)[i] = element;
		i++;
	}
}

tritset::reference tritset::operator[](int position) { //оператор индексации
	if (position < 0)
		throw std::invalid_argument("position cannot be less than zero");
	return tritset::reference(*this, position);
}

trit tritset::reference::getTrit() const{ //получаем значение трита
	if (pTritset->size_trits <= pos)
		return trit::Unknown;
	return (trit)((pTritset->set[pos / 4] & (mask << (6 - 2 * (pos % 4))))
		>> (6 - 2 * (pos % 4)));
}

tritset::reference::reference(tritset& t_set, size_t position) : pos(position){ //конструктор reference
	this->pTritset = &t_set;
}

tritset::reference::operator trit() const{ //приведение к типу trit
	return this->getTrit();
}

tritset::reference& tritset::reference::operator=(trit x) { //присваивание значению
	if (pTritset->size_trits <= pos) {
		if (x == trit::Unknown) {
			return *this;
		}
		else {
			pTritset->size_chars = (pos % 4 == 0) ? pos / 4 : pos / 4 + 1;
			pTritset->set.resize(pTritset->size_chars);
			pTritset->size_trits = pos + 1;
		}
	}
	pTritset->set[pos / 4] = ((pTritset->set[pos / 4] & ~(mask << (6 - 2 * (pos % 4)))));
	pTritset->set[pos / 4] = pTritset->set[pos / 4] | ((unsigned)x << (6 - 2 * (pos % 4)));
	return *this;
}

tritset::reference& tritset::reference::operator=(const tritset::reference reference) { //-||-
	*this = reference.getTrit();
	return *this;
}