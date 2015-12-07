#include <iostream>

using namespace std;

class Cerchio {
	float raggio;
public:
	void setRaggio(float raggio) {
		this -> raggio = raggio;
	}

	Cerchio(float raggio) {
		setRaggio(raggio);
	}

	float calcolaCirconferenza() {
		return 2 * 3.14 * raggio;
	}

	float calcolaArea() {
		return 3.14 * raggio * raggio;
	}
};

class Cilindro : public Cerchio {
	float altezza;
public:
	void setAltezza(float altezza) {
		this -> altezza = altezza;
	}

	Cilindro(float raggio, float altezza) : Cerchio(raggio) {
		setAltezza(altezza);
	}

	float calcolaVolume() {
		return calcolaArea() * altezza;
	}
};

int main() {
	Cilindro mCilindro(3.0, 10.0);

	cout << "Volume: " << mCilindro.calcolaVolume() << endl;
	cout << "Circonferenza di base: " << mCilindro.calcolaCirconferenza() << endl;
	cout << "Area di base: " << mCilindro.calcolaArea() << endl;
}
