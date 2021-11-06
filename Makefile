
basicClassification.o: basicClassification.c 
	gcc -g -c -Wall basicClassification.c -o basicClassification.o

advancedClassificationLoop.o: advancedClassificationLoop.c 
	gcc -g -c -Wall advancedClassificationLoop.c -o advancedClassificationLoop.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c 
	gcc -g -c -Wall advancedClassificationRecursion.c -o advancedClassificationRecursion.o

loops: basicClassification.o advancedClassificationLoop.o
	ar r libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	gcc -fPIC -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so

recursives: basicClassification.o advancedClassificationRecursion.o
	ar r libclassrec.a basicClassification.o advancedClassificationRecursion.o

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -fPIC -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so

mains: libclassrec.so
	gcc -g main.c libclassrec.a -lm -o mains

maindloop: libclassloops.so
	gcc -g main.c -lclassloops -L. -Wl,-rpath,. -o maindloop

maindrec: recursived
	gcc -g main.c -lclassrec -lm -L. -Wl,-rpath,. -o maindrec

all: maindrec maindloop mains

clean:
	rm *.a *.so *.o maindrec maindloop mains
	#rm !(*.c|*.txt|Makefile)
