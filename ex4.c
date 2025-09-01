#include <stdio.h>
#include <stdlib.h>
int a=0,b=0,c=0,d=0,e=0,f=0,g=0;
int y,pts=0,tot=0,j=0,jog=0;
int ent,s,op,i;

void clear() {
	system("cls");
	system("clear");
}

void zerar(){
    pts=0;
	a=0;
	b=0;
	c=0;
	d=0;
	e=0;
	f=0;
	g=0;
	j++;
}
void partida(){
    printf("\t\033[3;33mPartida %d\033[0m\n\n",j);
	for(i=1; i<=5; i++) {
		printf("\033[1;32m> Bola %d:\033[0m ",i);
		scanf("%d",&ent);
		if(ent!=0 && ent!=1 && ent!=2) {
			printf("\033[1;31m  > Invalido, use 0,1 ou 2\033[0m\n");
			i--;
		} 
		else {
			if(ent==0){
				if(a==0){
					a=1;
					if(b==0){b=1;s=0;}
					else {s=1;b=0;}
				} 
				else{
					a=0;
					if(c==0){c=1;s=1;}
					else{s=2;c=0;}
			    }
			}
			if(ent==1){
				if(d==0){d=1;s=0;}
				else{
					d=0;
					if(e==0){e=1;s=1;}
					else{s=2;e=0;}
				}
			}
			if(ent==2){
				if(f==0){f=1;s=1;}
				else{
					f=0;
					if(g==0) {g=1;s=0;}
					else {s=2;g=0;}
				}
			}
			if(s==0) y=10;
			if(s==1) y=20;
			if(s==2) y=30;
			pts+=y;
			printf("\033[1;33m  > saiu %d (+%d)\033[0m\n",s,y);
			}
		}
		jog++;
		tot+=pts;
		printf("\n\033[1;36m> Pontos da partida %i: %d\n",j,pts);
		printf("\033[1;95m> Total de pontos: %d\n",tot);
		printf("\033[1;93m> Jogar novamente? (1 sim / 0 nao)?\033[0m ");
		scanf("%d",&op);
}
void fim(){
    if(jog>1){
	    clear();
		printf("\t\033[2;40;94m>Fim de jogo :(\n\nVoce jogou %d vezes e fez %d pontos\n",j,tot);
	}
	else {
	    clear();
		printf("\t\033[2;94mFim de jogo :(\n\nVoce jogou %d vez e fez %d pontos\n",j,tot);
	}
}
void jogo() {
	do {
	    clear();
        zerar();
        partida();
	} while(op==1);
	fim();
}

int main() {
	jogo();
	return 0;
}