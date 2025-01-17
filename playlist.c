#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "sistema.h"

struct playlist{
    int tipo;                // (0)--> publica e (1)--> privada;
    char *nomePlaylist;    
    char *colaboradores[3];
    int qtdColaboradores;
    int qtdMidias;
    Midia *midia[51];
};

Playlist* AlocaPlaylist(){
    Playlist *p=(Playlist*)malloc(sizeof(Playlist));
    p->nomePlaylist=(char*)malloc(50);
    
    for(int i=0;i<3;i++){
        p->colaboradores[i]=(char*)malloc(50);
    }
    for(int i=0;i<51;i++){
        p->midia[i]=AlocaMidia();
    }
    return p;
}

void CriaPlaylist(Playlist *p, char* nomep, char* colab1, char* colab2, int qtdColab, int qtdMidia, int tipo){
    strcpy(p->nomePlaylist,nomep);
    p->qtdColaboradores=qtdColab;
    p->qtdMidias=0;
    p->tipo=tipo;
    if(qtdColab==1){
        strcpy(p->colaboradores[0],colab1);
    }
    else if(qtdColab==2){
        strcpy(p->colaboradores[0],colab1);
        strcpy(p->colaboradores[1],colab2);
    }
}

int RetornaQtdMidias(Playlist *p){
    return p->qtdMidias;
}

void AdicionaMidiaPlaylist(Playlist *p, Midia *m){    
    if(p->qtdMidias<50){
        p->midia[p->qtdMidias]=m;
        p->qtdMidias++;
        printf("\n\t\tMidia adicionada!");
    }
    else printf("\n\t\tPlaylist cheia!");
}

void ImprimePlaylist(Playlist *p){
    printf("\n");
    ImprimeNomePlaylist(p);
    ImprimeColaboradoresPlaylist(p);
    ImprimeMidiasPlaylist(p);
}
int RetornaTipo(Playlist *p){
    return p->tipo;
}

void ApagaMidiaPlaylist(Playlist *p,int posicao){
    p->midia[51] = p->midia[posicao];
    for(int i=posicao;i<p->qtdMidias;i++){
        TrocaMidia(p,i,i+1);
    }
    p->qtdMidias--;
    printf("\n\t\tMidia apagada com sucesso!");
}

void TrocaMidia(Playlist *p, int posicao1, int posicao2){
    Midia *auxiliar;
    auxiliar=AlocaMidia();
    auxiliar=p->midia[posicao1];
    p->midia[posicao1]=p->midia[posicao2];
    p->midia[posicao2]=auxiliar;
    
}

void ImprimeNomePlaylist(Playlist *p){
        printf("\t\t%s\n",p->nomePlaylist);
    }    
void ImprimeColaboradoresPlaylist(Playlist *p){
    for(int i=0;i<p->qtdColaboradores;i++){
        printf("\t\tColaborador [%02d]: ",i);
        printf(" %s\n",p->colaboradores[i]);
        }
    }  
void ImprimeMidiasPlaylist(Playlist *p){
    for(int i=0;i<p->qtdMidias;i++){
        printf("\n\t\tMidia [%02d]:",i);
        ImprimeMidia(p->midia[i]);
        }
    }  

void AtribuiNomePlaylist(Playlist *p, char *nomep){
    p->nomePlaylist=nomep;
}

void ImprimePlaylistFavorita(Playlist *playfav){
    printf("\n\t\tPlaylist Favorita: ");
    ImprimeNomePlaylist(playfav);
    ImprimeColaboradoresPlaylist(playfav);
    ImprimeMidiasPlaylist(playfav);
}

Playlist *LerPlaylistArquivo(FILE *arquivo){
    Playlist *p=AlocaPlaylist();
    fscanf(arquivo, "%d",&p->tipo);
    fscanf(arquivo, "\n");
    fscanf(arquivo, "%[^\n]s",p->nomePlaylist);
    fscanf(arquivo, "\n");
    fscanf(arquivo, "%d",&p->qtdColaboradores);
    fscanf(arquivo, "\n");
    fscanf(arquivo, "%d",&p->qtdMidias);
    fscanf(arquivo, "\n");
    for(int i=0;i<p->qtdColaboradores;i++){
        fscanf(arquivo, "%[^\n]s",p->colaboradores[i]);
        fscanf(arquivo, "\n");
    }
    for(int i=0;i<p->qtdMidias;i++){
        p->midia[i]=LerMidiaArquivo(arquivo);
    }
    return p;
}

void SalvaPlaylist(Playlist *p, FILE *arquivo){
    fprintf(arquivo, "%d",p->tipo);
    fprintf(arquivo, "\n");
    fprintf(arquivo, "%s",p->nomePlaylist);
    fprintf(arquivo, "\n");
    fprintf(arquivo, "%d",p->qtdColaboradores);
    fprintf(arquivo, "\n");
    fprintf(arquivo, "%d",p->qtdMidias);
    fprintf(arquivo, "\n");
    for(int i=0;i<p->qtdColaboradores;i++){
        fprintf(arquivo, "%s",p->colaboradores[i]);
        fprintf(arquivo, "\n");
    }
    for(int i=0;i<p->qtdMidias;i++){
       SalvaMidia(p->midia[i],arquivo);
    }
}


char* RetornaColaborador(Playlist *p){
    char *aux=(char*)malloc(50);
    if(p->qtdColaboradores==1){
        return p->colaboradores[0];
    }
    else aux=p->colaboradores[0];
    for(int i=0;p->qtdColaboradores;i++){
       TrocaColaborador(p,i,i+1);
    }
    p->qtdColaboradores--;
    return aux;
}

void TrocaColaborador(Playlist *p, int posicao1, int posicao2){
    char *aux=(char*)malloc(50);
    aux=p->colaboradores[posicao1];
    p->colaboradores[posicao1]=p->colaboradores[posicao2];
    p->colaboradores[posicao2]=aux;
}

int RetornaQtdColaborador(Playlist *p){
    return p->qtdColaboradores;
}

char* RetornaNomePlaylist(Playlist *p){
    return p->nomePlaylist;
}