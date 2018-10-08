#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <algorithm>
#include "Factibilidad.hpp"
#include "Optimalidad.hpp"
#include "PD.hpp"
#include "FB.hpp"
#include <chrono>
#include <time.h>
#include <math.h>
using namespace std;
int main()
{	
	vector<int> objetivos = {800000};
	vector<int> cantidad_elementos = {25};
	bool correrFB = true;
	bool correrFactibilidad = true;
	bool correrOptimalidad = true;
	bool correrPD = true;
	int cantidad_de_iteraciones = 5;
	for (int i = 0; i < objetivos.size(); ++i)
	{
		cout << "Corriendo casos de suma: " << objetivos[i] << endl;
		ofstream fb ("plots/FB_objetivos_"+to_string(objetivos[i])+".csv");
		ofstream fac ("plots/Fac_objetivos_"+to_string(objetivos[i])+".csv");
		ofstream pd ("plots/PD_objetivos_"+to_string(objetivos[i])+".csv");
		ofstream op ("plots/Op_objetivos_"+to_string(objetivos[i])+".csv");
		vector<double> fb_resultados(cantidad_elementos.size(),0);
		vector<double> fac_resultados(cantidad_elementos.size(),0);
		vector<double> op_resultados(cantidad_elementos.size(),0);
		vector<double> pd_resultados(cantidad_elementos.size(),0);
		srand (time(NULL));
		for (int j = 0; j < cantidad_elementos.size(); ++j)
		{
				cout << "cantidad de elementos: "<< cantidad_elementos[j] << endl;
					//generando caso
				vector<int> elementos;
				for (int k = 0; k < cantidad_elementos[j]; ++k)
				{
					//ultima corrida con 7
					//elementos.push_back(objetivos[i]);
					elementos.push_back((rand() % (objetivos[i]+1))/16);
				}
				sort(elementos.begin(), elementos.end());
				reverse(elementos.begin(), elementos.end());
		for (int cant_iter = 0; cant_iter < cantidad_de_iteraciones; ++cant_iter)
		{	
			cout << "Numero de iteracion: "<< cant_iter<< endl;
				int resultadoFB;
				if (correrFB)
				{	
					cout << "Inicio FB con cantidad de elementos: "<< cantidad_elementos[j] << endl;
					int indiceInicioFB = 0;
					int cant_en_uso_FB = 0;
					auto starFB = chrono::steady_clock::now();
					resultadoFB = resolverFB(elementos, cantidad_elementos[j], indiceInicioFB, objetivos[i], cant_en_uso_FB);
					auto endFB = chrono::steady_clock::now();
					auto diffFB = endFB - starFB;
					fb_resultados[j] += chrono::duration <double, milli>(diffFB).count();
					cout << " Fin FB con cantidad de elementos: "<< cantidad_elementos[j] << endl;
				}
				if (correrFactibilidad)
				{
					int indiceInicioFac = 0;
					int cant_en_uso_Fac = 0;
					cout << "Inicio Fac con cantidad de elementos: "<< cantidad_elementos[j] << endl;
					auto starFac = chrono::steady_clock::now();
					int resultadoFac = resolverFac(elementos, cantidad_elementos[j], indiceInicioFac, objetivos[i], cant_en_uso_Fac);
					auto endFac = chrono::steady_clock::now();
					auto diffFac = endFac - starFac;
					fac_resultados[j] += chrono::duration <double, milli>(diffFac).count();
					cout << " Fin Fac con cantidad de elementos: "<< cantidad_elementos[j] << endl;
					if (resultadoFac != resultadoFB)
					{
						ofstream FacRompe ("ROmpe_Fac_cantidad_de_elementos"+to_string(cantidad_elementos[j])+"objetivos_"+to_string(objetivos[i])+".csv");
						FacRompe << cantidad_elementos[j];
						FacRompe << " ";
						FacRompe << objetivos[i];
						FacRompe << " Fac: ";
						FacRompe << resultadoFac;
						FacRompe << " FB: ";
						FacRompe << resultadoFB;
						FacRompe << endl;
						for (int k = 0; k < cantidad_elementos[j]-1; ++k)
						{
							FacRompe << elementos[k];
							FacRompe << " ";
						}
						FacRompe << elementos[cantidad_elementos[j]-1];
						FacRompe << endl;
						FacRompe.close();
					}
				}
				int resultadoOp;
				if (correrOptimalidad)
				{
					int indiceInicioOp = 0;
					int cant_en_uso_Op = 0;
					int cantidad_optima_elems = cantidad_elementos[j]+1;
					cout << "Inicio Op con cantidad de elementos: "<< cantidad_elementos[j] << endl;
					auto starOp = chrono::steady_clock::now();
					resultadoOp = resolverOp(elementos, cantidad_elementos[j], indiceInicioOp, objetivos[i], cant_en_uso_Op, cantidad_optima_elems);
					auto endOp = chrono::steady_clock::now();
					auto diffOp = endOp - starOp;
					op_resultados[j] += chrono::duration <double, milli>(diffOp).count();
					cout << " Fin Op con cantidad de elementos: "<< cantidad_elementos[j] << endl;
					if (resultadoOp != resultadoFB)
					{
						ofstream OpRompe ("OpRompe_cantidad_de_elementos"+to_string(cantidad_elementos[j])+"objetivos_"+to_string(objetivos[i])+".csv");
						OpRompe << cantidad_elementos[j];
						OpRompe << " ";
						OpRompe << objetivos[i];
						OpRompe << " Op: ";
						OpRompe << resultadoOp;
						OpRompe << " FB: ";
						OpRompe << resultadoFB;
						OpRompe << endl;
						for (int k = 0; k < cantidad_elementos[j]-1; ++k)
						{
							OpRompe << elementos[k];
							OpRompe << " ";
						}
						OpRompe << elementos[cantidad_elementos[j]-1];
						OpRompe << endl;
						OpRompe.close();
					}
				}
				if (correrPD)
				{	
					int indiceInicioPD = 0;
					int filas = cantidad_elementos[j]-1;//cantidad de elementos-1
					int columnas = objetivos[i];
					int maximoValor = objetivos[i]+1;
					cout << "Inicio PD con cantidad de elementos: "<< cantidad_elementos[j] << endl;
					auto starPD = chrono::steady_clock::now();
					vector< vector<int> > Matrix(cantidad_elementos[j],vector<int>(maximoValor,maximoValor));
					for (int i = 0; i < cantidad_elementos[j]; ++i)
					{
						Matrix[i][0] = 0;
					}
					int resultadoPD = ResolverPD(elementos, Matrix, filas, columnas, maximoValor);
					auto endPD = chrono::steady_clock::now();
					auto diffPD = endPD - starPD;
					pd_resultados[j] += chrono::duration <double, milli>(diffPD).count();
					cout << " Fin PD con cantidad de elementos: "<< cantidad_elementos[j] << endl;
					//if (resultadoPD != resultadoFB)
					if (false)
					{
						ofstream pdRompe ("PDRompe_cantidad_de_elementos"+to_string(cantidad_elementos[j])+"objetivos_"+to_string(objetivos[i])+".csv");
						pdRompe << cantidad_elementos[j];
						pdRompe << " ";
						pdRompe << objetivos[i];
						pdRompe << " PD: ";
						pdRompe << resultadoPD;
						pdRompe << " FB: ";
						pdRompe << resultadoFB;
						pdRompe << endl;
						for (int k = 0; k < cantidad_elementos[j]-1; ++k)
						{
						pdRompe << elementos[k];
							pdRompe << " ";
						}
						pdRompe << elementos[cantidad_elementos[j]-1];
						pdRompe << endl;
						pdRompe.close();
					}
				}
			}
			cout << endl;		
		}
		for (int iter = 0; iter < fb_resultados.size()-1; ++iter)
		{
			fb_resultados[iter] = fb_resultados[iter]/cantidad_de_iteraciones;
			fb << fb_resultados[iter];
			fb << ",";
		}
		for (int iter = 0; iter < op_resultados.size()-1; ++iter)
		{
			op_resultados[iter] = op_resultados[iter]/cantidad_de_iteraciones;
			op << op_resultados[iter];
			op << ",";
		}
		for (int iter = 0; iter < fac_resultados.size()-1; ++iter)
		{
			fac_resultados[iter] = fac_resultados[iter]/cantidad_de_iteraciones;
			fac << fac_resultados[iter];
			fac << ",";
		}
		for (int iter = 0; iter < pd_resultados.size()-1; ++iter)
		{
			pd_resultados[iter] = pd_resultados[iter]/cantidad_de_iteraciones;
			pd << pd_resultados[iter];
			pd << ",";
		}
		fb_resultados[fb_resultados.size()-1] = fb_resultados[fb_resultados.size()-1]/cantidad_de_iteraciones;
		fb << fb_resultados[fb_resultados.size()-1];
		fac_resultados[fac_resultados.size()-1] = fac_resultados[fac_resultados.size()-1]/cantidad_de_iteraciones;
		fac << fac_resultados[fac_resultados.size()-1];
		op_resultados[op_resultados.size()-1] = op_resultados[op_resultados.size()-1]/cantidad_de_iteraciones;
		op << op_resultados[op_resultados.size()-1];
		pd_resultados[pd_resultados.size()-1] = pd_resultados[pd_resultados.size()-1]/cantidad_de_iteraciones;
		pd << pd_resultados[pd_resultados.size()-1];
		cout << "Termino casos de suma: " << objetivos[i] << endl;
		pd.close();
		fac.close();
		fb.close();
		op.close();
	}
	return 0;
}