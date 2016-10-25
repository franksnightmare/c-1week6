#include "main.ih"

// Size of the acct_v3 struct
// as well as relative positions
// of the name and exit code.
size_t stepSize = sizeof(acct_v3);
size_t relNamePos = stepSize -
					sizeof(char) * ACCT_COMM;
size_t relCodePos = stepSize +
					sizeof(char) * 2 +
					sizeof(__u16);

void process(Vars &vars)
{
	ifstream is(vars.path, ifstream::binary);
	
	if (!is)
	{
		cerr << "No file found.\n";
		cerr << vars.path << '\n';
		return;
	}
	
	// Get the length of the file and
	// return to the beginning.
	is.seekg(0, is.end);
	size_t length = is.tellg();
	is.seekg(0, is.beg);
	
	char name[ACCT_COMM];
	__u32 exitCode;
	
	size_t process = 0;
	size_t place = 0;
	while ((place = process * stepSize) < length)
	{
		is.seekg(place + relCodePos, is.beg);
		is.read(reinterpret_cast<char *>(&exitCode), sizeof(exitCode));
		
		is.seekg(place + relNamePos, is.beg);
		is.read(reinterpret_cast<char *>(&name), sizeof(char) * ACCT_COMM);
		
		if (exitCode != 0 || vars.method == VERBOSE)
			printProcess(name, exitCode);
		
		++process;
	}
}
