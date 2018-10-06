#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int PodaFactibilidad(vector<int>& elems, int cant_total_elems, int ind, int objetivo, int cant_en_uso){
	int con = cant_total_elems+1;
	int sin = cant_total_elems+1;
	if (objetivo == 0){return cant_en_uso;}
	if (ind < cant_total_elems)
	{
		if (objetivo > 0){sin = PodaFactibilidad(elems, cant_total_elems, ind+1, objetivo, cant_en_uso);}

		if (objetivo - elems[ind] == 0){return min(sin,cant_en_uso+1);}
		else if (objetivo - elems[ind] < 0){return sin;}
		else
		{
			con = PodaFactibilidad(elems, cant_total_elems, ind+1, objetivo-elems[ind],cant_en_uso+1);
			return min(con,sin);
		}
	}
	return cant_total_elems+1;
}
int resolverFac(vector<int>& elems, int cant_total_elems, int ind, int objetivo, int cant_en_uso){
	int res = PodaFactibilidad(elems, cant_total_elems, ind, objetivo,cant_en_uso);
	if (res == cant_total_elems+1)
	{
		return -1;
	}
	return res;
}