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


unsigned int F4(unsigned int x, unsigned int y, unsigned int z){
    return (x & z) | (y & (~z));
}


unsigned int modifyI(int i, int val, unsigned int x){
    unsigned int mask1 = 0xffffffff;
    unsigned int tmp;

    if(val == 0){
        tmp = mask1 ^ (1<<i);
        return x & tmp;
    }else{
        tmp = ~(mask1 ^ (1<<i));
        return x | tmp;
    }
}

int main(){
	   srand((unsigned)time(NULL));

	getExp();
	srand(time(NULL));

	ofstream outFile("result.txt", ios::out);

	unsigned int Y31, Y32, Y27, Y28, Y29, Y30;
	unsigned int constant = getRand();
	unsigned int M;
	unsigned int T;
	unsigned int sT;
	unsigned int sX33;

	unsigned int count = 0;
	unsigned int test = 0xfffffff;
	unsigned int _and = 0x200;



	while (test--){		
		Y28 = getRand();
        Y29 = getRand();

        Y29 = modifyI(31, 0, Y29);
        Y28 = modifyI(6, 0, Y28);
        Y28 = modifyI(7, 0, Y28);
        Y28 = modifyI(8, 0, Y28);
        Y28 = modifyI(9, 0, Y28);

        unsigned int T7, S1;

        do{
            M = getRand();
            Y27 = getRand();
			Y30 = getRand();
	    	Y31 = getRand();
            S1 = LL(Y27, 10) + M + constant;
            T7 = LL(Y27, 10)+(Y30 &_and)+ M +constant;
        }while(getNumber(S1, 6) != 0 || getNumber(S1, 7) != 0 || getNumber(S1, 8)!=0);


        Y32 = LL(Y28, 10) + LL(T7, 11);
        unsigned int bit20 = getNumber(Y32, 20);

        T = LL(Y27,10) + F4(Y31, Y30, LL(Y29, 10)) + M + constant;
        Y32 = LL(Y28, 10) + LL(T, 11);
        if (bit20 == getNumber(Y32, 20)){
            count++;
        }
        else{
            outFile <<dec<< Y27 << " " << Y28 << " " << Y29 << " " << Y30 << " " << Y31<<" "<<M<<" "<<constant << endl;
            outFile << hex << Y27 << " " << Y28 << " " << Y29 << " " << Y30 << " " << Y31 << " " << M << " " << constant<<" "<<F4(Y31, Y30, LL(Y29, 10))<<" "<<S1<<" "<<T7<<" "<<T << endl << endl;
        }

	}
	cout << hex << count << endl;
	outFile.close();
	system("pause");
	return 0;
}

