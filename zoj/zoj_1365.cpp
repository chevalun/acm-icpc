#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string temp;
	int rst = 0, m;
	char x;
	
	for(;;) {
		cin >> temp;
		if(temp == "#")
			break;
		else if(temp == "0") {
			cout << rst << endl;
			rst = 0;
		} else {
			cin >> temp >> m >> x;
			if(x == 'F')
				rst += 2*m;
			else if (x == 'B')
				rst += (m + ceil(m/2.0));
			else if (m < 500)
				rst += 500;
			else
				rst += m;
		}	
	}
	return 0;
}