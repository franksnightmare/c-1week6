#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

ostream &now(ostream &stream)
{	
	time_t ltime = time(NULL);

	string *currentTime = asctime(localtime(&ltime));
	currentTime.erase(currentTime.find_last_of("\n"), 1);

	return stream << currentTime;
}

int main()
{
	cout << now << '\n';
}
