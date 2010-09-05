/*
ID: chevalu2
TASK: fence8
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, space, mid, sum, rsum[2000], bag[100], r[2000];

bool dfsid(int now, int last)
{
	if (now <= 0)
		return true;
	if (space > sum - rsum[mid])
		return false;
	for(int i = last; i <= N; ++i)
		if(bag[i] >= r[now]) {
			bag[i] -= r[now];
			if(bag[i] < r[1])
				space += bag[i];
			if(r[now] == r[now-1]) {
				if(dfsid(now-1, i))
					return true;
			} else {
				if (dfsid(now-1, 1))
					return true;
			}
			if(bag[i] < r[1])
				space -= bag[i];
			bag[i] += r[now];
		}
	return false;	
}

int main()
{
	ifstream cin("fence8.in");
	ofstream cout("fence8.out");
	
	int b[51];
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> b[i];
		sum += b[i];
	}
	
	int R;
	cin >> R;
	for(int i = 1; i <= R; ++i)
		cin >> r[i];
	sort(b, b + N + 1);
	sort(r, r + R + 1);
	r[0] = b[0] = 0;
	for(int i = 1; i <= R; ++i)
		rsum[i] = rsum[i-1] + r[i];
	while(rsum[R] > sum)
		--R;
	
	int left = 0, right = R;
	mid = (left + right) / 2;
	while(left <= right) {
		for(int i = 1; i <= N; ++i)
			bag[i] = b[i];
		space = 0;	
		if(dfsid(mid, 1)) {
			left = mid + 1;
			mid = (left + right) / 2;
		} else {
			right = mid - 1;
			mid = (left + right)/2;
		}
	}
	cout << mid << endl;
	return 0;	
}