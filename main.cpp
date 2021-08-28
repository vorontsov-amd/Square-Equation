///\file
///\brief main file on the program solves linear and square equation

/*! \mainpage Square equation soliver
*
* Features of this program:
*
* Get keyboard data to solve an equation.
*
* Based on the entered data, determine which type of equation it is.
*
* Solve the equation for you.
*
* Display the values ​​of the roots on the screen.
*/

#include "square.h"

int main ()
{
    double a = NAN, b = NAN, c = NAN;

    setlocale (LC_ALL, "Rus");

#ifndef UNIT_TEST
    ProgramTest ();
#endif

    ScanThreeCoef (&a, &b, &c);

    double x1 = NAN;
    double x2 = NAN;

    solutions n_solutions = SolveSquareLinearEq (a, b, c, &x1, &x2);

    PrintAnswer (n_solutions, x1, x2);

    return 0;
}

void ScanThreeCoef (double* a, double* b, double* c)
{
    assert (a);
    assert (b);
    assert (c);
    assert (a != b);
    assert (a != c);
    assert (b != c);

    printf ("Введите параметры a, b, c\n");

    while (scanf ("%lf %lf %lf", a, b, c) != 3)
    {
        ClearBuffer ();
        printf ("Введите параметры a, b, c\n");
    }

    ClearBuffer ();

    assert (isfinite (*a));
    assert (isfinite (*b));
    assert (isfinite (*c));
}

solutions SolveSquareLinearEq (const double a, const double b, const double c, double* x1, double* x2)
{
    solutions count_roots = NO_ROOT;

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1);
    assert (x2);
    assert (x1 != x2);

    if (NumbersAreEqual (a, 0))
        count_roots = SolveLinearEq (b, c, x1);
    else
        count_roots = SolveQuadricEq (a, b, c, x1, x2);
    return count_roots;
}

solutions SolveLinearEq (const double b, const double c, double* x1)
{

    assert (isfinite (b));
    assert (isfinite (c));
    assert (x1);

    if (NumbersAreEqual (b, 0))
    {
        if (NumbersAreEqual (c, 0))
            return INF_ROOT;
        else
            return NO_ROOT;
    }
    else
    {
        *x1 = CalcLinearRoot (b, c);
        return ONE_ROOT;
    }

}

solutions SolveQuadricEq (const double a, const double b, const double c, double* x1, double* x2)
{

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1);
    assert (x2);
    assert (x1 != x2);

    double discriminant = CalcDiscriminant (a, b, c);
    const double sqrt_d = sqrt (discriminant);

    if (discriminant >= 0)
    {
        *x1 = CalcFirstQuadricRoot (a, b, sqrt_d);
        *x2 = CalcSecondQuadricRoot (a, b, sqrt_d);
        if (NumbersAreEqual (discriminant, 0))
        {
            *x2 = NAN;
            return ONE_ROOT;
        }
        else
            return TWO_ROOT;
    }
    else
        return NO_ROOT;

}

static inline double CalcDiscriminant (const double a, const double b, const double c)
{
    return b * b - 4 * a * c;
}

bool NumbersAreEqual (const double first, const double second)
{
    return (fabs (first - second) <= EPS);

}

static inline double CalcFirstQuadricRoot (const double a, const double b, const double sqrt_d)
{
    return (-b + sqrt_d) / (2 * a);
}

static inline double CalcSecondQuadricRoot (const double a, const double b, const double sqrt_d)
{
    return (-b - sqrt_d) / (2 * a);
}

static inline double CalcLinearRoot (const double b, const double c)
{
    return -c / b;
}

void PrintAnswer (solutions n_solutions, const double x1, const double x2)
{
    switch (n_solutions)
    {
        case INF_ROOT:
            printf ("Ответ: Уравнение имеет бесчисленное множетсво корней\n");
            break;
        case NO_ROOT:
            printf ("Уравнение не имеет корней\n");
            break;
        case ONE_ROOT:
            printf ("Ответ: х1 = %lf\n", x1);
            break;
        case TWO_ROOT:
            printf ("Ответ: х1 = %lf    x2 = %lf\n", x1, x2);
            break;
        default:
            printf ("ERROR: количество корней %d\n", n_solutions);
    }
}

void ProgramTest ()
{
    int number_errors = 0;
         //  № теста  коэфициент a  коэфициент b  коэфициент c  Количество корней  1 корень  2 корень
    if (IsFail (1,         1,           2,            1,            ONE_ROOT,        -1,       NAN)) number_errors++;
    if (IsFail (2,         1,           5,            4,            TWO_ROOT,        -1,        -4)) number_errors++;
    if (IsFail (3,         1,           1,            1,             NO_ROOT,       NAN,       NAN)) number_errors++;
    if (IsFail (4,         0,           0,            0,            INF_ROOT,       NAN,       NAN)) number_errors++;
    if (IsFail (5,         0,           5,          -10,            ONE_ROOT,         2,       NAN)) number_errors++;
    if (IsFail (6,         0,           0,            1,             NO_ROOT,       NAN,       NAN)) number_errors++;

    printf ("При тесте обнаружено %d ошибок\n\n", number_errors);
}

bool IsFail (const int test_number, const double a_test, const double b_test, const double c_test, solutions num_root_test, const double x1_expected, const double x2_expected)
{
    double x1_program = NAN, x2_program = NAN;
    bool is_wrong = false;

    solutions num_root_program = SolveSquareLinearEq (a_test, b_test, c_test, &x1_program, &x2_program);

    switch (num_root_test)
        {
        case NO_ROOT:
            if (num_root_test != num_root_program)
            {

                is_wrong = ErrorText (test_number, a_test, b_test, c_test, x1_program, x2_program,
                                      x1_expected, x2_expected, num_root_program, num_root_test);
            }

            break;

        case INF_ROOT:
            if (num_root_test != num_root_program)
            {

                is_wrong = ErrorText (test_number, a_test, b_test, c_test, x1_program, x2_program,
                                      x1_expected, x2_expected, num_root_program, num_root_test);
            }

            break;

        case TWO_ROOT:
            if ((num_root_test != num_root_program)
            || (!NumbersAreEqual(x1_expected, x1_program))
            || (!NumbersAreEqual(x2_expected, x2_program)))
            {

                is_wrong = ErrorText (test_number, a_test, b_test, c_test, x1_program, x2_program,
                                      x1_expected, x2_expected, num_root_program, num_root_test);
            }

            break;

        case ONE_ROOT:
            if ((num_root_test != num_root_program)
            || (!NumbersAreEqual(x1_expected, x1_program)))
            {

                is_wrong = ErrorText (test_number, a_test, b_test, c_test, x1_program, x2_program,
                                      x1_expected, x2_expected, num_root_program, num_root_test);
            }

            break;

        default:
            printf ("Ошибка в тестовой программе\n");
        }
    return is_wrong;
}

bool ErrorText (const int test_number, const double a_test, const double b_test, const double c_test,
                const double x1_program, const double x2_program,
                const double x1_expected, const double x2_expected,
                solutions num_root_program,
                solutions num_root_test)
{
    printf ("Тест %d прошел с ошибкой при данных a = %lf b = %lf c = %lf\n", test_number, a_test, b_test, c_test);
    printf ("Программа получила результат x1 = %lf x2 = %lf количество корней %d\n", x1_program, x2_program, num_root_program);
    printf ("Ожидаемый результат x1 = %lf x2 = %lf количество корней %d\n", x1_expected, x2_expected, num_root_test);

    return true;
}

void ClearBuffer ()
{
    int ch = 0;
    while ((ch = getchar ()) != EOF)
    {
        if (ch == '\n')
            break;
    }
}
