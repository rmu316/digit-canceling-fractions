digit_cancel: digit_cancel.o
	gcc -o digit_cancel -g digit_cancel.o
digit_cancel.o: digit_cancel.c
	gcc -g -c -Wall digit_cancel.c
clean:
	rm -f *.o digit_cancel  
