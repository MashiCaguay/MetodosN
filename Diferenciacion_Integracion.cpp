#include<stdio.h>
#include<stdlib.h>
void nuevo();
void tabla(double *, double *, int );
void interval(double *, double *, int , double );
void diferenciacion(double *,double *, int  ,int ,int , double );
void integracion(double *,double *,int ,int ,int , double );

int main()
{
 int opc;
  printf("Desea utilizar la tabla de interpolaci%cn y ajuste: ",162);
  do{
    printf("\n1-S%c 2-Ingresar nueva tabla\nOpci%cn: ",161,162);
    scanf("%d",&opc);
  }while(opc!=1&&opc!=2);
  switch(opc)
  {
    case 1:
      printf("En proceso...");
      break;
    case 2:
      nuevo();
      break;
 }
}
void nuevo()
{
  int n,i;
  do{
    printf("N%cmero de puntos: ",163);
    scanf("%d",&n);
  }while(n<=3);
  double num1[n], num2[n];
  double *x=num1,*y=num2;
  tabla(x,y, n);
}

void tabla(double *x, double *y, int n)
{
  int i, ban=1;
  double h;
    printf("Valor inicial x0: ");
    scanf("%lf",(x+0));
    printf("Tama%co de paso (h): ",162);
    scanf("%lf",&h);
    printf("\ti \tx \t           f(x)\n");
    for(i=0;i<n;i++)
    {
      (x+(i+1));
      *(x+(i+1))=*(x+i)+h;
      printf("\t%d \t%lf \t",i,*(x+i));
      scanf("%lf", (y+i));
    }
    interval(x,y,n,h);
}

void interval(double *x, double *y, int n, double h)
{
    int sup, inf,alt=0;
    do{
      printf("Ingresa POSICION (i) de intervalo\n a(inferior): ");
      scanf("%d",&inf);
    }while(inf<0);
    do{
      printf(" b(superior): ");
      scanf("%d",&sup);
    }while(sup>(n-1));
    diferenciacion(x,y,n,sup,inf,h);
}

void diferenciacion(double *x,double *y,int n,int sup,int inf, double h)
{
    int i;
    double deriv[n];
    for(i=inf;i<sup;i++)
      deriv[i]=(*(y+(i+2))-*(y+i))/(2*h);
    for(i=inf;i<sup-1;i++)
    {
     printf("\n\tf'(%d)  \t%lf",i+1,deriv[i]);
    }
    integracion(x,y,n,sup,inf,h);
}

void integracion(double *x,double *y,int n,int sup,int inf, double h)
{
 double integ=0,integ1=0,integ2=0;
 int i, m=0, alt;
 m=n%2;
 if(n==3)
  {
      integ=(*(y+0))+(*(y+(n-1)));
      for(i=1;i<n-1;i++)
      {
        if(i%3==0)
           integ+=2*(*(y+i));
        else
           integ+=3*(*(y+i));
      }
      printf("\nIntegraci%cn: %lf",162,((3*h)/8)*integ);
  }else
  {
   if(n%2==0)
    {
     integ1=(*(y+0))+(*(y+3));
     for(i=1;i<=2;i++)
     {
        integ1+=3*(*(y+i));
     }
     for(i=4;i<=n-4;i++)
     {
      if(i%2==0)
         integ1+=4*(*(y+i));
       else
         integ1+=2*(*(y+i));
     }
     integ1*=(h/3);

     for(i=n-4;i<=n-2;i++)
     {
      if(i%2==0)
         integ2+=4*(*(y+i));
       else
         integ2+=2*(*(y+i));
     }
     integ2+=(*(y+(n-1)));
     integ2*=((3*h)/8);
     printf("\nIntegraci%cn: %lf",162,integ1+integ2);
    }
    }
    do
    {
        printf("\n\nDesea ingresar otro intervalo: ");
        printf("\n\t0-No \t1S%c\n",161);
        scanf("%d",&alt);
    }while(alt!=0&&alt!=1);
    if(alt==0)
        exit(0);
    else
     interval(x,y,n,h);
}
