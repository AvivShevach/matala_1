
basicClassification.o: basicClassification.c 
	gcc -g -c -Wall basicClassification.c -o basicClassification.o

advancedClassificationLoop.o: advancedClassificationLoop.c 
	gcc -g -c -Wall advancedClassificationLoop.c -o advancedClassificationLoop.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c 
	gcc -g -c -Wall advancedClassificationRecursion.c -o advancedClassificationRecursion.o

loops: basicClassification.o advancedClassificationLoop.o
	ar r libclassloops.a basicClassification.o advancedClassificationLoop.o

loopd: basicClassification.o advancedClassificationLoop.o
	gcc -fPIC -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so

recursives: basicClassification.o advancedClassificationRecursion.o
	ar r libclassrec.a basicClassification.o advancedClassificationRecursion.o

recursived: basicClassification.o advancedClassificationRecursion.o
	gcc -fPIC -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so

mains: recursives
	gcc -g main.c libclassrec.a -lm -o mains

maindloop: loopd
	gcc -g main.c -lclassloops -L. -o maindloop

maindrec: recursived
	gcc -g main.c -lclassrec -lm -L. -o maindrec

all: maindrec maindloop mains

clean:
	rm *.a *.so *.o maindrec maindloop mains
	#rm !(*.c|*.txt|Makefile)