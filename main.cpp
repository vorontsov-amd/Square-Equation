#include "square.h"

int main ()
{
    double a = NAN, b = NAN, c = NAN;

    setlocale (LC_ALL, "Rus");

#ifdef UNIT_TEST
    programm_test();
#endif

    scan_three_coef (&a, &b, &c);

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    double x1 = NAN;
    double x2 = NAN;

    Solutions nSolutions = nRoots (a, b, c, &x1, &x2);

    assert (nSolutions >= INF_ROOT);
    assert (nSolutions <= TWO_ROOT);

    print_answer (nSolutions, x1, x2);

    return 0;
}

void scan_three_coef (double* a, double* b, double* c)   // ������� �������� ���������� �� ���������, ������� ����� ������
{
    assert (a);
    assert (b);
    assert (c);

    printf ("������� �������� a\n");
    scanf ("%lf", a);

    printf ("������� �������� b\n");
    scanf ("%lf", b);

    printf ("������� �������� c\n");
    scanf ("%lf", c);
}

Solutions nRoots (const double a, const double b, const double c, double* x1, double* x2)            // ������� ������� ���������� ������
{
    Solutions countRoots = NO_ROOT;

    assert (x1);
    assert (x2);

    if (cmp_two_doubles (a, 0))
        solve_linear_eq (b, c, x1, x2, &countRoots);
    else
        solve_quadric_eq (a, b, c, x1, x2, &countRoots);
    return countRoots;
}

void solve_linear_eq (const double b, const double c, double* x1, double* x2, Solutions* countRoots)  // ������� ������������� ������, ����� ��������� ��������
{

    assert (x1);
    assert (x2);
    assert (countRoots);

    if (cmp_two_doubles (b, 0))
    {
        if (cmp_two_doubles (c, 0))
            *countRoots = INF_ROOT;
        else
            *countRoots = NO_ROOT;
    }

    else
    {
        *x1 = *x2 = calc_linear_root (b, c);
        *countRoots = ONE_ROOT;
    }

}

void solve_quadric_eq (const double a, const double b, const double c, double* x1, double* x2, Solutions* countRoots)     // ������� ������������� ������, ����� ��������� ����������
{
    assert (x1);
    assert (x2);
    assert (countRoots);

    double D = calc_discriminant(a, b, c);

    if (D >= 0)   // ���� ��������� ����� �����
    {
        *x1 = calc_first_quadric_root (a, b, D);
        *x2 = calc_second_quadric_root (a, b, D);
        if (cmp_two_doubles (D, 0))
            *countRoots = ONE_ROOT;
        else
            *countRoots = TWO_ROOT;
    }

    else                       // ���� �� �����
        *countRoots = NO_ROOT;

}

inline double calc_discriminant (const double a, const double b, const double c)   // ������� ������� ������������ ����������� ���������
{
    return b * b - 4 * a * c;
}

bool cmp_two_doubles (const double first, const double second)    // ��������������� ������ ��� ��������� ������
{
    double module = fabs (first - second);
    if (module <= EPS)
        return true;
    else
        return false;

}

inline double calc_first_quadric_root (const double a, const double b, const double D)  // ������� 1-�� ������ ����������� ���������
{
    return (-b + sqrt (D)) / (2 * a);
}

inline double calc_second_quadric_root (const double a, const double b, const double D)      // ������� ������ ������ ����������� ���������
{
    return (-b - sqrt (D)) / (2 * a);
}

inline double calc_linear_root (const double b, const double c)                      // ������� ������ ��������� ���������
{
    return -c / b;
}

void print_answer (const int nSolutions, const double x1, const double x2)     // ������� ������� �����
{
    switch (nSolutions)
    {
        case INF_ROOT:
            printf ("�����: ��������� ����� ������������ ��������� ������\n");
            break;
        case NO_ROOT:
            printf ("��������� �� ����� ������\n");
            break;
        case ONE_ROOT:
            printf ("�����: �1 = %lf\n", x1);
            break;
        case TWO_ROOT:
            printf ("�����: �1 = %lf    x2 = %lf\n", x1, x2);
            break;
        default:
            printf ("ERROR: ���������� ������ %d\n", nSolutions);
    }
}

void programm_test ()       // ������� ���������, ��������� �� �������� ���������
{                           // �������� � � ���������� ������������� � ��������� ���������� �����
                            // � ������������� ������� �������
    double aTest = NAN, bTest = NAN, cTest = NAN, x1Test = NAN, x2Test = NAN;
    int intSolutions;
    Solutions TestSolutions;

    printf ("������� ��������� a, b, c � ���������� ������, ������� ����� ������ ���������\n");
    printf ("���� ��������� ����� ������������ ��������� ������ ������� ���������� ������ -1\n");


    while (scanf ("%lf %lf %lf %d", &aTest, &bTest, &cTest, &intSolutions) == 4)
        {
         switch (intSolutions)
         {
            case -1:
                TestSolutions = INF_ROOT;
                break;
            case 0:
                TestSolutions = NO_ROOT;
                break;
            case 1:
                TestSolutions = ONE_ROOT;
                printf ("������� x1\n");
                scanf ("%lf", &x1Test);

                x2Test = x1Test;

                break;
            case 2:
                TestSolutions = TWO_ROOT;
                printf ("������� x1 � �2 � ������� �����������\n");
                scanf ("%lf %lf", &x1Test, &x2Test);

                break;
            default:
                printf ("����������� ������, ������� ����� �����\n");
                continue;
        }
        if (isFail (aTest, bTest, cTest, x1Test, x2Test, TestSolutions))
            {
            printf ("���������� ������ ��� ���������� a = %lf b = %lf c = %lf \n", aTest, bTest, cTest);
            printf ("x1 = %lf, x2 = %lf (���������� ������ %d)\n", x1Test, x2Test, intSolutions);
            }
        else
            {
            printf ("������ �� ���������o\n");
            printf ("������� ��������� ������ ��� ��������\n");
            }
        }
}

bool isFail (const double aTest, const double bTest, const double cTest, const double x1Test, const double x2Test, Solutions TestSolutions)
{
    double x1 = 0, x2 = 0;
    return !(TestSolutions == nRoots (aTest, bTest, cTest, &x1, &x2) && cmp_two_doubles (x1, x1Test) && cmp_two_doubles (x2, x2Test));
}
