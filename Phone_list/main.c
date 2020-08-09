#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define N 1

struct person {
	char firstName[20];
	char lastName[20];
	long number;

};

void addPerson(struct person *book, int *numOfPerson){ //добавление человека

			char *point;  //строка для имени и отчества
			printf("Введите имя и фамилию\n");
			
			point = book[*numOfPerson].firstName; //пишем имя
			
			while((*point++=getchar()) != ' '); //считываем символы пока не пробел
			
				*point = '\0'; //добавили символ конца строки

			point = book[*numOfPerson].lastName; //пишем фамилию
			
			while((*point++=getchar()) != '\n'); //считываем символы пока не пробел
			
				*point = '\0'; //символ конца строки
			
			printf("Введите номер телефона\n");
			
			scanf("%ld", &book[*numOfPerson].number); //считали и записали номер
			

}

void printBook(struct person *book, int numOfPersonInBook){ //распечатать телефонную книгу
	
		printf("\n**************************");
		
	for (int i = 0; i < numOfPersonInBook; ++i) {	
		
		char str[50]; //создаем массив символов для вывода элементов книги
		strcpy(str,book[i].firstName); //копируем в новый массив имя
		strcat(str," "); //добавляем пробел
		strcat(str,book[i].lastName); //добавляем фамилию
		puts(str); //вывод на экран полученной строки
		printf("%ld", book[i].number); //вывод номера
		printf("\n**************************");
	
	}
}

void deletePerson(struct person *book, int *numOfPersonInBook, long long deleteNumber){ //удалить номер
	
	int numToDelete = -1; //установим номер для удаления, выходящий на 1 за начало
		
	for (int i = 0; i < *numOfPersonInBook; ++i) { //проходим по элементам записной книги
		
		if (book[i].number == deleteNumber) { //если номер в записной книге и введенный номер совпадают
			numToDelete = i; //удаляем его
		
		}
		
		else { //если не совпало и номер до сих пор -1
			printf("Такого номера не существует!\n"); //ошибка
			return;
		
		}
	}
	
	for (int i = numToDelete; i < *numOfPersonInBook - 1 ; ++i) { //восстанавливаем очередность данных
			
			book[i].number = book[i+1].number; //сдвигаем все на 1 после удаления
			strcpy(book[i].firstName,book[i+1].firstName);
			strcpy(book[i].lastName,book[i+1].lastName);

	}
			*numOfPersonInBook = *numOfPersonInBook - 1;
}

void searchPerson(struct person *book, int numOfPersonInBook, long long deleteNumber){ //поиск человека в записной книге по номеру
	
	for (int i = 0; i < numOfPersonInBook; ++i) { // проходим по всем записям в книге
		
		if (book[i].number == deleteNumber) { //номер в записной книге совпал с введеным
	
			char str[50]; //делаем массив символов для вывода данных найденного челоквека
			strcpy(str,book[i].firstName); //копируем в новый массив имя найденного человека
			strcat(str," "); // и т.д. как в записи
			strcat(str,book[i].lastName);
			puts(str);
			printf("%ld", book[i].number);
		}
		
		else {
			printf("Нет такой записи!\n");
			return;
			
		}
	}
}

int main(int argc, char const *argv[]) {
	setlocale(LC_ALL, "Rus");
	struct person *book;
	book = (struct person*)malloc(N * sizeof(struct person)); //выделяем данные под структуру

	int choice; //выбор элемента меню
	int RecordNumber = 0; //номер записи
	//Переменная, нужная для поиска номера
	long numberToSearch;
	do {
		printf("\n_______________________________\n\nТелефонная книга\n1 - Добавить номер\n2 - Показать записи\n3 - Удалить запись\n4 - Поиск записи\n5 - Выход\n_______________________________\n");
		scanf("%d", &choice);

		switch(choice) {

			case 1:
			addPerson(book, &RecordNumber); //добавление
			RecordNumber++;
			if (RecordNumber >= N) {
				book = realloc(book, (RecordNumber + 1) * sizeof(struct person)); //перевыделение памяти на +1
			}
			break;

			case 2: //вывод
			printBook(book,RecordNumber);
			break;

			case 3: //удаление
			printf("Введите номер телефона: ");
			scanf("%ld",&numberToSearch);
			deletePerson(book, &RecordNumber, numberToSearch);
			break;

			case 4: //поиск
			printf("Введите номер телефона: ");
			scanf("%ld",&numberToSearch);
			searchPerson(book, RecordNumber, numberToSearch);
			break;
		}
		
	} while (choice!=5); 

	free(book);
	
	return 0;
}
