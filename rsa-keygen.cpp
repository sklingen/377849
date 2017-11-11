#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

long long int N;

int gen_rnd_number(int lower, int upper){
	int num=0;

	num = lower+(rand()%(upper-lower+1));

	return num;
}

long long int gcd(long long int num1, long long int num2){

	int temp;
	while(1){
		temp=num1%num2;
		if(temp==0){
			return num2;
		}
		num1=num2;
		num2=temp;
	}
}

int phi(unsigned int n){
	unsigned int result=1;
	for(int i=2; i<n; i++){
		if(gcd(i,n) == 1){
			result++;
		}
	}
	return result;
}


void gen_keys(long long int &ekey, long long int &dkey, long long int val){

	ekey=2;

	while(gcd(ekey, val)!=1){
		ekey++;
	}

	int k = 2;
	
	dkey = (1+(k*val))/ekey;
		 
	while(((1+(k*val))%ekey)!=0){
		k++;
		dkey = (1+(k*val))/ekey;
	}

	cout << "val: " << val << endl;
					 
	return;
}

void is_prime(int &p, int &q, int num){
	int i;
	
	if(num==0 || num==1){
		return;
	}
	if(num==2){
		return;
		if(p==0){
			p=num;
		}else if(q==0 && p!=num){
			q=num;
		}
	}
	for(i=2; i<=sqrt(num); i++){
		if(num%i==0){
			return;
		}
	}
	if(p==0){
		p=num;
	}else if(q==0 && p!=num){
		q=num;
	}

	return;
}

int lcm(int p, int q){
	int max;

	max = (p > q) ? p : q;

	do{
		if(max%p==0 && max%q==0){
			return max;
		}else{
			max++;
		}
	}while(true);

	return 0;

}



int main(int argc, char *argv[]){
	string pkeyfile, skeyfile;
	long long int ekey, dkey;
	int n;
	int p=0, q=0, i;
	long long int val;

	//parsing of command line arguements
	if(argc!=7){
		cout << "usage: Must provide -p (public key file), -s (secret key file), and -n (number of bits)\n";
		return -1;
	}

	if(argv[1]!= "-p"){
		cout << "usage: Must provide -p (public key file), -s (secret key file), and -n (number of bits)\n";
	        return -1;
	}

	if(argv[3]!= "-s"){
		cout << "usage: Must provide -p (public key file), -s (secret key file), and -n (number of bits)\n";
		return -1;
	}

	if(argv[5]!= "-n"){
		cout << "usage: Must provide -p (public key file), -s (secret key file), and -n (number of bits)\n";
		return -1;
	}

	n=atoi(argv[6]);

	srand(time(NULL));

	//find two random prime numbers between n and n/1
	while(p==0 || q==0){
		is_prime(p, q, gen_rnd_number(2, n/2));
	}

	N=p*q;

	/*This is were I believe the code is messing up.
	 * I have read many different ways to find the totient which  have called val. 
	 * Some read that you need to iterate through all possible phi(i) until you get one that eaquals (p-1)*(q-1)
	 * While other say you just call the below line to obtain your val. 
	 * I have also read that the val can be the lcm of (p-1)*(q-1). 
	 * My code for this method is in the lcm function above*/

	val = phi((p-1)*(q-1));

	//calls for the generation of ekey and dkey given the totient (val) from above
	gen_keys(ekey, dkey, val);

	//code to write to both files
	ofstream file;

	file.open(argv[1]);
	file << n << "\n" << p*q << "\n" << ekey;
	file.close();

	file.open(argv[2]);
	file << n << "\n" << p*q << "\n" << dkey;
	file.close();

	return 0;
}
