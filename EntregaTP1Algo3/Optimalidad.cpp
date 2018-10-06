#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

uint PodaOptimalidad(vector<uint>& elems, uint cant_total_elems, uint ind, uint objetivo, uint cant_en_uso, uint optimo_actual){
	uint con = cant_total_elems+1;
	uint sin = cant_total_elems+1;
	if (ind < cant_total_elems)
	{
		if (cant_en_uso < optimo_actual)
		{
			if (objetivo - elems[ind] == 0)
			{
				optimo_actual = cant_en_uso;
			}
			con = PodaOptimalidad(elems, cant_total_elems, ind+1, objetivo-elems[ind],cant_en_uso+1, optimo_actual);
		}
		sin = PodaOptimalidad(elems, cant_total_elems, ind+1, objetivo, cant_en_uso, optimo_actual);
	}
	if (objetivo - elems[ind] == 0){return min(min(con,sin),cant_en_uso+1);}
	if (objetivo - elems[ind] < 0){return cant_total_elems+1;}
	if (objetivo == 0){return min(min(con,sin),cant_en_uso);}
	return min(con,sin);
}

int main()
{
	uint cant_total_elems,objetivo;
	cin >> cant_total_elems;
	cin >> objetivo;
	vector<uint> elems(cant_total_elems);
	uint cant_en_uso = 0;
	uint indice = 0;
	uint optimo_actual = cant_total_elems+1;
	uint a;
	for (uint i = 0; i < cant_total_elems; ++i)
	{
		cin >> a;
		elems[i] = a;
	}
	uint res = PodaOptimalidad(elems, cant_total_elems, indice, objetivo, cant_en_uso, optimo_actual);
	if (res == cant_total_elems+1){cout <<  -1 << endl;}
	else{cout << res << endl;}
	return 0;
}

