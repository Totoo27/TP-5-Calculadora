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



// ----- Punto 2 - Operaciones Con Vectores



// ----- Punto 3 - Operaciones con Matrices

void sumarestamatrices();
void multiplicarporescalar();
void multiplicarmatrices();
void multiplicarporescalarv();

// ----- Punto 4 - Sistemas de ecuación.

void sistema2x2();
void sistema3x3();
char PosToChar(int numero);


// ----- MAIN -----

int main(){

	// Variables

	bool terminado = false;

	// Proceso

	do{
		switch(menu()){

		case 1:
			switch(menuOperaciones()){

			case 1:
				break;

			case 2:

				break;

			case 3:

				break;

			case 4:

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

		case 2:
			switch(menuVectores()){

			case 1:

				break;

			case 2:

				break;

			case 3:

				break;

			case 4:

				break;

			case 5:
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

	//sistema3x3(); Funcionando correctamente
	//sistema2x2(); Funcionando correctamente
	//sumarestamatrices(); Funcionando correctamente
	//multiplicarporescalar(); Funcionando correctamente
	//multiplicarmatrices(); Funcionando correctamente
	//multiplicarporescalarv(); Funcionando correctamente

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
	cout<<"1. Suma y Resta"<<endl<<"2. Multiplicacion por Escalar"<<endl<<"3. Producto Escalar"<<endl<<"4. Producto Vectorial"<<endl<<"5. Atras"<<endl<<"Opcion: ";
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



// ----- Punto 2 - Operaciones Con Vectores



// ----- Punto 3 - Operaciones con Matrices

void sumarestamatrices(){
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
				matrizres[j][i]=matriz1[j][i]+matriz2[j][i];
			}
		}
	}else{
		for(int j=0; j<limite0;j++){
			for(int i=0; i<limite1;i++){
				matrizres[j][i]=matriz1[j][i]-matriz2[j][i];
			}
		}
	}

	//Resultado
	cout<<"El resultado es:"<<endl;
	for(int j=0; j<limite0;j++){
		for(int i=0; i<limite1; i++){
			cout<<matrizres[j][i]<<"   ";
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



void multiplcarporescalarv(){
	//Variables
	int limite0=0, limite1=0, esc=0;
	//Aclaracion
	//Ingreso de datos
	cout<<"Ingrese la dimension del vector"<<endl;
	cin>>limite0;
	vector<float> vector(limite0);

	cout<<"Ingrese el numero escalar"<<endl;
	cin>>esc;

	cout<<"Ingreso de datos de la matriz"<<endl;
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
			cout<<vector[j]<<", ";
	}
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
