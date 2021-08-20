#include <stdio.h>
#include <math.h>
#include <locale.h>
#define EPS 1e-7    // малая величина

void scan (float a, float b, float c);
void linear (float a, float b, float c);
void quadric (float a, float b, float c);
float discriminant (float a, float b, float c);
void ans (float x1, float x2);
float zero (float number);

int main ()
{
    float a = 0;    // параметры a, b и c в уравнении вида ax^2+bx+c=0
    float b = 0;
    float c = 0;

    setlocale (LC_ALL, "Rus");

    scan (a, b, c);

    return 0;
}

void scan (float a, float b, float c)   // Функция собирает информацию об уравнении, которое нужно решить
{
    printf ("Введите параметр a\n");
    scanf ("%f", &a);

    printf ("Введите параметр b\n");
    scanf ("%f", &b);

    printf ("Введите параметр c\n");
    scanf ("%f", &c);

    linear(a, b, c);
}


void linear (float a, float b, float c)  // Функция рассматривает случай, когда уравнение линейное
{
    float x = 0;

    if (zero(a) <= EPS && zero(b) > EPS) {   // Случай, когда уравнение линейное
        x = -c / b;
        printf ("Ответ %f\n", x);
    }

    else if (zero(a) <= EPS && zero(b) <= EPS && zero(c) > EPS) {  // Cлучай, когда 0 приравнивается к числу
        printf ("Уравнение не имеет корней.\n");
    }

    else if (zero(a) <= EPS && zero(b) <= EPS && zero(c) <= EPS) {    // Случай, когда 0 = 0
        printf ("Уравнение имеет бесчисленное множество решений.\n");
    }

    else {
        quadric (a, b, c);
    }
}

void quadric (float a, float b, float c)     // Функция рассматривает случай, когда уравнение квадратное
{
    float D = 0;
    float x1 = 0;
    float x2 = 0;

    D = discriminant(a, b, c);

    if (D > 0) {    // Случай, когда квадратное уравнение имеет 2 корня
        x1 = (-b + sqrt(D)) / (2*a);
        x2 = (-b - sqrt(D)) / (2*a);
    }

    else if (zero(D) <= EPS) {    // Случай, когда квадратное уравнение имеет 2 одинаковых корня
        x1 = -b / (2*a);
    }

    else if (D < 0) {  // Случай, когда квадратное уравнение не имеет действительных корней
        printf ("Уравнение не имеет корней в области действительных чисел.\n");
    }

    ans(x1, x2);  // Вывод ответа
}

float discriminant (float a, float b,float c)   // Фунция считает дискриминант квадратного уравнения
{
    float d = b * b - 4 * a * c;
    return d;
}

void ans (float x1, float x2)   // Функция выводит корни квадратного уравнения
{
    if (zero(x1) > EPS && zero(x2) <= EPS) {
        printf ("Ответ: %f\n", x1);
        }
    else if (zero(x1) > EPS && zero(x2) > EPS) {
        printf ("Ответ: %f %f\n", x1, x2);
        }
}

float zero (float number)    // Вспомогательная фунция для сравнения float`ов
{
    float nule = fabs (number);
    return nule;
}
