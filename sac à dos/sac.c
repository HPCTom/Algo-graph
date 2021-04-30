#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <unistd.h>

int sum(int taille){ // Calcul la somme des 2^n avec n<=taille
  int t = 0;
  for(int i = 1; i < taille+1; i++){
    t += pow(2,i);
  }
  return t;
}




void sac(double* v, double* p, double* V, double* P, double V_max,int taille, int taille_A){

  /// Calcul l'arbre
  int pere = 0;
  int fils = 0;
  int tab_pere[taille_A];
  for(int i = 0; i < taille; i++){
    int k = 0;
    for(int j = pow(2,i+1)-2; j < pow(2,i+2)-2; j++){
      if(k%2 == 0 && k==0){
        pere = pow(2,i+1)-pow(2,i)-2;
        tab_pere[j] = pere;
        tab_pere[j+1] = pere;
        V[j+1] = V[pere];
        V[j] = V[pere]+v[i];
        P[j+1] = P[pere];
        P[j] = P[pere]+p[i];
      }
      else if(k%2 == 0){
        pere = pere+1;
        tab_pere[j] = pere;
        tab_pere[j+1] = pere;
        V[j+1] = V[pere];
        V[j] = V[pere]+v[i];
        P[j+1] = P[pere];
        P[j] = P[pere]+p[i];
        }
      k++;
    }
  }

  /// Trouve la plus grande valeur inféreiure à V_max dans les feuilles avec le poid le plus grand
  int indice_min;
  double min = 0;
  double poids = 0;
  for(int i = taille_A-pow(2,taille); i<taille_A;i++){
    if(V[i] <= V_max && V[i] > min){
      if(P[i] > poids){
        poids = P[i];
        min = V[i];
        indice_min = i;
      }
    }
  }

  /// Retrouve le chemin de la feuille déterminée juste avant
  pere = tab_pere[indice_min]; // indice du pere de la feuille
  fils = indice_min; // indice de la feuille
  int cpt = taille;
  while(cpt > 0){
    if(V[pere] == V[fils]){
      if (cpt == 1){
        printf("Le %der n'est pas présent dans le sac...\n",cpt);
      }
      else{
      printf("Le %dième n'est pas présent dans le sac...\n",cpt);
    }
    }
    else{
      if (cpt == 1){
        printf("Le %der est présent dans le sac!!!\n",cpt);
      }
      else{
        printf("Le %dième est présent dans le sac!!!\n",cpt);
      }
    }
    fils = pere;
    pere = tab_pere[pere];
    cpt--;
  }


}




int main(int argc, char * argv[])
{
  int taille = 3;
  double v[3] = {1.0, 6.0, 10.0};
  double p[3] = {50.0,76.0,45.0};
  double V_max = 15.0;
  int taille_A = sum(taille);

  double *V = (double*)calloc(taille_A, sizeof(double));
  double *P = (double*)calloc(taille_A, sizeof(double));

  sac(v,p,V,P,V_max,taille,taille_A);

  return 0;
}
