// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <math.h>
using namespace std;
double getMaxNuts(double N, double D, double C, double F) {
    if(N <= C)
    {
        double remain = N-D*F;
        return remain > 0 ? remain : 0;
    }
    int numTrips = 2*ceil(N/C)-1;
    double consumePerKm = F*numTrips;
    double remain = C*(ceil(N/C)-1);
    double travled = (N-remain)/consumePerKm;
    if(travled >= D)
        return N-D*consumePerKm;
    return getMaxNuts(remain, D - travled, C, F);

}
int main() {
    double N = 100;
    double D = 20;
    double C = 50;
    double F = 1;
    cout<<getMaxNuts(N,D,C,F);
    
    
    return 0;
}