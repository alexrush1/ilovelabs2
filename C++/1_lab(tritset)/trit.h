//
// Created by alexrush1 on 13.10.2019.
//

#ifndef LAB1_TRIT_H
#define LAB1_TRIT_H

#include <iostream>

enum class trit {Unknown = 0, False, True};

trit operator&(const trit& left, const trit& right);
trit operator|(const trit& left, const trit& right);
trit operator!(const trit& a);

std::ostream& operator<<(std::ostream& out, trit value);

#endif //LAB1_TRIT_H
