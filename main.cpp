#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
#include <fstream>
#include <sstream>

using namespace std;

// MergeSort function declarations
void mergeSort(vector<string>& a, vector<string>& tmp, int left, int right);
void mergeSortedLists(vector<string>& a, vector<string>& tmp, int leftPos, int rightPos, int rightEnd);

// BubbleSort function declaration
void swap (string *a, string *b);
void bubbleSort(string *a, int n);

int main() {
    /* open input and ouput files here */
    ifstream inFS; // input file stream
    string filename = "ramenBubble.txt";
    ofstream oFS;
    oFS.open(filename);
    ofstream oFS2;
    oFS2.open("ramenMerge.txt");

    // get input: vector length which is the total number of entries in your data set
    int length;


    inFS.open(filename);
    if (!inFS.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return -1;
    }

    string line;
    vector<string> v(length); // vector to be sorted
    vector<string> t(length); // temporary workspace
    getline(inFS, line);
    while (getline(inFS, line)) {
        // turn line into input string stream
        istringstream ramenRatings(line);
        string substring;
        // read Review#
        getline(ramenRatings, substring, ',');
        string rNum = substring;
        v.push_back(rNum);
        // read Brand
        getline(ramenRatings, substring, ',');
        string brand = substring;
        v.push_back(brand);
        // read variety
        getline(ramenRatings, substring, ',');
        string variety = substring;
        v.push_back(variety);
        // read style
        getline(ramenRatings, substring, ',');
        string style = substring;
        v.push_back(style);
        // read country
        getline(ramenRatings, substring, ',');
        string country = substring;
        v.push_back(country);
        // read stars
        getline(ramenRatings, substring, ',');
        string stars = substring;
        v.push_back(stars);
        // read top10
        getline(ramenRatings, substring, ',');
        string top10 = substring;
        v.push_back(top10);
    }
    inFS.close(); // because we care

    // define a string pointer dynamically allocate an array of strings
    string str[length];


    // populate and print input
    cout << "Unsorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        /* read from file here */
        oFS << v.at(i) << '\t';
        oFS2 << v.at(i) << '\t';
    }
    cout << endl;

    // copy the list of strings from vector to array
    /* your code here */

    clock_t start_mergeSort = clock();
    // sort vector using mergeSort
    mergeSort(v,t, 0, v.size() - 1);
    clock_t end_mergeSort = clock();

    // check output, make sure vector is sorted after mergeSort
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    // check output, make sure array is sorted after bubbleSort
    /* your code here */

    clock_t start_bubbleSort = clock();
    // sort array using bubbleSort
    /* your code here */
    clock_t end_bubbleSort = clock();


    // print sorted vector after mergeSort into "merge.txt"
    cout << "Sorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        /* replace this */
        oFS << v.at(i) << '\t';
        oFS2 << v.at(i) << '\t';
    }
    cout << endl;

    // print sorted array after bubbleSort into file "bubble.txt"


    // print elapsed time for mergeSort and bubbleSort
    double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;

    cout << elapsed_mergeSort << " " << elapsed_bubbleSort << endl;

    return 0;
}

void mergeSortedLists(vector<string>& a, vector<string>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }
    
    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(vector<string>& a, vector<string>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function
void swap(string *a, string *b) {
    string temp = *a;
    *a = *b;
    *b = temp;

}

// BubbleSort function
void bubbleSort(string *a[], int n) {
    for (int i = 0; i < (n-1); i++){
        for (int j = 0; j < n-i-1; j++){
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }

        }

    }

}
