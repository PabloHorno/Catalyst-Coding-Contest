#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
	while (true) {
		vector<pair<unsigned, unsigned>> tiradas;
		string input;
		cout << "Input:" << endl;
		getline(cin, input);

		unsigned numero_rondas = stoul(input.substr(0, input.find(":")));

		input = input.substr(input.find(":") + 1, input.size());

		for (int i = 0; i < numero_rondas+1; i++)
		{
			pair<unsigned, unsigned> tirada;

			tirada.first = stoul(input.substr(0, input.find(",")));
			input = input.substr(input.find(",") + 1, input.size());
			if (tirada.first != 10) {
				tirada.second = stoul(input.substr(0, input.find(",")));
				input = input.substr(input.find(",") + 1, input.size());
			}
			else
				tirada.second = 0;
			tiradas.push_back(tirada);
		}

		unsigned resultado = 0;
		for (int i = 0; i < numero_rondas; i++)
		{
			if (tiradas.at(i).first == 10) { //Strike
				resultado += tiradas.at(i).first + (tiradas.at(i + 1).first == 10 ? tiradas.at(i + 1).first + tiradas.at(i + 2).first : tiradas.at(i + 1).first + tiradas.at(i + 1).second);
			}
			else if ((tiradas.at(i).first + tiradas.at(i).second) == 10)//Spares
				resultado += tiradas.at(i).first + tiradas.at(i).second + tiradas.at(i + 1).first;
			else
				resultado += tiradas.at(i).first + tiradas.at(i).second;
			cout << resultado << (numero_rondas-1 != i ?",":"");
		}
		cout << endl;
	}
}