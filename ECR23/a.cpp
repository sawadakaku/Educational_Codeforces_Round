#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>

using namespace std;

void solve(vector<int> dest, vector<int> port) {
    bool flag = true;
    if (dest[0]%port[0] != 0 || dest[1]%port[1] != 0) {
        flag = false;
    } else if(abs((dest[0]/port[0])%2) != abs((dest[1]/port[1])%2)){
        flag = false;
    }
    if (flag) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    vector<int> orig(2);
    vector<int> dest(2);
    vector<int> port(2);

    gettimeofday(&start,NULL);

    std::cin >> orig[0] >> orig[1] >> dest[0] >> dest[1];
    dest[0] = dest[0] - orig[0];
    dest[1] = dest[1] - orig[1];
    std::cin >> port[0] >> port[1];

    solve(dest, port);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
