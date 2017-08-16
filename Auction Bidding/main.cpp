/*#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class puja {
public:
	string nombre;
	unsigned cantidad_pujada;
	unsigned precio_actual;
};

class apuesta
{
public:
	puja estado_apuesta;
	vector <puja> pujas;
	string pujador_maximo;
	unsigned maximo_pujas() {
		unsigned max = 0;
		for (auto puja : pujas)
			if (puja.cantidad_pujada > max)
				max = puja.cantidad_pujada;
		return max;
	}
};
void main()
{
	while (true)
	{
		apuesta apuestas;
		string input;
		getline(cin, input);
		cout << endl;
		input.push_back(',');
		
		unsigned valor_inicial = stoul(input.substr(0, input.find(",")));
		input = input.substr(input.find(",") + 1, input.size());
		apuestas.estado_apuesta = { "-",valor_inicial, valor_inicial };

		cout << apuestas.pujador_maximo << "," << apuestas.estado_apuesta.precio_actual << ",";

		while (input.size() > 1)
		{
			bool print = true;
			puja puja;
			puja.nombre = input.substr(0, input.find(","));
			input = input.substr(input.find(",") + 1, input.size());
			puja.cantidad_pujada = stoul(input.substr(0, input.find(",")));
			input = input.substr(input.find(",") + 1, input.size());

			if (puja.cantidad_pujada > apuestas.maximo_pujas()) {
				if (apuestas.maximo_pujas() != valor_inicial && apuestas.pujador_maximo != puja.nombre)
					apuestas.estado_apuesta.precio_actual = apuestas.maximo_pujas() + 1;
				else
					print = false;
				apuestas.pujador_maximo = puja.nombre;
			}
			else if (puja.cantidad_pujada != apuestas.maximo_pujas()) {
				if (puja.cantidad_pujada > apuestas.estado_apuesta.precio_actual)
					apuestas.estado_apuesta.precio_actual = puja.cantidad_pujada + 1;
			}
			else if (puja.cantidad_pujada == apuestas.maximo_pujas())
				apuestas.estado_apuesta.precio_actual = puja.cantidad_pujada;
			apuestas.pujas.push_back(puja);
			if(print)
				cout << apuestas.pujador_maximo << "," << apuestas.estado_apuesta.precio_actual << ",";
		}

	}
}*/


#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

#define LL long long
#define INFILE "a.in" 
#define OUTFILE ".out"
#define INF 10000000
ifstream fin(INFILE);
ofstream fout(OUTFILE);

char buf[512];

struct bid {
	string bidder;
	int actual_bid;
	int max_bid;
	int buy_now;
};

int main() {

	while (fin.getline(buf, 512)) {
		string str = buf;
		istringstream in(buf);

		bid b;
		in >> b.max_bid >> b.buy_now >> b.bidder >> b.actual_bid;
		if (b.buy_now == 0) b.buy_now = INF;
		fout << "-," << b.max_bid << "," << b.bidder << "," << b.max_bid;
		string bidder;
		int price;
		while (in >> bidder >> price) {
			if (price > b.actual_bid) {
				if (b.bidder == bidder) {
					b.actual_bid = price;
				}
				else {
					b.bidder = bidder;
					b.max_bid = b.actual_bid + 1;
					b.actual_bid = price;
					fout << "," << b.bidder << ",";
					if (b.max_bid >= b.buy_now) {
						fout << b.buy_now;
						break;
					}
					fout << b.max_bid;
				}
			}
			else if (price >= b.max_bid) {
				b.max_bid = (price + 1)< (b.actual_bid)?price+1:b.actual_bid;
				fout << "," << b.bidder << ",";
				if (b.max_bid >= b.buy_now) {
					fout << b.buy_now;
					break;
				}
				fout << b.max_bid;
			}
		}
		fout << endl;
	}

	return 0;
}