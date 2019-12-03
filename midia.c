#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "sistema.h"

struct midia{
    int  tipo;
    int qtdArtista;
    int qtdCompositor;                        //1.musica,2.video,3.podcast;    
    char *nomeMidia; 
    char *nomeArtista[2];
    char *nomeCompositor[2];   
    char *genero;
    char *produzidoPor;
    float duracao;
};

void ImprimeMidia(Midia *m){
    ImprimeTipo(m);
    ImprimeNomeMidia(m);
    if(m->qtdCompositor==1){
        ImprimeNomeCompositor1(m);
    }
    else if(m->qtdCompositor==2){
        ImprimeNomeCompositor1(m);
        ImprimeNomeCompositor2(m);
    }
    if (m->qtdArtista==1){
        ImprimeNomeArtista1(m);
    }
    else if(m->qtdArtista==2){
        ImprimeNomeArtista1(m);
        ImprimeNomeArtista2(m);
    }
       
    ImprimeProdutora(m);
    ImprimeGenero(m);
    ImprimeDuracao(m);
}
  
void CriaMidia(Midia* m, char* nome, char* nomeArtista,char* nomeArtista2, char* nomeCompositor,char* nomeCompositor2,char* genero, char* produtora,  int tipo, float duracao, int qtdA, int qtdC){
    m->nomeMidia=nome;
    if(qtdA==1){m->nomeArtista[0]=nomeArtista;}
    else if(qtdA==2){
        m->nomeArtista[0]=nomeArtista;
        m->nomeArtista[1]=nomeArtista2;
    }
    if(qtdC==1){m->nomeCompositor[0]=nomeCompositor;}
    else if(qtdA==2){
        m->nomeCompositor[0]=nomeCompositor;
        m->nomeCompositor[1]=nomeCompositor2;
    }    
    
    m->genero=genero;
    m->produzidoPor=produtora;
    m->tipo=tipo;
    m->duracao=duracao;
    m->qtdCompositor=qtdC;
    m->qtdArtista=qtdA;
}

void DeletaMidiaPrograma(Midia *m){
    if(m){
        if(m->nomeMidia)free(m->nomeMidia);
        for(int i=0;i<m->qtdArtista;i++){
            if(m->nomeArtista[i])free(m->nomeArtista[i]);
        }        
        if(m->genero)free(m->genero);
        if(m->produzidoPor)free(m->produzidoPor);

        for(int i=0;i<m->qtdCompositor;i++){
            if(m->nomeCompositor[i])free(m->nomeCompositor[i]);
        }
        printf("\t\tMusica Apagada com sucesso");
        free(m);
    }    
}

Midia* AlocaMidia(){
    Midia* m=(Midia*)malloc(sizeof(Midia));
    m->nomeMidia=(char*)malloc(50);
    m->nomeArtista[0]= (char*)malloc(50);
    m->nomeArtista[1]= (char*)malloc(50);
    m->genero= (char*)malloc(50);        
    m->produzidoPor =(char*)malloc(50);   
    m->nomeCompositor[0]= (char*)malloc(50); 
    m->nomeCompositor[1]= (char*)malloc(50); 
    return m;    
}

void AtribuiNomeMidia(Midia *m, char* nome){m->nomeMidia=nome;}
void AtribuiNomeArtista1(Midia *m, char* nomeArtista){m->nomeArtista[0]=nomeArtista;}
void AtribuiNomeCompositor1(Midia *m, char* nomeCompositor){m->nomeCompositor[0]=nomeCompositor;}

void AtribuiNomeArtista2(Midia *m, char* nomeArtista){m->nomeArtista[1]=nomeArtista;}
void AtribuiNomeCompositor2(Midia *m, char* nomeCompositor){m->nomeCompositor[1]=nomeCompositor;}

void AtribuiNomeGenero(Midia *m, char* genero){m->genero=genero;}
void AtribuiTipo(Midia *m, int tipo){m->tipo=tipo;}
void AtribuiDuracao(Midia *m, float duracao){m->duracao=duracao;}
void AtribuiNomeProdutora(Midia *m, char* produtora){m->produzidoPor=produtora;}

void ImprimeNomeMidia(Midia *m){printf("\t\tNome da Midia: %s\n",m->nomeMidia);}    
void ImprimeNomeArtista1(Midia *m){printf("\t\tNome do Artista 0: %s\n",m->nomeArtista[0]);}
void ImprimeNomeCompositor1(Midia *m){printf("\t\tNome do Compositor 0: %s\n",m->nomeCompositor[0]);}   
void ImprimeNomeArtista2(Midia *m){printf("\t\tNome do Artista 1: %s\n",m->nomeArtista[1]);}
void ImprimeNomeCompositor2(Midia *m){printf("\t\tNome do Compositor 1: %s\n",m->nomeCompositor[1]);} 

void ImprimeGenero(Midia *m){printf("\t\tGenero: %s\n",m->genero);}
void ImprimeDuracao(Midia *m){printf("\t\tDuracao: %.2f\n",m->duracao);}
void ImprimeTipo(Midia *m){    
    printf("\n\t\tTipo da Midia: ");
    if(m->tipo==1){printf("Musica\n");}
    else if(m->tipo==2){printf("Video\n");}
    else if(m->tipo==3){printf("Podcast\n");}
}
void ImprimeProdutora(Midia *m){printf("\t\tProduzido por: %s\n",m->produzidoPor);}

void PesquisaMidia(Midia *m, char* nome){
    if(!(strcmp(m->nomeMidia,nome))){
        printf("\n");
        ImprimeMidia(m);
    }
}
void PesquisaArtistaMidia(Midia *m, char* nomeA){
    if(!(strcmp(m->nomeArtista[0],nomeA))){
        printf("\n");
        ImprimeMidia(m);
    }
    else if(!(strcmp(m->nomeArtista[1],nomeA))){
        printf("\n");
        ImprimeMidia(m);
    }
}


int RetornaQtdArtista(Midia *m){
    return m->qtdArtista;
}
int RetornaQtdCompositor(Midia *m){
     return m->qtdCompositor;
}

void PesquisarNomeCompositorMidia(Midia *m, char* nomeC){
    if(!(strcmp(m->nomeCompositor[0],nomeC))){
        printf("\n");
        ImprimeMidia(m);
    }
    else if(!(strcmp(m->nomeCompositor[1],nomeC))){
        printf("\n");
        ImprimeMidia(m);
    }
}
void PesquisarGeneroMidia(Midia *m, char* nomeG){
    if(!(strcmp(m->genero,nomeG))){
        printf("\n");
        ImprimeMidia(m);
    }
}
void PesquisarProdutoraMidia(Midia *m, char* nomeP){
    if(!(strcmp(m->produzidoPor,nomeP))){
        printf("\n");
        ImprimeMidia(m);
    }
}