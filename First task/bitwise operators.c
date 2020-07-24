#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale (LC_ALL, "Rus");
	int n;
	int a = 0x00DDAABB;
	unsigned char c;
	c = (a&0xFF);
	
			printf ("Первый байт a = %X\n",c);
			
			c = ((a>>8)&0xFF);
			printf ("Второй байт a = %X\n",c);
			
			c = ((a>>16)&0xFF);
			printf ("Третий байт a = %X\n",c);
			
			c = ((a>>24)&0xFF);
			printf ("Четвертый байт a = %X\n",c);
			
			c = ((a>>16)&0xAA);
			
	printf ("\n______________________\n");
	printf ("\nОбновленный третий байт a = %X \n",c);
	a = (a&0xFFAAFFFF);
	printf ("Новое значение a = %X \n", a);

return 0;
}
