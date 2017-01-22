#include "ADTList.h"
#include "FsArrayList.h"
#include "Object.h"
#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	FsArrayList* lista = new FsArrayList(10);
	cout<<lista->insert(new Person("Mario",23),0)<<endl;
	cout<<lista->insert(new Person("Antonio",15),3)<<endl;
	cout<<lista->insert(new Person("Diana",16),0)<<endl;
	cout<<lista->insert(new Person("Miguel",17),1)<<endl;
	cout<<lista->first()->toString()<<endl;
	cout<<lista->last()->toString()<<endl;
	cout<<lista->getSize();
	for (int i = 0; i < lista->getSize(); ++i)
	{
		cout<<lista->get(i)->toString()<<endl;
	}
	cout<<lista->remove(0)->toString()<<"Yolo"<<endl;
	lista->clear();
	for (int i = 0; i < lista->getSize(); ++i)
	{
		cout<<lista->get(i)->toString()<<endl;
	}
	cout<<lista->getSize();
	delete lista;
	return 0;
}