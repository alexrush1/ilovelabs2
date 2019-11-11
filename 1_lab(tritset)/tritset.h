//
// Created by alexrush1 on 13.10.2019.
//

#ifndef LAB1_TRITSET_H
#define LAB1_TRITSET_H

#include <vector>
#include <iostream>
#include "trit.h"
#include <unordered_map>

class tritset {
	static const size_t mask = 0b11;
    int size_chars;
    int size_trits;
	std::vector <int> set;

public:
	tritset() { size_chars = 0; size_trits = 0; }
    explicit tritset(const int set_value);
	tritset(const std::initializer_list<trit>& list); //дл€ объ€влени€ через {}

	class reference {  //reference - прокси-класс
		friend class tritset;
		tritset *pTritset{};
		int pos{};
		[[nodiscard]] trit getTrit() const; //атрубут "важно не пропускать возвращаемое значение функции"
	public:
		reference(tritset& curTritset, size_t position);
		operator trit() const; // приведение типа
		reference& operator=(trit x);
		reference& operator=(reference reference);
	};

	friend class reference;
	reference operator[](int position);
	friend tritset operator&(tritset& a, tritset& b);
	friend tritset operator|(tritset& a, tritset& b);
	friend tritset operator!(const tritset& a);
	trit operator[](int position) const;
	trit getTrit();
	void shrink();
	int trit_capacity();
	int capacity();
	size_t cardinality(trit value);
	std::unordered_map< trit, int > cardinality();
	void trim(size_t lastIndex);
	size_t t_length();
};



#endif //LAB1_TRITSET_H
