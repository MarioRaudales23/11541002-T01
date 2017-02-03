#include <string>
#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
	char resp="s";
	string cadena;
	int size=0,estado;
	while(resp == 's'||resp=='S'){
		cout<<"Hola";
		cin>>cadena;
		char apertura[cadena.length()/2]; 
		for (int i = 0; i < cadena.length(); ++i)
		{
			if (cadena[i] == '['||cadena[i] == '{'||cadena[i] == '(')
			{
				apertura[size]==cadena[i];
				size++;
			}else{
				if (cadena[i] == ')')
				{
					if (apertura[size-1]=='(')
					{
						apertura[size-1]=' ';
						size--;
					}else{
						estado=1;
					}
				}
				if (cadena[i] == ']')
				{
					if (apertura[size-1]=='[')
					{
						apertura[size-1]=' ';
					}else{
						estado=1;
					}
				}
				if (cadena[i] == '}')
				{
					if (apertura[size-1]=='{')
					{
						apertura[size-1]=' ';
						size--;
					}else{
						estado=1;
					}
				}
			}
		}
		if (estado==0)
		{
			cout<<"Esta Balanceado";
		}else{
			cout<<"No esta Balanceado";
		}
	}
	return 0;
}