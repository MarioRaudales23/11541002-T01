main:	ADTList.o Person.o FsArrayList.o Object.o VsArrayList.o LinkedList.o main.o
	g++ ADTList.o Person.o FsArrayList.o Object.o VsArrayList.o LinkedList.o main.o -o run

ADTList.o:	ADTList.h ADTList.cpp Object.h
	g++ -c ADTList.cpp

Person.o:	Person.h Person.cpp Object.h
	g++ -c Person.cpp

FsArrayList.o:	FsArrayList.h FsArrayList.cpp ADTList.h Object.h
	g++ -c FsArrayList.cpp

Object.o: Object.h Object.cpp
	g++ -c Object.cpp

main.o:	main.cpp ADTList.h FsArrayList.h Person.h Object.h
	g++ -c main.cpp

VsArrayList.o:	ADTList.h VsArrayList.h VsArrayList.cpp Object.h
	g++ -c VsArrayList.cpp
LinkedList.o:	ADTList.h LinkedList.h LinkedList.cpp Object.h
	g++ -c LinkedList.cpp

