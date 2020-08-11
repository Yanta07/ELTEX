#include "calc.h"
#include <locale.h>

void scan(float *a, float *b){
	setlocale(LC_ALL, "RUS");
	printf("\nВедите a = ");
	scanf("%f",&*a);
	printf("\nВведите b = ");
	scanf("%f",&*b);
}
