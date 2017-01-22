#pragma once
#include "ADTList.h"
#include "Object.h"

class FsArrayList:public ADTList{
		int capacity;
		Object** array;
	public:
		FsArrayList(int);
		virtual ~FsArrayList();
		virtual bool insert(Object* ,int);
		virtual Object* remove(int);
		virtual Object* first()const;
		virtual Object* last()const;
		virtual void clear();
		virtual int indexof(Object*);
		virtual Object* get(int)const;
		virtual int getCapacity()const;
		virtual bool isEmpty()const;
		virtual bool isFull()const;
};