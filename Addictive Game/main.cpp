#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Flow.h"
using namespace std;

void main()
{
	ifstream inputs("input/level1-0.in");
	ofstream outputs("input/soluciones.txt", ofstream::ate);
	unsigned rows, cols, num_pos;
	vector<unsigned> posiciones;

	inputs >> rows >> cols >> num_pos;

	Flow Juego(rows, cols);

	while (num_pos-->0) {
		long int pos;
		inputs >> pos;
		posiciones.push_back(pos);
	}

	for (auto x : posiciones) {
		cout << Juego.get_posicion(x).first << " " << Juego.get_posicion(x).second << " ";
	}
	cout << endl;
	outputs.close();
}