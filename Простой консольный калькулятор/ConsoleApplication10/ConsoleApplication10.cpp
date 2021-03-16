#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>
#include <iomanip>

using namespace std;

class Math;
class History;
int vibor;

class History {
	vector<string> H;
	string s;
	int z = 0;
public:
	void setHistory(int a, string b, int c, int g) {
		s = to_string(a);
		s += b;
		s += to_string(c);
		s += {" = "};
		s += to_string(g);
		H.push_back(s);
		z++;
	}
	void getHistory() {
		system("cls");
		cout << "History" << endl;
		for (int y = 0; y < H.size(); y++)
		{
			for (int x = 0; x < H[y].length(); x++)
			{
				cout << H[y][x];
			}
			cout << endl;
		}
	}
	bool daHistory() {
		if (z == 0) {
			return 0;
		}
		else return 1;
	}
};

History hist; 

class Math {
	int deustvie;
public:
	int getMath(int a, int b) {
		if (deustvie == 1) {
			hist.setHistory(a, " + ", b, a + b);
			return a + b;
		}
		if (deustvie == 2) {
			hist.setHistory(a, " - ", b, a - b);
			return a - b;
		}
		if (deustvie == 3) {
			hist.setHistory(a, " * ", b, a * b);
			return a * b;
		}
		if (deustvie == 4) {
			hist.setHistory(a, " / ", b, a / b);
			return a / b;
		}
	}
	void getMath1(int c) {
		int a, b;
		do {
			system("cls");
			cout << "1. +" << endl << "2. -" << endl << "3. *" << endl << "4. /" << endl << "5. Back" << endl;
			cin >> deustvie;
			if (deustvie > 0 && deustvie < 5) {
				system("cls");
				cout << "vvedi chisla" << endl;
				cin >> a >> b;
				cout << getMath(a, b) << endl;
				break;
			}
			if (deustvie == 5) {
				break;
			}
			else {
				system("cls");
				cout << "Net takou fynkcii!" << endl << "poprobyu ehse raz, ya yveren y tebya vse polychitsya" << endl;
				system("pause");
			}
		} while (0 < deustvie < 5);
	}
};

int Vibor() {
	int c;
	do{
		system("pause");
		system("cls");
		cout << "0. Exit" << endl << "1. Math" << endl << "2. History" << endl;
		cin >> c;
		if (c == 0) {
			exit(0);
		}
		if (c == 1) {
			Math math;
			math.getMath1(c);
		}
		if (c == 2) {
			if (hist.daHistory() == 0) {
				system("cls");
				cout << "istoryya poka pystaya" << endl;
			}
			else {
				hist.getHistory();
			}
		}
		if (c > 2) {
			system("cls");
			cout << "Net takou cifri!" << endl;
		}
	}while(c > 0);
}

int main() {
	Vibor();
	
	return 0;
}