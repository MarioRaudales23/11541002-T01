#include "FsArrayList.h"
#include "ADTList.h"
#include "Object.h"
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
FsArrayList::FsArrayList(int capacity){
	this->capacity=capacity;
	array=new Object*[capacity];
	if (!array)
	{
		cerr<<"Out of Memory"<<endl;
	}
}

FsArrayList::~FsArrayList(){
	for (int i = 0; i < getSize(); ++i)
	{
		if (array[i])
		{
			delete array[i];
		}
	}
	delete array;
}

bool FsArrayList::insert(Object* e,int p){
	if (p<0||p>getSize())
	{
		return false;
	}
	if (isFull())
	{
		return false;
	}
	for (int i = getSize(); i > p; --i)
	{
		array[i] = array[i-1];
	}
	array[p] = e;
	size++;
	return true;
}

void FsArrayList::clear(){
	for (int i = 0; i < getSize(); ++i)
	{
		if (array[i])
		{
			delete array[i];
			array[i] = NULL;
		}
	}
	size=0;
}

Object* FsArrayList::remove(int p){
	if (p < 0|| p > getSize())
	{
		cerr<<"Posicion invalida";
		return NULL;
	}
	Object* temp = array[p];
	//delete array[p];
	for (int i = p; i <size ; ++i)
	{
		array[i] = array[i+1];
	}
	size--;
	return temp;
}

Object* FsArrayList::first()const{
	return array[0];
}
Object* FsArrayList::last()const{
	return array[size-1];
}

int FsArrayList::indexof(Object* e){
	if (isEmpty())
	{
		cout<<"No hay nada en la lista";
		return -1;
	}
	for (int i = 0; i < size; ++i)
	{
		if (array[i]->equals(e))
		{
			return i;
		}
	}
	return -1;
}

Object* FsArrayList::get(int p)const{
	if (isEmpty())
	{
		cout<<"No hay nada en la lista";
		return NULL;
	}
	if (p<0||p>size)
	{
		cerr<<"Posicion invalida";
		return NULL;
	}else{
		return array[p];
	}
}

int FsArrayList::getCapacity()const{
	return capacity;
}

bool FsArrayList::isFull()const{
	if (size == capacity)
	{
		return true;
	}
	return false;
}

bool FsArrayList::isEmpty()const{
	if (size==0)
	{
		return true;
	}
	return false;
}