/*Вывести элементы квадратной матрицы*/

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale (LC_ALL, "Rus");

	int elem;
	int N;
	
	
	printf("Введите размерность матрицы(прим:4): ");
	scanf("%d", &N);
	int A[N][N];  //сначала вводим размерность, затем формируем матрицу
	
	printf("Введите элементы матрицы: ");

	for (int i=0; i<N; i++){		//проходим по строкам
		for (int j=0; j<N; j++){	//проходим по столбцам
			scanf("%d", &elem);	//считываем данные из терминала
			A[i][j]=elem;		//записываем элементы в матрицу
			printf("%d ", A[i][j]);//выводим результат в терминал
		}
		printf("\n");			//переходим на новую строку
	}
	
	return 0;
}
