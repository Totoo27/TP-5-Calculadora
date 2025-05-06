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
#include <string>
#include <limits>
#include <math.h>


using namespace std;

// Estructuras

struct Resultado3x3{
	float x,y,z;
};

struct Resultado2x2{
	float x,y;
};

// FUNCIONES PROTOTIPADOS

string floatLimit(float numero);

// ----- Menus

int menu();
int menuOperaciones();
int menuVectores();
int menuMatrices();
int menuSistemas();

// ----- Punto 1 - Operaciones Básicas

void suma();
void resta();
void multiplicacion();
void division();
void potencia();
void raiz();

// ----- Punto 2 - Operaciones Con Vectores

void ingresoVector(vector<float>& vector);
void sumaVectores();
void restaVectores();
void multiplicarporescalarv();
void productoEscalar();
void productoVectorial();


// ----- Punto 3 - Operaciones con Matrices

void sumarestamatrices();
void multiplicarporescalar();
void multiplicarmatrices();
float sacarDet(vector<vector<float>>& matriz, int limite);
void sacarDeterminante();

// ----- Punto 4 - Sistemas de ecuación.

void sistema2x2();
void sistema3x3();
char PosToChar(int numero);


// ----- MAIN -----

int main(){

	// Variables

	bool terminado = false;

	// Proceso

	//sumarestamatrices(); *

	do{
		switch(menu()){

		case 1:
			switch(menuOperaciones()){

			case 1:
				suma();
				break;

			case 2:
				resta();
				break;

			case 3:
				multiplicacion();
				break;

			case 4:
				division();
				break;

			case 5:
				potencia();
				break;

			case 6:
				raiz();
				break;

			case 7:
				// Volver
				break;

			default:
				cout<<"Esa no es una opcion valida."<<endl;
			}
			break;

		case 2:
			switch(menuVectores()){

			case 1:
				sumaVectores();
				break;

			case 2:
				restaVectores();
				break;

			case 3:
				multiplicarporescalarv();
				break;

			case 4:
				productoEscalar();
				break;

			case 5:
				productoVectorial();
				break;

			case 6:
				// Volver
				break;

			default:
				cout<<"Esa no es una opcion valida."<<endl;
			}
			break;

		case 3:
			switch(menuMatrices()){

			case 1:
				sumarestamatrices();
				break;

			case 2:
				multiplicarporescalar();
				break;

			case 3:
				multiplicarmatrices();
				break;

			case 4:
				sacarDeterminante();
				break;

			case 5:
				
				break;

			case 6:

				break;

			case 7:
				// Volver
				break;

			default:
				cout<<"Esa no es una opcion valida."<<endl;
			}
			break;

		case 4:
			switch(menuSistemas()){
			case 1:
				sistema2x2();
				break;

			case 2:
				sistema3x3();
				break;

			case 3:
				// Volver
				break;

			default:
				cout<<"Esa no es una opcion valida."<<endl;
			}
			break;

		case 5:
			terminado = true;
			cout<<"Sistema finalizado.";
			break;

		default:
			cout<<"Esa no es una opcion valida."<<endl;

		}

	}while(!terminado);

	system("pause");
	return 0;
}

// Funciones

string floatLimit(float numero) {

    string num = to_string(numero);

    while (!num.empty() && num.back() == '0') {
        num.pop_back();
    }

    if (!num.empty() && num.back() == '.') {
        num.pop_back();
    }

    return num;
}

// ----- Menus

int menu(){

	int opcion;

	cout<<"----- MENU -----"<<endl<<endl;
	cout<<"1. Operaciones"<<endl<<"2. Operaciones con Vectores"<<endl<<"3. Operaciones con Matrices"<<endl<<"4. Sistemas de Ecuacion"<<endl<<"5. Salir"<<endl<<"Opcion: ";
	cin>>opcion;


	// Detectar caracter
	if(cin.fail()){

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return -1;

	} else{

		return opcion;

	}

}

int menuOperaciones(){

	int opcion;

	cout<<"----- MENU OPERACIONES -----"<<endl<<endl;
	cout<<"1. Suma"<<endl<<"2. Resta"<<endl<<"3. Multiplicacion"<<endl<<"4. Division"<<endl<<"5. Potencia"<<endl<<"6. Raiz"<<endl<<"7. Atras"<<endl<<"Opcion: ";
	cin>>opcion;


	// Detectar caracter
	if(cin.fail()){

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return -1;

	} else{

		return opcion;

	}
}

int menuVectores(){
	int opcion;

	cout<<"----- MENU VECTORES -----"<<endl<<endl;
	cout<<"1. Suma"<<endl<<"2. Resta"<<endl<<"3. Multiplicacion por Escalar"<<endl<<"4. Producto Escalar"<<endl<<"5. Producto Vectorial"<<endl<<"6. Atras"<<endl<<"Opcion: ";
	cin>>opcion;


	// Detectar caracter
	if(cin.fail()){

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return -1;

	} else{

		return opcion;

	}
}

int menuMatrices(){
	int opcion;

	cout<<"----- MENU MATRICES -----"<<endl<<endl;
	cout<<"1. Suma y Resta"<<endl<<"2. Multiplicacion por escalar"<<endl<<"3. Multiplicacion"<<endl<<"4. Averiguar Determinante"<<endl<<"5. Averiguar Inversa"<<endl<<"6. Division"<<endl<<"7. Atras"<<endl<<"Opcion: ";
	cin>>opcion;


	// Detectar caracter
	if(cin.fail()){

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return -1;

	} else{

		return opcion;

	}
}

int menuSistemas(){
	int opcion;

	cout<<"----- MENU SISTEMAS -----"<<endl<<endl;
	cout<<"1. Sistema 2x2"<<endl<<"2. Sistema 3x3"<<endl<<"3. Atras"<<endl<<"Opcion: ";
	cin>>opcion;


	// Detectar caracter
	if(cin.fail()){

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return -1;

	} else{

		return opcion;

	}
}


// ----- Punto 1 - Operaciones Básicas

void suma(){
	//variables
	float a,b,suma;
	
	//ingreso de datos
	cout<<"ingresa el primer numero: ";
	cin>>a;
	cout<<"ingresa el segundo numero: ";
	cin>>b;
	
	//proceso matematico
	suma = a + b;
	
	//resultado
	cout<<"el resultado es: "<<suma<<endl;
	
}

void resta(){
	//variables
	float a,b,resta;
	
	//ingreso de datos
	cout<<"ingresa el primer numero: ";
	cin>>a;
	cout<<"ingresa el segundo numero: ";
	cin>>b;
	
	//proceso matematico
	resta = a - b;
	
	//resultado
	cout<<"el resultado es: "<<resta<<endl;
	
}

void multiplicacion(){
	//variables
	float a,b,multi;
	
	//ingreso de datos
	cout<<"ingresa el primer numero: ";
	cin>>a;
	cout<<"ingresa el segundo numero: ";
	cin>>b;
	
	//proceso matematico
	multi = a * b;
	
	//resultado
	cout<<"el resultado es: "<<multi<<endl;
	
}

void division(){
	//variables
	float a,b,divi;
	
	//ingreso de datos
	cout<<"ingrese el numerador: ";
	cin>>a;
	cout<<"ingrese el divisor: ";
	cin>>b;
	
	//proceso matematico
	
	if(b == 0){
	cout<<"No se puede dividir por 0."<<endl;
	return;
	}
	
	divi = a / b;
	
	//resultado
	cout<<"el resultado es: "<<divi<<endl;
	
}

void potencia(){
	//variables
	float a,b,po;
	
	//ingreso de datos
	cout<<"ingrese el numero: ";
	cin>>a;
	cout<<"ingrese el indice de la potencia: ";
	cin>>b;
	
	//proceso matematico
	po = pow(a,b);
	
	//resultado
	cout<<"el resultado es: "<<po<<endl;
	
}

void raiz(){

	//variables
	float a,b,r;
	
	//ingreso de datos
	cout<<"ingrese el numero: ";
	cin>>a;
	cout<<"ingrese el indice de la raiz: ";
	cin>>b;
	
	//proceso matematico
	r = pow(a,1/b);
	
	//resultado
	cout<<"el resultado es: "<<r<<endl;
	
}

// ----- Punto 2 - Operaciones Con Vectores

void ingresoVector(vector<float>& vector){

	for(int i = 0; i < vector.size(); i++){

		cout<<"Ingrese el numero "<<i+1<<": ";
		cin>>vector[i];

	}
	cout<<endl;

}

void sumaVectores(){

	// Variables
	int limite;

	// Aclaracion
	cout<<"Ambos vectores tienen que tener las mismas dimensiones."<<endl<<endl;

	cout<<"Ingrese la dimension de los vectores: ";
	cin>>limite;


	// Vectores
	vector<float> vector1(limite);
	vector<float> vector2(limite);
	vector<float> vectorR(limite);

	// Ingreso de Datos
	cout<<"Ingrese los valores del primer vector: "<<endl;
	ingresoVector(vector1);

	cout<<"Ingrese los valores del segundo vector: "<<endl;
	ingresoVector(vector2);

	// Proceso matematico
	for(int i = 0; i < limite; i++){
		vectorR[i] = vector1[i] + vector2[i];
	}

	// Resultado

	cout<<"El vector resultado es:"<<endl;
	for(int i = 0; i < limite; i++){
		cout<<vectorR[i]<<"\t";
	}
	cout<<endl;

}

void restaVectores(){

	// Variables
	int limite;

	// Aclaracion
	cout<<"Ambos vectores tienen que tener las mismas dimensiones."<<endl<<endl;

	cout<<"Ingrese la dimension de los vectores: ";
	cin>>limite;


	// Vectores
	vector<float> vector1(limite);
	vector<float> vector2(limite);
	vector<float> vectorR(limite);

	// Ingreso de Datos
	cout<<"Ingrese los valores del primer vector: "<<endl;
	ingresoVector(vector1);

	cout<<"Ingrese los valores del segundo vector: "<<endl;
	ingresoVector(vector2);

	// Proceso matematico
	for(int i = 0; i < limite; i++){
		vectorR[i] = vector1[i] - vector2[i];
	}

	// Resultado

	cout<<"El vector resultado es:"<<endl;
	for(int i = 0; i < limite; i++){
		cout<<vectorR[i]<<"\t";
	}
	cout<<endl;

}

void multiplicarporescalarv(){

	//Variables
	int limite0=0, esc=0;

	//Ingreso de datos
	cout<<"Ingrese la dimension del vector"<<endl;
	cin>>limite0;
	vector<float> vector(limite0);

	cout<<"Ingrese el numero escalar"<<endl;
	cin>>esc;

	cout<<"Ingreso de datos del vector"<<endl;
	for(int i=0; i<limite0; i++){
			cout<<"Ingrese elemento "<<i<<endl;
			cin>>vector[i]; 
	}

	//Proceso matematico
	for(int j=0; j<limite0;j++){
			vector[j]=vector[j]*esc;
	}

	//Resultado
	cout<<"El resultado es:"<<endl;
	for(int j=0; j<vector.size();j++){
			cout<<vector[j]<<"\t";
	}
	cout<<endl;
}

void productoEscalar(){

	// Variables
	int limite;
	float resultado = 0;

	// Aclaracion
	cout<<"Ambos vectores tienen que tener las mismas dimensiones."<<endl<<endl;

	cout<<"Ingrese la dimension de los vectores: ";
	cin>>limite;


	// Vectores
	vector<float> vector1(limite);
	vector<float> vector2(limite);

	// Ingreso de Datos
	cout<<"Ingrese los valores del primer vector: "<<endl;
	ingresoVector(vector1);

	cout<<"Ingrese los valores del segundo vector: "<<endl;
	ingresoVector(vector2);

	// Proceso matematico

	for(int i=0; i<limite; i++){
		resultado+=vector1[i]*vector2[i];
	}

	// Resultado

	cout<<"El producto escalar de ambos vectores es: "<<resultado<<endl;

}

void productoVectorial(){

	// Variables
	int limite = 3;
	// Vectores
	vector<float> vector1(limite);
	vector<float> vector2(limite);
	vector<float> vectorR(limite);

	// Aclaracion
	cout<<"Ambos vectores tienen dimension 3."<<endl<<endl;

	// Ingreso de Datos
	cout<<"Ingrese los valores del primer vector: "<<endl;
	ingresoVector(vector1);

	cout<<"Ingrese los valores del segundo vector: "<<endl;
	ingresoVector(vector2);

	// Proceso matematico

	vectorR[0]=(vector1[1]*vector2[2])-(vector2[1]*vector1[2]);
	vectorR[1]=(vector1[2]*vector2[0])-(vector2[2]*vector1[0]);
	vectorR[2]=(vector1[0]*vector2[1])-(vector2[0]*vector1[1]);

	// Resultado

	cout<<"El vector resultante es: "<<endl;
	for(int i = 0; i < limite; i++){
		cout<<vectorR[i]<<"\t";
	}
	cout<<endl;

}

// ----- Punto 3 - Operaciones con Matrices

void sumarestamatrices(){ // No funciona correctamente
	//Variables
	int limite0=0, limite1=0, op=0;

	//Aclaracion
	cout<<"La suma o resta de matrices, debe ser necesariamente con matrices de dimensiones identicas"<<endl;
	//Ingreso de datos
	cout<<"Seleccione operacion."<<endl;
	cout<<"1. Suma"<<endl;
	cout<<"2. Resta"<<endl;
	cin>>op;

	cout<<"Ingrese la dimension de las matrices (filas)"<<endl;
	cin>>limite0;
	cout<<"Ingrese la dimension de las matrices (columnas)"<<endl;
	cin>>limite1;
	
	float matriz1[limite0][limite1];
	float matriz2[limite0][limite1];
	float matrizres[limite0][limite1];

	cout<<"Ingreso de datos de la primer matriz"<<endl;
	for(int i=0; i<limite0; i++){
		for(int j=0; j<limite1; j++){
			cout<<"Ingrese elemento "<<i<<" de la columna "<<j<<endl;
			cin>>matriz1[i][j]; 
		}
	}

	cout<<"Ingreso de datos de la segunda matriz"<<endl;
	for(int i=0; i<limite0; i++){
		for(int j=0; j<limite1; j++){
			cout<<"Ingrese elemento "<<i<<" de la columna "<<j<<endl;
			cin>>matriz1[i][j]; 
		}
	}

	//Proceso matematico
	if(op==1){

		for(int j=0; j<limite0;j++){
			for(int i=0; i<limite1;i++){
				matrizres[j][i] = matriz1[j][i] + matriz2[j][i];
			}
		}

	}else{

		for(int j=0; j<limite0;j++){
			for(int i=0; i<limite1;i++){
				matrizres[j][i] = matriz1[j][i] - matriz2[j][i];
			}
		}

	}

	//Resultado
	cout<<"El resultado es:"<<endl;
	for(int j=0; j<limite0;j++){
		for(int i=0; i<limite1; i++){
			cout<<matrizres[j][i]<<"\t";
		}
		cout<<endl;
	}
}


void multiplicarporescalar(){
	//Variables
	int limite0=0, limite1=0, esc=0;
	//Aclaracion
	//Ingreso de datos
	cout<<"Ingrese la dimension de las matriz (filas)"<<endl;
	cin>>limite0;
	cout<<"Ingrese la dimension de las matriz (columnas)"<<endl;
	cin>>limite1;
	vector<vector<float>> matriz1(limite0, vector<float>(limite1));

	cout<<"Ingrese el numero escalar"<<endl;
	cin>>esc;

	cout<<"Ingreso de datos de la matriz"<<endl;
	for(int i=0; i<limite0; i++){
		for(int j=0; j<limite1; j++){
			cout<<"Ingrese elemento "<<i<<" de la columna "<<j<<endl;
			cin>>matriz1[i][j]; 
		}
	}
	//Proceso matematico
	for(int j=0; j<limite0;j++){
		for(int i=0; i<limite1;i++){
			matriz1[j][i]=matriz1[j][i]*esc;
		}
	}
	//Resultado
	cout<<"El resultado es:"<<endl;
	for(int j=0; j<limite0;j++){
		for(int i=0; i<limite1; i++){
			cout<<matriz1[j][i]<<"   ";
		}
		cout<<endl;
	}
}



void multiplicarmatrices(){
	//Variables
	int limite0=0, limite1=0, op=0,limite2=0,limite3=0;

	//Aclaracion
	cout<<"El número de columnas de la primera matriz debe ser igual al numero de filas de la segunda matriz"<<endl;
	//Ingreso de datos
	
	cout<<"Ingrese la dimension de la matriz 1 (filas)"<<endl;
	cin>>limite0;
	cout<<"Ingrese la dimension de la matriz 1 (columnas)"<<endl;
	cin>>limite1;
	cout<<"Ingrese la dimension de la matriz 2 (filas)"<<endl;
	cin>>limite2;
	cout<<"Ingrese la dimension de la matriz 2 (columnas)"<<endl;
	cin>>limite3;
	
	vector<vector<float>> matriz1(limite0, vector<float>(limite1));
    vector<vector<float>> matriz2(limite2, vector<float>(limite3));
    vector<vector<float>> matrizres(limite0, vector<float>(limite3, 0.0f));
	if(limite1!=limite2){
		cout<<"Dimensiones no validas"<<endl;
		return;
	}

	cout<<"Ingreso de datos de la primer matriz"<<endl;
	for(int i=0; i<limite0; i++){
		for(int j=0; j<limite1; j++){
			cout<<"Ingrese elemento "<<i<<" de la columna "<<j<<endl;
			cin>>matriz1[i][j]; 
		}
	}
	cout<<"Ingreso de datos de la segunda matriz"<<endl;
	for(int i=0; i<limite2; i++){
		for(int j=0; j<limite3; j++){
			cout<<"Ingrese elemento "<<i<<" de la columna "<<j<<endl;
			cin>>matriz2[i][j]; 
		}

	}
	//Proceso matematico
		for(int i=0; i<limite0;i++){
			for(int j=0; j<limite3;j++){
				for(int k=0; k<limite1; k++){
					matrizres[i][j]+=matriz1[i][k]*matriz2[k][j];
				}
			}
		}

	//Resultado
	cout<<"El resultado es:"<<endl;
	for(int j=0; j<limite0;j++){
		for(int i=0; i<limite3; i++){
			cout<<matrizres[j][i]<<"   ";
		}
		cout<<endl;
	}
}

float sacarDet(vector<vector<float>>& matriz, int limite) {

    float resultado = 0;

    if (limite == 1) { // Sacar matriz 1x1

        resultado = matriz[0][0];

    } else if (limite == 2) { // Sacar matriz 2x2

        resultado = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];

    } else { // Sacar matriz NxN si N > 2

        for (int j = 0; j < limite; j++) {
            
            vector<vector<float>> submatriz;

            for (int fila = 1; fila < limite; fila++) {

                vector<float> nuevaFila;

                for (int col = 0; col < limite; col++) {

                    if (col != j) {
                        nuevaFila.push_back(matriz[fila][col]);
                    }

                }

                submatriz.push_back(nuevaFila);

            }

            float signo;
			if (j % 2 == 0) {
    			signo = 1;
			} else {
   				signo = -1;
			}

            resultado += signo * matriz[0][j] * sacarDet(submatriz, limite - 1);
        }

    }

    return resultado;
}

void sacarDeterminante(){

	// Variables
	int limite;

	// Aclaracion
	cout<<"La matriz debe ser una matriz cuadrada para tener determinante."<<endl;

	// Ingreso Datos
	cout<<"Ingrese el numero de columnas y filas que tendrá la matriz: ";
	cin>>limite;

	vector<vector<float>> matriz(limite, vector<float>(limite));

	for(int i = 0; i<limite;i++){

		for(int j = 0; j<limite;j++){

			cout<<"Ingrese el numero de la posicion "<<i<<", "<<j<<": ";
			cin>>matriz[i][j];

		}

	}

	// Proceso matematico

	float D = sacarDet(matriz, limite);

	// Resultado
	cout<<endl<<"La determinante de la matriz ingresada es: "<<D<<endl;

}

void determinantematriz(){
	//Variables
	//Aclaracion
	//Ingreso de datos
	
	//Proceso matematico
	
	//Resultado
	
}

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
		cout<<"X = "<<floatLimit(resultado.x)<<endl<<"Y = "<<floatLimit(resultado.y)<<endl;
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
         	 + (matriz[0][1]*matriz[3][2] - matriz[0][2]*matriz[3][1]) * matriz[2][0];

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

		cout<<"X = "<<floatLimit(resultado.x)<<endl<<"Y = "<<floatLimit(resultado.y)<<endl<<"Z = "<<floatLimit(resultado.z)<<endl;
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
