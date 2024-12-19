#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ifstream file("score.txt");
    if (!file) {
        cerr << "Error: Unable to open score.txt" << endl;
        return 1;
    }

    vector<double> scores;
    double value, sum = 0, sumSquared = 0;
    int count = 0;

    
    while (file >> value) {
        scores.push_back(value);
        sum += value;
        count++;
    }

    file.close();

    if (count == 0) {
        cerr << "Error: No data in file." << endl;
        return 1;
    }

    
    double mean = sum / count;

    
    for (double score : scores) {
        sumSquared += pow(score - mean, 2);
    }
    double stdDev = sqrt(sumSquared / count);

    
    cout << "Number of data = " << count << endl;
    cout << "Mean = " << setprecision(3) << mean << endl;
    cout << "Standard deviation = " <<  setprecision(3) << stdDev << endl;

    return 0;
}
