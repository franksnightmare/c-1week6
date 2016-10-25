    cout << "extracted first number: " << no1 << '\n';

    istr.seekg(0);
    
    istr.str(argv[2]);
    size_t no2 = 0;
    istr >> no2;
