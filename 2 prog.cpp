#include<stdio.h> 
#include<math.h> 

#define limit_Nmax 1e7 //Максимальное количество точек
#define limit_a 1e6 //Максиальный радиус круга
#define min_a 100 //Начальный радиус

double circle(double, double); //Выдает квадрат y в зависимости от координаты Х и радиуса круга.

int main() 
{ 

double x,y,Pi; 
long long int a=min_a;//сторона квадарата
int i=0;//Счетчик 
double Ncirc=0;//Количество точек, попавших в круг 
double Nmax=a; //Общее количество точек
while (a<limit_a)  //Перебор  значений радиуса
{ 
Nmax=a; 
 while (Nmax<=limit_Nmax) // Перебор значения количества точек
 { 
 Ncirc=0; i=0; //обнуляторы
    while (i<Nmax) 
    { 
    x = a*(random() % 1000)/1000.;  //Рандомный Х с 3 знаками после запятой
    y = a*(random() % 1000)/1000.;  //Рандомный Y с 3 знаками после запятой
        if (y*y<=circle(x,a))  //Условие принадлежности точки к кругу
        { 
        Ncirc++; 
        } 
    i++; 
    } 

 Pi=(Ncirc/Nmax)*4; 
 
 printf("\n%lld,%.0f,%f",a,Nmax,Pi); 
 
 Nmax *= 2; 

 } 
a*=2; 
} 

} 

double circle(double x, double radius) 
{ 
double y=radius*radius-x*x; 
return y; 
}