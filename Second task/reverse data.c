/*Вывести элементы одномерного массива в обратном порядке*/
#include <stdio.h>
#include <locale.h>

int main(){
	setlocale (LC_ALL, "Rus");
	
	int elem;
	int N;
	
	
	printf("Введите количество элементов: ");
	scanf("%d", &N);
	int A[N];
	
	printf("Введите элементы для обратного вывода: ");

	for (int i=0; i<N; i++){		//ввод элементов и запись в одномерный массив
		scanf("%d", &elem);
		A[i]=elem;
	}	
	
	for (int i=N-1; i>=0; i--){		//вывод элементов в обратном порядке в терминал
		printf("%d ", A[i]);
	}
	
	printf("\n");
	
	return 0;
	
}
