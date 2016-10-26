#include "main.ih"

// Size of the acct_v3 struct
// as well as relative positions
// of the name and exit code.

void process(Vars &vars, ostream &output)
{
	ifstream is(vars.path, ifstream::binary);
	
	if (!is)
	{
		cerr << "File not found or not openable.\n";
		cerr << vars.path << '\n';
		return;
	}
	
	// Get the length of the file and
	// return to the beginning.
	is.seekg(0, is.end);
	size_t length = is.tellg();
	is.seekg(0, is.beg);	
	
	// The reading process reads acct_v3 structs from the file.
	// It then reads the important information directly
	// from the struct.
	acct_v3 log;
	
	size_t process = 0;
	size_t place = 0;
	size_t stepSize = sizeof(log);
	while ((place = process * stepSize) < length)
	{
		is.seekg(place, is.beg);
		is.read(reinterpret_cast<char *>(&log), sizeof(log));
		
		if (log.ac_exitcode != 0 || vars.method == VERBOSE)
			printProcess(output, log.ac_comm, log.ac_exitcode);
		
		++process;
	}
}
