#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

//this function was used to flip a negative number into its positive counter part
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
	long long int msg;
	long long int tot, n, ekey;
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

	//grabbing values from key file
	file.open(argv[2]);
	file >> n >> tot >> ekey;
	file.close();

	file.open(argv[4]);
	outfile.open(argv[6]);

	//encode while loop
	while(file >> msg){
		//this was the most popular way to encode an integer for RSA encryption
		long long int dec=pow(msg, ekey);
		dec=dec%tot;

		//this method was supposed to take a char from an input string and encrpt it using RSA
		//char c = '\0';
		//dec="";
		//cout << msg << "\n" << msg.size() << "\n";
		/*for(i=0; i<msg.size(); i++){
			int h = (int)msg.at(i);
			long long a = (long long)pow(h, ekey);
			a = a%tot;

			if(a<0){
				a=negMod(a, tot);
			}

			//c = (char) a;
			//cout << i << " " << c << " " << a << " ";
			//dec += c;

			//c = '\0';
		}*/


		outfile << dec << " ";
	}
	outfile << "\n";

	file.close();
	outfile.close();

	return 0;
}
