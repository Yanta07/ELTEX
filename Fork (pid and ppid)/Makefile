CC := gcc
SOURCE := main
RESULT := fork

all: $(SOURCE).o
	$(CC) $(SOURCE).o -o $(RESULT)

$(SOURCE).o: $(SOURCE).c
	gcc -c $(SOURCE).c -o $(SOURCE).o

clear:
	rm -rf *.o
