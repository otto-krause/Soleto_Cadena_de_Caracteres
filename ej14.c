#include <stdio.h>
#include <string.h>
int main(){
  char nombre[20] = "", onombre[20] = "";
  int a,m,d, oa = 2021, om = 13, od = 32;
  int sueldo = 0, osueldo = 0;
  for(int i = 1; i <= 3; i++){
    sueldo = 0;
    printf("ingrese el nombre del empleado %d: ", i);
    scanf("%s", nombre);
    printf("ingrese la fecha de ingreso de %s: ", nombre);
    scanf("%d/%d/%d", &a, &m, &d);
    if(!(m <= 12 && ((m != 2 && d <= 31) || (m == 2 && d <= 29)))){
      printf("fecha invalida");
      continue;
    }
    printf("ingrese el sueldo de %s: ", nombre);
    scanf("%d", &sueldo);
    if (a < oa || ((a == oa && m < om) || (m == om && d < od))){
      oa = a;
      om = m;
      od = d;
      strcpy(onombre, nombre);
      osueldo = sueldo;
    }
  }
  printf("el empleado más antiguo es %s con $%d de sueldo\n", onombre, osueldo);
}
