// Copyright 2023 VasenkovAA

#include "gtest.h"
#include <climits>
//#include "../TMonoms/TMonoms.h"  
//TEST(TVaribleTest, SetVariable) {
//    TVarible<int> var(42, 3);
//    var.setVariable(78);
//    EXPECT_EQ(78, var.getVariable());
//}
//
//// Test case for setting the degree
//TEST(TVaribleTest, SetDegree) {
//    TVarible<int> var(42, 3);
//    var.setDegree(Fraction(2, 3));
//    EXPECT_EQ(Fraction(2, 3), var.getDegree());
//}
//
//// Test case for getting the variable
//TEST(TVaribleTest, GetVariable) {
//    TVarible<int> var(42, 3);
//    var.setVariable(78);
//    EXPECT_EQ(78, var.getVariable());
//}
//
//// Test case for getting the degree
//TEST(TVaribleTest, GetDegree) {
//    TVarible<int> var(42, 3);
//    var.setDegree(Fraction(2, 3));
//    EXPECT_EQ(Fraction(2, 3), var.getDegree());
//}
//
//// Test case for the equality operator
//TEST(TVaribleTest, OperatorEqual) {
//    TVarible<int> var1(42, 3);
//    TVarible<int> var2(42, 3);
//    EXPECT_EQ(var1, var2);
//}
//
////// Test case for the not-equal operator
////TEST(TVaribleTest, OperatorNotEqual) {
////    TVarible<int> var1(42, 3);
////    TVarible<int> var2(42, 4);
////    EXPECT_NE(var1, var2);
////}
//
//// Test case for the less-than operator
//TEST(TVaribleTest, OperatorLess) {
//    TVarible<int> var1(42, 3);
//    TVarible<int> var2(42, 4);
//
//
//    EXPECT_LT(var1, var2);
//}
//
//// Test case for the less-than-or-equal operator
//TEST(TVaribleTest, OperatorLessOrEqual) {
//    TVarible<int> var1(42, 3);
//    TVarible<int> var2(42, 4);
//    EXPECT_LE(var1, var2);
//}
//
//// Test case for the greater operator
//TEST(TVaribleTest, OperatorGreater) {
//    TVarible<int> var1(42, 3);
//    TVarible<int> var2(42, 2);
//    EXPECT_GT(var1, var2);
//}
//
////// Test case for the greater-or-equal operator
////TEST(TVaribleTest, OperatorGreaterOrEqual) {
////    TVarible<int> var1(42, 3);
////    TVarible<int> var2(42, 4);
////    EXPECT_GE(var1, var2);
////}
//
//// Test case for the run function
//TEST(TVaribleTest, Run) {
//    TVarible<float> var(3.14, 2);
//    ASSERT_NEAR(pow(3.14, 2), var.run(),0.00001);
//}
//
//// Test case for the pow function
//TEST(FractionTest, Pow) {
//    Fraction result = pow<float>(2, Fraction(3, 2));
//    ASSERT_NEAR(pow(2, 1.5), result.run(),0.5);
//}
//
//TEST(TMonomTest, AddVarTest1) {
//    TMonom<int> monom1, monom2;
//    monom1.addVar(TVarible<int>(2, Fraction(1, 2)));
//    monom2.addVar(TVarible<int>(2, Fraction(1, 2)));
//    TMonom<int> result( monom1 + monom2);
//    EXPECT_EQ(result.var.size(), 1);
//    EXPECT_EQ(result.coef, Fraction(6, 3));
//}
//TEST(TMonomTest, AddVarTest2) {
//    TMonom<int> monom1, monom2;
//    monom1.addVar(TVarible<int>(2, Fraction(1, 2)));
//    monom2.addVar(TVarible<int>(2, Fraction(1, 2)));
//    monom2.coef = 6;
//    TMonom<int> result(monom1 + monom2);
//    EXPECT_EQ(result.var.size(), 1);
//    EXPECT_EQ(result.coef, Fraction(7, 1));
//}
//TEST(TMonomTest, AddVarTest3) {
//    TMonom<int> monom1, monom2;
//    monom1.addVar(TVarible<int>(2, Fraction(1, 2)));
//    monom2.addVar(TVarible<int>(2, Fraction(1, 2)));
//    TMonom<int> result(monom1 + monom2);
//    EXPECT_EQ(result.var.size(), 1);
//    EXPECT_EQ(result.coef, Fraction(6, 3));
//}
//TEST(TMonomTest, AddVarTest4) {
//    TMonom<int> monom1, monom2;
//    monom1.addVar(TVarible<int>(2, Fraction(1, 2)));
//    monom2.addVar(TVarible<int>(2, Fraction(1, 2)));
//    TMonom<int> result(monom1 + monom2);
//    EXPECT_EQ(result.var.size(), 1);
//    result.coef  = 2;
//    EXPECT_EQ(result.coef, Fraction(6, 3));
//}
//
//TEST(TMonomTest, DifVarTest) {
//    TMonom<int> monom1, monom2;
//    monom1.addVar(TVarible<int>(2, Fraction(1, 2)));
//    monom2.addVar(TVarible<int>(2, Fraction(1, 2)));
//    TMonom<int> result(monom1 - monom2);
//    EXPECT_EQ(result.var.size(), 1);
//    EXPECT_EQ(result.coef, Fraction(0, 1));
//}
//





