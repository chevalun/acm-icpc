#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while(N--) {
		int M;
		cin >> M;
		string word;
		while(M) {
			cin >> word;
			for (string::reverse_iterator rit=word.rbegin() ; rit < word.rend(); rit++)
				cout << *rit;
			if(getchar() == '\n') {
				cout << endl;
				--M;
			}
			else
				cout << " ";
		}
		if (N)
			cout << endl;
	}
	return 0;
}