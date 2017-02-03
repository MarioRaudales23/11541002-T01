#include "ADTList.h"
#include "VsArrayList.h"
#include "FsArrayList.h"
#include "LinkedList.h"
#include "Object.h"
#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	ADTList* lista = new LinkedList();
	cout<<lista->insert(new Person("Mario",23),0)<<endl;
	cout<<lista->insert(new Person("Antonio",15),3)<<endl;
	cout<<lista->insert(new Person("Diana",16),0)<<endl;
	cout<<lista->insert(new Person("Miguel",17),1)<<endl;
	cout<<lista->first()->toString()<<endl;
	cout<<lista->last()->toString()<<endl;
	cout<<"Size: "<<lista->getSize()<<endl;
	cout<<"Is Full: "<<lista->isFull()<<endl;
	cout<<"Is Empty: "<<lista->isEmpty()<<endl;
	for (int i = 0; i < lista->getSize(); ++i)
	{
		cout<<lista->get(i)->toString()<<endl;
	}
	Object* eliminado = lista->remove(1);
	cout<<eliminado->toString()<<"Yolo me borro"<<endl;
	for (int i = 0; i < lista->getSize(); ++i)
	{
		cout<<lista->get(i)->toString()<<endl;
	}
	lista->clear();
	cout<<"Size: "<<lista->getSize()<<endl;
	delete lista;
	return 0;
}
