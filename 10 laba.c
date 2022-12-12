#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 10
double fun(double x)
{
    double result = pow(x, 2) - pow(cos(x + 1), 2);
    return result;
}
int main()
{

    setlocale(LC_ALL, "RUS");
	float A[N], temp;
	for (int i = 0; i < N; i++)
	{
		printf("a[%d]=", i + 1);
		scanf_s("%f",&temp);
		A[i] = temp;
	}

    printf("\n-----------------------------------------------\n"
        "| индекс | исходное значение | новое значение |\n"
        "-----------------------------------------------\n");
    for (int i = 0; i < N; i++)
    {
        printf("| %6d | %17.2f | %15.2f|\n", i, A[i], A[i] / 10);
        
    }
    printf("-----------------------------------------------\n");



    float sum = 0, sr;
    for (int i = 0; i < N; i++) sum += A[i];
    sr = sum / N;
    printf("Среднее арифметическое массива A[%d] = %g\n", N, sr);

    
    // функция y=x^2-cos^2(x+1) [0.1;2.2]
    float B[100];
    float step = (2.2f - 0.1f) / 100;   
    float current_step = 0.1f;
    for (int i = 0; i < 100; i++, current_step += step) B[i] = fun(current_step);


    float sum_positive = 0, sum_negative = 0;
    int count_positive = 0, count_negative = 0;
    for (int i = 0; i < 100; i++)
    {
        if (B[i] > 0)
        {
            sum_positive += B[i];
            count_positive++;
        }
        else
        {
            sum_negative += B[i];
            count_negative++;
        }
    }
    float srpositive = sum_positive / count_positive;
    float srnegative = sum_negative / count_negative;
    printf("Массив B[100]:\n"
           " Положительные числа:\n");
    printf("   Сумма: %.2f\n", sum_positive);
    printf("   Количество: %d\n", count_positive);
    printf("   Среднее арифметическое: %.2f\n", srpositive);
    printf(" Отрицательные числа:\n");
    printf("   Сумма: %.2f\n", sum_negative);
    printf("   Количество: %d\n", count_negative);
    printf("   Среднее арифметическое: %.2f\n", srnegative);
}