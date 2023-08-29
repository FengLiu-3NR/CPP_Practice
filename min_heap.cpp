#include <iostream>
#include <cstdlib>>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class heap {
    int size;
    int data[10000];
    bool isHeap(int i) {
        if(i*2+1<size) {
                if(data[i] > data[i*2+1]) return false;
                if(!isHeap(i*2+1)) return false;
        }
        if(i*2+2<size) {
                if(data[i] > data[i*2+2]) return false;
                if(!isHeap(i*2+2)) return false;
        }
        return true;
    }
    void heapify(int i) {
        int ni = i;
        if(i*2+1 < size && data[ni] > data[i*2+1]) ni = i*2+1;
        if(i*2+2 < size && data[ni] > data[i*2+2]) ni = i*2+2;
        if(ni != i) {
            int tmp = data[i];
            data[i] = data[ni];
            data[ni] = tmp;
            heapify(ni);
        } else {
            ni = (i+1)/2 - 1;
            for(; i>0; i = ni, ni = (i+1)/2 - 1) {
                if(data[i] < data[ni]) {
                    int tmp = data[i];
                    data[i] = data[ni];
                    data[ni] = tmp;
                } else {
                    break;
                }
            }
        }
    }
public:
    heap():size(0){}
    bool isHeap() {
        return isHeap(0);
    }
    void push(int x) {
        cout << "push " << x << endl;
        data[size] = x;
        size++;
        heapify(size-1);
    }
    void remove(int i) {
        cout << "remove at " << i << endl;
        if(i < size) {
            size--;
            data[i] = data[size];
            heapify(i);
        }
    }
    int ssize() {
        return size;
    }
    void print() {
        for(int i = 0; i < size; i++) {
            cout << data[i] << ' ';
        }
        cout << endl;
    }
};


int main()
{
    srand(time(nullptr));
    heap h;
    for(int i = 0; i < 1000; i++) {
        h.push(rand()%100);
        h.print();
        if(!h.isHeap()) {
            cout << "error after push" << endl;
            break;
        }
        if(rand()%100 < 95) {
            h.remove(rand()%h.ssize());
            h.print();
            if(!h.isHeap()) {
                cout << "error after push" << endl;
                break;
            }
        }
    }
    h.print();

    return 0;
}
