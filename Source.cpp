#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*!
    \brief Используется в качестве переменной,
           отвечающей за эпсилон окрестность
           нуля
*/

#define EPS 10e-9

/*!
    \brief Используется в качестве переменной,
           отвечающей за бесконечное количество
           корней
*/

#define INF_ROOTS -1

/*!
    \brief  Используется в качестве переменной,
            отвечающей за число 0
*/

#define ZERO 0

/*!
    \brief Используеется для проверки
     нашего числа на ноль

*/

int IsZero(double solution);

/*!
    \brief Используеется для нахождения корней
           линейного уравнения

    \param[in] a1       - коэффициент линейного уравнения перед x
    \param[in] b1       - свободный член линейного уравнения
    \param[in] answer   - корень линейного уравнения уравнения
*/

int SolveLine(double a1, double b1, double* answer);
// TODO: answer, output, solution, result

/*!
    \brief Использоуется для нахождения
           количества корней квадратного
           уравнения и значений их же

    \param[in] a, b, c            - коэффициенты квадратного уравнения
    \param[in] answer_1, answer_2 - корни квадратного уравнения
*/

int SolveSquare(double a, double b, double c, double* answer_1, double* answer_2);

//-----------------------------------------------------------------------------------------------------------

int main()
{   
    TestSolveSquare();

    double a = 0, b = 0, c = 0;
    double answer1 = 0, answer2 = 0;
    int res;

    printf("# Square  equation solver\n"
        "# (c) Temchik, 2020\n\n");

    printf("# Enter coefficients of quadratic equation, please: a, b and c\n");

    //return parameter + []
    res = scanf_s("%lg %lg %lg", &a, &b, &c);
    while (res != 3)
    {
        printf("%s", "Your information is not right.\n Please, enter coefficients of quadratic equation: a, b and c");
        res = scanf_s("%lg %lg %lg", &a, &b, &c);
    }

    int nRoots = SolveSquare(a, b, c, &answer1, &answer2);

    switch (nRoots)
    {
    case 0:
        printf("No roots\n");
        break;

    case 1:
        printf("x0 = %lg\n", answer1);
        break;

    case 2:
        printf("x1 = %lg, x2 = %lg\n", answer1, answer2);
        break;

    case INF_ROOTS:
        printf("Infinity roots\n");
        break;

    default:
        printf("main(): nRoots = %d\nError\n", nRoots);
        return 1;
    }

    printf("Programm has finished");

    return 0;
}

//-----------------------------------------------------------------------------------------------------------

int SolveLine(double a1, double b1, double* answer)
{
    if (a1 == 0 && b1 != 0)
        return 0;

    if (a1 == 0)
        return INF_ROOTS;

    // a1 != 0 && b1 != 0
    return b1 / a1;
}

//-----------------------------------------------------------------------------------------------------------

int SolveSquare(double a, double b, double c, double* answer_1, double* answer_2)
{

    if (a == 0)
        return SolveLine(b, c, answer_1);

    //a != 0
    double discr = b * b - 4 * a * c;

    if ((fabs(discr) < EPS))
    {
        *answer_1 = *answer_2 = -b / (2 * a);
        return 1;
    }

    if (discr < ZERO)
        return 0;

    //discr > 0
    *answer_1 = (-b + sqrt(discr)) / (2 * a);
    *answer_2 = (-b - sqrt(discr)) / (2 * a);

    return 2;
}

//-----------------------------------------------------------------------------------------------------------

int IsZero(double solution)
{
    if (fabs(solution) < EPS)
        return 1;
    return 0;
}

//-----------------------------------------------------------------------------------------------------------
void TestSolveSquare()
{   
        double x1, x2;
        int nRoots = SolveSquare(0, 0, 0, &x1, &x2);
        if (IsZero(nRoots - INF_ROOTS) != 1)
            printf("TEST 1 is BAD! IsZero(nRoots - INF_ROOTS) = false\n");
        else
            printf("TEST 1 is OK\n");
}








