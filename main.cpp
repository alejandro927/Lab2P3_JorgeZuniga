#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu() {
	int opcion=0;
	cout<<"\nLas opciones son:\n";
	cout<<"1)Ejercicio1\n";
	cout<<"2)Ejercicio2\n";
	cout<<"3)Ejercicio3\n";
	cout<<"4)salida salida\n";
	cout<<"Elija su opcion:\n";
	cin>>opcion;
	cout<<endl;
	return opcion;
}

void RecursivaPascal(int max, int n, int res_anterior [], int salida []){
	if( n == max ){
		
	}else{
		for(int i=0 ; i < n ; i++){
			if( (i == 0) || (i == n-1)){
				salida[i] = 1;
			}else{
				salida[i] = res_anterior[i-1] + res_anterior[i];
			}
		}
		
		for(int i=0;i < n;i++){
			res_anterior[i] = salida[i];
			cout<<salida[i]<<" ";	
			salida[i]=0;
		}
		cout<<endl;
		RecursivaPascal(max,n+1,res_anterior,salida);
	}
}

void Ejercicio1() {
	int max_n=0;
	cout<<"Ingrese el valor max_n : ";
	cin>>max_n;
	while((max_n<=0)||(max_n>=100)){
		cout<<"El valor no es permitido inngrese otro:";
		cin>>max_n;
	}
	int n=1;
	int res_anterior [100];
	int salida [100];
	RecursivaPascal(max_n+2,n,res_anterior,salida);
}


int main(int argc, char** argv) {
	int opcion=0;
	bool respuesta;
	respuesta=true;
	while(respuesta==true) {
		opcion = menu();
		switch(opcion) {
			case 1: {
				Ejercicio1();
			}
			break;
			case 2: {

			}
			break;
			case 3: {

			}
			break;
			case 4: {
				respuesta = false;
				break;
			}
		}
	}
	return 0;
}