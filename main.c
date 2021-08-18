#include <stdio.h>
#include <math.h>
int main(void)
{
    float a, b, c; // параметры a, b и c в уравнении вида ax^2+bx+c=0
    float x1, x2, D; // x1, x2 - корни квадратного уравнения, D - дискриминант

    /* Ввод данных с клавиатуры */
    printf("Enter parameter a\n");
    scanf("%f", &a);
    printf("Enter parameter b\n");
    scanf("%f", &b);
    printf("Enter parameter c\n");
    scanf("%f", &c);

    if ( a == 0 && b != 0) { // Случай, когда уравнение линейное
        x1 = -c/b;
        printf("Answer: %f\n", x1);
    }
    else if ( a == 0 && b == 0 && c != 0) { // Cлучай, когда 0 приравнивается к числу
        printf("The equation has no solutions.");
    }
    else if ( a == 0 && b == 0 && c == 0) {// Случай, когда 0 = 0{
        printf("The equation has countless solutions.");
    }
    else {
        D = b * b - 4 * a * c; // Случай, когда квадратное уравнение имеет 2 корня
        if ( D > 0 ) {
            x1 = (-b + sqrt(D))/(2*a);
            x2 = (-b - sqrt(D))/(2*a);
            printf("Answer: %f, %f", x1, x2);
        }
        else if ( D == 0 ) { // Случай, когда квадратное уравнение имеет 2 одинаковых корня
            x1 = -b/(2*a);
            printf("Answer: %f", x1);
        }
        else { // Случай, когда квадратное уравнение не имеет действительных корней
            printf("The equation has no solutions, on the field of real numbers.");
        }
    }
    return 0;
}
