#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <math.h>
using namespace std;
ofstream salida("salida.txt");
class parking {
public:
	parking(unsigned N) { maximo_plazas = N; numero_coches = vector<int>(N, 0); }
	vector <int> numero_coches;
	vector <int> precios;
	vector <int> pesos;
	deque <int> cola;
	unsigned maximo_coches = 0;
	unsigned maximo_cola = 0;
	unsigned maximo_plazas;
	unsigned ganancia_in_cash = 0;

	bool sacar_de_cola(int coche) {
		for (int i = 0; i < cola.size(); i++)
		{
			salida << "Buscamos el coche " << coche << "En cola: " << cola[i] << endl;
			if (cola[i] == -coche) {
				cola.erase(cola.begin() + i);
				return true;
			}
		}
		return false;
	}
	unsigned coches_aparcados() {
		int coches = 0;
		for (int x : numero_coches)
			if (x)
				coches++;
		return coches;
	}
	void aparcar(int coche) {
		for (unsigned i = 0; i < numero_coches.size(); i++)
		{
			if (!numero_coches[i])
			{
				numero_coches[i] = coche;
				ganancia_in_cash += precios[i] * (int)ceil((double)pesos[coche - 1] / 100);

				return;
			}
		}
	}
	void desaparcar(int coche) {

		for (unsigned i = 0; i < numero_coches.size(); i++)
		{
			if (numero_coches[i] == -coche) {
				numero_coches[i] = 0;
				return;
			}
		}
	}

	void get(int coche) {
		salida << "Entra el coche " << coche;
		if (coche > 0 && coches_aparcados() < maximo_plazas) {
			salida << " APARCA" << endl;
			aparcar(coche);
			if (coches_aparcados() > maximo_coches)
				maximo_coches = coches_aparcados();
		}
		else if (coche < 0) {
			if (!sacar_de_cola(coche)){
				salida << " DESAPARCA" << endl;
				desaparcar(coche);
				if (cola.size()) {
					salida << " y entra el coche en cola " << cola.front() << endl;
					get(cola.front());
					cola.pop_front();
				}
			}
		}
		else
		{
			salida << "En cola: " << coche << endl;
			cola.push_back(coche);
			if (cola.size() > maximo_cola)
				maximo_cola = cola.size();
		}
	}
};

void main() {

	ifstream inputs("level5/input.5");
	int dato, numero_coches = 0, plazas_maximas = 0;
	inputs >> plazas_maximas >> numero_coches;
	parking parking(plazas_maximas);
	for (int i = 0; i < plazas_maximas; i++) {
		inputs >> dato;
		parking.precios.push_back(dato);
	}
	for (int i = 0; i < numero_coches; i++) {
		inputs >> dato;
		parking.pesos.push_back(dato);
	}
	while (inputs >> dato)
		parking.get(dato);

	salida << parking.ganancia_in_cash << endl;
	salida.close();
}