#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Flow {
public:
	Flow(unsigned rows, unsigned cols)
	{
		this->num_rows = rows;
		this->num_cols = cols;
		unsigned cont = 1;
	}
	pair<unsigned, unsigned> get_posicion(const unsigned index_casilla)
	{
		unsigned columna;
		unsigned fila;

		fila = (index_casilla%num_rows == 0) ? num_rows : index_casilla%num_rows;

		columna = ceil((double)index_casilla / (num_rows*num_cols)*num_cols);

		return pair<unsigned, unsigned>{fila, columna};
	}
private:
	unsigned num_rows;
	unsigned num_cols;
	vector<vector<unsigned>> tablero;
};