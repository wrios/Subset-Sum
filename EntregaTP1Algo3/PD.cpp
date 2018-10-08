#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int PD(vector<int>& elems , vector< vector<int> >& Matrix, int filas, int columnas, int maximoValor){
	if (filas < 0 || columnas < 0 || columnas > maximoValor || filas > maximoValor)
	{
		return maximoValor;
	}
	if (columnas == 0)
	{
		return Matrix[filas][columnas];
	}
	if (Matrix[filas][columnas] == maximoValor)
	{
		Matrix[filas][columnas] = min(PD(elems,Matrix,filas-1,columnas,maximoValor),1+PD(elems,Matrix,filas-1,columnas-elems[filas],maximoValor));
		if (Matrix[filas][columnas] == maximoValor)
		{
			Matrix[filas][columnas] = maximoValor+1;
		}
	}
	return Matrix[filas][columnas];
}

int ResolverPD(vector<int>& elems , vector< vector<int> >& Matrix, int filas, int columnas, int maximoValor){
	int res = PD(elems, Matrix, filas, columnas, maximoValor);
	if (res == maximoValor+1)
	{
		return -1;
	}
	return res;
}


int main()
{


	int tam;
	int objetivo;
	cin >> tam;
	cin >> objetivo;
	vector<int> elems(tam);//tamaño objetivo?
	int cantidad = 0;
	int indice = 0;
	int elem;
	for (int i = 0; i < tam; ++i)
	{
		cin >> elem;
		elems[i] = elem;
	}
	int filas = tam-1;
	int columnas = objetivo;
	int maximoValor = objetivo+1;
	vector< vector<int> > Matrix(tam,vector<int>(maximoValor,maximoValor));
	for (int i = 0; i < tam; ++i)
	{
		Matrix[i][0] = 0;
	}
	int res = ResolverPD(elems, Matrix, filas, columnas, maximoValor);
	cout << res << endl;

	return 0;
}