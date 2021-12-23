all: clean
	gcc labb4main.c labb4file.c filemanager.c -o labb4.out

clean:
	rm -f labb4.out