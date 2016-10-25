#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

ostream &now(ostream &stream)
{
	struct tm *newTime;
	time_t ltime;

	time(&ltime);

	newTime = localtime(&ltime);

	char *currentTime = asctime(newTime);
	currentTime[strlen(currentTime) - 1] = '\0';

	return stream << currentTime;
}

int main()
{
	cout << now << '\n';
}
