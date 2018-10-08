#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int PodaOptimalidad(vector<int>& elems, int cant_total_elems, int ind, int objetivo, int cant_en_uso, int optimo_actual){
	int con = cant_total_elems+1;
	int sin = cant_total_elems+1;
	if (ind < cant_total_elems)
	{
		sin = PodaFactibilidad(elems, cant_total_elems, ind+1, objetivo, cant_en_uso);
		if (cant_en_uso+1 < optimo_actual)
		{
			if (objetivo - elems[ind] == 0)
			{
				optimo_actual = cant_en_uso+1;
			}
			con = PodaOptimalidad(elems, cant_total_elems, ind+1, objetivo-elems[ind],cant_en_uso+1, optimo_actual);
		}
		return min(min(con,sin),optimo_actual);
	}
	if (objetivo == 0){return cant_en_uso;}
	return cant_total_elems+1;
}
int resolverOp(vector<int>& elems, int cant_total_elems, int ind, int objetivo, int cant_en_uso, int optimo_actual){
	int res = PodaOptimalidad(elems, cant_total_elems, ind, objetivo, cant_en_uso, optimo_actual);
	if (res == cant_total_elems+1)
	{
		return -1;
	}
	return res;
}