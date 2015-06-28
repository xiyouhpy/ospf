objects = main.o
CC = gcc

io : $(objects)
	$(CC) -o io $(objects) -lpthread
	rm main.o *.gch

$(objects) : main.c Global_io.h
	$(CC) -c main.c Global_io.h


.PHONY : clean
clean :
	rm io $(objects) *.gch io
