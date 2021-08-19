#include <stdio.h>
#include <math.h>

void linear (float a, float b, float c, float eps);
void quadric (float a, float b, float c, float eps);

int main () // Функция получает на ввод значения для решения задачи
{
    float a = 0;    // параметры a, b и c в уравнении вида ax^2+bx+c=0
    float b = 0;
    float c = 0;
    float eps = 1e-7;   // малая величина

    printf ("Enter parameter a\n");
    scanf ("%f", &a);

    printf ("Enter parameter b\n");
    scanf ("%f", &b);

    printf ("Enter parameter c\n");
    scanf ("%f", &c);

    linear (a, b, c, eps);
    return 0;
}

void linear (float a, float b, float c, float eps)  // Функция рассматривает случай, когда уравнение линейное
{
    float x = 0;

    if (fabs(a) <= eps && fabs(b) > eps) {   // Случай, когда уравнение линейное
        x = -c / b;
        printf ("Answer: %f\n", x);
    }

    else if (fabs(a) <= eps && fabs(b) <= eps && fabs(c) > eps) {  // Cлучай, когда 0 приравнивается к числу
        printf ("The equation has no solutions.");
    }

    else if (fabs(a) <= eps && fabs(b) <= eps && fabs(c) <= eps) {    // Случай, когда 0 = 0
        printf ("The equation has countless solutions.");
    }

    else {
        quadric (a, b, c, eps);
    }
}

void quadric (float a, float b, float c, float eps)     // Функция рассматривает случай, когда уравнение квадратное
{
    float D = 0;
    float x1 = 0;
    float x2 = 0;

    D = b * b - 4 * a * c;

    if (D > 0) {    // Случай, когда квадратное уравнение имеет 2 корня
        x1 = (-b + sqrt(D)) / (2*a);
        x2 = (-b - sqrt(D)) / (2*a);
        printf ("Answer: %f, %f", x1, x2);
    }

    else if (fabs(D) <= eps) {    // Случай, когда квадратное уравнение имеет 2 одинаковых корня
        x1 = -b / (2*a);
        printf ("Answer: %f", x1);
    }

    else if (D < 0) {  // Случай, когда квадратное уравнение не имеет действительных корней
        printf ("The equation has no solutions, on the field of real numbers.");
    }
}
