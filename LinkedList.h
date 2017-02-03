#pragma once
#include "Object.h"
#include "ADTList.h"
class LinkedList:public ADTList{
	class Node{
		public:
			Object* data;
			Node* next;
			Node(Object* e):data(e){next=NULL;};
			Node(Object* e,Node* n):data(e),next(n){};
			~Node(){
				if (data)
				{
					delete data;
				}
				if (next)
				{
					delete next;
				}
			};
	};
	protected:
		Node* head;
	public:
		LinkedList();
		virtual ~LinkedList();
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