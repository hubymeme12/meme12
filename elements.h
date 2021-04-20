// This header file deals with searching atom details

// Format:
// element [name] [weight] [proton]
// [neutron] [radius] [electronegativity]
// [isotope] [melting point] [boiling point]
#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <iostream>
#include <sstream>
#include "electro.h"
using namespace std;

// used too much space in stack on this part
// since it'll be difficult (allocation of multidimensional array in heap), we instead allocate this
// in stack (even if stack is limited only)
// we can actually store these in txt form and parse it. (but, using fstream library)
const string elements[][10] = {
	{"Ac", "Actinium", "227", "89", "138", "195", "1.1", "36", "1050", "3200"},
	{"Al", "Aluminum", "26.98", "13", "14", "125", "1.61", "27", "660.32", "2519"},
	{"Am", "Americium", "243", "95", "148", "175", "1.3", "14", "1,176", "2011"},
	{"Sb", "Antimony", "121.76", "51", "71", "145", "2.05", "2", "630.63", "1587"},
	{"Ar", "Argon", "39.948", "18", "22", "71", "N/A", "3", "-189", "-186"},
	{"As", "Arsenic", "74.922", "33", "42", "115", "2.18", "33", "816.9", "614"},
	{"At", "Astatine", "210", "85", "125", "N/A", "2.2", "39", "302", "350"},
	{"Ba", "Barium", "137.33", "56", "81", "215", "0.89", "6", "730", "1870"},
	{"Bk", "Berkelium", "247", "97", "150", "N/A", "1.3", "14", "1,050", "N/A"},
	{"Be", "Beryllium", "9.0122", "4", "5", "105", "1.57", "12", "1287", "2470"},
	{"Bi", "Bismuth", "208.98", "83", "126", "160", "2.02", "41", "271.3", "1564"},
	{"Bh", "Bohrium", "270","107", "155", "N/A", "N/A", "10", "N/A", "N/A"},
	{"B", "Boron", "10,81", "5", "6", "85", "2.04", "11", "2075", "4000"},
	{"Br", "Bromine", "79.904", "35", "45", "115", "2.96", "2", "-7350", "58.9"},
	{"Cd", "Cadmium", "112.41", "48", "64", "155", "1.69", "8", "321.07", "766.9"},
	{"Ca", "Calcium", "40.078", "20", "20", "180", "1.0", "26", "841.9", "1484"},
	{"Cf", "Californium", "251", "98", "153", "N/A", "1.3", "20", "899.9", "N/A"},
	{"C", "Carbon", "12.011", "6", "6", "70", "2.55", "3", "3550", "4027"},
	{"Ce", "Cerium", "140.12", "58", "82", "185", "1.12", "4", "797.9", "3360"},
	{"Cs", "Caesium", "132.91", "55", "78", "260", "0,79", "40", "28.440", "671"},
	{"Cl", "Chlorine", "35.35", "17", "18", "100", "3.16", "2", "-101.5", "-34.040"},
	{"Cr", "Chromium", "51.996", "24", "28", "140", "1.66", "4", "1907", "2671"},
	{"Co", "Cobalt", "58.933", "27", "32", "135", "1.88", "1", "1495", "2900"},
	{"Cn", "Copernicium", "285", "112", "173", "N/A", "N/A", "5", "N/A", "N/A"},
	{"Cu", "Copper", "63.546", "29", "35", "135", "1.90", "2", "1084.62", "2562"},
	{"Cm", "Curium", "247", "96", "151", "N/A", "1.3", "14", "1345", "3110"},
	{"Ds", "Darmstadtium", "281", "110", "151", "N/A", "N/A", "9", "N/A", "N/A"},
	{"Db", "Dubnium", "268","105","163", "N/A", "N/A", "12", "N/A", "N/A"},
	{"Dy", "Dysprosium", "162.50","66", "97", "175", "1.22", "7", "1412", "2567"},
	{"Es", "Einsteinium", "252", "99", "153", "N/A", "1.3", "16", "859.9", "N/A"},
	{"Er", "Erbium", "167.26", "68", "99", "175", "1.24", "6", "1497", "2868"},
	{"Eu", "Europium", "151.96", "63", "89", "185", "N/A", "2", "821.9", "1500"},
	{"Fm", "Fermium", "257", "100", "157", "N/A", "1.3", "21", "1500", "N/A"},
	{"Fl", "Flerovium", "289", "114", "175", "N/A", "N/A", "7", "N/A", "N/A"},
	{"F", "Fluorine", "18.998", "9", "10", "50", "3.98", "17", "-220", "-1881.1"},
	{"Fr", "Francium", "223", "87", "136", "N/A", "0.7", "34", "20,9", "650"},
	{"Gd", "Gadolinium", "157.25", "64", "93", "180", "1.20", "8", "1313", "3250"},
	{"Ga", "Gallium", "69.723", "31", "39", "130", "1.81", "2", "29.760", "2204"},
	{"Ge", "Germanium", "72.630", "32", "41", "125", "2.01", "5", "938.25", "2820"},
    {"Au", "Gold", "196.97", "79", "118", "135", "2.54", "41", "1,064.18", "2,856"},
    {"Hf", "Hafnium", "178.49", "72", "106", "155", "1.3", "5", "2,233", "4,603"},
    {"Hs", "Hassium", "270", "108", "157", "N/A", "N/A", "15", "N/A", "N/A"},
    {"He", "Helium", "4", "2", "2", "31", "N/A", "2", "N/A", "-269"},
    {"Ho", "Holmium", "164.93", "67", "98", "175", "1.23", "1", "1,474", "2,700"},
    {"H", "Hydrogen", "1", "1", "0", "25", "2.20", "3", "-259.1", "-252.9"},
    {"In", "Indium", "114.82" "49", "66", "155", "1.78", "2", "156.60", "2,072"},
    {"I", "Iodine", "126.90", "53", "74", "140", "2.66", "37", "113.70", "184.3"},
    {"Ir", "Iridium", "192.22", "77", "115", "135", "2.20", "2", "2,466", "4,428"},
    {"Fe", "Iron", "55.85", "26", "30", "140", "1.83", "4", "1,538", "2,862"},
    {"Kr", "Krypton", "83.80", "36", "48", "N/A", "3.0", "6", "-157.36", "-153.22"},
    {"La", "Lanthanum", "138.91", "57", "82", "195", "1.10", "38", "919.9", "3,464"},
    {"Lr", "Lawrencium", "266", "103", "159", "N/A", "N/A", "13", "1,600", "N/A"},
    {"Pb", "Lead", "207.2", "82", "125", "180", "2.33", "4", "327.46", "1,749"},
    {"Li", "Lithium", "6.94", "3", "2", "145", "0.98", "2", "180.54", "1,342"},
    {"Lv", "Livermorium", "293", "116", "177", "N/A", "N/A", "4", "N/A", "N/A"},
    {"Lu", "Lutetium", "174.97", "71", "104", "175", "1.27", "2", "1,663", "3,402"},
    {"Mg", "Magnesium", "24.31", "12", "12", "150", "1.31", "3", "650", "1,090"},
    {"Mn", "Manganese", "54.94", "25", "30", "140", "1.55", "1", "1,246", "2,061"},
    {"Mt", "Meitnerium", "278", "109", "157", "N/A", "N/A", "8", "N/A", "N/A"},
    {"Md", "Mendelevium", "258", "101", "157", "N/A", "1.3", "17", "830", "N/A"},
    {"Hg", "Mercury", "200.59","80", "121", "150", "2.0", "7", "-38.83", "356.73"},
    {"Mo", "Molybdenum", "95.95", "42", "54", "145", "2.16", "33", "2,623", "4,639"},
    {"Mc", "Moscovium", "290", "115", "175", "N/A", "N/A", "4", "N/A", "N/A"},
    {"Nd", "Neodymium", "144.24", "60", "84", "185", "1.14", "5", "1,021", "3,100"},
    {"Ne", "Neon", "20.18", "10", "10", "N/A", "N/A", "3", "-248.6", "-246.1"},
    {"Np", "Neptunium", "237", "93", "144", "175", "1.36", "25", "644", "4,000"},
    {"Ni", "Nickel", "58.69", "28", "31", "135", "1.91", "5", "1,455", "2,913"},
    {"Nh", "Nihonium", "286", "113", "173", "N/A", "N/A", "6", "N/A", "N/A"},
    {"Nb", "Niobium", "92.91", "41", "52", "145", "1.6", "28", "2,477", "4,744"},
    {"N", "Nitrogen", "14.01", "7", "7", "65", "3.04", "2", "-210.1", "-195.8"},
    {"No", "Nobelium", "259", "102", "157", "N/A", "1.3", "12", "830", "N/A"},
    {"Og", "Oganesson", "294", "118", "176", "N/A", "N/A", "1", "N/A", "N/A"},
    {"Os", "Osmium", "190.23", "76", "114", "130", "2.2", "7", "3,033", "5,012"},
    {"O", "Oxygen", "16", "8", "8", "60", "3.44", "3", "-218", "-183"},
    {"Pd", "Palladium", "106.42", "46", "60", "140", "2.20", "6", "1,544.90", "2,963"},
    {"P", "Phosphorus", "30.97", "15", "16", "100", "2.19", "23", "44.15", "280.5"},
    {"Pt", "Platinum", "195.08", "78", "117", "135", "2.28", "5", "1,768.3", "3,825"},
    {"Pu", "Plutonium", "244", "94", "150", "175", "1.28", "5", "640", "3,230"},
    {"Po", "Polonium", "209", "84", "125", "190", "2.0", "33", "255", "961.9"},
    {"K", "Potassium", "39.10", "19", "20", "220", "0.82", "17", "63.38", "758.9"},
    {"Pr", "Praseodymium", "140.91", "59", "82", "185", "1.13", "1", "930.9", "3,290"},
    {"Pm", "Promethium", "145", "61", "84", "185", "N/A", "38", "1,100", "3,000"},
    {"Pa", "Protactinium", "231.03", "91", "148", "180", "1.5", "3", "1,572", "4,000"},
    {"Ra", "Radium", "226", "88", "138", "215", "0.9", "25", "700", "1,737"},
    {"Rn", "Radon", "222", "86", "136", "N/A", "N/A", "39", "-71.2", "-61.85"},
    {"Re", "Rhenium", "186.21", "75", "111", "135", "1.9", "1", "3,186", "5,596"},
    {"Rh", "Rhodium", "102.91", "45", "58", "135", "2.28", "1", "1,964", "3,695"},
    {"Rg", "Roentgenium", "282", "111", "161", "N/A", "N/A", "7", "N/A", "N/A"},
    {"Rb", "Rubidium", "85.47", "37", "48", "235", "0.82", "2", "39.31", "688"},
    {"Ru", "Ruthenium", "101.07", "44", "57", "130", "2.2", "7", "2,334", "4,150"},
    {"Rf", "Rutherfordium", "267", "104", "157", "N/A", "N/A", "12", "N/A", "N/A"},
    {"Sm", "Samarium", "150.36", "62", "88", "185", "1.17", "7", "1,072", "1,803"},
    {"Sc", "Scandium", "44.96", "21", "24", "160", "1.36", "1", "1,541", "2,830"},
    {"Sg", "Seaborgium", "269", "106", "157", "N/A", "N/A", "No stable isotope", "N/A", "N/A"},
    {"Se", "Selenium", "78.97", "34", "45", "115", "2.55", "6", "221", "685"},
    {"Si", "Silicon", "28.09", "14", "14", "110", "1.90", "3", "1,414", "2,900"},
    {"Ag", "Silver", "107.87", "47", "61", "160", "1.93", "2", "961.78", "2,162"},
    {"Na", "Sodium", "22.99", "11", "12", "180", "0.93", "1", "97.72", "882.9"},
    {"Sr", "Strontium", "87.62", "38", "50", "200", "0 95", "4", "776.9", "1,382"},
    {"S", "Sulfur", "32.06", "16", "16", "100", "2.58", "4", "115.21", "444.72"},
    {"Ta", "Tantalum", "180.95", "73", "108", "145", "1.5", "2", "3,017", "5,458"},
    {"Tc", "Technetium", "98", "43", "55", "135", "1.9", "22", "2,157", "4,265"},
    {"Te", "Tellurium", "127.60", "52", "76", "140", "2.1", "39", "449.51", "987.9"},
    {"Ts", "Tennessine", "294", "117", "177", "N/A", "N/A", "2", "N/A", "N/A"},
    {"Tb", "Terbium", "158.93" , "65", "94", "175", "N/A", "1", "1,356", "3,230"},
    {"Tl", "Thallium", "204.38", "81", "123", "190", "1.62", "41", "304", "1,473"},
    {"Th", "Thorium", "232.04", "90", "142", "180", "1.3", "7", "1,750", "4,820"},
    {"Tm", "Thulium", "168.93", "69", "100", "175", "1.25", "32", "1,545", "1,950"},
    {"Sn", "Tin", "118.71", "50", "69", "145", "1.96", "10", "231.93", "2,602"},
    {"Ti", "Titanium", "47.87", "22", "26", "140", "1.54", "5", "1,668", "3,287"},
    {"W", "Tungsten", "183.84", "74", "110", "135", "2.36", "5", "3,422", "5,555"},
    {"U", "Uranium", "238.03", "92", "146", "175", "1.38", "3", "1,135", "3,900"},
    {"V", "Vanadium", "50.94", "23", "28", "135", "1.63", "2", "1,910", "3,407"},
    {"Xe", "Xenon", "131.29", "54", "77", "N/A", "2.6", "9", "-111.8", "-108.0"},
    {"Yb", "Ytterbium", "173.05", "70", "103", "175", "N/A", "7", "818.9", "1,196"},
    {"Y", "Yttrium", "88.91", "39", "50", "180", "1.22", "25", "1,526", "3,345"},
    {"Zn", "Zinc", "65.38", "30", "35", "135", "1.65", "5", "419.53", "906.9"},
    {"Zr", "Zirconium", "91.22", "40", "51", "155", "1.33", "4", "1,855", "4,409"}
};

// uflag is the flag that determines the current sort of the arrays in elements (initially sorted by name).
char uflag = 'n';
int target = 1;

// check if array is needed to be sorted
void set_flag(char flag) {
	// already the flag
	if (flag != uflag) {
		uflag = flag;
		switch (flag) {
			case 'n':
				target = 1;
				break;
			case 'a':
				target = 3;
				break;
			case 's':
				target = 0;
				break;
		}
	}
}

// interprets the validity of searched index
void interpret_index(int x) {
	string box;

	if (x < 0) {
		cout << "[!] The element you searched isn\'t found" << endl;
	} else {
		system("cls");
//		system("clear");
		cout << "=================================================================================================" << endl;
		// design setup
		if (elements[x][0].size() == 2) {
			cout << " ------------ \n|            |\n|     ";
			cout << elements[x][0];
			cout << "     |\n|            |\n ------------ ";
		} else {
			cout << " ---------- \n|          |\n|    ";
			cout << elements[x][0];
			cout << "     |\n|          |\n ---------- ";
		} cout << endl;

		// prints details about the specific atom
		cout << "Name : " << elements[x][1] << endl;
		cout << "Mass : " << elements[x][2] << endl;
		cout << "Atomic number : " << elements[x][3] << endl;
		cout << "Neutron number : " << elements[x][4] << endl;
		cout << "Atomic radius : " << elements[x][5] << endl;
		cout << "Electronegativity : " << elements[x][6] << endl;
		cout << "Isotope : " << elements[x][7] << endl;
		cout << "Melting point (Celsius) : " << elements[x][8] << endl;
		cout << "Boiling point (Celsius) : " << elements[x][9] << endl;

		// some conversion
		stringstream stoi;
		int enumb;

		stoi << elements[x][3];		// store to stringstream
		stoi >> enumb;			// store to variable

		cout << "Electron configuration : "; econfig(enumb); cout << endl << endl;

		// quantum numbers
		int pq = getPrincipal(enumb);
		interpretQuantumNumber(pq);

		cout << "=================================================================================================" << endl;
	}
}

// An algorithm that searches for element in index above
int search(string elem) {
	// use linear search
	for (int i = 0; i < 118; i++) {
		if (elements[i][target] == elem) {
			return i;
		}
	}

	return -1;
}

// convert string (for searching purposes) into searchable format for name
string search_filterN(string out) {
	string ret;
	char inp[30] = {0};

	cout << out;
	cin >> inp;

	// check if it's within the range of alphabet
	if (!(((inp[0] <= 'z') && (inp[0] >= 'a')) || (inp[0] <= 'Z') && (inp[0] >= 'A'))) {
		cout << "[-] Error : invalid input detected!" << endl;
		// get value again
		return search_filterN(out);
	}

	// first letter must be in upper case
	if ((inp[0] <= 'z') && (inp[0] >= 'a')) {
		// lower-case
		inp[0] = inp[0] - 32;
	}
	ret += inp[0];

	for (int i = 1; i < 30; i++) {
		if (inp[i] == 0) {
			break;
		} else {
			// must be on lower-case
			if ((inp[i] <= 'Z') && (inp[i] >= 'A')) {
				// convert to lowercase
				inp[i] = inp[i] + 32;
			}
			ret += inp[i];
		}
	}
	return ret;
}

string search_filterA(string out) {
	string store;

	cout << out;
	cin >> store;

	// input is a number
	if ((store[0] <= '9') && (store[0] >= '1')) {
		return store;
	} else if (store == "exit") {
		return "exit";
	} else {
		cout << "[-] Invalid input detected! Try again." << endl;
		return search_filterA(out);
	}
}
#endif
