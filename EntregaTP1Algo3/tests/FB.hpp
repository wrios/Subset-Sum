#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int FB(vector<int>& elems, int cant_total_elems, int ind, int objetivo, int cant_en_uso){
	int con = cant_total_elems+1;
	int sin = cant_total_elems+1;
	if (ind < cant_total_elems)
	{
		con = FB(elems, cant_total_elems, ind+1, objetivo-elems[ind],cant_en_uso+1);
		sin = FB(elems, cant_total_elems, ind+1, objetivo, cant_en_uso);
		if (objetivo - elems[ind] == 0){return min(sin,cant_en_uso+1);}
		if (objetivo - elems[ind] < 0){return sin;}
		return min(con,sin);
	}
	return cant_total_elems+1;
}
int resolverFB(vector<int>& elems, int cant_total_elems, int ind, int objetivo, int cant_en_uso){
	int res = FB(elems, cant_total_elems, ind, objetivo, cant_en_uso);
	if (res == cant_total_elems+1)
	{
		return -1;
	}
	return res;
}