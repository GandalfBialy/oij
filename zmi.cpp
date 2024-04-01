#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
	const int A = 26;  // number of small-case English letters
	
	string s;
	cin >> s;
	
	int n = s.length();
	auto psum = vector<vector<int>> (A, vector<int> (n, 0));
	auto firstCharIdx = vector<int>(A, n + 1);
	auto lastCharIdx  = vector<int>(A, -1);

	psum[s[0] - 'a'][0] = 1;
	firstCharIdx[s[0] - 'a'] = 0;

	for(int i=1;i<n;i++){
		short ch = s[i] - 'a';
		lastCharIdx[ch] = i;
		if(firstCharIdx[ch] == n+1)
			firstCharIdx[ch] = i;

		for(int c=0;c<A;c++){
			psum[c][i] = psum[c][i-1] + (s[i] == char(c + 'a'));
		}
	}
	long long res1=0, res2 = 0;

	// solve first part
	for(int i=1;i<n-1;i++){
		int middleChar = s[i] - 'a';
		long long L = i - psum[middleChar][i-1];
		long long R = n - psum[middleChar][n-1] - L; // -1 for s[i]
		res1 += L * R;
	}

	// solve second part
	for(int x=0;x<A;x++){
		for(int y=0;y<A;y++){
			for(int z=0;z<A;z++){
				if(! (x != y && y != z) ) continue;
				int idxX = firstCharIdx[x]; // first occurence of 'x'
				int idxZ = lastCharIdx[z];  // last occurence of 'z'
				if(idxX != n + 1 && idxZ != -1
					&& idxX + 1 < idxZ && psum[y][idxZ-1] - psum[y][idxX] > 0){
					// last condition means that there exist at least one letter 'y'
					// between first 'x' and last 'z'
					++res2;
				}
			}
		}
	}
	cout << res1 << ' '<< res2 << '\n';
	
    return 0;
}
