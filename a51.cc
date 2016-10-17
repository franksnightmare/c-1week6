//Once a file has been opened in read and write mode, 
//the << operator can be used to insert information
//into the file, while the >> operator may be used to
//extract information from the file. These operations
//may be performed in any order, but a seekg or seekp
//operation is required when switching between insertions
//and extractions. The seek operation is used to activate
//the stream's data used for reading or those used for
//writing (and vice versa). 

    cout << "extracted first number: " << no1 << '\n';

    istr.seekg(0);
    
    istr.str(argv[2]);
    size_t no2 = 0;
    istr >> no2;
