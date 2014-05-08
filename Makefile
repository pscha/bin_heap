CFLAGS?=-Wall -pedantic 

normal:
	$(CC) -o test Test.c $(CFLAGS) 


all: normal
