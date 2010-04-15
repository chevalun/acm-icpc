#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main()
{
	map<string, string> dict;
	string line, key, word;
	for(;;) {
		getline(cin, line);
		if(line == "")
			break;
		stringstream s(line);
		s >> word >> key;
		dict[key] = word;
	}
	while(cin >> key) {
		if (dict.count(key))
			cout << dict[key] << endl;
		else
			cout << "eh" << endl;
	}
	return 0;
}