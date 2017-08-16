#include <iostream>
#include <string>
using namespace std;

int main() {
	while (true) {
		long double longitud;
		long double perimetro = 0;
		long double relacion = 1;
		int iteraciones;
		cout << "Introduzca Longitud:" << endl;
		cin >> longitud;
		cout << "Introduzca Iteraciones:" << endl;
		cin >> iteraciones;

		for (int i = 0; i < iteraciones; i++)
		{
			relacion = relacion * 5 / 3;
			cout << relacion << endl;
		}
		cout.width(10);
		cout << "El perimetro es: " << to_string(longitud*relacion * 4) << endl;
	}
}