make: enc dec keygen

enc:
	g++ -g -o rsa-enc rsa-enc.cpp

dec:
	g++ -g -o rsa-dec rsa-dec.cpp

keygen:
	g++ -g -o rsa-keygen rsa-keygen.cpp
