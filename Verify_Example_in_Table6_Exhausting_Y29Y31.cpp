#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include<time.h>

   #define F1(x,y,z) (x^y^z)
   #define F2(x,y,z) ((x&y)|((~x)&z))
   #define F3(x,y,z) (z^(x|(~y)))
   #define F4(x,y,z) ((x&z)|(y&(~z)))
   #define F5(x,y,z) (x^(y|(~z)))
   #define LROT(x,s)  (((x)<<s)|((x)>>(32-s)))
   #define RROT(x,s)  (((x)>>s)|((x)<<(32-s)))
   #define bit(x,n)    ((x<<(31-n))>>31)
   #define power2(x)    (0x1<<x)
   #define p printf

//pseudo-random number generator
unsigned int getRand(){
	unsigned int retNum = 0;
	retNum = rand(); retNum <<= 16; retNum ^= rand(); retNum ^= LROT(retNum, 17);
	return retNum;
   }


   main()
   {
	srand((unsigned)time(NULL));
    unsigned long X[65],Y[65],T[65],R[65],M[16];
	unsigned long XX[65],YY[65],TT[65],RR[65],MM[16];
	unsigned long T4,T5,T6,T7,T8;
	unsigned long TT4,TT5,TT6,TT7,TT8;
	unsigned long Y11,Y15,Y21,Y27;
	unsigned long Y20;
	unsigned long YY11,YY15,YY21,YY27,YY20;
	unsigned long difY[65];
	unsigned long Z;

    int i,num;

	num=0;

M[2]=0x74f1f030;
M[5]=0xf3bf86c1;
M[8]=0x87ffd902;
M[9]=0x47c76e30;
M[10]=0x8f04abf1;
M[12]=0x9df619c1;
M[13]=0xb5eb9e8d;
M[14]=0xbc9e3a19;
M[15]=0x10630dee;

Y[17]=0xf2c0a544;
Y[18]=0x9453c4fc;
Y[19]=0xb6052b22;
Y[20]=0xef1c7569;
Y[21]=0xcb2693e7;

YY[17]=0xf2c0a544;
YY[18]=0x9453c4fc;
YY[19]=0xb6052b22;
YY[20]=0xef1c7529;
YY[21]=0xcb2293e7;


  unsigned long counter1,counter2;
  for(counter1=1;counter1<power2(28);counter1++)
	   {	  
    	Y[29] = getRand();
	    Y[31] = getRand();


	    T[22] = LROT(Y[17],10) + F4(Y[21], Y[20], LROT(Y[19], 10)) + M[13] + 0x5c4dd124;
        Y[22] = LROT(Y[18], 10) + LROT(T[22], 8);
		TT[22] = LROT(YY[17],10) + F4(YY[21], YY[20], LROT(YY[19], 10)) + M[13] + 0x5c4dd124;
        YY[22] = LROT(YY[18], 10) + LROT(TT[22], 8);

		T[23] = LROT(Y[18],10) + F4(Y[22], Y[21], LROT(Y[20], 10)) + M[5] + 0x5c4dd124;
        Y[23] = LROT(Y[19], 10) + LROT(T[23], 9);
		TT[23] = LROT(YY[18],10) + F4(YY[22], YY[21], LROT(YY[20], 10)) + M[5] + 0x5c4dd124;
        YY[23] = LROT(YY[19], 10) + LROT(TT[23], 9);

		T[24] = LROT(Y[19],10) + F4(Y[23], Y[22], LROT(Y[21], 10)) + M[10] + 0x5c4dd124;
        Y[24] = LROT(Y[20], 10) + LROT(T[24], 11);
		TT[24] = LROT(YY[19],10) + F4(YY[23], YY[22], LROT(YY[21], 10)) + M[10] + 0x5c4dd124;
        YY[24] = LROT(YY[20], 10) + LROT(TT[24], 11);

		T[25] = LROT(Y[20],10) + F4(Y[24], Y[23], LROT(Y[22], 10)) + M[14] + 0x5c4dd124;
        Y[25] = LROT(Y[21], 10) + LROT(T[25], 7);
		TT[25] = LROT(YY[20],10) + F4(YY[24], YY[23], LROT(YY[22], 10)) + M[14] + 0x5c4dd124;
        YY[25] = LROT(YY[21], 10) + LROT(TT[25], 7);

		T[26] = LROT(Y[21],10) + F4(Y[25], Y[24], LROT(Y[23], 10)) + M[15] + 0x5c4dd124;
        Y[26] = LROT(Y[22], 10) + LROT(T[26], 7);
        TT[26] = LROT(YY[21],10) + F4(YY[25], YY[24], LROT(YY[23], 10)) + M[15] + 0x5c4dd124;
        YY[26] = LROT(YY[22], 10) + LROT(TT[26], 7);

        T[27] = LROT(Y[22],10) + F4(Y[26], Y[25], LROT(Y[24], 10)) + M[8] + 0x5c4dd124;
        Y[27] = LROT(Y[23], 10) + LROT(T[27], 12);
        TT[27] = LROT(YY[22],10) + F4(YY[26], YY[25], LROT(YY[24], 10)) + M[8] + 0x5c4dd124;
        YY[27] = LROT(YY[23], 10) + LROT(TT[27], 12);

        T[28] = LROT(Y[23],10) + F4(Y[27], Y[26], LROT(Y[25], 10)) + M[12] + 0x5c4dd124;
        Y[28] = LROT(Y[24], 10) + LROT(T[28], 7);
        TT[28] = LROT(YY[23],10) + F4(YY[27], YY[26], LROT(YY[25], 10)) + M[12] + 0x5c4dd124;
        YY[28] = LROT(YY[24], 10) + LROT(TT[28], 7);

	
		Y[29] = Y[29]^(bit(Y[29], 0)<<0)^(bit(Y[29], 4)<<4)^(bit(Y[29], 15)<<15)^(bit(Y[29], 30)<<30)^(bit(Y[29], 31)<<31)
                ^((bit(Y[29], 10)^1)<<10)^((bit(Y[29], 11)^1)<<11)^((bit(Y[29], 12)^1)<<12)^((bit(Y[29], 14)^1)<<14)^((bit(Y[29], 17)^1)<<17)^((bit(Y[29], 20)^1)<<20)
                ^((bit(Y[29], 26)^bit(Y[28], 26))<<26);
		YY[29]=Y[29]^0x104400;


		T[30] = LROT(Y[25], 10) + F4(Y[29], Y[28], LROT(Y[27], 10)) + M[9] + 0x5c4dd124;
        Y[30] = LROT(Y[26], 10) + LROT(T[30], 15);
		TT[30] = LROT(YY[25], 10) + F4(YY[29], YY[28], LROT(YY[27], 10)) + M[9] + 0x5c4dd124;
        YY[30] = LROT(YY[26], 10) + LROT(TT[30], 15);


		Y[31]=Y[31]^((bit(Y[31], 5)^1)<<5)^((bit(Y[31], 10)^1)<<10)^((bit(Y[31], 21)^1)<<21)^((bit(Y[31], 30)^1)<<30)^((bit(Y[31], 24)^bit(Y[30], 24))<<24)
			^((bit(Y[31], 20)^bit(Y[30], 20)^1)<<20);
		YY[31]=Y[31]^0x400;


		T[32] = LROT(Y[27], 10) + F4(Y[31], Y[30], LROT(Y[29], 10)) + M[2] + 0x5c4dd124;
        Y[32] = LROT(Y[28], 10) + LROT(T[32], 11);
        TT[32] = LROT(YY[27], 10) + F4(YY[31], YY[30], LROT(YY[29], 10)) + M[2] + 0x5c4dd124;
        YY[32] = LROT(YY[28], 10) + LROT(TT[32], 11);


//compute Y30[15,21,27,30,31]
		T4 = LROT(Y[25], 10) + (F4(Y[29], Y[28], LROT(Y[27], 10))&0x1d800000) + M[9] + 0x5c4dd124;
        Y11 = LROT(Y[26], 10) + LROT(T4, 15);
		TT4 = LROT(YY[25], 10) + (F4(YY[29], YY[28], LROT(YY[27], 10))&0x1d800000) + M[9] + 0x5c4dd124;
        YY11 = LROT(YY[26], 10) + LROT(TT4, 15);

		T5 = LROT(Y[25], 10) + (F4(Y[29], Y[28], LROT(Y[27], 10))&0xc0000001) + M[9] + 0x5c4dd124;
        Y15 = LROT(Y[26], 10) + LROT(T5, 15);
		TT5 = LROT(YY[25], 10) + (F4(YY[29], YY[28], LROT(YY[27], 10))&0xc0000001) + M[9] + 0x5c4dd124;
        YY15 = LROT(YY[26], 10) + LROT(TT5, 15);

		T6 = LROT(Y[25], 10) + (F4(Y[29], Y[28], LROT(Y[27], 10))&0x78) + M[9] + 0x5c4dd124;
        Y21 = LROT(Y[26], 10) + LROT(T6, 15);
		TT6 = LROT(YY[25], 10) + (F4(YY[29], YY[28], LROT(YY[27], 10))&0x78) + M[9] + 0x5c4dd124;
        YY21 = LROT(YY[26], 10) + LROT(TT6, 15);

		T7 = LROT(Y[25], 10) + (F4(Y[29], Y[28], LROT(Y[27], 10))&0x1fe00) + M[9] + 0x5c4dd124;
        Y27 = LROT(Y[26], 10) + LROT(T7, 15);
		TT7 = LROT(YY[25], 10) + (F4(YY[29], YY[28], LROT(YY[27], 10))&0x1fe00) + M[9] + 0x5c4dd124;
        YY27 = LROT(YY[26], 10) + LROT(TT7, 15);

//compute Y32[20] 
		T8 = LROT(Y[27], 10) + (F4(Y[31], Y[30], LROT(Y[29], 10))&0x200) + M[2] + 0x5c4dd124;
        Y20 = LROT(Y[28], 10) + LROT(T8, 11);
		TT8 = LROT(YY[27], 10) + (F4(YY[31], YY[30], LROT(YY[29], 10))&0x200) + M[2] + 0x5c4dd124;
        YY20 = LROT(YY[28], 10) + LROT(TT8, 11);


		difY[17]=Y[17]^YY[17];
		difY[18]=Y[18]^YY[18];
		difY[19]=Y[19]^YY[19];
		difY[20]=Y[20]^YY[20];
		difY[21]=Y[21]^YY[21];
		difY[22]=Y[22]^YY[22];
		difY[23]=Y[23]^YY[23];
		difY[24]=Y[24]^YY[24];
		difY[25]=Y[25]^YY[25];
		difY[26]=Y[26]^YY[26];
		difY[27]=Y[27]^YY[27];
		difY[28]=Y[28]^YY[28];
		difY[30]=Y[30]^YY[30];


      if(		  	  
		  (difY[17]==0)&&(difY[18]==0)&&(difY[19]==0)&&(difY[20]==0x40)&&(difY[21]==0x40000)&&(difY[22]==0x1c001f01)
		  &&(difY[23]==0x60e0060)&&(difY[24]==0x90000830)&&(difY[25]==0x2080080b)&&(difY[26]==0x1778)
		  &&(difY[27]==0x4310007)&&(difY[28]==0x8200022)&&(difY[30]==0x8200000)
          &&(bit(Y15,15)==1)&&(bit(Y[30],15)==1)&&(bit(YY[30],15)==1)&&(bit(Y21,21)==0)&&(bit(Y[30],21)==0)&&(bit(YY[30],21)==1)
		  &&(bit(Y21,27)==0)&&(bit(Y[30],27)==0)&&(bit(YY[30],27)==1)
          &&(bit(Y21,30)==0)&&(bit(Y[30],30)==0)&&(bit(YY[30],30)==0)&&(bit(Y21,31)==0)&&(bit(Y[30],31)==0)&&(bit(YY[30],31)==0)
		  &&(bit(Y20,20)==0)&&(bit(Y[32],20)==0)&&(bit(YY[32],20)==0)
		   )
	  num=num+1;
  
}

	  p("num=%x\n",num);   
}

