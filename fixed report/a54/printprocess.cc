#include "main.ih"

void printProcess(ostream &output, char *name, size_t exitCode)
{
	output << '\'' << name << "\' ";
	switch(exitCode)
	{
		case(SIGKILL):
			output << "KILL";
		break;
		case(SIGTERM):
			output << "TERM";
		break;
		default:
			output << exitCode;
		break;
	}
	output << '\n';
}
