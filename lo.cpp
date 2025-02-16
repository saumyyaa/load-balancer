#include <bits/stdc++.h>
using namespace std;

class LoadBalancer {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

public:
    LoadBalancer(int servers) {
        for (int i = 1; i <= servers; i++)
            minHeap.push({0, i});
    }

    void addRequest() {
        auto [load, server] = minHeap.top();
        minHeap.pop();
        load++;
        minHeap.push({load, server});
        cout << "Request assigned to Server " << server << ", New Load: " << load << endl;
    }
};

int main() {
    LoadBalancer lb(3);
    lb.addRequest();
    lb.addRequest();
    lb.addRequest();
    lb.addRequest();
    return 0;
}
