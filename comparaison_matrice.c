#include <stdio.h>
#include <stdlib.h>


int ** creation_poids(void){  //cette fonction renvoi un tableau de tableau, cest un tableau contenant les vecteur de poids

int poids1[64]={1,1,-1,1,-1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,-1,1,-1,-1,1,1,1,1,-1,1,-1,1,1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,1,1}; 
int poids2[64]={1,-1,1,1,1,-1,-1,1,-1,1,-1,1,-1,1,1,1,1,1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,-1,1,1,-1,1,-1,1,1,1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1}; 
int poids3[64]={1,-1,1,1,1,-1,-1,1,-1,1,-1,1,-1,1,1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,1,1,1,1,-1,1,-1,1,1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,1};   
	
	int **tab_poids;
	tab_poids = (int**)malloc(3*sizeof(int*));

	tab_poids[0]=poids1;
	tab_poids[1]=poids2;
	tab_poids[2]=poids3;
	
	/*for(int i = 0; i < 3; i++) {
    	for(int j = 0; j < 63; j++) {
        	printf("%d ", tab_poids[i][j]);
    	}
    	printf("\n");
	}*/

	return tab_poids;
}


float comparaison (int matrice1[] , int matrice2[]){  //cette fonction compare renvoi les score de comparaison de 2 vecteurs

	float score =0;
	float score_max =0; //score max est l'addition de tout les positif des poids


	for(int i=0; i<64; i++){

			score+=(matrice1[i]*matrice2[i]); //score image
			if(matrice1[i]>0) //poids
				score_max+=matrice1[i]; //score poids	
	}

		/*printf("score = %.2f \n",score);
		printf("score max poids = %.2f \n",score_max);
		printf("score final = %.2f\n",(score/score_max));*/
	//printf(" score: %.2f \n", (float)score);
	//printf(" max: %.2f \n", (float)score_max);
	return score/score_max;
}


//ce que je dois faire
//je compare mon num a tout les matrices de poids et le meilleurs je lui renvoi 0 si score <0 et 1 si score >0 (vecteur)
//les matrices de poids sont celle faite par boris
void comparaison_poids(int matrice[], int ** tab_poids){ //cette fonction prends un arguments le "dessin vecteur" a comparer et tout les poids (le tab_poids)
	float resultat[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //initilisation du vecteur que je vais renvoyer a la fin pour les score
	for(int i=0;i<16;i++){ //je parcours resulat pour la remplir
		//printf("compa %.2f\n",(comparaison(matrice,tab_poids[1])));
		resultat[i]=(comparaison(matrice,tab_poids[1])>=0)?1:0; //je remplis le tableau si comparaison est >0 je mets un 1 dans le tableau[i] sinon un 0 
	}								//il faudrait remplacer 1 par i pour parcourir les differents vecteur de poids de chaque neuronne. sinon tout est pareil  //ICI EST LE PROBLEME// !!!!!!!!!
	printf("comparaison des poids :");
	for(int i = 0; i < 16; i++) {
        	printf("%d ", resultat[i]); //jaffiche juste le vecteur de sortie
    	}
    	printf("\n");

}



int main(void){

int matrice1[64]={-4,+6,+3,-4,+2,+2,+2,-4,-8,0,+2,-1,-8,+9,-6,+9,-7,-0,+6,+6,+9,-5,+6,+5,+2,+8,+6,0,+5,-7,+9,-0,+4,-1,+3,-4,+3,+7,+0,+2,+9,-7,+8,-1,-3,-5,-2,+7,-6,+3,-3,+5,+4,-1,+9,+9,+9,-4,-3,+7,+2,+8,-2}; //vecteur de poids au hasard
int matrice2[64]={0,1,0,1,0,1,1,0,1,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,1,0,0,1,0,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1}; //vecteur representant le dessin d'un numero

	/*float a;
	a=comparaison(matrice1,matrice2);
	printf("score_final = %.2f \n",a);
	//creation_poids();*/
	comparaison_poids(matrice2,creation_poids()); //je lance la fonction qui compare un chiffre (matrice2) a tout les vecteurs de poids creation poids renvoi un tableau avec les vecteurs de poids
}


