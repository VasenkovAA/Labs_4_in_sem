// Copyright 2023 VasenkovAA

#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>
#include <list>
#include "../TMonoms/TMonoms.h"
using namespace std;
template <typename T>
class TPolinom {
public:
    list<TMonom<T>> MonomList;
public:
	TPolinom(TPolinom& var):MonomList(var.MonomList) {
	}	
	TPolinom() {
	}
	TPolinom(TMonom<T> monom) {
		MonomList.push_back(monom);
	}

    TPolinom operator+(const TMonom<T> rhs) {
		TPolinom<T> result(*this);
		int j = 0;
		
		for (auto i:result.MonomList) {
			try
			{
				i = i + rhs;
			}
			catch (const std::exception&)
			{
				j++;
			}
		}
		if (j == result.MonomList.size()) {
			result.MonomList.push_back(rhs);
		
		}
		return result;
    }
	TPolinom operator + (const TPolinom<T> rhs) {
		TPolinom<T> result(*this);
		
		for (auto pMonom:rhs.MonomList) {
			int j = 0;
			for (auto i : result.MonomList) {
				try
				{
					i = i + pMonom;
				}
				catch (const std::exception&)
				{
					j++;
				}
			}
			if (j == result.MonomList.size()) {
				result.MonomList.push_back(pMonom);

			}
		}
		return result;
	}

	std::string to_string() const {
		std::string result;
		if (MonomList.empty()) {
			result = "Polynomial is empty";
		}
		else {
			for (auto i : MonomList) {
				result += " + " + i.to_string();
			}
		}
		return result;
	}
};

#endif //POLINOM_H