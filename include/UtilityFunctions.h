//
// Created by demongo on 23.05.19.
//

#ifndef PROJEKT3_UTILITYFUNCTIONS_H
#define PROJEKT3_UTILITYFUNCTIONS_H

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

#endif //PROJEKT3_UTILITYFUNCTIONS_H
