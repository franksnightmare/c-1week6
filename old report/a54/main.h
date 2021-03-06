#ifndef MAIN_H_
#define MAIN_H_

#include<iostream>

enum OPTION
{
	ABRIDGED, VERBOSE
};

struct Vars
{
	OPTION method = ABRIDGED;
	std::string path = "/var/log/account/pacct";
};

void arguments(Vars &vars, int argc, char **argv);
void process(Vars &vars);
void printProcess(char *name, size_t exitCode);

#endif
