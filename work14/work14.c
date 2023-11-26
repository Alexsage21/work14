#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);
double find_max_ch_element(double* ptr_array, int n, int ch); //ch(0 - чЄтные позиции, 1 - нечЄтные позиции)

int main()
{
	setlocale(LC_ALL, "RUS");
	double array[100];
	int size;
	printf("¬ведите размер массива > ");
	scanf("%d", &size);
	full_elements(array, size);
	printf("index = %d(M[%d])", find_element(array, size, 7), find_element(array, size, 7)+1);
	printf("\n%lf", find_max_ch_element(array, size, 0));
}
//Z1
double* full_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("M[%d] = ", i+1);
		scanf("%lf", &ptr_array[i]);
	}
}
int put_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%lf\n", *(ptr_array+i));
	}
}
double* calc_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		ptr_array[i] = (int)ceil(ptr_array[i]);
	}
}
//Z2
double sum_elements(double* ptr_array, int begin, int end)
{
	int summ = 0;
	for (int i = begin; i < end; i++)
	{
		summ += ptr_array[i];
	}
	return summ;
}
int find_element(double* ptr_array, int n, double element)
{
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] == element)
			index = i;
	}
	return index;
}
//Z3
double find_max_ch_element(double* ptr_array, int n, int ch)
{
	double max_element = ptr_array[0];
	for (int i = 0; i < n; i++)
	{
		if (i%2==ch & max_element < ptr_array[i])
		{
			max_element = ptr_array[i];
		}
	}
	return max_element;
}