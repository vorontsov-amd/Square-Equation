#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>
#include <assert.h>


const double EPS = 1e-7;    // малая величина

enum Solutions
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
void scan_three_coef (double* a, double* b, double* c);


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
Solutions nRoots (const double a, const double b, const double c, double* x1, double* x2);


//---------------------------------------------------------------------------
//! Solve a linear equation
//!
//! @param [in]   b            b-coefficient
//! @param [in]   c            c-coefficient
//! @param [out]  x1           Pointer to the 1st root
//! @param [out]  x2           Pointer to the 2st root
//! @param [out]  countRoots   Pointer to count of roots
//!
//! @note consider the second root so that it is not NAN
//!       and so that the check function works correctly
//---------------------------------------------------------------------------
void solve_linear_eq (const double b, const double c, double* x1, double* x2, Solutions* countRoots);


//---------------------------------------------------------------------------
//! Solve a quadric equation
//!
//! @param [in]   a           a-coefficient
//! @param [in]   b           b-coefficient
//! @param [in]   c           c-coefficient
//! @param [out]  x1          Pointer to the 1st root
//! @param [out]  x2          Pointer to the 2st root
//! @param [out]  countRoots  Pointer to count of roots
//---------------------------------------------------------------------------
void solve_quadric_eq (const double a, const double b, const double c, double* x1, double* x2, Solutions* countRoots);


//---------------------------------------------------------------------------
//! The function considers the discriminant
//!
//! @param [in]   a            a-coefficient
//! @param [in]   b            b-coefficient
//! @param [in]   c            c-coefficient
//!
//! @return   The value of the discriminant
//---------------------------------------------------------------------------
inline double calc_discriminant (const double a, const double b, const double c);


//---------------------------------------------------------------------------
//! Compares two double`s
//!
//! @param [in]   first             first double number
//! @param [in]   second            second double number
//!
//! @return true if first = second, else false
//---------------------------------------------------------------------------
bool cmp_two_doubles (const double first, const double second);


//---------------------------------------------------------------------------
//! The function considers the first root on the quadric equation
//!
//! @param [in]   a            a-coefficient
//! @param [in]   b            b-coefficient
//! @param [in]   D            discriminant
//!
//! @return   The value of the first equation
//---------------------------------------------------------------------------
inline double calc_first_quadric_root (const double a, const double b, const double D);


//---------------------------------------------------------------------------
//! The function considers the second root on the quadric equation
//!
//! @param [in]   a            a-coefficient
//! @param [in]   b            b-coefficient
//! @param [in]   D            discriminant
//!
//! @return   The value of the first equation
//---------------------------------------------------------------------------
inline double calc_second_quadric_root (const double a, const double b, const double D);


//---------------------------------------------------------------------------
//! The function considers the root on the linear equation
//!
//! @param [in]   a            a-coefficient
//! @param [in]   b            b-coefficient
//!
//! @return   The value of the first equation
//---------------------------------------------------------------------------
inline double calc_linear_root (const double b, const double c);


//---------------------------------------------------------------------------
//! Displays the response on the screen
//!
//! @param [in]   nSolutions            Number of Solutions
//! @param [in]   x1                    First answer
//! @param [in]   x2                    Second answer
//---------------------------------------------------------------------------
void print_answer (const int nSolutions, const double x1, const double x2);


//---------------------------------------------------------------------------
//! Tests the program for errors
//!
//! @note You will have to manually count the roots
//---------------------------------------------------------------------------
void programm_test ();


//---------------------------------------------------------------------------
//! Compares manually calculated results with program results
//!
//! @param [in]   a               a-coefficient (Test)
//! @param [in]   b               b-coefficient (Test)
//! @param [in]   c               c-coefficient (Test)
//! @param [in]   x1              1st root
//! @param [in]   x2              2st root
//! @param [in]   TestSolutions   number of roots
//!
//! @return False if there are no errors, true if there are errors
//---------------------------------------------------------------------------
bool isFail (const double aTest, const double bTest, const double cTest, const double x1Test, const double x2Test, Solutions TestSolutions);

#endif // SQUARE_H_INCLUDED
