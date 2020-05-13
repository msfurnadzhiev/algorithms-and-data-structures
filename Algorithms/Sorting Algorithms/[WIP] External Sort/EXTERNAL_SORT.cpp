#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <thread>
#include <ctime>
#include <iomanip>
#include "MinHeap.h"
using namespace std;


const unsigned int PARTITION_SIZE = 10000; //count of numbers in one partition

// help functions
long long_rand() { //for 64bit numbers
    return (static_cast<long>(rand()) << (sizeof(int) * 8)) | rand();
}

ofstream open_file_for_writing(const string& file_path) {
    ofstream file(file_path.c_str(), ios::binary | ios::trunc);
    if (!file) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return file;
}

ifstream open_file_for_reading(const string& file_path) {
    ifstream file(file_path.c_str(), ios::binary);
    if(!file) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return file;
}

unsigned long get_file_size(const string& file_path) {
    ifstream file = open_file_for_reading(file_path);
    file.seekg(0,ios::end);
    auto bytes = static_cast<unsigned long>(file.tellg());
    file.close();
    return bytes;
}


bool generate_random_file_content(const string& file_path, const unsigned& int_count) {
    ofstream file = open_file_for_writing(file_path);

    for(int i=0; i<int_count; i++ ){
        long temp = long_rand();
        file.write(reinterpret_cast<const char*>(&temp), sizeof(long));
    }
    file.close();
    return static_cast<bool>(file);
}

bool is_file_sorted(const string& file_path) {
    ifstream ifile = open_file_for_reading(file_path);

    long first = 0, second = 0;
    ifile.read(reinterpret_cast<char*>(&first), sizeof(long));
    ifile.read(reinterpret_cast<char*>(&second), sizeof(long));

    while(!ifile.eof()) {
        if(first > second) { return false; }
        first = second;
        ifile.read(reinterpret_cast<char*>(&second), sizeof(long));
    }

    ifile.close();
    return true;
}

bool save_in_file(const string&  file_path, const vector<long>& data) {
    ofstream file = open_file_for_writing(file_path);
    file.write(reinterpret_cast<const char*>(data.data()),data.size()*sizeof(long));
    file.close();
    return static_cast<bool>(file);
}

bool load_from_file(const string& file_path, vector<long>& data, const unsigned& index) {
    data.clear();

    ifstream file = open_file_for_reading(file_path);

    file.seekg(index*PARTITION_SIZE*sizeof(long),ios::beg);
    data.resize(PARTITION_SIZE);
    file.read(reinterpret_cast<char*>(data.data()),PARTITION_SIZE*sizeof(long));
    if(!file){
        data.clear();
        return false;
    }
    return true;
}



// cut partition from file and sort partition data
void cut_partition_from_file(const string& file_path, const string& new_file_path, const int& index) {
    vector<long> data;

    load_from_file(file_path,data, index);

    sort(data.begin(),data.end());

    save_in_file(new_file_path,data);

}

void split_file_into_partitions(const string& file_path, const int& partitions) {
    vector<thread> workers(partitions);

    for(int i=0; i<partitions; i++) {
        workers[i] = thread(cut_partition_from_file,file_path, to_string(i), i);
    }

    for(int i=0; i<partitions; i++) {
        workers[i].join();
    }
}

void merge_files(const string& output_file, const int& partition_count) {

    vector<ifstream> ifile;
    ifile.resize(partition_count);
    for(int i=0; i<partition_count;i++) {
        ifile[i] = open_file_for_reading(to_string(i));
    }

    // construct heap
    Node* heap = new Node[partition_count];
    for(int i=0; i<partition_count; i++) {
        ifile[i].read(reinterpret_cast<char*>(&heap[i].element), sizeof(long));
        heap[i].parent_index = i;
    }
    MinHeap min_heap(heap, partition_count);

    // close file descriptors
    for(int j=0; j<partition_count; j++) {
        ifile[j].close();
    }

    // construct sorted file
    ofstream ofile = open_file_for_writing(output_file);

    int count = 0;
    while(count != partition_count) {
        Node root = min_heap.get_root();
        ofile.write(reinterpret_cast<const char*>(&root.element), sizeof(long));
        ifile[root.parent_index].read(reinterpret_cast<char*>(&root.element), sizeof(long));
        if (!ifile[root.parent_index]) {
            root.element = LONG_MAX;
            count++;
        }
        min_heap.replace_root(root);
    }

    ofile.close();
}

void external_sort(const string& file_path) {

    long file_size = get_file_size(file_path);

    int partition_count = file_size / (PARTITION_SIZE * sizeof(long));

    split_file_into_partitions(file_path,partition_count);

    merge_files(file_path,partition_count);

    for(int i=0; i<partition_count; i++) {
        remove(to_string(i).c_str());
    }
}


int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    string input_file = "input";

    generate_random_file_content(input_file,2000*PARTITION_SIZE);

    clock_t  start = clock();

    external_sort(input_file);

    clock_t end = clock();

    cout << "The file \"" << input_file << "\" is sorted: " << boolalpha << is_file_sorted(input_file) << endl;
    cout << "Time: " << (end-start)/(CLOCKS_PER_SEC/1000) << " milliseconds" << endl;

    return 0;
}
