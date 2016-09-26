#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include<time.h>
using namespace std;

ifstream inFile("read.txt", ios::in);
unsigned int ONE = 1;
unsigned int ex[32];

struct Index{
	int pos;
	bool flag;
	void f(int i, bool f){
		pos = i;
		flag = f;
	}
};

unsigned int LL(unsigned int number, int r){
	number = (number >> (32 - r)) | (number << r);
	return number;
}



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

	unsigned int X33, X34, X35, X36, X37, X38;
	unsigned int constant = getRand();
	unsigned int M;
	unsigned int T;
	unsigned int sT;
	unsigned int sX33;

	unsigned int count = 0;
	unsigned int test = 0xfffffff;
	unsigned int _and = 0x1fff;



	while (test--){
		X33 = getRand();
		X34 = getRand();
		X35 = getRand();
		X36 = getRand();
        X37 = getRand();

		X35 = X35 & 0X8001FFF8;
        X37 = X37 | 0X00001FFF;
        X37 = X37 & 0XFFFFFFFB;
        X34 = X34 & 0XFFFFFFBF;
        X36 = X36 | 0X00000004;

        unsigned int T2;

        do{
            M = getRand();
            T2 = LL(X33, 10)+ ((0x1ffb^ LL(X35, 10))&_and)+(M&_and)+constant;
        }while(getNumber(T2, 7) != 0);

        X38 = LL(X34, 10) + LL(T2, 9);
        unsigned int bit21 = getNumber(X38, 21);

        T = LL(X33,10) + F3(X37, X36, LL(X35, 10)) + M + constant;
        X38 = LL(X34, 10) + LL(T, 9);
        if (bit21 == getNumber(X38, 21)){
            count++;
        }
        else{
            outFile <<dec <<  X33 << " " << X34 << " " << X35 << " " << X36<<" "<<X37 <<" "<<M<<" "<<constant << endl;
            outFile << hex << X33 << " " << X34 << " " << X35 << " " << X36 << " "<<X37<< " " << M << " " << constant<<" "<<T2<<" "<<T << endl << endl;
        }

	}
	cout << hex << count << endl;
	outFile.close();
	system("pause");
	return 0;
}

