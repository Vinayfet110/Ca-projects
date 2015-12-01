
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
int ccad,muxd,shiftd,trigd,*sum,*a,*b,*a1,*b1,*cc1,*cc0,*c0,*c1,*t0,*t1,*res,resi,i,j,k,n,s,m,l,t,td,flag,c0f,c0l,c1f,c1l;
long ttd;
float avgd;
void adder();
void setcc0cc1();
void set();
void bits(int *cc0,int *cc1,int *t0,int *t1,int *a,int *b);
int* comp2();
void freemem(){
free(cc0);free(cc1);free(c0);free(c1);free(t0);free(t1);free(a);free(b);free(sum);free(res);
}
void rtshift(int *p,int n){
int i;
shiftd+=2;
trigd+=2;
res[resi]=p[n];
resi--;
for(i=n;i>0;i--){
  p[i]=p[i-1];
}
}
void mul(){
int i=n,j,k;
int pre=0,curr=i;

for(i=n,curr=i,pre=0;i>=0;i--,curr--){
  if(b[curr]==0 && pre==0){
    res[i]=c1[i];
    pre=b[curr];
    rtshift(c1,n);
    continue;
  }
  else if(b[curr]==1 && pre==1){
    res[i]=c1[i];
    pre=b[curr];
    rtshift(c1,n);
    continue;
  }
  else if(b[curr]==0 && pre==1){
    for(j=0;j<=n;j++){
      c0[j]=a[j];
    }
  }
  else if(b[curr]==1 && pre==0){
    c0=comp2(a,n+1);
  }
     muxd+=2;
  setcc0cc1();
  do{
    bits(cc0,cc1,t0,t1,c1,c0);
    flag=0;
    for(k=0;k<=n+1;k++){
      if(cc0[k]==cc1[k]){
	flag=1;
	set();
      }
    }
    if(flag==0){  /*
      t++;
      td+=2;
      ttd+=td;      */
      break;
    }
    else{             /*
      t++;
      td+=2;            */
    }
      ccad+=2;
  }
  while(flag==1);
  adder();
    for(k=0;k<=n;k++){
      c1[k]=sum[k];
    }
    rtshift(c1,n);
    pre=b[curr];
}
}

void adder(){
    ccad+=2;
    for(i=n;i>=0;i--)
      sum[i]=c1[i]^c0[i]^cc1[i+1];
      //printf("\n");
}
void set(){
  for(j=0;j<=n+1;j++){
      t1[j]=cc1[j];
      t0[j]=cc0[j];
    }
}
void bits(int *c0,int *c1,int *t0,int *t1,int *a,int *b){
for(i=n;i>=0;i--){
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
void setcc0cc1(){
    for(i=0;i<=(n+1);i++){
      t1[i]=0;
      t0[i]=0;
      cc1[i]=0;
      cc0[i]=0;
    }
    //printf("\n %d...%d...%d......",t1[n+1],t0[n+1],n);
    t1[n+1]=0;
    t0[n+1]=1;
    cc1[n+1]=0;
    cc0[n+1]=1;
    ccad+=2;
}
int* comp2(int *p,int last){
int i,carry=0,n=last;
int *c0;
//p=(int *)calloc(n,sizeof(int));
c0=(int *)calloc(n,sizeof(int));
for(i=last-1;i>=0;i--){
  if(p[i]==0){
    c0[i]=1;
  }
  else if(p[i]==1){
    c0[i]=0;
  }
}
for(i=last-1;i>=0;i--){
  if(i==last-1){
    if(c0[i]==0){
      c0[i]=1;
    }
    else if(c0[i]==1){
      c0[i]=0;
      carry=1;
    }
  }
  else{
    if(c0[i]==0 && carry==1){
      c0[i]=1;
      carry=0;
    }
    else if(c0[i]==1 && carry==1){
      c0[i]=0;
      carry=1;
    }
  }
}
return c0;
}

void main(){
//int pre=0,curr=i;
int x,y,z,loop=10;
unsigned long totaldelay;
float avgdelay;
//printf("execution begins:");
clrscr();
	     z=3;
  t=0,ttd=0;
 for(z=2;z<=32;z++){
  a=(int *)malloc((z+1)*sizeof(int));
  b=(int *)malloc((z+1)*sizeof(int));
  c1=(int *)malloc((z+1)*sizeof(int));
  c0=(int *)malloc((z+1)*sizeof(int));
  cc1=(int *)malloc((z+2)*sizeof(int));
  cc0=(int *)malloc((z+2)*sizeof(int));
  t1=(int *)malloc((z+2)*sizeof(int));
  t0=(int *)malloc((z+2)*sizeof(int));
  sum=(int *)malloc((z+1)*sizeof(int));
  res=(int *)malloc((z+z+2)*sizeof(int));
  resi=z+z+1;
  ttd=0;
  totaldelay=0;
  n=z;
  //ccad=0,muxd=0,shiftd=0,trigd=0;
  for(x=0;x<loop;x++){
    ttd=0,ccad=0,muxd=0,shiftd=0,trigd=0;
    resi=n+n;
    td=2;
    //a[0]=0;a[1]=1;a[2]=0;a[3]=0;a[4]=1;a[5]=0;a[6]=1;a[7]=1;a[8]=0;a[9]=1;a[10]=1;a[11]=1;//a[12]=1;//a[13]=0;a[14]=1;a[15]=1;a[16]=0;a[17]=1;a[18]=1;a[19]=0;a[20]=0;a[21]=1;a[22]=0;a[23]=1;
    //b[0]=0;b[1]=1;b[2]=1;b[3]=0;b[4]=1;b[5]=1;b[6]=0;b[7]=0;b[8]=1;b[9]=0;b[10]=0;b[11]=1;//b[12]=1;//b[13]=1;b[14]=0;b[15]=0;b[16]=1;b[17]=0;b[18]=0;b[19]=0;b[20]=1;b[21]=0;b[22]=1;b[23]=1;

    for(y=0;y<n+1;y++){
      a[y]=0;
      b[y]=0;
      c0[y]=0;
      c1[y]=0;
      sum[y]=0;
    }
    for(y=0;y<n+2;y++){
      t0[y]=0;
      t1[y]=0;
      cc0[y]=0;
      cc1[y]=0;
      //sum[y]=0;
    }
    t1[z+1]=0;
    t0[z+1]=1;
    cc1[z+1]=0;
    cc0[z+1]=1;
    for(y=0;y<=n+n+1;y++)
      res[y]=0;
    for(y=1;y<n+1;y++){
      a[y]=((rand())%2);
      b[y]=((rand())%2);
    }
    a[0]=0;
    b[0]=0;
    //printf("\n");
    mul();
    resi++;
    for(i=n;i>=0;i--){
      res[resi]=sum[i];
      resi--;
    }
    ttd=ccad+shiftd+trigd+muxd;
    totaldelay+=ttd;
    //printf("\nfinal delay for %dth bit till %dloop=%ld",n,x,totaldelay);
  }
  //printf("\n");
  //printf("\ntotal delay for %dth bit number is d",n);
  freemem();
  //totaldelay+=ttd;
  avgdelay=(float)totaldelay/loop;
  //printf("\n");
  printf("\ntotal delay for %dth bit number = %lud and avg delay = %f",z,totaldelay,avgdelay);
  getch();
 }
 getch();
}

