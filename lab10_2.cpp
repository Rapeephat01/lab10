#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream source;
    ofstream dest;
    source.open("cheerbook.txt");
    dest.open("cheerbook_copy.txt");

    if (!source) {
        cerr << "Error: Unable to open cheerbook.txt" << endl;
        return 1;
    }

    if (!dest) {
        cerr << "Error: Unable to open cheerbook_copy.txt" << endl;
        return 1;
    }

    // Write header line
    dest << "-------------------- BOOM ---------------------" << endl;

    // Copy content from source to destination
    string line;
    while (getline(source, line)) {
        dest << line << endl;
    }

    // Write footer line
    dest << "-------------------- HA!! ---------------------" << endl;

    source.close();
    dest.close();
    return 0;
}
