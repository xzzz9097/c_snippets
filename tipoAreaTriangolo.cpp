/*
	Dati in input 3 numeri, verifico se possono essere i lati di un
	triangolo e ne calcolo l'area.
*/

#include <iostream>
#include <cmath>
using namespace std;

const int TIPO_SCALENO = 0;
const int TIPO_ISOSCELE = 1;
const int TIPO_EQUILATERO = 2;

int main() {
	// Dichiarazione variabili
	int mA, mB, mC;
	bool mTriangolo;
	int mTipo;
	float mArea;

	// Input
	cout << "Inserisci tre numeri: " << endl;
	cin >> mA >> mB >> mC;

	// Verifiche
	if (mA < mB + mC && mB < mA + mC && mC < mA + mB) {
		// Esiste il triangolo
		mTriangolo = true;
		if (mA == mB | mA == mC | mB == mC) {
			// E' isoscele
			mTipo = TIPO_ISOSCELE;
			if (mA == mB == mC) {
				// E' equilatero
				mTipo = TIPO_EQUILATERO;
				mArea = mA * sqrt(pow(mA, 2.0) - pow(mA/2, 2.0)) / 2;
			} else if (mA == mB) {
				mArea = mC * sqrt(pow(mA, 2.0) - pow(mC/2, 2.0)) / 2;
			} else if (mA == mC) {
				mArea = mB * sqrt(pow(mA, 2.0) - pow(mB/2, 2.0)) / 2;
			} else if (mB == mC) {
				mArea = mA * sqrt(pow(mB, 2.0) - pow(mA/2, 2.0)) / 2;
			}
		} else {
			// E' scaleno
			mTipo = TIPO_SCALENO;
		}
	} else {
		// Non esiste il triangolo
		mTriangolo = false;
	}

	// Output
	if (mTriangolo) {
		// Tipo
		cout << "Il triangolo e' ";
		if (mTipo == TIPO_SCALENO) {
			cout << "scaleno." << endl;
		} else if (mTipo == TIPO_ISOSCELE) {
			cout << "isoscele." << endl;
		} else if (mTipo == TIPO_EQUILATERO) {
			cout << "equilatero." << endl;
		}

		// Area
		if (mTipo == TIPO_ISOSCELE | mTipo == TIPO_EQUILATERO) {
			cout << "L'area e' " << mArea << endl;
		}
	} else {
		cout << "Non esiste un triangolo con questi lati" << endl;;
	}
}