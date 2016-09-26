#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

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


   main()
   {
    unsigned long X[65],T[65],M[16];
	unsigned long XX[65],TT[65];
	unsigned long difX[65];

	unsigned long A[20],AA[20];
	unsigned long B17,BB17;//calculate X37,17
	unsigned long B21,BB21;//calculate X37,21
	unsigned long B2,BB2;//calculate X37[0-12]
	unsigned long B[13],BB[13];//calculate X38[17,21]
    int num; 
	
num=0;

M[0]=0x7ed471ba;
M[2]=0x7e3d71d1;
M[3]=0x1edb7709;
M[5]=0xa3d9b37f;
M[6]=0x70477536;
M[8]=0xbdb9fa58;
M[9]=0x2e63c462;
M[10]=0xb0477764;
M[11]=0x67740efc;
M[12]=0xf9e7b23c;
M[14]=0x50321425;
M[15]=0x61b8f56a;

X[17]=0xe17af3a8;
X[18]=0xcc966a05;
X[19]=0xb7573bfe;
X[20]=0x9336419e;
X[21]=0xf6920500;

XX[17]=0xe17af3e8;
XX[18]=0xcc966a05;
XX[19]=0xb7573bfe;
XX[20]=0x9336419e;
XX[21]=0xf6930500;


unsigned long counter1;
  for(counter1=1;counter1<0xfffffff;counter1++)
  {	  
	    X[36]= counter1;	

        T[22]= LROT(X[17],10) + F2(X[21], X[20], LROT(X[19], 10)) + M[6] + 0x5a827999;
        X[22]= LROT(X[18], 10) + LROT(T[22], 9);
		TT[22]= LROT(XX[17],10) + F2(XX[21], XX[20], LROT(XX[19], 10)) + M[6] + 0x5a827999;
        XX[22]= LROT(XX[18], 10) + LROT(TT[22], 9);

		T[23]= LROT(X[18],10) + F2(X[22], X[21], LROT(X[20], 10)) + M[15] + 0x5a827999;
        X[23]= LROT(X[19], 10) + LROT(T[23], 7);
		TT[23]= LROT(XX[18],10) + F2(XX[22], XX[21], LROT(XX[20], 10)) + M[15] + 0x5a827999;
        XX[23]= LROT(XX[19], 10) + LROT(TT[23], 7);

		T[24]= LROT(X[19],10) + F2(X[23], X[22], LROT(X[21], 10)) + M[3] + 0x5a827999;
        X[24]= LROT(X[20], 10) + LROT(T[24], 15);
		TT[24]= LROT(XX[19],10) + F2(XX[23], XX[22], LROT(XX[21], 10)) + M[3] + 0x5a827999;
        XX[24]= LROT(XX[20], 10) + LROT(TT[24], 15);

		T[25]= LROT(X[20],10) + F2(X[24], X[23], LROT(X[22], 10)) + M[12] + 0x5a827999;
        X[25]= LROT(X[21], 10) + LROT(T[25], 7);
		TT[25]= LROT(XX[20],10) + F2(XX[24], XX[23], LROT(XX[22], 10)) + M[12] + 0x5a827999;
        XX[25]= LROT(XX[21], 10) + LROT(TT[25], 7);


		T[26]= LROT(X[21],10) + F2(X[25], X[24], LROT(X[23], 10)) + M[0] + 0x5a827999;
        X[26]= LROT(X[22], 10) + LROT(T[26], 12);
		TT[26]= LROT(XX[21],10) + F2(XX[25], XX[24], LROT(XX[23], 10)) + M[0] + 0x5a827999;
        XX[26]= LROT(XX[22], 10) + LROT(TT[26], 12);

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



//bit(B17,17)==bit(X[37],17)£¬bit(B17,17) is independent of X[36]
		A[0]= LROT(X[32],10) + (F3(X[36], X[35], LROT(X[34], 10))&0xf) + (M[9]&0xf) + 0x6ed9eba1;
		B17= LROT(X[33],10) + LROT(A[0],14);
		AA[0]= LROT(XX[32],10) + (F3(XX[36], XX[35], LROT(XX[34], 10))&0xf) + (M[9]&0xf) + 0x6ed9eba1;
		BB17= LROT(XX[33],10) + LROT(AA[0],14);
	
//bit(B21,21)==bit(X[37],21)£¬bit(B21,21) is independent of X[36]
		A[1]= LROT(X[32],10) + (F3(X[36], X[35], LROT(X[34], 10))&0xe0) + (M[9]&0xe0) + 0x6ed9eba1;
		B21= LROT(X[33],10) + LROT(A[1],14);
		AA[1]= LROT(XX[32],10) + (F3(XX[36], XX[35], LROT(XX[34], 10))&0xe0) + (M[9]&0xe0) + 0x6ed9eba1;
		BB21= LROT(XX[33],10) + LROT(AA[1],14);
	
//bit(B2,i)==bit(X[37],i) (i=0,...,12)£¬bit(B2,i) is independent of X[36]		
		A[2]= LROT(X[32],10) + (F3(X[36], X[35], LROT(X[34], 10))&0x7fff0000) + (M[9]&0x7fff0000) + 0x6ed9eba1;
		B2= LROT(X[33],10) + LROT(A[2],14);
		AA[2]= LROT(XX[32],10) + (F3(XX[36], XX[35], LROT(XX[34], 10))&0x7ffe0000) + (M[9]&0x7ffe0000) + 0x6ed9eba1;
		BB2= LROT(XX[33],10) + LROT(AA[2],14);

//bit(B[3],i)==bit(X[38],i)	 (i=17,21)£¬bit(B[3],i) is independent of X[36]	
		A[3]= LROT(X[33],10) + (F3(X[37], X[36], LROT(X[35], 10))&0x1fff) + (M[15]&0x1fff) + 0x6ed9eba1;
		B[3]= LROT(X[34],10) + LROT(A[3],9);
		AA[3]= LROT(XX[33],10) + (F3(XX[37], XX[36], LROT(XX[35], 10))&0x1fff) + (M[15]&0x1fff) + 0x6ed9eba1;
		BB[3]= LROT(XX[34],10) + LROT(AA[3],9);


		difX[31]=X[31]^XX[31];
		difX[32]=X[32]^XX[32];
		difX[33]=X[33]^XX[33];
		difX[34]=X[34]^XX[34];
		difX[35]=X[35]^XX[35];
		difX[37]=X[37]^XX[37];
		difX[38]=X[38]^XX[38];

     if(
		  (bit(B17,17)==1)&&(bit(X[37],17)==1)&&(bit(B21,21)==0)&&(bit(X[37],21)==0)&&(bit(B2,0)==1)&&(bit(X[37],0)==1)
		  &&(bit(B2,1)==1)&&(bit(B2,2)==0)&&(bit(B2,3)==1)&&(bit(B2,4)==1)&&(bit(B2,5)==1)&&(bit(B2,6)==1)&&(bit(B2,7)==1)
		  &&(bit(X[37],1)==1)&&(bit(X[37],2)==0)&&(bit(X[37],3)==1)&&(bit(X[37],4)==1)&&(bit(X[37],5)==1)&&(bit(X[37],6)==1)&&(bit(X[37],7)==1)
		  &&(bit(B2,8)==1)&&(bit(B2,9)==1)&&(bit(B2,10)==1)&&(bit(B2,11)==1)&&(bit(B2,12)==1)
		  &&(bit(X[37],8)==1)&&(bit(X[37],9)==1)&&(bit(X[37],10)==1)&&(bit(X[37],11)==1)&&(bit(X[37],12)==1)
		  &&(bit(B[3],17)==0)&&(bit(B[3],21)==0)&&(bit(X[38],17)==0)&&(bit(X[38],21)==0)		  		  		   
          &&(difX[31]==0x41600208)&&(difX[32]==0x10400)&&(difX[33]==0x41200000)&&(difX[34]==0x80)&&(difX[35]==0x1200000)&&(difX[37]==0x200000)&&(difX[38]==0)
		   )
         
		     num=num+1;
}

			 p("num=%x\n",num);		
}
