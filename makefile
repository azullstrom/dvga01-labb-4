all: clean
	gcc -c labb4main.c labb4file.c filemanager.c
	gcc labb4main.o labb4file.o filemanager.o -o labb4

clean:
	rm -f labb4