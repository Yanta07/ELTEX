#include "stdio.h"
#include "lib/calc.h"
#include <locale.h>

int main(){
	float a, b, c;
	int menu;
	
	setlocale(LC_ALL, "RUS");
	
	do {
		printf("\n___________________________\nКалькулятор:\n1 - Сумма (a + b) \n2 - Разность (a - b)\n3 - Деление (a / b)\n4 - Умножение (a * b)\n5 - Выход\nВыберите пункт меню: ");
		scanf("%d", &menu);

	switch(menu){
		case 1:
			scan(&a, &b);
			c = sum(a, b);
			print(c);
		break;
		
		case 2:
			scan(&a, &b);
			c = min(a, b);
			print(c);
		break;
		
		case 3:
			scan(&a, &b);
			c = div(a, b);
			print(c);
		break;
		
		case 4:
			scan(&a, &b);
			c = mult(a, b);
			print(c);
		break;
	}

	} while (menu != 5);
	return 0;
}
