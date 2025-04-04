#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int fifoPageReplacement(const vector<int>& pages, int capacity) {
    queue<int> cache;
    unordered_map<int, bool> pageTable;
    int faults = 0;

    for (int page : pages) {
        if (!pageTable[page]) {
            if (cache.size() == capacity) {
                pageTable.erase(cache.front());
                cache.pop();
            }
            cache.push(page);
            pageTable[page] = true;
            faults++;
        }
    }
    return faults;
}

int main() {
    vector<int> pages = {1, 2, 3, 2, 4, 1, 5};
    int capacity = 3;

    int faults = fifoPageReplacement(pages, capacity);
    cout << "FIFO Page Faults: " << faults << endl;

    return 0;
}
