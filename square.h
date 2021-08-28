///\file
///\brief head file on program solves linear and square equation (mail.cpp)


#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>
#include <assert.h>


const double EPS = 1e-7;    // малая величина

enum solutions
{
    INF_ROOT = -1,
    NO_ROOT = 0,
    ONE_ROOT = 1,
    TWO_ROOT = 2
};


//---------------------------------------------------------------------------
//! The function reads the parameters a, b, c from the keyboard
//!
//! @param [in]   a    pointer to a
//! @param [in]   b    pointer to b
//! @param [in]   c    pointer to c
//! @param [out]  a    a-coefficient
//! @param [out]  b    b-coefficient
//! @param [out]  c    c-coefficient
//---------------------------------------------------------------------------
void ScanThreeCoef (double* a, double* b, double* c);


//---------------------------------------------------------------------------
//! Solve a quadric and linear equation ax^2+bx+c=0
//!
//! @param [in]   a    a-coefficient
//! @param [in]   b    b-coefficient
//! @param [in]   c    c-coefficient
//! @param [out]  x1   Pointer to the 1st root
//! @param [out]  x2   Pointer to the 2st root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots, returns -1
//---------------------------------------------------------------------------
solutions SolveSquareLinearEq (const double a, const double b, const double c, double* x1, double* x2);


//---------------------------------------------------------------------------
//! Solve a linear equation
//!
//! @param [in]   b            b-coefficient
//! @param [in]   c            c-coefficient
//! @param [out]  x1           Pointer to the 1st root
//!
//! @return Number of roots
//---------------------------------------------------------------------------
solutions SolveLinearEq (const double b, const double c, double* x1);


//---------------------------------------------------------------------------
//! Solve a quadric equation
//!
//! @param [in]   a           a-coefficient
//! @param [in]   b           b-coefficient
//! @param [in]   c           c-coefficient
//! @param [out]  x1          Pointer to the 1st root
//! @param [out]  x2          Pointer to the 2st root
//!
//! @return Number of roots
//---------------------------------------------------------------------------
solutions SolveQuadricEq (const double a, const double b, const double c, double* x1, double* x2);


//---------------------------------------------------------------------------
//! The function considers the discriminant
//!
//! @param [in]   a            a-coefficient
//! @param [in]   b            b-coefficient
//! @param [in]   c            c-coefficient
//!
//! @return   The value of the discriminant
//---------------------------------------------------------------------------
static inline double CalcDiscriminant (const double a, const double b, const double c);


//---------------------------------------------------------------------------
//! Compares two double`s
//!
//! @param [in]   first             first double number
//! @param [in]   second            second double number
//!
//! @return true if first = second, else false
//---------------------------------------------------------------------------
bool NumbersAreEqual (const double first, const double second);


//---------------------------------------------------------------------------
//! The function considers the first root on the quadric equation
//!
//! @param [in]   a               a-coefficient
//! @param [in]   b               b-coefficient
//! @param [in]   discriminant    discriminant
//!
//! @return   The value of the first equation
//---------------------------------------------------------------------------
static inline double CalcFirstQuadricRoot (const double a, const double b, const double sqrt_d);


//---------------------------------------------------------------------------
//! The function considers the second root on the quadric equation
//!
//! @param [in]   a               a-coefficient
//! @param [in]   b               b-coefficient
//! @param [in]   discriminant    discriminant
//!
//! @return   The value of the first equation
//---------------------------------------------------------------------------
static inline double CalcSecondQuadricRoot (const double a, const double b, const double sqrt_d);


//---------------------------------------------------------------------------
//! The function considers the root on the linear equation
//!
//! @param [in]   b            b-coefficient
//! @param [in]   c            c-coefficient
//!
//! @return   The value of the first equation
//---------------------------------------------------------------------------
static inline double CalcLinearRoot (const double b, const double c);


//---------------------------------------------------------------------------
//! Displays the response on the screen
//!
//! @param [in]   n_solutions            Number of Solutions
//! @param [in]   x1                    First answer
//! @param [in]   x2                    Second answer
//---------------------------------------------------------------------------
void PrintAnswer (solutions n_solutions, const double x1, const double x2);


//---------------------------------------------------------------------------
//! Tests the program for errors
//!
//! @note You will have to manually count the roots
//---------------------------------------------------------------------------
void ProgramTest ();


//---------------------------------------------------------------------------
//! Compares the table result with the program result
//!
//! @param [in]   a_test               a-coefficient (Test)
//! @param [in]   b_test               b-coefficient (Test)
//! @param [in]   c_test               c-coefficient (Test)
//! @param [in]   x1_test              1st root (Test)
//! @param [in]   x2_test              2st root (Test)
//! @param [in]   num_root_test        number of roots (Test)
//!
//! @return True if there are errors, otherwise false
//---------------------------------------------------------------------------
bool IsFail (const int test_number, const double a_test, const double b_test, const double c_test, solutions num_root_test, const double x1_test, const double x2_test);


//---------------------------------------------------------------------------
//! Compares the table result with the program result
//!
//! @param [in]   a_test               a-coefficient (Test)
//! @param [in]   b_test               b-coefficient (Test)
//! @param [in]   c_test               c-coefficient (Test)
//! @param [in]   x1_test              1st root (Test)
//! @param [in]   x2_test              2st root (Test)
//! @param [in]   num_root_test        number of roots (Test)
//! @param [in]   num_root_program     number of roots (return SolveSquareLinearEq)
//! @param [in]   x1_program           1st root  (out SolveSquareLinearEq)
//! @param [in]   x2_program           1st root  (out SolveSquareLinearEq)
//!
//! @return True if there are errors, otherwise false
//---------------------------------------------------------------------------
bool ErrorText (const int test_number, const double a_test, const double b_test, const double c_test, const double x1_program, const double x2_program, const double x1_expected, const double x2_expected, solutions num_root_program, solutions num_root_test);


//---------------------------------------------------------------------------
//! Clears the memory buffer
//!
//! @note Designed for code readability
//---------------------------------------------------------------------------
void ClearBuffer ();

#endif // SQUARE_H_INCLUDED
