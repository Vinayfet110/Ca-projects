#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
int *sum,*a,*b,*c0,*c1,*t0,*t1,i,j,k,n,s,m,l,t,td,flag; // declaration of variables used in the program
long ttd; // variable to store total time delay
float avgd; // variable to store average delay
void adder(){
    for(i=n-1;i>=0;i--){
      sum[i]=a[i]^b[i]^c1[i+1]; // XOR of a ,b and carry –in, to calculate the sum
      
    }
    for(i=0;i<n;i++)
      printf("%d ",sum[i]);
}
void set(){
// Set function is used to store the carryout bits in one cycle in a temporary array which acts as a carry in for the  bits in next clock cycle.
  for(j=0;flag==1 && j<=n;j++){
      t1[j]=c1[j]; // As mentioned in the above comments carry out is being stored in temp array
      t0[j]=c0[j];
    }
}
void bits(){
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
  n=24,t=0;
  a=(int *)malloc(n*sizeof(int));
  b=(int *)malloc(n*sizeof(int));
  c1=(int *)malloc((n+1)*sizeof(int));
  c0=(int *)malloc((n+1)*sizeof(int));
  t1=(int *)malloc((n+1)*sizeof(int));
  t0=(int *)malloc((n+1)*sizeof(int));
  sum=(int *)malloc((n+1)*sizeof(int));

  td=2; //Initializing to 2d, because at the last cycle, when all the carry bits get finalized we need to add 2d.
  a[0]=1;a[1]=0;a[2]=1;a[3]=0;a[4]=0;a[5]=1;a[6]=0;a[7]=0;a[8]=1;a[9]=1;a[10]=0;a[11]=0;a[12]=1;a[13]=0;a[14]=1;a[15]=1;a[16]=0;a[17]=1;a[18]=1;a[19]=0;a[20]=0;a[21]=1;a[22]=0;a[23]=1;
  b[0]=0;b[1]=1;b[2]=0;b[3]=1;b[4]=0;b[5]=1;b[6]=1;b[7]=1;b[8]=1;b[9]=0;b[10]=0;b[11]=0;b[12]=0;b[13]=1;b[14]=0;b[15]=0;b[16]=1;b[17]=0;b[18]=0;b[19]=0;b[20]=1;b[21]=0;b[22]=1;b[23]=1;

    for(i=0;i<n;i++){
      t1[i]=0;
      t0[i]=0;
      c1[i]=0;
      c0[i]=0;
    }
    t1[n]=0;
    t0[n]=1;
    c1[n]=0;
    c0[n]=1;
    printf("a :");
    for(k=0;k<n;k++){
      printf("%d ",a[k]);
    }
    printf("\nb :");
    for(k=0;k<n;k++){
      printf("%d ",b[k]);
    }
    printf("\n\n");
  do{
    printf("\nc1 values :");
    for(k=0;k<=n;k++){
      printf("%d ",c1[k]);
    }
    printf("\nc0 values :");
    for(k=0;k<=n;k++){
      printf("%d ",c0[k]);
    }
    printf("\nat cycle %d  :",t);
    printf("\n");
    bits();
    flag=0;
    for(k=0;k<=n;k++){
      if(c0[k]==c1[k]){
       //printf("value at %d of c0 is %d and c1 is %d\n",j,c0[j],c1[j]);
       flag=1;
        set();
      }
    }
    If(t=3){   //If this line and the next line “getch()” is commented, all the 8cycles will be printed, but the only the output that fits the screen will be displayed i.e first 3 cycles will not be displayed because it doesn’t fit on the screen, so  in order to view even the first three cycles, the statements “if(t=3){getch()} should not be commented. If we wish to rest of the 8 cycles comment the statements “if(t=3){getch()}”
Getch();
}
    if(flag==0){
      t++;
      td+=2;
      ttd+=td;
      break;
    }
    else{
      t++;
      td+=2;
    }
  }
  while(flag==1);

  avgd=(float)ttd/1000;
  printf("\nfinal result c1: ");
  for(i=0;i<=n;i++){
    printf("%d ",c1[i]);
  }

  printf("\nfinal result c0: ");
  for(i=0;i<=n;i++){
    printf("%d ",c0[i]);
  }

  printf("\nat cycle %d ",t);
  printf("final sum is :");
  adder();
  printf("\n");
  printf("\ntotal delay for %dth bit number is %dd",n,td);

getch();
}
