#include "Object.h"
#include "ADTList.h"
#include "LinkedList.h"
#include <iostream>
#include <stddef.h>
using std::cerr;
using std::cout;

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    if (head)
        delete head;
}



bool LinkedList::insert(Object* data, int p) { 
    if (p < 0 || p > size)
        return false;
    Node* neo = new Node(data);
    if (!head)
        head = neo;
    else {
        if (p == 0){
            neo->next=head;
            head = neo;
        }else{
        	Node* temp = head;
        	for (int i = 1; i < p; ++i)
        	{
        		temp = temp->next;
        	}
        	neo->next = temp->next;
        	temp->next = neo;
        }
    }
    size++;
    return true;
}

Object* LinkedList::remove(int p) {
	if (p>0||p>getSize())
	{
		return NULL;
	}
	if (p==0)
	{
		Node* temp;
		temp = head;
		head = head->next;
		Object* retval = temp->data;
		temp->data=NULL;
		delete temp;
		size--;
		return retval;
	}else if (p == getSize()-1)
	{
		Node* temp;
		temp = head;
		for (int i = 1; i < size-1; ++i)
		{
			temp = temp->next;
		}
		Object* retval = temp->next->data;
		temp->next->data = NULL;
		delete temp->next;
		temp->next=NULL;
		size--;
		return retval;
	}else{
		Node* temp;
		temp = head;
        for (int i=1; i<p; i++){
       		temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next=temp2->next;
        Object* retval = temp2->data;
        delete temp2;
        temp2->data=NULL;
        size--;
		return retval;
	}
}
Object* LinkedList::first()const{
	return head->data;
}
Object* LinkedList::last()const{
	Node* temp = head;
	for (int i = 1; i < size-1 ; ++i)
	{
		temp = temp->next;
	}
	return temp -> data;
}
void LinkedList::clear(){
	if (head)
        delete head;
    head = NULL;
	size=0;
}
int LinkedList::indexof(Object* e){
	if (isEmpty())
	{
		cout<<"No hay nada en la lista";
		return -1;
	}
	Node* temp = head;
	if (temp->data->equals(e))
	{
		return 0;
	}
	for (int i = 1; i < size; ++i)
	{
		if (temp->data->equals(e))
		{
			return i;
		}
		temp=temp->next;
	}
	return -1;
}
Object* LinkedList::get(int p)const{
	if (isEmpty())
	{
		cout<<"No hay nada en la lista";
		return NULL;
	}
	if (p<0||p>size)
	{
		cerr<<"Posicion invalida";
		return NULL;
	}
	if (p == 0)
	{
		return head->data;
	}else{
		Node* temp = head;
		for (int i = 0; i < p; ++i)
		{
			temp = temp->next;
		}
		return temp->data;
	}
}
int LinkedList::getCapacity()const{
	return -1;
}
bool LinkedList::isEmpty()const{
	if (head == NULL)
	{
		return true;
	}
	return false;
}
bool LinkedList::isFull()const{
	if (size > 0)
	{
		return true;
	}
	return false;
}