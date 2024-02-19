// Copyright 2023 VasenkovAA
#ifndef POLINOM_H_TEST
#define POLINOM_H_TEST
#include "gtest.h"
#include <climits>
//#include "../TMonoms/TMonoms.h"  
#include "../TPolinoms/TPolinoms.h"

// Test case for add polinom with monoms
TEST(TPolinomTest, AddPolinomAndMonom1) {
    TPolinom<int>polinom1;
    TMonom<int> monom1, monom2;
    monom1.addVar(TVarible<int>(2, Fraction(1, 2)));
    monom2.addVar(TVarible<int>(1, Fraction(1, 2)));
    EXPECT_EQ(polinom1.MonomList.size(),0);
    auto polinom2 = new TPolinom<int>(polinom1 + monom2);
    EXPECT_EQ(polinom2->MonomList.size(),1);
}

TEST(TPolinomTest, AddPolinomAndMonom2) {
    TPolinom<int>polinom1;
    TMonom<int> monom1, monom2;
    monom1.addVar(TVarible<int>(2, Fraction(1, 2)));
    monom2.addVar(TVarible<int>(1, Fraction(1, 2)));
    polinom1.MonomList.push_back(monom1);
    EXPECT_EQ(polinom1.MonomList.size(), 1);
    auto polinom2 = new TPolinom<int>(polinom1 + monom2);
    EXPECT_EQ(polinom2->MonomList.size(), 2);
}

TEST(TPolinomTest, AddPolinomAndMonom3) {
    TPolinom<int>polinom1;
    TMonom<int> monom1, monom2,monom3;
    monom1.addVar(TVarible<int>(2, Fraction(1, 2)));
    monom2.addVar(TVarible<int>(1, Fraction(1, 2)));
    monom3.addVar(TVarible<int>(5, Fraction(1, 2)));
    polinom1.MonomList.push_back(monom1);
    EXPECT_EQ(polinom1.MonomList.size(), 1);
    auto polinom2 = new TPolinom<int>((polinom1 + monom2) + monom3);
    EXPECT_EQ(polinom2->MonomList.size(), 3);
}



TEST(TPolinomTest, AddPolinomAndPolinom1) {
    TPolinom<int>polinom1;
    TMonom<int> monom1, monom2, monom3;
    monom1.addVar(TVarible<int>(2, Fraction(1, 2)));
    monom2.addVar(TVarible<int>(1, Fraction(1, 2)));
    monom3.addVar(TVarible<int>(5, Fraction(1, 2)));
    polinom1.MonomList.push_back(monom1);
    monom3.addVar(TVarible<int>(12, Fraction(1, 2)));
    TPolinom<int>polinom3;
    polinom3.MonomList.push_back(monom3);

    EXPECT_EQ(polinom1.MonomList.size(), 1);


    auto polinom2 = new TPolinom<int>(polinom1 + polinom3);
    EXPECT_EQ(polinom2->MonomList.size(), 2);
    cout << polinom2->to_string() << endl;
}

#endif //POLINOM_H_TEST