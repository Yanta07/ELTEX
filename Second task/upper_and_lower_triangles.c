/* Заполнить верхний треугольник матрицы 1, а нижний 0. */

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale (LC_ALL, "Rus");
	
	int elem;
	int n=3;
	int A[n][n];
	
	printf("Матрица, разделенная по треугольникам: \n");

	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (i==n-j-1) // Выделяем побочную диагональ
				A[i][j]=0; 
					
			if (i>n-j-1) // Нижний треугольник
				A[i][j]=0;
				
			if (i<n-j-1) // Верхний треугольник
				A[i][j]=1;
				
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
