#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;



class Ciudad
{

public:
	Ciudad(string nombre, double x, double y)
	{
		this->nombre = nombre;
		this->x = x;
		this->y = y;
	};
	Ciudad() {};

	string nombre;
	double x,y;
};
class Jornada
{
public:
	Jornada(string inicio, string fin, double tiempo)
	{
		this->inicio = inicio;
		this->fin = fin;
		this->tiempo = tiempo;
	}
	Jornada(string inicio, string fin)
	{
		this->inicio = inicio;
		this->fin = fin;
	}
	string inicio;
	string fin;
	double tiempo;
};


class hyperloop
{
public:

	vector<Ciudad> ciudades;


	string ciudad_origen;
	string ciudad_destino;
	vector<string> ciudad_hyperloop;

	vector<Jornada> jornadas;

	double velocidad = 250;
	double tiempo_entre_paradas = 200;


	unsigned N;
	double D;

	double get_tiempo(string origen, string destino)
	{
		double distancia = get_distancia(origen, destino);
		double tiempo = distancia/velocidad + tiempo_entre_paradas;
		return tiempo;
	}
	double get_distancia(string origen, string destino)
	{
		return sqrt(pow((get_ciudad(origen).x - get_ciudad(destino).x), 2) + pow((get_ciudad(origen).y - get_ciudad(destino).y), 2));
	}
	double get_distancia(vector<string> ciudades)
	{
		double distancia = 0;
		for (auto ciudad : ciudades)
		{
			distancia += get_distancia(ciudades[i])
		}
		return sqrt(pow((get_ciudad(origen).x - get_ciudad(destino).x), 2) + pow((get_ciudad(origen).y - get_ciudad(destino).y), 2));
	}

	double get_tiempo_parada_mas_proxima(string nombre, Jornada jornada_actual)
	{
		double dist1 = get_distancia(jornada_actual.inicio, ciudad_origen);
		double dist2 = get_distancia(jornada_actual.inicio, ciudad_destino);
		double distancia_inicio;
		double distancia_fin;
		if (dist1 < dist2)
		{
			distancia_inicio = dist1;
			distancia_fin = get_distancia(ciudad_destino, jornada_actual.fin);
		}
		else {
			distancia_fin = get_distancia(ciudad_origen, jornada_actual.fin);
			distancia_inicio = dist2;
		}

		return distancia_inicio / 15 + distancia_fin / 15 + get_tiempo(ciudad_origen, ciudad_destino);

	}
	unsigned num_mejor_que_jornada()
	{
		unsigned num_mejoras = 0;
		for (auto jornada : jornadas)
		{
			if (jornada.tiempo > round(get_tiempo_parada_mas_proxima(jornada.inicio, jornada)))
			{
				num_mejoras++;
			}
		}
		return num_mejoras;
	}
	string get_ciudad_aleatoria()
	{
		std::mt19937 rng;
		std::uniform_real_distribution<double> aleatorio(0, size(ciudades));
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		rng.seed(seed);

		return ciudades[(unsigned)aleatorio(rng)].nombre;
	}
	Ciudad get_ciudad(string nombre)
	{
		for (auto ciudad : ciudades)
		{
			if (ciudad.nombre == nombre)
				return ciudad;
		}
	}
	vector<Ciudad> get_ciudades(vector<string> ciudades)
	{
		vector<Ciudad> aux;
		for(auto ciudad:ciudades)
			aux.push_back(get_ciudad(ciudad));

		return aux;
	}
	void buscar_ruta_hyperloop(unsigned num_mejoras)
	{
		N = num_mejoras;
		unsigned intentos = 0;
		do {
			do {

				ciudad_destino = get_ciudad_aleatoria();
				ciudad_origen = get_ciudad_aleatoria();
				intentos++;
			} while (ciudad_origen == ciudad_destino);
			cout << intentos++ << endl;
		} while (N > num_mejor_que_jornada());
	}
	void buscar_ruta_hyperloop(unsigned num_mejoras, unsigned distancia_hyper)
	{
		N = num_mejoras;
		D = distancia_hyper;
		unsigned intentos = 0;
		do {
			vector<Ciudad> ciudades;
			do {
				ciudad_destino = get_ciudad_aleatoria();
				ciudad_origen = get_ciudad_aleatoria();
				intentos++;

			} while (ciudad_origen == ciudad_destino && get_distancia(ciudades);

			cout << intentos++ << endl;
		} while (N > num_mejor_que_jornada());
	}
	Ciudad get_ciudad_mas_cercana(string origen, vector<Ciudad>ciudades) {
		double distancia = 99999999999;
		Ciudad ciudad_mas_cercana;
		for (unsigned i = 0; i < size(ciudades); i++)
		{
			if (distancia > get_distancia(origen, ciudades[i].nombre)) {
				ciudad_mas_cercana = ciudades[i];
				distancia = get_distancia(origen, ciudades[i].nombre);
			}
		}
		return ciudad_mas_cercana;
	}
	double tiempo_en_coche(string origen, string destino)
	{
		double tiempo;
		return get_distancia(origen, destino) / 15;
	}
	unsigned tiempo_hyperloop(string origen, string destino)
	{
		double tiempo = 0;

		auto it1 = find(ciudad_hyperloop.begin(), ciudad_hyperloop.end(), origen);
		auto it2 = find(ciudad_hyperloop.begin(), ciudad_hyperloop.end(), destino);
		if (it1 > it2)
			swap(it1, it2);

		vector<string> recorrido(it1,it2+1);
		for (unsigned i = 0; i< size(recorrido)-1;i++)
		{
			tiempo += get_distancia(recorrido[i], recorrido[i + 1])/250+200;
		}
		return round(tiempo);
	}
};
