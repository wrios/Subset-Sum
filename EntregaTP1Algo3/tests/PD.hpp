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
