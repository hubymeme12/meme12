#ifndef ELECTRO_H
#define ELECTRO_H

#include <iostream>
#include <sstream>
using namespace std;

// Max electron per orbit
int number_set[] = {2, 8, 18, 32, 32, 32, 32};

// sequence of electron configuration and max electrons it can handle
string seq[] = {"1s", "2s", "2p", "3s", "3p", "4s", "3d", "4p", "5s", "4d", "5p", "6s", "4f", "5d", "6p", "7s", "5f", "6d", "7p", "6f", "7d", "7f"};
int maxim[] = {2, 2, 6, 2, 6, 2, 10, 6, 2, 10, 6, 2, 14, 10, 6, 2, 14, 10, 6, 14, 10, 14};

class electro {
	public:
		void econfig(int);
		int getPrincipal(int);
		void interpretQuantumNumber(int);
};

// e-config anomalies (switch)
// final electron configuration
// I chose to hardcode some part since, remaking the whole algorithm up there is kinda mess  -hubert
// e: number of electron in an atom
void electro::econfig(int e) {
	// Where final electron config will be stored
	string* config = new string;

	// for converting int to string
	ostringstream convert;

	// recursion of function for checking anomalies in normal electron configuration
	switch (e) {
		case 24:
			econfig(18); cout << "3d5 4s1" << endl;
			break;
		case 29:
			econfig(18); cout << "3d10 4s1" << endl;
			break;
		case 41:
			econfig(36); cout << "4d4 5s1" << endl;
			break;
		case 42:
			econfig(36); cout << "4d5 5s1" << endl;
			break;
		case 44:
			econfig(36); cout << "4d7 5s1" << endl;
			break;
		case 45:
			econfig(36); cout << "4d8 5s1" << endl;
			break;
		case 46:
			econfig(36); cout << "4d10" << endl;
			break;
		case 47:
			econfig(36); cout << "4d10 5s1" << endl;
			break;
		case 57:
			econfig(54); cout << "5d1 6s2" << endl;
			break;
		case 58:
			econfig(54); cout << "4f1 5d1 6s2" << endl;
			break;
		case 64:
			econfig(54); cout << "4f7 5d1 6s2" << endl;
			break;
		case 78:
			econfig(54); cout << "4f14 5d9 6s1" << endl;
			break;
		case 79:
			econfig(54); cout << "4f14 5d10 6s1" << endl;
			break;
		case 89:
			econfig(86); cout << "6d1 7s2" << endl;
			break;
		case 90:
			econfig(86); cout << "6d2 7s2" << endl;
			break;
		case 91:
			econfig(86); cout << "5f2 6d1 7s2" << endl;
			break;
		case 92:
			econfig(86); cout << "5f3 6d1 7s2" << endl;
			break;
		case 93:
			econfig(86); cout << "5f4 6d1 7s2" << endl;
			break;
		case 96:
			econfig(86); cout << "5f7 6d1 7s2" << endl;
			break;
		case 103:
			econfig(86); cout << "5f14 7s2 7p1" << endl;
			break;
		case 110:
			econfig(86); cout << "5f14 6d9 7s1" << endl;
			break;
		case 111:
			econfig(86); cout << "5f14 6d10 7s1" << endl;
			break;
		default:
			// normal method
			for (int i = 0; i < 22; i++) {
					e -= maxim[i];
					if (e > 0) {
						// meaning there are still electrons left to be placed
						//config += seq[i] + to_string(maxim[i]) + " ";		// only works on linux
						convert << maxim[i];
						(*config) += seq[i] + convert.str() + " ";

						// reset
						convert.str("");
					} else if (e == 0) {
						// exact electrons were placed (no remainder)
						// config += seq[i] + to_string(maxim[i]) + " ";	// linux onli
						convert << maxim[i];
						(*config) += seq[i] + convert.str() + " ";
						break;
					} else {
						// max number of electron is larger than current number of electron
						// ei = ef - max
						// for getting electrons left:
						// ef + max = ei
						// config += seq[i] + to_string(e + maxim[i]) + " ";	// linux onli
						convert << (e + maxim[i]);
						(*config) += seq[i] + convert.str() + " ";
						break;
					}
			}
			cout << (*config);
	}
}

// gets principal number of atom.
int electro::getPrincipal(int e) {
	for (int i = 0; i < 7; i++) {
		// meaning, number_set[i] is bigger than number of electrons.
		// e is e
		if (e/number_set[i] == 0 || e == number_set[i]) {
			return i + 1;
		} else {
			e = e - number_set[i];
		}
	}
}

void electro::interpretQuantumNumber(int e) {
	cout << "Principal quantum number(N) : " << e << endl;
	cout << "Possible orbitals : ";

	for (int i = 0; i < e; i++) {
		if (i == (e - 1)) {
			cout << i << endl;
		} else {
			cout << i << ", ";
		}
	}

	cout << "Magnetic quantum number (orbital orientation): ";
	for (int i = -(e - 1); i < e; i++) {
		if (i == (e - 1)) {
			cout << i << endl;
		} else {
			cout << i << ", ";
		}
	}

	cout << endl;
}
#endif
