#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

//this function is used to change a negative number to its positive counterpart
int negMod(int num1, int mod){
	
	num1=abs(num1);
	int i = 1;
	while(mod*i < num1){
		i++;
	}
	int ans=mod*i-num1;
	return ans;
}

int main(int argc, char *argv[]){
	ifstream file;
	ofstream outfile;
	long long int msg;//, dec="";
	long long int tot, n, dkey;
	int i;

	//parsing command line arguements
	if(argc!=7){
		cout << "usage: Must provide -k (public key file), -i (input file), and -o (output file destination)\n";
		cout << "Order matters\n";
		return -1;
	}

	if(argv[1]!="-k"){
		cout << "usage: Must provide -k (public key file), -i (input file), and -o (output file destination)\n";
		cout << "Order matters\n";
		return -1;
	}

	if(argv[3]!="-i"){
		cout << "usage: Must provide -k (public key file), -i (input file), and -o (output file destination)\n";
		cout << "Order matters\n";
		return -1;
	}

	if(argv[5]!="-o"){
		cout << "usage: Must provide -k (public key file), -i (input file), and -o (output file destination)\n";
		cout << "Order matters\n";
		return -1;
	}

	//grabs the value from key file
	file.open(argv[2]);
	file >> n >> tot >> dkey;
	file.close();

	file.open(argv[4]);
	outfile.open(argv[6]);

	//this is the decode while loop
	while(file >> msg){
		//this was the most popular way to decode an integer of base 10 using RSA
		long long int dec=pow(msg, dkey);
		dec=dec%tot;

		//this calls the function to flip the negative to a positive
		if(dec<0){
			dec=negMod(dec, tot);
		}

		//this method was supposed to decode a char of a string given by the encode program
		/*char c = '\0';
		char *c1 = new char[msg.size()];
		for(i=0; i<msg.size(); i++){
			int h = (int)msg.at(i);
			long long a = (long long)pow(h, dkey);
			a = a%tot;

			if(a<0){
				a=negMod(a, tot);
			}

			c = a;
			dec += c;
			cout << i << a << c;
			c1[i] = (char)a;

			c = '\0';
		}*/


		outfile << dec << " ";
	}
	outfile << "\n";
	file.close();
	outfile.close();

	return 0;
}
