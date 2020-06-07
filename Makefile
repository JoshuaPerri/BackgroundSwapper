background: background.c functions.c fileFunctions.c
	gcc -Wall -o background background.c functions.c fileFunctions.c

clean:
	rm background