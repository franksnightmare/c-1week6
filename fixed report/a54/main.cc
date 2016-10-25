#include "main.h"

int main(int argc, char **argv)
{
	Vars vars;
	arguments(vars, argc, argv);
	process(vars);
}
