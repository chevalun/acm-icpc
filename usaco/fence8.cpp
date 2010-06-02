/*
ID: chevalu2
LANG: C++
TASK: fence8
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream stdin("fence8.in");
	ofstream stdout("fence8.out");
	
	int N, sum, b[51];
	stdin >> N;
	for(int i = 0; i < N; ++i) {
		stdin >> b[i];
		sum += b[i];
	}
	
	int R, r[1024], rsum[1024];
	stdin >> R;
	for(int i = 0; i < R; ++i)
		stdin >> r[i];
	rsum[0] = r[0];	
	for(int i = 1; i < R; ++i)
		rsum[i] = rsum[i-1] + r[i];
	sort(b, b + N);
	sort(r, r + R);	
	
	while(rsum[R] > sum)
		--R;
	return 0;	
}