#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hyperloop.h"
using namespace std;

void main()
{
	ifstream inputs("input/level4/level4-4.txt");
	unsigned num_destinos;
	unsigned num_journey;
	unsigned num_mejoras_para_aceptar_ruta;
	unsigned distancia_maxima_loop;
	inputs >> num_destinos;
	hyperloop hyper;

	for(unsigned i = 0; i < num_destinos; i++)
	{
		string ciudad;
		double x, y;

		inputs >> ciudad;
		inputs >> x >> y;

		hyper.ciudades.push_back(Ciudad(ciudad, x,y));
	}
	inputs >> num_journey;

	for (unsigned i = 0; i < num_journey; i++)
	{
		string inicio, fin;
		double tiempo;
		inputs >> inicio >> fin >> tiempo;
		hyper.jornadas.push_back(Jornada(inicio, fin, tiempo));
	}
	
	inputs >> num_mejoras_para_aceptar_ruta;
	inputs >> distancia_maxima_loop;

	hyper.buscar_ruta_hyperloop(num_mejoras_para_aceptar_ruta, distancia_maxima_loop);

}
