#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//gcc -o main.exe main.c



int main (){
	FILE *arq;
	arq = fopen("teste2.json", "r");
	
	int count=0;
	
	char aux;
	int transic[50][2];
	int estads=0,alfabet=0,transis=0,inin=0,fin=0;
	int i = 0;
	
	
	
	//passa o arquivo ate chegar no primeiro '['
	do{
		aux = fgetc(arq);
		printf("%c",aux);
	}while(aux != '[');
	
	//passa o arquivo ate chegar no segundo '['
	do{
		aux = fgetc(arq);
		printf("%c",aux);
	}while(aux != '[');
	
	//contar a quantidade de estados
	aux = fgetc(arq);
	do{
		aux = fgetc(arq);
		printf("%c",aux);
		if(aux == ','){
			estads++;
		}
	}while(aux != '[');
	
	//conta a quantidade de simbulos do alfabeto
	do{
		aux = fgetc(arq);
		printf("%c",aux);
		if(aux == ','){
			alfabet++;
		}
	}while(aux != '\n');
	
	
	
	//conta a quantidade de transicoes
	do{
		aux = fgetc(arq);
		printf("%c",aux);
	}while(aux != '[');
	do{
		aux = fgetc(arq);
		printf("%c",aux);
		if(aux =='['){
			count++;
		}
	}while(aux != '[');
	do{
		do{
			aux = fgetc(arq);
			printf("%c",aux);
			if(aux =='['){
				count++;
			}
			if(aux ==']'){
				count--;
			}
		}while(aux != '[');
		transis++;
	}while(count>0);
	
	
	
	
	//conta os estados iniciais
	do{
		aux = fgetc(arq);
		printf("%c",aux);
		if(aux == ','){
			inin++;
		}
	}while(aux != '\n');
	
	
	//conta os estados finais
	do{
		aux = fgetc(arq);
		printf("%c",aux);
		if(aux == ','){
			fin++;
		}
	}while(aux != '\n');
	fin++;

	
	//termina o arquivo
	do{
		aux = fgetc(arq);
		printf("%c",aux);

	}while(aux != '}');
	fclose(arq); //Fecha o arquivo
	
	
	char estados[estads][50], alfabeto[alfabet][50], iniciais[inin][50], finais[fin][50];
	char transicao[transis][50];
	int remover[estads];
	
	
	arq = fopen("teste.json", "r");
	
	
	
	//passa o arquivo ate chegar no primeiro '['
	do{
		aux = fgetc(arq);
	}while(aux != '[');
	
	//passa o arquivo ate chegar no segundo '['

	do{
		aux = fgetc(arq);
	}while(aux != '[');
	
	//contar a quantidade de estados
	
	//contar a quantidade de estados
	aux = fgetc(arq);
	do{
		aux = fgetc(arq);
	}while(aux != '[');
	
	//conta a quantidade de simbulos do alfabeto
	do{
		aux = fgetc(arq);
	}while(aux != '[');
		
		
	
	int j =0,x;
	aux = fgetc(arq);
	aux = fgetc(arq);
	aux = fgetc(arq);
	aux = fgetc(arq);
	aux = fgetc(arq);
	aux = fgetc(arq);
	aux = fgetc(arq);
		
	for(x=0;x<transis;x++){

		fscanf(arq, "%d %c %c %c %c %c %c %c %d",
		&transic[x][0], &aux, &aux, &aux, &transicao[x][0], &aux, &aux, &aux, &transic[x][1]);
		transicao[x][1] = '\0';
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
	}
	
	
	
	
	for(i=0;i<inin;i++){
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
		iniciais[i][0] = aux;
		iniciais[i][1] = '\0';
		aux = fgetc(arq);
	}
	
	
	do{
		aux = fgetc(arq);
	}while(aux != '[');
	
	
	for(i=0;i<fin;i++){

		aux = fgetc(arq);
		aux = fgetc(arq);
		
		finais[i][0] = aux;
		finais[i][1] = '\0';
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
	}
	
	do{
		aux = fgetc(arq);
	}while(aux != '[');
	
	
	aux = fgetc(arq);
	for(i=0;i<estads;i++){
		aux = fgetc(arq);
		
		remover[i] = atoi(&aux);
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
		aux = fgetc(arq);
	}
	
	fclose(arq);
	
	
	
	char ER[100];
	//int n =9;

	
	/*
	 transic[50][2];
	int estads=0,alfabet=0,transis=0,inin=0,fin=0;
	
	estados[estads][50], alfabeto[alfabet][50], iniciais[inin][50], finais[fin][50];
	char transicao[transis][50];
	int remover[estads];
	
	
	*/
	j=0;
	for(i=transis;i<inin+transis;i++){
		transic[i][0] = 111;
		transic[i][1] = atoi(iniciais[j]);
		
		transicao[i][0] = '#';
		transicao[i][1] = '\0';
		
		j++;
	}
	transis = transis+inin;
	
	j=0;
	for(i=transis;i<fin+transis;i++){
		transic[i][0] = atoi(finais[j]);
		transic[i][1] = 999;
		
		transicao[i][0] = '#';
		transicao[i][1] = '\0';
		
		j++;
	}
	transis = transis+fin;

	int n = transis-1;
	//juntar duas transiçoes que partem a chgam ao mesmo lugar
	for(i=0; i<transis;i++){
		for(j=0; j<i;j++){

			if((transic[i][0] == transic[j][0]) && (i != j) && (transic[i][1] == transic[j][1]) && (transicao[i][0] != '#')){
				
				n++;
				
				
				transic[n][0] = transic[i][0];
				transic[n][1] = transic[j][1];
				transicao[n][0] = transicao[i][0];
				transicao[n][1] = '+';
				transicao[n][2] = transicao[j][0];
				transicao[n][3] = '\0';

				transic[i][0] = '#';
				transic[j][0] = '#';

			}
			
		}	
		
	}
	
	
	int transicaux[50][2],parent=0;
	int newtransic[50][2];
	char newtransicao[50];
	aux = n;
	x=0;
	char transicao_aux[50][50];
	int k;
	
	int q,eliminar;
	for(q=0;q<estads;q++){
		eliminar = remover[q];
		x=0;
		newtransicao[0] = '\0';
		for(i=0; i<n+1;i++){
			if(transic[i][0] == eliminar || transic[i][1] == eliminar){
				
				transicaux[x][0] = transic[i][0];
				transicaux[x][1] = transic[i][1];
				
				strcpy(transicao_aux[x], transicao[i]);
				printf("Eliminar: ");
				printf("%d ",transicaux[x][0]);
				printf("%s ",transicao_aux[x]);
				printf("%d \n",transicaux[x][1]);
				
				if(transicaux[x][0] == transicaux[x][1]){
					strcat(transicao_aux[x], "*");
					strcat(newtransicao, transicao_aux[x]);
					}
				else if(transicao_aux[x][0] != '#'){
					strcat(newtransicao, "(");
					strcat(newtransicao, transicao_aux[x]);
					strcat(newtransicao, ")");	
				}
				x++;
				transic[i][0] = '#';
				transic[i][1] = '#';
			}
		}
		

		i=0;
		
		for(j=0;j<x;j++){
			if(transicaux[j][0] != eliminar){
				newtransic[i][0] = transicaux[j][0];
				for(k=0;k<x;k++){
					if(transicaux[k][1] != eliminar){
						newtransic[i][1] = transicaux[k][1];
						printf("Nova Trancicao: ");
						printf("%d - %d\n",newtransic[i][0],newtransic[i][1]);
						transic[n+1][0] = newtransic[i][0];
						transic[n+1][1] = newtransic[i][1];
						strcpy(transicao[n+1],newtransicao);
						
						n++;
						i++;
					}
				}
			}
		}
		
		
		for(i=0;i<n+1;i++){
			for(j=0;j<i;j++){
				if(transic[i][0] == transic[j][0] && transic[i][1] == transic[j][1]){
					
					strcat(transicao[j],"+");
					strcat(transicao[j],transicao[i]);
					transic[i][0] = '#';
					transic[i][0] = '#';
				}
			}
		}
		
		
		
		
		
		j=0;
		for(i=0; i<n+1;i++){
			if(transic[i][0] != '#'){
				
				//printf("%d ",transic[i][0]);
				//printf("%s ",transicao[i]);
				//printf("%d \n",transic[i][1]);
				strcpy(transicao_aux[j],transicao[i]);
				
				transicaux[j][0] = transic[i][0];
				transicaux[j][1] = transic[i][1];
				
				printf("%d %s %d\n",transicaux[j][0], transicao_aux[j], transicaux[j][1]);
				j++;
			}	
		}
		printf("\n---\n");
		for(i=0; i<j;i++){
			strcpy(transicao[i], transicao_aux[i]);
				
			transic[i][0] = transicaux[i][0];
			transic[i][1] = transicaux[i][1];
				
			printf("%d ",transic[i][0]);
			printf("%s ",transicao[i]);
			printf("%d \n",transic[i][1]);
		}
		n=j;
		
		system("pause");
		
		//scanf("%d",&eliminar);
		//eliminar = 3;
		printf("\n-------------------\n");
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	printf("--------------\n");
	
	eliminar=3;
	x=0;
	for(i=0; i<n+1;i++){
			
		if(transic[i][0] == eliminar || transic[i][1] == eliminar){
			transicaux[x][0] = transic[i][0];
			transicaux[x][1] = transic[i][1];
			
			strcpy(transicao_aux[x], transicao[i]);
			printf("%d ",transicaux[x][0]);
			printf("%s ",transicao_aux[x]);
			printf("%d \n",transicaux[x][1]);
			
			if(transicaux[x][0] == transicaux[x][1]){
				strcat(transicao_aux[x], "*");
				strcat(newtransicao, transicao_aux[x]);
				

				}
			else if(transicao_aux[x][0] != '#'){
				strcat(newtransicao, "(");
				strcat(newtransicao, transicao_aux[x]);
				strcat(newtransicao, ")");	
				
			}
			x++;
			transic[i][0] = '#';
			transic[i][1] = '#';
		}
	}
	
	i=0;
	for(j=0;j<x;j++){
		if(transicaux[j][0] != eliminar){
			newtransic[i][0] = transicaux[j][0];
			for(k=0;k<x;k++){
				if(transicaux[k][1] != eliminar){
					newtransic[i][1] = transicaux[k][1];
					printf("\n%d - %d\n",newtransic[i][0],newtransic[i][1]);
					
					transic[n+1][0] = newtransic[i][0];
					transic[n+1][1] = newtransic[i][1];
					strcpy(transicao[n+1],newtransicao);
					
					n++;
					i++;
				}
			}
		}
	}
	for(i=0;i<n+1;i++){
		for(j=0;j<i;j++){
			if(transic[i][0] == transic[j][0] && transic[i][1] == transic[j][1]){
				strcat(transicao[j],"+");
				strcat(transicao[j],transicao[i]);
				transic[i][0] = '#';
				transic[i][0] = '#';
			}
		}
	}
	
	
	
	
	printf("--------------\n");
	for(i=0; i<n+1;i++){
		if(transic[i][0] != '#'){
			printf("%d ",transic[i][0]);
			printf("%s ",transicao[i]);
			printf("%d \n",transic[i][1]);
		}	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	printf("\n\n%s",newtransicao);
	
	
	
	
	
}
