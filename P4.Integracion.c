#include<stdio.h>
#include<stdlib.h>
void nuevo();
void tabla(double *, double *, int );
void interval(double *, double *, int , double );
void diferenciacion(double *,double *, int  ,int ,int , double );
void integracion(double *,double *,int ,int ,int , double );

int main()
{
 printf("\n\tINTEGRANTES");
 printf("\n\tAlmanza Centeno Daniel");
 printf("\n\tMaceda P%crez Olivia Yuyu",130);
 printf("\n\tMargarito Flores Briseyda");
 int opc;
  printf("\n\nDesea utilizar la tabla de interpolaci%cn y ajuste: ",162);
  do{
    printf("\n\t1-Si \t2-Ingresar nueva tabla\nOpci%cn: ",162);
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
    printf("\nN%cmero de puntos (m%cs la posici%cn 0): ",163,134,162);
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
    printf("Tama%co de paso (h): ",164);
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
      printf("Ingresa POSICI%cN (i) de intervalo\n a(inferior): ",162);
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
 double integ=0;
 int i, alt;
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
      printf("\n\tIntegraci%cn: %lf",162,((3*h)/8)*integ);
  }else
  {
   if(n%2==0)
    {
     integ=(*(y+0))+(*(y+(n-1)));
     for(i=1;i<=n-2;i++)
     {
      if(i%2==0)
         integ+=2*(*(y+i));
       else
         integ+=4*(*(y+i));
     }
     printf("\nIntegraci%cn: %lf",162,(h/3)*integ);
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
