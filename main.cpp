#include <iostream>
#include <random>
#include <ctime>
#include <math.h>
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

void RecursivaPascal(int max, int n, int res_anterior [], int salida []) {
	if( n == max ) {

	} else {
		for(int i=0 ; i < n ; i++) {
			if( (i == 0) || (i == n-1)) {
				salida[i] = 1;
			} else {
				salida[i] = res_anterior[i-1] + res_anterior[i];
			}
		}

		for(int i=0; i < n; i++) {
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
	while((max_n<=0)||(max_n>=100)) {
		cout<<"El valor no es permitido inngrese otro:";
		cin>>max_n;
	}
	int n=1;
	int res_anterior [100];
	int salida [100];
	RecursivaPascal(max_n+2,n,res_anterior,salida);
}

int* ImprimirArr(int arr[]) {
	for(int i=0 ; i<10 ; i++) {
		cout<<arr[i]<<" ";
	}
	return arr;
}

int* LlenarArr(int arr[]) {
	for(int i=0 ; i<10 ; i++) {
		arr[i] = 1 + (rand() % 20);
	}
	return arr;
}

int* LlenarArrEjercicio2(int arr[]) {
	for(int i=0 ; i<20 ; i++) {
		arr[i] = 1 + (rand() % 100);
	}
	return arr;
}

int* ImprimirArrEjercicio2(int arr[]) {
	for(int i=0 ; i<20 ; i++) {
		cout<<arr[i]<<" ";
	}
	return arr;
}

double promedio(int x[]){
	double resultado=0;
	for(int i=0 ; i<20 ; i++) {
		resultado += x[i];
	}
	resultado = resultado/20;
	return resultado;
}

double Sumatoria(double promedio,int x[]){
	double resultado=0;
	double resta=0;
	double ecuacion=0;
	for(int i=0 ; i < 20 ; i++) {
		if( x[i] > promedio){
			resta = x[i] - promedio;
			ecuacion = pow(resta,2);
			resultado = resultado + ecuacion;
			cout<<" ( "<<i<<") "<<resultado<<" ,";
		}else{
			resta = (double)promedio - x[i] ;
			ecuacion = pow(resta,2);
			resultado = resultado + ecuacion;
			cout<<" ( "<<i<<") "<<resultado<<" ,";
		}	
	}
	cout<<endl;
	return resultado;
}

void Ejercicio2() {
	int arreglo[20];
	double prom;
	double suma=0;
	double desviacion=0;
	LlenarArrEjercicio2(arreglo);
	ImprimirArrEjercicio2(arreglo);
	cout<<endl;
	prom = promedio(arreglo);
	cout<<"Promedio:"<<prom<<endl;
	suma = Sumatoria(prom,arreglo);
	cout<<"La suma es:"<<suma<<endl;
	desviacion = sqrt(suma/20);
	cout<<"La desviacion es de:"<< desviacion<<endl;
	
}

void Primero(int x[], int y[]){
	char val = 177;
	char val2= 178;
	for(int i=0 ; i < 10 ; i++){
		cout<<i<<". "<<endl;
		for(int j=0; j < x[i]; j++){
			cout<<val<<" ";
		}
		cout<<endl;
		for(int j=0; j < y[i]; j++){
			cout<<val2<<" ";
		}
		cout<<endl;
	}
}
void Segundo(int x[]){
	char val = 178;
	for(int i=0 ; i < 10 ; i++){
		for(int j=0; j < x[i]; j++){
			cout<<val<<endl;
		}
	}
}

void Ejercicio3() {
	int arreglo1[10];
	int arreglo2[10];
	LlenarArr(arreglo1);
	ImprimirArr(arreglo1);
	cout<<endl;
	LlenarArr(arreglo2);
	ImprimirArr(arreglo2);
	cout<<endl;
	Primero(arreglo1,arreglo2);

}


int main(int argc, char** argv) {
	srand(time(NULL));
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
				Ejercicio2();
			}
			break;
			case 3: {
				Ejercicio3();
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