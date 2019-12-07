#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "sistema.h"


struct album{
    char *nomeAlbum;
    char *nomeArtista;       
    char *genero;
    char *produzidoPor;        
    Midia *midia[21];
    int qtdMidias;
    int qtdMidiasTotal;
    int ano;
};

void CriaAlbum(Album *a,char* nomeAlb, char* nArtista,char* gen, char* produtor,int ano,int qtd){
    strcpy(a->nomeAlbum,nomeAlb);
    strcpy(a->nomeArtista,nArtista);
    strcpy(a->genero,gen);
    strcpy(a->produzidoPor,produtor);
    a->ano=ano;
    a->qtdMidiasTotal=qtd;
    a->qtdMidias=0;
}

Album* AlocaAlbum(){
    Album* a=(Album*)malloc(sizeof(Album));
    a->nomeAlbum=(char*)malloc(50);
    a->nomeArtista= (char*)malloc(50);
    a->genero= (char*)malloc(50);        
    a->produzidoPor =(char*)malloc(50);

    for(int i=0;i<21;i++){
        a->midia[i]=AlocaMidia();
    }
    return a;
}
void ImprimeAlbum(Album *a){
    
    ImprimeNomeAlbum(a);   
    ImprimeArtistaAlbum(a);
    ImprimeGeneroAlbum(a);
    ImprimeProdutoraAlbum(a);
    ImprimeqtdMidias(a);
    ImprimeAnoAlbum(a);
    for(int i=0;i<a->qtdMidias;i++){
        printf("\n\t\t[%02d] ",i);
        ImprimeMidia(a->midia[i]);
    }   
}

void AdicionaMidiaAlbum(Album* a,Midia* m){
    a->midia[a->qtdMidias]=m;
    a->qtdMidias++;
}


void AtribuiNomeAlbum(Album *a, char* nome){a->nomeAlbum=nome;}
void AtribuiArtistaAlbum(Album *a, char* nomeArtista){a->nomeArtista=nomeArtista;}
void AtribuiGenero(Album *a, char* genero){a->genero=genero;}


void AtribuiProdutoraAlbum(Album *a, char* produtora){a->produzidoPor=produtora;}
void AtribuiAnoAlbum(Album *a, int ano){a->ano=ano;}
void AtribuiqtdMidias(Album *a, int qtd){a->qtdMidias=qtd;}

void ImprimeNomeAlbum(Album *a){printf("\n\t\tNome do Album: %s",a->nomeAlbum);}    
void ImprimeArtistaAlbum(Album *a){printf("\n\t\tNome do Artista: %s",a->nomeArtista);}  
void ImprimeGeneroAlbum(Album *a){printf("\n\t\tGenero: %s",a->genero);}  
void ImprimeProdutoraAlbum(Album *a){printf("\n\t\tProduzido por: %s",a->produzidoPor);}  
void ImprimeqtdMidias(Album *a){printf("\n\t\tQuantidade de Midias: %d",a->qtdMidias);}  
void ImprimeAnoAlbum(Album *a){printf("\n\t\tAno: %d",a->ano);}  

Midia* RetornaMidiaAlbum(Album *a, int posicao){
    return a->midia[posicao];
}

void ImprimeDadosBasicosAlbum(Album *a){
    ImprimeNomeAlbum(a);
    ImprimeArtistaAlbum(a);
    ImprimeAnoAlbum(a);
    ImprimeGeneroAlbum(a);
    ImprimeProdutoraAlbum(a);
    printf("\n");
}

void PesquisaAlbum(Album *a, char *nome){
    if(!(strcmp(a->nomeAlbum,nome))){
        printf("\n");
        ImprimeAlbum(a);
    }
}

void PesquisaMidiaAlbum(Album *a, char* nomeM){
    for(int i=0;i<a->qtdMidiasTotal;i++){
        PesquisaMidia(a->midia[i],nomeM);
    }
}

void PesquisaArtistaMidiaAlbum(Album *a, char* nomeA){
    for(int i=0;i<a->qtdMidiasTotal;i++){
       PesquisaArtistaMidia(a->midia[i],nomeA);
    }
}

void PesquisarNomeCompositorAlbum(Album *a, char* nomeC){
    for(int i=0;i<a->qtdMidiasTotal;i++){
       PesquisarNomeCompositorMidia(a->midia[i],nomeC);
    }
}
void PesquisarGeneroAlbum(Album *a, char* nomeG){
    for(int i=0;i<a->qtdMidiasTotal;i++){
       PesquisarGeneroMidia(a->midia[i], nomeG);
    }
}
void PesquisarProdutoraAlbum(Album *a, char* nomeP){
    for(int i=0;i<a->qtdMidiasTotal;i++){
        PesquisarProdutoraMidia(a->midia[i], nomeP);
       
    }
}

Album* LerAlbunsArquivo(FILE *arquivo){
    Album *a=AlocaAlbum();
    a->qtdMidiasTotal=20;
    fscanf(arquivo, "%[^\n]s",a->nomeAlbum);    
    fscanf(arquivo, "\n");   
    fscanf(arquivo, "%[^\n]s",a->nomeArtista);    
    fscanf(arquivo, "\n");
    fscanf(arquivo, "%[^\n]s",a->genero);
    fscanf(arquivo, "\n");
    fscanf(arquivo, "%[^\n]s",a->produzidoPor);
    fscanf(arquivo, "\n");
    fscanf(arquivo, "%d",&a->ano);
    fscanf(arquivo, "\n");
    fscanf(arquivo, "%d",&a->qtdMidias);
    fscanf(arquivo, "\n");
    for(int i=0;i<a->qtdMidias;i++){
        a->midia[i]=LerMidiaArquivo(arquivo);        
    }
    return a;
}

void SalvaAlbum(Album *a, FILE *arquivo){

    fprintf(arquivo, "%s",a->nomeAlbum);        
    fprintf(arquivo, "\n");   
    fprintf(arquivo, "%s",a->nomeArtista);    
    fprintf(arquivo, "\n");
    fprintf(arquivo, "%s",a->genero);
    fprintf(arquivo, "\n");
    fprintf(arquivo, "%s",a->produzidoPor);
    fprintf(arquivo, "\n");
    fprintf(arquivo, "%d",a->ano);
    fprintf(arquivo, "\n");
    fprintf(arquivo, "%d",a->qtdMidias);
    fprintf(arquivo, "\n");
    for(int i=0;i<a->qtdMidias;i++){
        SalvaMidia(a->midia[i],arquivo);        
    }
}