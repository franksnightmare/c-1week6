#include "main.ih"

void arguments(Vars &vars, int argc, char **argv)
{
	// If there are no arguments do nothing.
	if (argc == 1)
		return;
	
	// If an option -a is found then the method is set to verbose.
	int opt;
	while((opt = getopt(argc, argv, "a")) != EOF)
	{
		switch (opt)
        {
			case 'a':
				vars.method = VERBOSE;
			break;
			default:
				cerr << "Invalid option " << opt << '\n';
				return;
		}
	}
	
	if (vars.method == VERBOSE)
	{
		if (argc >= 3)
			vars.path = argv[2];
	}
	else
		vars.path = argv[1];
}
