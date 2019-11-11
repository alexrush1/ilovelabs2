//
// Created by alexrush1 on 13.10.2019.
//

#include "trit.h"

trit operator&(const trit& left, const trit& right) {
	if ((left == trit::False) || (right == trit::False))
		return trit::False;
	else if ((left == trit::Unknown) || (right == trit::Unknown))
		return trit::Unknown;
	else
		return trit::False;
}

trit operator!(const trit& a) {
	if (a == trit::True) {
		return trit::False;
	}
	else if (a == trit::False) {
		return trit::True;
	} else {
		return trit::Unknown;
	}
}

std::ostream& operator<<(std::ostream& out, trit value){
	if (value == trit::False) {
		out << "False";
	}
	else if (value == trit::True) {
		out << "True";
	}
	else if (value == trit::Unknown) {
		out << "Unknown";
	}
	return out;
}

trit operator|(const trit& left, const trit& right) {
	if ((left == trit::True) || (right == trit::True))
		return trit::True;
	else if ((left == trit::Unknown) || (right == trit::Unknown))
		return trit::Unknown;
	else
		return trit::False;
}