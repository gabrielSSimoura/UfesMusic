#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"

void DadosMidia(Midia* m);
void DadosAlbum(Album* a);
void DadosPlaylist(Playlist *p);
void PreencheAlbum(Album *a, int qtd);
void PreenchePlaylst(Playlist* p,Album *a);
void AlteraMidia(Midia *m,char escolha);
void AlteraAlbum(Album *a,char escolha);
char* LeDados();
int LerInteiros();
float LerFloat();


char* LeDados(){
    char *dados=(char*)malloc(50);      
    setbuf(stdin, NULL); 
    scanf("%[^\n]s",dados);
    setbuf(stdin, NULL);    
    return dados;
}

int LerInteiros(){
    int num;
    setbuf(stdin, NULL); 
    scanf("%d",&num);
    setbuf(stdin, NULL); 
    return num;
}

float LerFloat(){
    float fnum;    
    setbuf(stdin, NULL); 
    scanf("%f",&fnum);
    setbuf(stdin, NULL);  
    return fnum;
}
void PreencheAlbum(Album *a, int qtd){
    Midia* m;

    for(int i=0;i<qtd;i++){
        m=AlocaMidia();
        DadosMidia(m);        
        AdicionaMidiaAlbum(a,m,i);
    }
}

void DadosAlbum(Album* a){   
    char* nomeAlb=(char*)malloc(50);
    char* nArtista=(char*)malloc(50);    
    char* gen=(char*)malloc(50);
    char* produtor=(char*)malloc(50);
    int ano,qtd; 

    printf("Ano de Lançamento do Album: ");
    ano=LerInteiros();
    printf("Quantidade de midias: ");
    qtd=LerInteiros();
    printf("Nome do Album: ");
    nomeAlb=LeDados();
    printf("Nome do artista: ");
    nArtista=LeDados();
    printf("Nome produtora: ");
    produtor=LeDados();
    printf("Genero: ");
    gen=LeDados();
    CriaAlbum(a,nomeAlb,nArtista,gen,produtor,ano,qtd); 
    PreencheAlbum(a,qtd);   

}
void DadosMidia(Midia* m){
    char* nome=(char*)malloc(50);
    char* nomeArtista=(char*)malloc(50);
    char* nomeCompositor=(char*)malloc(50);
    char* genero=(char*)malloc(50);
    char* produtora=(char*)malloc(50);
    int tipo;
    float duracao;

    printf("Tipo da midia [01]Musica, [02]Video, [03]Podcast: ");
    tipo=LerInteiros();
    printf("Nome da midia: ");
    nome=LeDados();
    printf("Nome do artista: ");
    nomeArtista=LeDados();
    printf("Nome Compositor: ");
    nomeCompositor=LeDados();
    printf("Nome produtora: ");
    produtora=LeDados();
    printf("Genero: ");
    genero=LeDados();
    printf("Duracao: ");
    duracao=LerFloat();

    CriaMidia(m,nome,nomeArtista,nomeCompositor,genero,produtora,tipo,duracao);
}

void DadosPlaylist(Playlist *p){
    char *nomep=(char*)malloc(50);
    char *nomeColab1=(char*)malloc(50);
    char *nomeColab2=(char*)malloc(50);
    int qtdColab, qtdMidia=0;

    printf("Nome da Playlist: ");
    nomep=LeDados();
    printf("Quantidade de colaboradores (MAX 2): ");
    qtdColab=LerInteiros();
    if(qtdColab==1){
        nomeColab1=LeDados();
    }
    else if(qtdColab==2){
        nomeColab1=LeDados();
        nomeColab2=LeDados();
    }

    CriaPlaylist(p,nomep,nomeColab1, nomeColab2, qtdColab, qtdMidia);

}


void AlteraMidia(Midia *m,char escolha){
    char *nome=(char*)malloc(50);
    int num;
    float fnum;
    if(escolha=='1'){
        printf("Nome da midia: ");
        nome=LeDados();
        AtribuiNomeMidia(m,nome);
    }
    else if(escolha=='2'){
        printf("Nome do artista: ");
        nome=LeDados();
        AtribuiNomeArtista(m,nome);
    }
    else if(escolha=='3'){
        printf("Nome Compositor: ");
        nome=LeDados();
        AtribuiNomeCompositor(m,nome);
    }
    else if(escolha=='4'){
        printf("Genero: ");
        nome=LeDados();
        AtribuiNomeGenero(m,nome);
    }
    else if(escolha=='5'){
        printf("Tipo: ");
        num=LerInteiros();
        AtribuiTipo(m,num);
    }
    else if(escolha=='6'){
        printf("Duracao: ");
        fnum=LerFloat();
        AtribuiDuracao(m,fnum);
    }
    else if(escolha=='7'){
       printf("Nome produtora: ");
       nome=LeDados();
       AtribuiNomeProdutora(m,nome);   

    }
}

void AlteraAlbum(Album *a,char escolha){
    char *nome=(char*)malloc(50);
    int num;    
    if(escolha=='1'){
        printf("Nome do Album: ");
        nome=LeDados();
        AtribuiNomeAlbum(a,nome);
    }
    else if(escolha=='2'){
        printf("Nome do artista: ");
        nome=LeDados();
        AtribuiArtistaAlbum(a,nome);
    }
    else if(escolha=='3'){
        printf("Genero: ");
        nome=LeDados();
        AtribuiGenero(a,nome);
    }
    else if(escolha=='4'){
       printf("Nome produtora: ");
       nome=LeDados();
       AtribuiProdutoraAlbum(a,nome); 
    }
    else if(escolha=='5'){
        printf("Ano do Album: ");
        num=LerInteiros();
        AtribuiAnoAlbum(a,num);
    }
    
    

}

void PreenchePlaylst(Playlist* p, Album *a){
    Midia *m=AlocaMidia();
    int num;
    ImprimeAlbum(a);
    printf("\t\tNumero da midia que deseja adicionar na Playlist: ");
    num=LerInteiros();
    m=RetornaMidiaAlbum(a,num);
    AdicionaMidiaPlaylist(p,m);
}

int main(){
    Album *a=AlocaAlbum();
    Playlist *p=AlocaPlaylist();
    DadosAlbum(a);
    DadosPlaylist(p);
    
    PreenchePlaylst(p,a);
    ImprimePlaylist(p);
    PreenchePlaylst(p,a);
    ImprimePlaylist(p);
    //printar todos os Albuns
    //Escolher Album
    //int qtdMidiasPlay;
    //qtdMidiasPlay=RetornaQtdMidias(p);

    
      
/*
while(1){
    opcao=MenuInicial();

    scanf("%d\n",&opcao);   
    if(opcao=='1'){       
            


    }
    else if(opcao=='2'){              
       //OPçao Desenvolvedor       
       
    }
    else if(opcao=='3'){return 0;}

    }
     */
return 0;
}

