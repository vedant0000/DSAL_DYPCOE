// Read the marks obtained by students of second year in an online examination of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm.

#include<iostream>
#include<vector>
using namespace std;

class Heap {
    public:
        vector<int> arr;
        int size = 0;

        Heap(vector<int> data) {
            arr = data;
            size = data.size();
        }
        
        int maxHeap() {
            buildMax();
            return arr[0];
        }

        int minHeap() {
            buildMin();
            return arr[0];
        }

        void buildMax() {
            for(int i = size / 2 - 1; i >= 0; i--) {
                maxHeapify(i);
            }
        }

        void buildMin() {
            for(int i = size / 2 - 1; i >= 0; i--) {
                minHeapify(i);
            }
        }

        void maxHeapify(int i) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if(left < size && arr[left] > arr[largest]) {
                largest = left;
            }

            if(right < size && arr[right] > arr[largest]) {
                largest = right;
            }

            if(largest != i) {
                swap(arr[largest], arr[i]);
                maxHeapify(largest);
            }
        }

        void minHeapify(int i) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if(left < size && arr[left] < arr[smallest]) {
                smallest = left;
            }

            if(right < size && arr[right] < arr[smallest]) {
                smallest = right;
            }

            if(smallest != i) {
                swap(arr[i], arr[smallest]);
                minHeapify(smallest);
            }
        }
};

int main() {
    int n;

    cout<<"Enter total number of students:";
    cin>>n;

    vector<int> data(n);

    for(int i = 0; i < n; i++) {
        cout<<"Enter marks for student "<<i+1<<": ";
        cin>>data[i];
    }

    Heap h(data);

    cout<<"Maximum marks scored by student is "<<h.maxHeap()<<endl;
    cout<<"Minimum marks scored by student is "<<h.minHeap()<<endl;

    return 0;
}