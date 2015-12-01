#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
int k,*a,*b,*c0,*c1,*t0,*t1,i,j,n,s,m,l,td,flag;
long ttd;  // variable to store delay
float avgd;  // variable to store average delay

void set(){
  for(j=0;flag==1 && j<=n;j++){

      t1[j]=c1[j];
      t0[j]=c0[j];
    }  // Set function is used to store all the carryout bits in a temporary array, which acts as carry-in bits
}
void bits(int *c0,int *c1,int *t0,int *t1){
//// bit function checks for all conditions possible and generates carry-out bits

for(i=n-1;i>=0;i--){

    s=a[i]+b[i];
    if(s==0){
      c0[i]=1;
      c1[i]=0;

    }
    else if(s>1){
      c0[i]=0;
      c1[i]=1;
    }
    else if(s==1){
      if(t0[i+1]==t1[i+1]){
	c0[i]=0;
	c1[i]=0;
      }
      else{
	m=s+t1[i+1];
	if(m>1){
	  c0[i]=0;
	  c1[i]=1;

	}
	else if(m<=1){
	  c0[i]=1;
	  c1[i]=0;

	}
      }
    }

  }
}
void main(){

clrscr();
for(n=2;n<=48;n++){
  ttd=0;
  a=(int *)malloc(n*sizeof(int)); // creates memory for the array to store the variable no of bits
  b=(int *)malloc(n*sizeof(int));
  c1=(int *)malloc((n+1)*sizeof(int));
  c0=(int *)malloc((n+1)*sizeof(int));
  t1=(int *)malloc((n+1)*sizeof(int));
  t0=(int *)malloc((n+1)*sizeof(int));

   for(l=0;l<1000;l++){		//for looping 1000
   td=2;   //2 because we need to add 2d delay at the end when all the carries get finalized.
    for(i=0;i<n;i++){
      a[i]=((rand())%2); // random bits will be stored in a[i]
      b[i]=((rand())%2);
    }


    for(i=0;i<n;i++){
      t1[i]=0; // initializing all the bits to 0
      t0[i]=0; // initializing all the bits to 0
      c1[i]=0;
      c0[i]=0;
    }
    t1[n]=0; // finalizing the carry –in bit, because the incoming carry will always be 0 so t1[n]=0
    t0[n]=1;
    c1[n]=0;
    c0[n]=1;

  do{
    bits(c0,c1,t0,t1); // control goes to the function “bits()” and executes the logic there and returns
    flag=0; // flag=0 means the carry outs are finalized
    for(k=0;k<=n;k++){
      if(c0[k]==c1[k]){
		flag=1; // carry outs are not finalized
	set(); // calls the function “set()”
      }
    }

    if(flag==0){
      td+=2; // calculation of delay for each cycle when bits are finalzied
      ttd+=td; // calculation of total delay
      break;
    }
    else{
      td+=2; //calculation of delay when bits are not finalized
    }
  }
  while(flag==1);

  }


  avgd=(float)ttd/1000; // calculation of average delay
  printf("\ntotal delay for %dth bit number is %ld and average delay is %f",n,ttd,avgd);
}
getch();
}


