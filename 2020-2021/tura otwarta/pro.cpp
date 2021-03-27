#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int programsQuantity, cdsQuantity;

    cin >> programsQuantity;
    int* programs = new int[programsQuantity];

    for (int i = 0; i < programsQuantity; i++) cin >> programs[i];
    
    cin >> cdsQuantity;
    int* cds = new int[cdsQuantity];

    for (int i = 0; i < cdsQuantity; i++) cin >> cds[i];

    sort(programs, programs + programsQuantity);
    sort(cds, cds + cdsQuantity);

    int counter = 0;
    int programIndex = 0;
    int cdIndex = 0;

    while (cdIndex < cdsQuantity and programIndex < programsQuantity) {
        //cout << "cdIndex: " << cdIndex << " cd: " << cds[cdIndex] << "\t";
        //cout << "programIndex: " << programIndex << " program: " << programs[programIndex] << "\t";
        //cout << (cds[cdIndex] >= programs[programIndex]) << endl;
        if (cds[cdIndex] >= programs[programIndex]) {
            counter++;
            programIndex++;
        }

        cdIndex++;
    }

    cout << counter << endl;
}