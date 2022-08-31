#include <iostream>

double data[2][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10}
};

using namespace std;

int main(int argc, char* argv[]) {

    double * inL = data[0];
    double * inR = data[1];

    for (int i = 0; i < 5; i++) {

        cout << "i: " << i <<  " *inL++: " << *inL++ << endl;
        // cout << *inR++ << endl;
        if (i >= 1) {
            cout << "\ti: " << i << " data: " << data[0][i] << endl;
            // cout << "\ti: " << i << " *inL--: " << *(--inL) << endl;
        }
    }



    return 0;
}