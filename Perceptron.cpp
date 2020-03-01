#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void Perceptron(){
 srand(time(NULL));
float intervalos[] = {-0.98,-0.87,-0.65,-0.75,0.45,0.95,-0.32,-0.28,-0.11,-0.06,0.023,0.23,0.23,0.46,0.67,0.78, 0.75,0.82,0.98};
 float aprendizaje[] = {0.023,0.23,0.233,0.467,0.675,0.788, 0.752,0.823,0.987};
 float Umbral,defumbral,factor;
 int i;
 
 
//Datos que se usaran para el entrenamiento del perceptron.
 int x1[] = {-1,1,-1,1,-1,1};
 int x2[] = {1,-1,-1,1,1,-1};
 int x3[] = {1,1,-1,-1,-1,1};
 int x4[] = {1,1,1,-1,1,1};
 int x5[] = {1,1,1,1,1,1};
 int x6[] = {1,1,1,1,1,1};

 int result[] = {1,1,-1,-1,-1,1};
 float w[6] = {intervalos[rand() % 18],intervalos[rand() % 18],intervalos[rand() % 18],intervalos[rand() % 18],intervalos[rand() % 18],intervalos[rand() % 18]};

 factor = intervalos[rand() % 18];
 Umbral = intervalos[rand() % 18];
 defumbral = 1;

 int verdad = 0;
 int op;
 int cont = 0;
 int n = 0;
//////////// ENTRENAMIENTO DEL PERCEPTRON;
 while(verdad == 0){
  n++;
  for(i=0;i<6;i++){
   op = ((x1[i]*w[0])+(x2[i]*w[1])+(x3[i]*w[2])+(x4[i]*w[3])+(x5[i]*w[4])+(x6[i]*w[5])) + (defumbral*Umbral);
   if(op >= 0){
    op = 1;
   }
   else{
    op = -1;
   }
   if(op != result[i]){
    w[0] = w[0] + (6*factor)*(x1[i]*result[i]);
    w[1] = w[1] + (6*factor)*(x2[i]*result[i]);
    w[2] = w[2] + (6*factor)*(x3[i]*result[i]);
    w[3] = w[3] + (6*factor)*(x4[i]*result[i]);
    w[4] = w[4] + (6*factor)*(x5[i]*result[i]);
    w[5] = w[5] + (6*factor)*(x6[i]*result[i]);
    
    Umbral = Umbral + (6*factor)*(defumbral*result[i]);
   }
  }
  for(i=0;i<6;i++){
   op = ((x1[i]*w[0])+(x2[i]*w[1])+(x3[i]*w[2])+(x4[i]*w[3])+(x5[i]*w[4])+(x6[i]*w[5])) + (defumbral*Umbral);
   if(op == result[i]){
    cont++;
   }
   if(cont == 6){
    verdad = 1;
   }
  }
  if(n > 900000000){
   printf("[!] Demasiadas epocas realizadas!\n");
   printf("[!] Intente nuevamente con otros pesos.\n");
   exit(1);
  }
 }
/////////// MOSTRAR RESULTADOS FINALES
 //system("clear");
 printf("\n[*] FINALIZANDO ENTRENAMIENTO...\n");
 printf("[*] PERCEPTRON SIMPLE [ENTRENADO]\n");
 printf("\n--------------- DATOS FINALES --------------------------------\n\n");
 printf("[*] Total de epocas: (%i)\n",n);
 printf("[*] Peso 1 w[1]\t\t--> %2.2f\n",w[0]);
 printf("[*] Peso 2 w[2]\t\t--> %2.2f\n",w[1]);
 printf("[*] Peso 3 w[3]\t\t--> %2.2f\n",w[2]);
 printf("[*] Peso 4 w[4]\t\t--> %2.2f\n",w[3]);
 printf("[*] Peso 5 w[5]\t\t--> %2.2f\n",w[4]);
 printf("[*] Peso 6 w[6]\t\t--> %2.2f\n",w[5]);
 printf("[*] Umbral(Polarizacion)\t\t--> %2.2f\n",Umbral);
 printf("\n\n--------------- VERFICIACION DE ENTRENAMIENTO ------------------\n\n");
 for(i=0;i<6;i++){
  op = ((x1[i]*w[0])+(x2[i]*w[1])+(x3[i]*w[2])+(x4[i]*w[3])+(x5[i]*w[4])+(x6[i]*w[5])) + (defumbral*Umbral);
  if(op >= 0){
   op = 1;
  }
  else{
   op = -1;
   }
  printf("\n[*] Entradas: (%2i,%2i,%2i,%2i,%2i,%2i) --> Salida: %2i",x1[i],x2[i],x3[i],x4[i],x5[i],x6[i],op);
  if(op != result[i]){
   //system("clear");
   printf("\n[!] Demasiadas epocas realizadas!\n");
   printf("[!] Intente nuevamente con otros pesos.\n");
   exit(1);
   Perceptron();
   }
 }
}
int main(int argc, char **argv)
{
 Perceptron();
 return 0;
}

