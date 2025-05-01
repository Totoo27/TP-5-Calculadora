/* 

Trabajo Practico Calculadora en C++. 
Integrantes:

Anza Axel,
Diaz Diaz Ignacio,
Findlay Juan Ignacio,
Coggiola Manuel,
Gennuso Santino.

*/

#include <iostream>
#include <iomanip>
#include <vector>


using namespace std;

// Estructuras

struct Resultado3x3{
	float x,y,z;
};

struct Resultado2x2{
	float x,y;
};

// FUNCIONES PROTOTIPADOS

// ----- Punto 1 - Operaciones Básicas



// ----- Punto 2 - Operaciones Con Vectores



// ----- Punto 2 - Operaciones con Matrices



// ----- Punto 4 - Sistemas de ecuación.

void sistema2x2();
void sistema3x3();
char PosToChar(int numero);


// ----- MAIN -----

int main(){

	// Variables

	// Proceso

	//sistema3x3(); test
	//sistema2x2(); test

	system("pause");
	return 0;
}

// Funciones

// ----- Punto 1 - Operaciones Básicas



// ----- Punto 2 - Operaciones Con Vectores



// ----- Punto 2 - Operaciones con Matrices



// ----- Punto 4 - Sistemas de ecuación.

void sistema2x2(){

	// Variables
	int limite = 2;
	char posicion;
	Resultado2x2 resultado;
	float matriz[limite+1][limite] = {0};

	// Aclaracion
	cout<<"Tener en cuenta que los valores se reemplazaran asi:"<<endl<<"A1*x + B1*y = C1"<<endl<<"A2*x + B2*y = C2"<<endl;

	// Ingreso de datos

	for(int i = 0; i<limite/*Le sumas 1 para añadirle el resultado.*/;i++){

		for(int j = 0; j<limite+1;j++){

			cout<<"Ingrese el valor "<<PosToChar(j)<<" de la ecuacion "<<i+1<<": ";
			cin>>matriz[j][i];

		}

	}

	// Proceso matematico

	float D = matriz[0][0] * matriz[1][1] -  matriz[0][1] * matriz[1][0]; // Determinante

	float Dx = matriz[2][0] * matriz[1][1] -  matriz[2][1] * matriz[1][0]; // Determinante X

	float Dy = matriz[0][0] * matriz[2][1] -  matriz[0][1] * matriz[2][0]; // Determinante Y

	// Resultado

	if(D == 0 && Dx == 0 && Dy == 0){
		cout<<"El sistema tiene infinitas soluciones."<<endl;
	} else if(D == 0){
		cout<<"El sistema no tiene solucion."<<endl;
	} else {
		resultado.x = Dx / D;
		resultado.y = Dy / D;

		cout<<fixed<< setprecision(4);
		cout<<"X = "<<resultado.x<<endl<<"Y = "<<resultado.y<<endl;
	}
}

void sistema3x3(){

	// Variables
	int limite = 3;
	Resultado3x3 resultado;
	int matriz[limite+1][limite] = {0};

	// Aclaracion
	cout<<"Tener en cuenta que los valores se reemplazaran asi:"<<endl<<"A1*x + B1*y + C1*z = D1"<<endl<<"A2*x + B2*y + C2*z = D2"<<endl<<"A3*x + B3*y + C3*z = D3"<<endl;

	for(int i = 0; i<limite;i++){

		for(int j = 0; j<limite+1;j++){

			cout<<"Ingrese el valor "<<PosToChar(j)<<" de la ecuacion "<<i+1<<": ";
			cin>>matriz[j][i];

		}

	}

	// Proceso Matematico

	float D = (matriz[1][1]*matriz[2][2] - matriz[1][2]*matriz[2][1]) * matriz[0][0]
			- (matriz[0][1]*matriz[2][2] - matriz[0][2]*matriz[2][1]) * matriz[1][0]
			+ (matriz[0][1]*matriz[1][2] - matriz[0][2]*matriz[1][1]) * matriz[2][0];

	float Dx = (matriz[1][1]*matriz[2][2] - matriz[1][2]*matriz[2][1]) * matriz[3][0]
			 - (matriz[3][1]*matriz[2][2] - matriz[3][2]*matriz[2][1]) * matriz[1][0]
			 + (matriz[3][1]*matriz[1][2] - matriz[3][2]*matriz[1][1]) * matriz[2][0];

	float Dy = (matriz[3][1]*matriz[2][2] - matriz[3][2]*matriz[2][1]) * matriz[0][0]
			 - (matriz[0][1]*matriz[2][2] - matriz[0][2]*matriz[2][1]) * matriz[3][0]
			 + (matriz[0][1]*matriz[1][2] - matriz[0][2]*matriz[3][1]) * matriz[2][0];

	float Dz = (matriz[1][1]*matriz[3][2] - matriz[1][2]*matriz[3][1]) * matriz[0][0]
			 - (matriz[0][1]*matriz[3][2] - matriz[0][2]*matriz[3][1]) * matriz[1][0]
			 + (matriz[0][1]*matriz[1][2] - matriz[0][2]*matriz[1][1]) * matriz[3][0];

	// Resultado

	if(D == 0 && Dx == 0 && Dy == 0 && Dz == 0){
		cout<<"El sistema tiene infinitas soluciones."<<endl;
	}else if(D == 0){
		cout<<"El sistema no tiene solucion."<<endl;
	} else{
		resultado.x = Dx / D;
		resultado.y = Dy / D;
		resultado.z = Dz / D;

		cout<<fixed<< setprecision(4);
		cout<<"X = "<<resultado.x<<endl<<"Y = "<<resultado.y<<endl<<"Z = "<<resultado.z<<endl;
	}
	
}

char PosToChar(int numero){ // Para transformar la posicion de la matriz a una letra para hacerlo comodo para el usuario.
	char caracter;

	if(numero == 0){
		caracter = 'A';
	} else if(numero == 1){
		caracter = 'B';
	} else if(numero == 2){
		caracter = 'C';
	} else if(numero == 3){
		caracter = 'D';
	}

	return caracter;
}
