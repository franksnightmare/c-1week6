#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double value = 12.04;
	
    cout
    << setw(15) << value << "\n" 
    << setw(15) << left << value << "\n"
    << setw(15) << right << value << "\n"
    << setw(15) << setprecision(3) << showpoint << value << "\n"
    << setw(15) << setprecision(4) << fixed << value << "\n"
    << resetiosflags(ios::fixed) << setw(15) << value << "\n";
}
