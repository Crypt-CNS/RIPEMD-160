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


unsigned int F4(unsigned int x, unsigned int y, unsigned int z){
    return (x & z) | (y & (~z));
}


int main(){
	   srand((unsigned)time(NULL));

	getExp();
	srand(time(NULL));

	ofstream outFile("result.txt", ios::out);

	unsigned int Y25, Y26, Y27, Y28, Y29, Y30;
	unsigned int constant = getRand();
	unsigned int M;
	unsigned int T;

	unsigned int count = 0;
	unsigned int test = 0xfffffff;
	unsigned int _and = 0xc0000001;



	while (test--){

		Y26 = getRand();
		Y27 = getRand();
        Y29 = getRand();

		Y29 = Y29 & 0X3fffffff;
		Y27 = Y27 & 0Xffbfffff;
		Y26 = Y26 & 0Xffffffef;

        unsigned int T3, S1;

       do{
            M = getRand();
            Y25 = getRand();
	    	Y28 = getRand();

			T3 = LL(Y25, 10)+(Y28 & LL(~Y27, 10)&_and) + M + constant;
        }while((getNumber(T3, 30) != 0)|| (getNumber(T3, 31) != 0));

        Y30 = LL(Y26, 10) + LL(T3, 15);
        unsigned int bit15 = getNumber(Y30, 15);

        T = LL(Y25,10) + F4(Y29, Y28, LL(Y27, 10)) + M + constant;
        Y30 = LL(Y26, 10) + LL(T, 15);

        if (bit15 == getNumber(Y30, 15)){
            count++;
        }
        else{
            outFile <<dec<< Y25 << " " << Y26 << " " << Y27 << " " << Y28 << " " << Y29<<" "<<M<<" "<<constant << endl;
            outFile << hex << Y25 << " " << Y26 << " " << Y27 << " " << Y28 << " " << Y29 << " " << M << " " << constant<<" "<<T3<<" "<<T << endl << endl;
        }
		
	}
	cout << hex << count << endl;
	outFile.close();
	system("pause");
	return 0;
}

