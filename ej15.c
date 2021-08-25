#include <stdio.h>
#include <string.h>

int edad(int f[]){
  int e = 2020 - f[0];
  if(f[1] < 8 && f[2] <= 25){
    e++;
  }
  return e;
}

int *tform(char s[]){
 int len = strlen(s);
  s[len] = '/';
  char buf[11] = "";
  static int fecha[2];
  int c = 0, t = 0;
  for(int i = 0; i <= len; i++){
    if(s[i] != '/'){
      buf[t] = s[i];
      t++;
    }
    else {
      fecha[c] = atoi(buf);
      strcpy(buf, "\r\r\r\r\r\r\r\r\r");
      t = 0;
      c++;
    }
  }
  return fecha;
}

int verif(int f[]){
  if(!(f[0] < 2021 || (f[0] == 2021 && f[1] < 9)))
    return 1;
  if(f[1]>=1 && f[1]<=12){
    if((f[2]>=1 && f[2]<=31) && (f[1]==1 || f[1]==3 || f[1]==5 || f[1]==7 || f[1]==8 || f[1]==10 || f[1]==12))
      return 1;
    else if((f[2]>=1 && f[2]<=30) && (f[1]==4 || f[1]==6 || f[1]==9 || f[1]==11))
      return 1;
    else if((f[2]>=1 && f[2]<=28) && (f[1]==2))
      return 1;
    else if(f[2]==29 && f[1]==2 && (f[0]%400==0 ||(f[0]%4==0 && f[0]%100!=0)))
      return 1;
    else
      return 0;
  }
  else{
    return 0;
  }
}
int main(){
  char n[20] = "";
  char f[11] = "";

  char fechas[3][11];
  char nombres[3][20];

  for(int i = 1; i <= 3; i++){
    printf("ingrese el nombre de la persona %d: ", i);
    scanf("%s", n);
    printf("ingrese la fecha de nacimiento de %s: ", n);
    scanf("%s", f);
    if(!verif(tform(f))){
      printf("fecha invalida\n");
      i--;
      continue;
    }
    strcpy(fechas[i - 1], f);
    strcpy(nombres[i - 1], n);
  }
  for(int i = 0; i < 3; i++){
    if(edad(tform(fechas[0])) > edad(tform(fechas[1])) && edad(tform(fechas[0])) > edad(tform(fechas[2]))){
      printf("Nombre: %s, Edad: %d, Fecha de nacimiento: %s\n", nombres[0], edad(tform(fechas[0])), fechas[0]);
      strcpy(fechas[0], "2036/12/31");
    }
    else if(edad(tform(fechas[1])) > edad(tform(fechas[0])) && edad(tform(fechas[1])) > edad(tform(fechas[2]))){
      printf("Nombre: %s, Edad: %d, Fecha de nacimiento: %s\n", nombres[1], edad(tform(fechas[1])), fechas[1]);
      strcpy(fechas[1], "2036/12/31");
    }
    else if(edad(tform(fechas[2])) > edad(tform(fechas[0])) && edad(tform(fechas[2])) > edad(tform(fechas[1]))){
      printf("Nombre: %s, Edad: %d, Fecha de nacimiento: %s\n", nombres[2], edad(tform(fechas[2])), fechas[2]);
      strcpy(fechas[2], "2036/12/31");
    }
  }
}
