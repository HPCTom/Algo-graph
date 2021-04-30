#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>



int main(int argc, char * argv[])
{
  int taille = 6;

  int M[36] = {0, 6, 10, 5, 3, 7, 6, 0, 12, 11, 14, 8, 10, 12, 0, 3, 12, 10, 5, 11, 3, 0, 4, 6, 3, 14, 12, 4, 0, 4,7, 8, 10, 6, 4, 0};

  int passe[6] = {1,0,0,0,0,0};
  int start = 0;
  printf("\nDépart au noeud %d\n\n",start);
  int depart = 0;
  int dist = 0;
  int min,min2,ind = 0;


  for(int nbr_noeud = 0; nbr_noeud < taille; nbr_noeud++){

    //calcul la plus petite distance
    int n = 0;
    for(int i = depart; i < depart+1; i++){
      for(int j = 0; j < 6; j++){
        int offset = i * 6 + j;
        if(n == 0 && passe[j] == 0){
          min = M[offset];
          ind = j;
          n++;
        }
        if(passe[j] == 0){
          min2 = M[offset];
          if(min2<min){
            min  = min2;
            ind = j;
          }
        }
        else{
          continue;
        }
      }
    }
    passe[ind] = 1;
    if(nbr_noeud<taille-1){
      dist += min;
      printf("noeud = %d , poid = %d\n",depart,min);
      depart = ind;
    }
    else{
      dist += M[start*6+ind];
      printf("noeud = %d , poid = %d\n",depart,M[start*6+ind]);
      depart = start;
      printf("\nRetour au noeud %d\n\n",depart);
    }
}
    printf("distance parcouru = %d\n",dist);
  return 0;
}
