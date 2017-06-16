#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>

using namespace std;

long long factal(long long n) {
    if (n==1 || n==0) {
        return 1;
    } else {
        return n * factal(n-1);
    }
}

void solve(int n, vector<int> a) {
    vector<int> b(3);
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < 3; i++) {
        b[i] = a.back();
        a.pop_back();
    }
    for (int i = 0; i < 3; i++) {
        a.push_back(b[i]);
    }
    long long c = count(b.begin(), b.end(), b[2]);
    long long d = count(a.begin(), a.end(), b[2]);
    long long ans = 1LL;
    for (int i = 0; i < c; i++) {
        ans *= d;
        d--;
    }
    ans /= factal(c);
    std::cout <<  ans << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int n;

    gettimeofday(&start,NULL);

    std::cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    solve(n, a);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
