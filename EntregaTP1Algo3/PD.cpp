#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


uint PD(vector<uint>& elems , vector< vector<uint> >& Matrix, uint filas, uint columnas, uint maximoValor){
	//cout << "filas: "<< Matrix.size() << " columnas: "<< (Matrix[0]).size() <<endl;
	//cout << "filas: "<< filas << " columnas: "<< columnas <<endl;
	if (filas < 0 || columnas < 0 || columnas > maximoValor || filas > maximoValor)
	{
		return maximoValor;
	}
	if (columnas == 0)
	{
		Matrix[filas][columnas] = 0;
	}
	if (Matrix[filas][columnas] == maximoValor)
	{
		Matrix[filas][columnas] = min(PD(elems,Matrix,filas-1,columnas,maximoValor),1+PD(elems,Matrix,filas-1,columnas-elems[filas],maximoValor));
	}
	return Matrix[filas][columnas];
}


int main()
{


	int tam;
	int objetivo;
	cin >> tam;
	cin >> objetivo;
	vector<uint> elems(tam);//tamaño objetivo?
	int cantidad = 0;
	int indice = 0;
	int elem;
	for (int i = 0; i < tam; ++i)
	{
		cin >> elem;
		elems[i] = elem;
	}
	uint filas = tam-1;
	uint columnas = objetivo;
	uint maximoValor = objetivo+1;
	vector< vector<uint> > Matrix(tam,vector<uint>(maximoValor,maximoValor));
	for (int i = 0; i < tam; ++i)
	{
		Matrix[i][0] = 0;
	}
	uint res = PD(elems, Matrix, filas, columnas, maximoValor);
	if (res == maximoValor){cout <<  -1 << endl;}
	else{cout << res << endl;}

	return 0;
}