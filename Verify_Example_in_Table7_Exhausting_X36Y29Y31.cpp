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
	unsigned long difX[65],difY[65];

	unsigned long A[20],AA[20],S[20],SS[20];
	unsigned long B17,BB17;//compute X37,17
	unsigned long B21,BB21;//compute X37,21
	unsigned long B2,BB2;//compute X37[0-12]
	unsigned long B[13],BB[13];//compute X38[17,21]
	unsigned long C,CC;

	unsigned long T4,T5,T6,T7,T8;
	unsigned long TT4,TT5,TT6,TT7,TT8;
	unsigned long Y11,Y15,Y21,Y27;//compute Y30[9,15,21,27,30,31]
	unsigned long Y20;//compute Y32[20]
	unsigned long YY11,YY15,YY21,YY27,YY20;
	unsigned long difT[65];
	unsigned long Z;
	unsigned long Q[65],QQ[65],difQ[65];

    int i,num; 

  num=0;

M[2]=0x8b4f1cd5;
M[3]=0x890c4f2f;
M[5]=0x2502e5de;
M[8]=0xff8dab49;
M[9]=0x6c17cd30;
M[10]=0x2ac8beb3;
M[11]=0xf9a6bb36;
M[12]=0x956624c5;
M[14]=0x3aba22d7;
M[15]=0x866a4c9c;


X[22]=0x91fc24e4;
X[23]=0xf7cef048;
X[24]=0xdd4217b5;
X[25]=0xd87761c5;
X[26]=0x31960dc6;


XX[22]=0x91fc24e4;
XX[23]=0xf7cef048;
XX[24]=0xdd4217b5;
XX[25]=0xdc7761c5;
XX[26]=0x3195fe46;


Y[18]=0x9f7021d5;
Y[19]=0x1546654b;
Y[20]=0xcd841de1;
Y[21]=0xe88edbd7;
Y[22]=0x508d0f5d;


YY[18]=0x9f7021d5;
YY[19]=0x1546654b;
YY[20]=0xcd841da1;
YY[21]=0xe88adbd7;
YY[22]=0x4c8d105c;


unsigned long counter1,counter2;
  for(counter1=1;counter1<power2(24);counter1++) 
{	
	  X[36] = getRand();
	  Y[29] = getRand();
	  Y[31] = getRand();

 //algorithm X

		T[27]= LROT(X[22],10) + F2(X[26], X[25], LROT(X[24], 10)) + M[9] + 0x5a827999;
        X[27]= LROT(X[23], 10) + LROT(T[27], 15);
		TT[27]= LROT(XX[22],10) + F2(XX[26], XX[25], LROT(XX[24], 10)) + M[9] + 0x5a827999;
        XX[27]= LROT(XX[23], 10) + LROT(TT[27], 15);

		T[28]= LROT(X[23],10) + F2(X[27], X[26], LROT(X[25], 10)) + M[5] + 0x5a827999;
        X[28]= LROT(X[24], 10) + LROT(T[28], 9);
		TT[28]= LROT(XX[23],10) + F2(XX[27], XX[26], LROT(XX[25], 10)) + M[5] + 0x5a827999;
        XX[28]= LROT(XX[24], 10) + LROT(TT[28], 9);

		T[29]= LROT(X[24],10) + F2(X[28], X[27], LROT(X[26], 10)) + M[2] + 0x5a827999;
        X[29]= LROT(X[25], 10) + LROT(T[29], 11);
		TT[29]= LROT(XX[24],10) + F2(XX[28], XX[27], LROT(XX[26], 10)) + M[2] + 0x5a827999;
        XX[29]= LROT(XX[25], 10) + LROT(TT[29], 11);

		T[30]= LROT(X[25],10) + F2(X[29], X[28], LROT(X[27], 10)) + M[14] + 0x5a827999;
        X[30]= LROT(X[26], 10) + LROT(T[30], 7);
		TT[30]= LROT(XX[25],10) + F2(XX[29], XX[28], LROT(XX[27], 10)) + M[14] + 0x5a827999;
        XX[30]= LROT(XX[26], 10) + LROT(TT[30], 7);

        T[31] = LROT(X[26],10) + F2(X[30], X[29], LROT(X[28], 10)) + M[11] + 0x5a827999;
        X[31] = LROT(X[27], 10) + LROT(T[31], 13);
		TT[31] = LROT(XX[26],10) + F2(XX[30], XX[29], LROT(XX[28], 10)) + M[11] + 0x5a827999;
        XX[31] = LROT(XX[27], 10) + LROT(TT[31], 13);

		T[32] = LROT(X[27],10) + F2(X[31], X[30], LROT(X[29], 10)) + M[8] + 0x5a827999;
        X[32] = LROT(X[28], 10) + LROT(T[32], 12);
		TT[32] = LROT(XX[27],10) + F2(XX[31], XX[30], LROT(XX[29], 10)) + M[8] + 0x5a827999;
        XX[32] = LROT(XX[28], 10) + LROT(TT[32], 12);

		T[33] = LROT(X[28],10) + F3(X[32], X[31], LROT(X[30], 10)) + M[3] + 0x6ed9eba1;
        X[33] = LROT(X[29], 10) + LROT(T[33], 11);
		TT[33] = LROT(XX[28],10) + F3(XX[32], XX[31], LROT(XX[30], 10)) + M[3] + 0x6ed9eba1;
        XX[33] = LROT(XX[29], 10) + LROT(TT[33], 11);

		T[34] = LROT(X[29],10) + F3(X[33], X[32], LROT(X[31], 10)) + M[10] + 0x6ed9eba1;
        X[34] = LROT(X[30], 10) + LROT(T[34], 13);
		TT[34] = LROT(XX[29],10) + F3(XX[33], XX[32], LROT(XX[31], 10)) + M[10] + 0x6ed9eba1;
        XX[34] = LROT(XX[30], 10) + LROT(TT[34], 13);

		T[35] = LROT(X[30],10) + F3(X[34], X[33], LROT(X[32], 10)) + M[14] + 0x6ed9eba1;
        X[35] = LROT(X[31], 10) + LROT(T[35], 6);
		TT[35] = LROT(XX[30],10) + F3(XX[34], XX[33], LROT(XX[32], 10)) + M[14] + 0x6ed9eba1;
        XX[35] = LROT(XX[31], 10) + LROT(TT[35], 6);
		
		X[36]=X[36]^(bit(X[36],11)<<11)^(bit(X[36],21)<<21)^((bit(X[36],2)^1)<<2)^((bit(X[36],7)^1)<<7)^((bit(X[36],24)^1)<<24);
        XX[36]=X[36]^0x80;

		T[37] = LROT(X[32],10) + F3(X[36], X[35], LROT(X[34], 10)) + M[9] + 0x6ed9eba1;
        X[37] = LROT(X[33], 10) + LROT(T[37], 14);
		TT[37] = LROT(XX[32],10) + F3(XX[36], XX[35], LROT(XX[34], 10)) + M[9] + 0x6ed9eba1;
		XX[37] = LROT(XX[33], 10) + LROT(TT[37], 14);

		T[38] = LROT(X[33],10) + F3(X[37], X[36], LROT(X[35], 10)) + M[15] + 0x6ed9eba1;
        X[38] = LROT(X[34], 10) + LROT(T[38], 9);
		TT[38] = LROT(XX[33],10) + F3(XX[37], XX[36], LROT(XX[35], 10)) + M[15] + 0x6ed9eba1;
        XX[38] = LROT(XX[34], 10) + LROT(TT[38], 9);

	

// algorithm Y

		Q[23] = LROT(Y[18],10) + F4(Y[22], Y[21], LROT(Y[20], 10)) + M[5] + 0x5c4dd124;
        Y[23] = LROT(Y[19], 10) + LROT(Q[23], 9);
		QQ[23] = LROT(YY[18],10) + F4(YY[22], YY[21], LROT(YY[20], 10)) + M[5] + 0x5c4dd124;
        YY[23] = LROT(YY[19], 10) + LROT(QQ[23], 9);

		Q[24] = LROT(Y[19],10) + F4(Y[23], Y[22], LROT(Y[21], 10)) + M[10] + 0x5c4dd124;
        Y[24] = LROT(Y[20], 10) + LROT(Q[24], 11);
		QQ[24] = LROT(YY[19],10) + F4(YY[23], YY[22], LROT(YY[21], 10)) + M[10] + 0x5c4dd124;
        YY[24] = LROT(YY[20], 10) + LROT(QQ[24], 11);

		Q[25] = LROT(Y[20],10) + F4(Y[24], Y[23], LROT(Y[22], 10)) + M[14] + 0x5c4dd124;
        Y[25] = LROT(Y[21], 10) + LROT(Q[25], 7);
		QQ[25] = LROT(YY[20],10) + F4(YY[24], YY[23], LROT(YY[22], 10)) + M[14] + 0x5c4dd124;
        YY[25] = LROT(YY[21], 10) + LROT(QQ[25], 7);

		Q[26] = LROT(Y[21],10) + F4(Y[25],Y[24],LROT(Y[23],10)) + M[15] + 0x5c4dd124;
        Y[26] = LROT(Y[22],10) + LROT(Q[26],7);
        QQ[26] = LROT(YY[21],10) + F4(YY[25],YY[24],LROT(YY[23],10)) + M[15] + 0x5c4dd124;
        YY[26] = LROT(YY[22],10) + LROT(QQ[26],7);

        Q[27] = LROT(Y[22],10) + F4(Y[26],Y[25],LROT(Y[24],10)) + M[8] + 0x5c4dd124;
        Y[27] = LROT(Y[23],10) + LROT(Q[27],12);
        QQ[27] = LROT(YY[22],10) + F4(YY[26],YY[25],LROT(YY[24],10)) + M[8] + 0x5c4dd124;
        YY[27] = LROT(YY[23],10) + LROT(QQ[27],12);

        Q[28] = LROT(Y[23],10) + F4(Y[27],Y[26],LROT(Y[25],10)) + M[12] + 0x5c4dd124;
        Y[28] = LROT(Y[24],10) + LROT(Q[28],7);
        QQ[28] = LROT(YY[23],10) + F4(YY[27],YY[26],LROT(YY[25],10)) + M[12] + 0x5c4dd124;
        YY[28] = LROT(YY[24],10) + LROT(QQ[28],7);

		Y[29] = Y[29]^(bit(Y[29],0)<<0)^(bit(Y[29],4)<<4)^(bit(Y[29],15)<<15)^(bit(Y[29],30)<<30)^(bit(Y[29],31)<<31)
                ^((bit(Y[29],10)^1)<<10)^((bit(Y[29],11)^1)<<11)^((bit(Y[29],12)^1)<<12)^((bit(Y[29],14)^1)<<14)^((bit(Y[29],17)^1)<<17)^((bit(Y[29],20)^1)<<20)
                ^((bit(Y[29],26)^bit(Y[28],26))<<26);
		YY[29]=Y[29]^0x104400;

		Q[30] = LROT(Y[25],10) + F4(Y[29],Y[28],LROT(Y[27],10)) + M[9] + 0x5c4dd124;
        Y[30] = LROT(Y[26],10) + LROT(Q[30],15);
		QQ[30] = LROT(YY[25],10) + F4(YY[29],YY[28],LROT(YY[27],10)) + M[9] + 0x5c4dd124;
        YY[30] = LROT(YY[26],10) + LROT(QQ[30],15);

		Y[31]=Y[31]^((bit(Y[31],5)^1)<<5)^((bit(Y[31],10)^1)<<10)^((bit(Y[31],21)^1)<<21)^((bit(Y[31],30)^1)<<30)^((bit(Y[31],24)^bit(Y[30],24))<<24)
			^((bit(Y[31],20)^bit(Y[30],20)^1)<<20);
		YY[31]=Y[31]^0x400;

		Q[32] = LROT(Y[27],10) + F4(Y[31],Y[30],LROT(Y[29],10)) + M[2] + 0x5c4dd124;
        Y[32] = LROT(Y[28],10) + LROT(Q[32],11);
        QQ[32] = LROT(YY[27],10) + F4(YY[31],YY[30],LROT(YY[29],10)) + M[2] + 0x5c4dd124;
        YY[32] = LROT(YY[28],10) + LROT(QQ[32],11);
		

//compute X37[0-12,17,21]
		A[0]= LROT(X[32],10) + (F3(X[36], X[35], LROT(X[34], 10))&0xf) + (M[9]&0xf) + 0x6ed9eba1;
		B17= LROT(X[33],10) + LROT(A[0],14);
		AA[0]= LROT(XX[32],10) + (F3(XX[36], XX[35], LROT(XX[34], 10))&0xf) + (M[9]&0xf) + 0x6ed9eba1;
		BB17= LROT(XX[33],10) + LROT(AA[0],14);
	
		A[1]= LROT(X[32],10) + (F3(X[36], X[35], LROT(X[34], 10))&0xe0) + (M[9]&0xe0) + 0x6ed9eba1;
		B21= LROT(X[33],10) + LROT(A[1],14);
		AA[1]= LROT(XX[32],10) + (F3(XX[36], XX[35], LROT(XX[34], 10))&0xe0) + (M[9]&0xe0) + 0x6ed9eba1;
		BB21= LROT(XX[33],10) + LROT(AA[1],14);
	
		A[2]= LROT(X[32],10) + (F3(X[36], X[35], LROT(X[34], 10))&0x7fff0000) + (M[9]&0x7fff0000) + 0x6ed9eba1;
		B2= LROT(X[33],10) + LROT(A[2],14);
		AA[2]= LROT(XX[32],10) + (F3(XX[36], XX[35], LROT(XX[34], 10))&0x7ffe0000) + (M[9]&0x7ffe0000) + 0x6ed9eba1;
		BB2= LROT(XX[33],10) + LROT(AA[2],14);

//compute X38[17,21]
		A[3]= LROT(X[33],10) + (F3(X[37], X[36], LROT(X[35], 10))&0x1fff) + (M[15]&0x1fff) + 0x6ed9eba1;
		B[3]= LROT(X[34],10) + LROT(A[3],9);
		AA[3]= LROT(XX[33],10) + (F3(XX[37], XX[36], LROT(XX[35], 10))&0x1fff) + (M[15]&0x1fff) + 0x6ed9eba1;
		BB[3]= LROT(XX[34],10) + LROT(AA[3],9);


//compute Y30[9,15,21,27,30,31]
		T4 = LROT(Y[25],10) + (F4(Y[29],Y[28],LROT(Y[27],10))&0x1d800000) + M[9] + 0x5c4dd124;
        Y11 = LROT(Y[26],10) + LROT(T4,15);
		TT4 = LROT(YY[25],10) + (F4(YY[29],YY[28],LROT(YY[27],10))&0x1d800000) + M[9] + 0x5c4dd124;
        YY11 = LROT(YY[26],10) + LROT(TT4,15);
		R[2]= LROT(Y[25],10) + M[9] + 0x5c4dd124;
		R[3]=F4(Y[29],Y[28],LROT(Y[27],10));

		T5 = LROT(Y[25],10) + (F4(Y[29],Y[28],LROT(Y[27],10))&0xc0000001) + M[9] + 0x5c4dd124;
        Y15 = LROT(Y[26],10) + LROT(T5,15);
		TT5 = LROT(YY[25],10) + (F4(YY[29],YY[28],LROT(YY[27],10))&0xc0000001) + M[9] + 0x5c4dd124;
        YY15 = LROT(YY[26],10) + LROT(TT5,15);

		T6 = LROT(Y[25],10) + (F4(Y[29],Y[28],LROT(Y[27],10))&0x78) + M[9] + 0x5c4dd124;
        Y21 = LROT(Y[26],10) + LROT(T6,15);
		TT6 = LROT(YY[25],10) + (F4(YY[29],YY[28],LROT(YY[27],10))&0x78) + M[9] + 0x5c4dd124;
        YY21 = LROT(YY[26],10) + LROT(TT6,15);

		T7 = LROT(Y[25],10) + (F4(Y[29],Y[28],LROT(Y[27],10))&0x1fe00) + M[9] + 0x5c4dd124;
        Y27 = LROT(Y[26],10) + LROT(T7,15);
		TT7 = LROT(YY[25],10) + (F4(YY[29],YY[28],LROT(YY[27],10))&0x1fe00) + M[9] + 0x5c4dd124;
        YY27 = LROT(YY[26],10) + LROT(TT7,15);

////compute Y32[20]
		T8 = LROT(Y[27],10) + (F4(Y[31],Y[30],LROT(Y[29],10))&0x200) + M[2] + 0x5c4dd124;
        Y20 = LROT(Y[28],10) + LROT(T8,11);
		TT8 = LROT(YY[27],10) + (F4(YY[31],YY[30],LROT(YY[29],10))&0x200) + M[2] + 0x5c4dd124;
        YY20 = LROT(YY[28],10) + LROT(TT8,11);
		R[9]= LROT(Y[27],10) + M[2] + 0x5c4dd124;
		

		difX[17]=X[17]^XX[17];
		difX[18]=X[18]^XX[18];
		difX[19]=X[19]^XX[19];
		difX[20]=X[20]^XX[20];
		difX[21]=X[21]^XX[21];
		difX[22]=X[22]^XX[22];
		difX[23]=X[23]^XX[23];
		difX[24]=X[24]^XX[24];
		difX[25]=X[25]^XX[25];
		difX[26]=X[26]^XX[26];
		difX[27]=X[27]^XX[27];
		difX[28]=X[28]^XX[28];
		difX[29]=X[29]^XX[29];
		difX[30]=X[30]^XX[30];
		difX[31]=X[31]^XX[31];
		difX[32]=X[32]^XX[32];
		difX[33]=X[33]^XX[33];
		difX[34]=X[34]^XX[34];
		difX[35]=X[35]^XX[35];
		difX[37]=X[37]^XX[37];
		difX[38]=X[38]^XX[38];
		

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
          (difX[29]==0x3811002e)&&(difX[30]==0xc44d18)&&(difX[31]==0x41600208)&&(difX[32]==0x10400)&&(difX[33]==0x41200000)
		  &&(difX[34]==0x80)&&(difX[35]==0x1200000)&&(difX[37]==0x200000)&&(difX[38]==0)
          &&(difY[26]==0x1778)&&(difY[27]==0x4310007)&&(difY[28]==0x8200022)&&(difY[30]==0x8200000)		
          &&(bit(B2,2)==0)&&(bit(X[37],2)==0)&&(bit(B2,7)==1)&&(bit(X[37],7)==1)&&(bit(B17,17)==1)&&(bit(X[37],17)==1)
		  &&(bit(B21,21)==0)&&(bit(X[37],21)==0)&&(bit(B[3],17)==0)&&(bit(X[38],17)==0)
          &&(bit(Y15,15)==1)&&(bit(Y[30],15)==1)&&(bit(Y21,21)==0)&&(bit(Y[30],21)==0)&&(bit(Y21,27)==0)&&(bit(Y[30],27)==0)
		  &&(bit(Y21,30)==0)&&(bit(Y[30],30)==0)&&(bit(Y21,31)==0)&&(bit(Y[30],31)==0)  
          &&(bit(Y20,20)==0)&&(bit(Y[32],20)==0)	  
		   )
		   

	   num=num+1;
}

		   p("num=%x\n",num);

			 p("X[22]=0x%x\n",X[22]);
			 p("X[23]=0x%x\n",X[23]);
			 p("X[24]=0x%x\n",X[24]);
			 p("X[25]=0x%x\n",X[25]);
			 p("X[26]=0x%x\n",X[26]);
			 p("X[27]=0x%x\n",X[27]);
			 p("X[28]=0x%x\n",X[28]);
			 p("X[29]=0x%x\n",X[29]);
			 p("X[30]=0x%x\n",X[30]);
			 p("X[31]=0x%x\n",X[31]);
			 p("X[32]=0x%x\n",X[32]);
			 p("X[33]=0x%x\n",X[33]);
			 p("X[34]=0x%x\n",X[34]);
			 p("X[35]=0x%x\n",X[35]);
			 p("X[37]=0x%x\n",X[37]);
			 p("X[38]=0x%x\n\n",X[38]);
			 
			 	
			 p("XX[22]=0x%x\n",XX[22]);
			 p("XX[23]=0x%x\n",XX[23]);
			 p("XX[24]=0x%x\n",XX[24]);
			 p("XX[25]=0x%x\n",XX[25]);
			 p("XX[26]=0x%x\n",XX[26]);
			 p("XX[27]=0x%x\n",XX[27]);
			 p("XX[28]=0x%x\n",XX[28]);
			 p("XX[29]=0x%x\n",XX[29]);
			 p("XX[30]=0x%x\n",XX[30]);
			 p("XX[31]=0x%x\n",XX[31]);
			 p("XX[32]=0x%x\n",XX[32]);
			 p("XX[33]=0x%x\n",XX[33]);
			 p("XX[34]=0x%x\n",XX[34]);
			 p("XX[35]=0x%x\n",XX[35]);
			 p("XX[37]=0x%x\n",XX[37]);
			 p("XX[38]=0x%x\n\n",XX[38]);

			 p("Y[18]=0x%x\n",Y[18]);
			 p("Y[19]=0x%x\n",Y[19]);
			 p("Y[20]=0x%x\n",Y[20]);
			 p("Y[21]=0x%x\n",Y[21]);		 
			 p("Y[22]=0x%x\n",Y[22]);
			 p("Y[23]=0x%x\n",Y[23]);
			 p("Y[24]=0x%x\n",Y[24]);
			 p("Y[25]=0x%x\n",Y[25]);
			 p("Y[26]=0x%x\n",Y[26]);
			 p("Y[27]=0x%x\n",Y[27]);
			 p("Y[28]=0x%x\n",Y[28]);
			 p("Y[30]=0x%x\n",Y[30]);
			 p("Y[32]=0X%x\n\n",Y[32]);

			 p("YY[18]=0x%x\n",YY[18]);
			 p("YY[19]=0x%x\n",YY[19]);
			 p("YY[20]=0x%x\n",YY[20]);
			 p("YY[21]=0x%x\n",YY[21]);
			 p("YY[22]=0x%x\n",YY[22]);
			 p("YY[23]=0x%x\n",YY[23]);
			 p("YY[24]=0x%x\n",YY[24]);
			 p("YY[25]=0x%x\n",YY[25]);
			 p("YY[26]=0x%x\n",YY[26]);
			 p("YY[27]=0x%x\n",YY[27]);
			 p("YY[28]=0x%x\n",YY[28]);
			 p("YY[30]=0X%x\n",YY[30]);
			 p("YY[32]=0X%x\n\n",YY[32]);

			 p("difX[22]=0x%x\n",difX[22]);
			 p("difX[23]=0x%x\n",difX[23]);
			 p("difX[24]=0x%x\n",difX[24]);
			 p("difX[25]=0x%x\n",difX[25]);
			 p("difX[26]=0x%x\n",difX[26]);
			 p("difX[27]=0x%x\n",difX[27]);
			 p("difX[28]=0x%x\n",difX[28]);
			 p("difX[29]=0x%x\n",difX[29]);
			 p("difX[30]=0x%x\n",difX[30]);
			 p("difX[31]=0x%x\n",difX[31]);
			 p("difX[32]=0x%x\n",difX[32]);
			 p("difX[33]=0x%x\n",difX[33]);
			 p("difX[34]=0x%x\n",difX[34]);
			 p("difX[35]=0x%x\n",difX[35]);
			 p("difX[37]=0x%x\n",difX[37]);
			 p("difX[38]=0x%x\n\n",difX[38]);

			 p("difY[18]=0x%x\n",difY[18]);
			 p("difY[19]=0x%x\n",difY[19]);
			 p("difY[20]=0x%x\n",difY[20]);
			 p("difY[21]=0x%x\n",difY[21]);
			 p("difY[22]=0x%x\n",difY[22]);
			 p("difY[23]=0x%x\n",difY[23]);
			 p("difY[24]=0x%x\n",difY[24]);
			 p("difY[25]=0x%x\n",difY[25]);
			 p("difY[26]=0x%x\n",difY[26]);
			 p("difY[27]=0x%x\n",difY[27]);
			 p("difY[28]=0x%x\n",difY[28]);
			 p("difY[30]=0x%x\n",difY[30]);			
}
