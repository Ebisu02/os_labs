binary: lab_5.o libworld.so
	gcc -o binary lab_5.o -L. -lworld -Wl,-rpath,.

lab_5.o: lab_5.c
	gcc -c lab_5.c

libworld.so: lab_1.o module2.o
	gcc -shared -o libworld.so lab_1.o module2.o

lab_1.o: lab_1.c
	gcc -c -fPIC lab_1.c

module2.o: module2.c
	gcc -c -fPIC module2.c

clean:
	rm -f *.o binary
