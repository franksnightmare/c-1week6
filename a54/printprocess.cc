#include "main.ih"

void printProcess(char *name, size_t exitCode)
{
	cout << '\'' << name << "\' ";
	switch(exitCode)
	{
		case(SIGKILL):
			cout << "KILL";
		break;
		case(SIGTERM):
			cout << "TERM";
		break;
		default:
			cout << exitCode;
		break;
	}
	cout << '\n';
}
