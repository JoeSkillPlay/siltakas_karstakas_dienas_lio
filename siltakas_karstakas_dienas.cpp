#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    vector<float> temperatures;

    
    ifstream dienasDat("C:\\Users\\Dans\\source\\repos\\siltakas_karstakas_dienas\\dienas.dat.txt");

    if (!dienasDat) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    };

    float number;
    while (dienasDat >> number) {
        if (number != 99.9f) {
            (temperatures.push_back(number));
        }
    };

    dienasDat.close();  

    if (temperatures.empty()) {
        cerr << "Error: No data in the file." << endl;
        return 1;  
    }
    
    int n = temperatures.size();

   
    float minTemp = temperatures[0];
    float maxTemp = temperatures[0];
    int warmestDays = 1;
    int coldestDays = 1;

   
    for (int i = 1; i < n; i++) {
        if (temperatures[i] > maxTemp) {
            maxTemp = temperatures[i];
            warmestDays++;  
        }
        if (temperatures[i] < minTemp) {
            minTemp = temperatures[i];
            coldestDays++;  
        }
    }

    cout << "Gada silto dienu skaits: " << warmestDays << endl;
    cout << "Gada auksto dienu skaits: " << coldestDays << endl;

    return 0;  
}
