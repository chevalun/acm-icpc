#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	stringstream line;
	string temp;
	while(cin >> temp) {
		if (!temp.compare("<br>")) {
			cout << line.str() << endl;
			line.str("");
		}
		else if (!temp.compare("<hr>")) {
			if (line.str().length())
				cout << line.str() << endl << string(80 , '-') << endl;
			else
				cout << string(80 , '-') << endl;
			line.str("");
		} else {
			if ((line.str().compare(""))) {
				if ((line.str().length() + temp.length() + 1 <= 80))
					line << " " << temp;
				else {
					cout << line.str() << endl;
					line.str("");
					line << temp;
				}
			} else {
				line << temp;
			}
		}
	}
	cout << line.str() << endl;
}