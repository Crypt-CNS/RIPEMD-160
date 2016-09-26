#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include<time.h>
using namespace std;

unsigned int ONE = 1;
unsigned int ex[32];

unsigned int LL(unsigned int number, int r){
	number = (number >> (32 - r)) | (number << r);
	return number;
}


unsigned int RR(unsigned int number, int r){
	number = (number << (32 - r)) | (number >> r);
	return number;
}

unsigned int K = 0x5C4DD124;
unsigned int S;


void getExp(){
	for (int i = 0; i < 32; i++){
		ex[i] = 1 << i;
	}
}

unsigned int getNumber(unsigned int number, unsigned int pos){
	number = number >> (pos);
	return number&ONE;
}



unsigned int getRand(){
	unsigned int retNum = 0;
	retNum = rand(); retNum <<= 16; retNum ^= rand(); retNum ^= LL(retNum, 17);
	return retNum;
   }


unsigned int F3(unsigned int x,unsigned int y,unsigned int z){
	return (x | (~y)) ^ z;
}


int main(){
	   srand((unsigned)time(NULL));

	getExp();
	srand(time(NULL));

	ofstream outFile("result1.txt", ios::out);

	unsigned int X32, X33, X34, X35, X36, X37;
	unsigned int constant = getRand();
	unsigned int M;
	unsigned int T;

	unsigned int count = 0;
	unsigned int test = 0xfffffff;
	unsigned int _and = 0x3fe0000;



	while (test--){
		X33 = getRand();
		X34 = getRand();
		X35 = getRand();
		X36 = getRand();


		X35 = X35 & 0XFC01FFFF;

        unsigned int S1;
        unsigned int T1;


		do{
            X32 = getRand();
            S1 = LL(X32, 10)+constant;
        } while((getNumber(S1, 16) != 0)|(getNumber(S1, 17) != 0));


        do{
            M = getRand();
            T1 = LL(X32, 10)+(LL(~X34, 10)&_and)+(M&_and)+constant;
        }while((getNumber(T1, 17) != 0)|(getNumber(F3(X36, X35, LL(X34, 10)) + M, 16) != 0));

        X37 = LL(X33, 10) + LL(T1, 14);
        unsigned int bit7 = getNumber(X37, 7);

        T = LL(X32,10) + F3(X36, X35, LL(X34, 10)) + M + constant;
        X37 = LL(X33, 10) + LL(T, 14);

        if (bit7 == getNumber(X37, 7)){
            count++;
        }
        else{
            outFile <<dec<< X32 << " " << X33 << " " << X34 << " " << X35 << " " << X36<<" "<<M<<" "<<constant << endl;
            outFile << hex << X32 << " " << X33 << " " << X34 << " " << X35 << " " << X36 << " " << M << " " << constant<<" "<<T1<<" "<<T <<" "<<S1<< endl << endl;
        }

	}
	cout << hex << count << endl;
	outFile.close();
	system("pause");
	return 0;
}

