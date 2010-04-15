#include <stack>
#include <iostream>
#include <string>	
using namespace std;

int main()
{
	int N;
	cin >> N;
	while(N--) {
		string temp, curr = "http://www.acm.org/";
		stack<string> forward, backward;
		for (;;) {
			cin >> temp;
			if (!temp.compare("VISIT")) {
				backward.push(curr);
				cin >> temp;
				cout << temp << endl;
				curr = temp;
				while(!forward.empty())
					forward.pop();
			} 
			else if (!temp.compare("BACK")) {
				if(backward.empty()) {
					cout << "Ignored\n";
				} else {
					forward.push(curr);
					curr = backward.top();
					backward.pop();
					cout << curr << endl;
				}
			}
			else if (!temp.compare("FORWARD")) {
				if (forward.empty()) 
					cout << "Ignored\n";
				else {
					backward.push(curr);
					curr = forward.top();
					forward.pop();
					cout << curr << endl;
				}
			}
			else if (!temp.compare("QUIT")) {
				break;
			}
		}
		if (N)
			cout << endl;
	}
	return 0;
}