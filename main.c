#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "sistema.h"

Midia* DadosMidia();
void DadosAlbum(Album* alb);
Playlist* DadosPlaylist();
Usuario* DadosUsuario();


int VerificaOpcao(int opinicial, int opfinal);
void AlteraMidia(Midia *m,char escolha);
void AlteraAlbum(Album *a,char escolha);

void PreencheSistemaComAlbum(Sistema *s);
void PreencheSistemaComUsuario(Sistema *s,Usuario *usu);
void PreencheAlbum(Album *a, int qtd);
void PreenchePlaylst(Playlist* p,Album *a);

char* LeDados();
int LerInteiros();
float LerFloat();

int VerificaOpcao(int opinicial, int opfinal){
    int num=0;
    num=LerInteiros();
    if(num>opinicial && num<opfinal){return num;}
    return 0;
}
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
void PreencheAlbum(Album *alb, int qtd){
    Midia* m;

    for(int i=0;i<qtd;i++){
        m=AlocaMidia();
        m=DadosMidia();        
        AdicionaMidiaAlbum(alb,m);
    }
}
Usuario* DadosUsuario(){
    Usuario *u=AlocaUsuario();
    char* lgin=(char*)malloc(50);
    char* snha=(char*)malloc(50);
    printf("\n\t\tLogin : ");
    lgin=LeDados();
    printf("\t\tSenha: ");
    snha=LeDados();

    CriaUsuario(u,lgin,snha);
    return u;
}
void DadosAlbum(Album *alb){
    
    char* nomeAlb=(char*)malloc(50);
    char* nArtista=(char*)malloc(50);    
    char* gen=(char*)malloc(50);
    char* produtor=(char*)malloc(50);
    int ano,qtd; 

    printf("\n\t\tAno de Lancamento do Album: ");
    ano=LerInteiros();
    printf("\t\tQuantidade de midias: ");
    qtd=LerInteiros();
    printf("\t\tNome do Album: ");
    nomeAlb=LeDados();
    printf("\t\tNome do artista: ");
    nArtista=LeDados();
    printf("\t\tNome produtora: ");
    produtor=LeDados();
    printf("\t\tGenero: ");
    gen=LeDados();
    CriaAlbum(alb,nomeAlb,nArtista,gen,produtor,ano,qtd); 
    PreencheAlbum(alb,qtd);    

}
Midia* DadosMidia(){
    Midia* m=AlocaMidia();
    char* nome=(char*)malloc(50);
    char* nomeArtista=(char*)malloc(50);
    char* nomeCompositor=(char*)malloc(50);
    char* genero=(char*)malloc(50);
    char* produtora=(char*)malloc(50);
    int tipo;
    float duracao;

    printf("\n\t\tTipo da midia [01]Musica, [02]Video, [03]Podcast: ");
    tipo=LerInteiros();
    printf("\t\tNome da midia: ");
    nome=LeDados();
    printf("\t\tNome do artista: ");
    nomeArtista=LeDados();
    printf("\t\tNome Compositor: ");
    nomeCompositor=LeDados();
    printf("\t\tNome produtora: ");
    produtora=LeDados();
    printf("\t\tGenero: ");
    genero=LeDados();
    printf("\t\tDuracao: ");
    duracao=LerFloat();

    CriaMidia(m,nome,nomeArtista,nomeCompositor,genero,produtora,tipo,duracao);
    return m;
}
Playlist* DadosPlaylist(){
    Playlist *p=AlocaPlaylist();
    char *nomep=(char*)malloc(50);
    char *nomeColab1=(char*)malloc(50);
    char *nomeColab2=(char*)malloc(50);
    int qtdColab=0, qtdMidia=0;

    printf("\n\t\tNome da Playlist: ");
    nomep=LeDados();
    printf("\t\tQuantidade de colaboradores (MAX 2): ");
    qtdColab=LerInteiros();
    if(qtdColab==1){
        printf("\t\tColaborador [00]: ");
        nomeColab1=LeDados();
    }
    else if(qtdColab==2){
         printf("\t\tColaborador [00]: ");
        nomeColab1=LeDados();
         printf("\t\tColaborador [01]: ");
        nomeColab2=LeDados();
    }

    CriaPlaylist(p,nomep,nomeColab1, nomeColab2, qtdColab, qtdMidia);
    return p;
}
void AlteraMidia(Midia *m,char escolha){
    char *nome=(char*)malloc(50);
    int num;
    float fnum;
    if(escolha=='1'){
        printf("\n\t\tNome da midia: ");
        nome=LeDados();
        AtribuiNomeMidia(m,nome);
    }
    else if(escolha=='2'){
        printf("\n\t\tNome do artista: ");
        nome=LeDados();
        AtribuiNomeArtista(m,nome);
    }
    else if(escolha=='3'){
        printf("\n\t\tNome Compositor: ");
        nome=LeDados();
        AtribuiNomeCompositor(m,nome);
    }
    else if(escolha=='4'){
        printf("\n\t\tGenero: ");
        nome=LeDados();
        AtribuiNomeGenero(m,nome);
    }
    else if(escolha=='5'){
        printf("\n\t\tTipo: ");
        num=LerInteiros();
        AtribuiTipo(m,num);
    }
    else if(escolha=='6'){
        printf("\n\t\tDuracao: ");
        fnum=LerFloat();
        AtribuiDuracao(m,fnum);
    }
    else if(escolha=='7'){
       printf("\n\t\tNome produtora: ");
       nome=LeDados();
       AtribuiNomeProdutora(m,nome);   

    }
}
void AlteraAlbum(Album *a,char escolha){
    char *nome=(char*)malloc(50);
    int num;    
    if(escolha=='1'){
        printf("\n\t\tNome do Album: ");
        nome=LeDados();
        AtribuiNomeAlbum(a,nome);
    }
    else if(escolha=='2'){
        printf("\n\t\tNome do artista: ");
        nome=LeDados();
        AtribuiArtistaAlbum(a,nome);
    }
    else if(escolha=='3'){
        printf("\n\t\tGenero: ");
        nome=LeDados();
        AtribuiGenero(a,nome);
    }
    else if(escolha=='4'){
       printf("\n\t\tNome produtora: ");
       nome=LeDados();
       AtribuiProdutoraAlbum(a,nome); 
    }
    else if(escolha=='5'){
        printf("\n\t\tAno do Album: ");
        num=LerInteiros();
        AtribuiAnoAlbum(a,num);
    }
}
void PreenchePlaylist(Playlist* p, Album *a){
    Midia *m=AlocaMidia();
    int num;
    ImprimeAlbum(a);
    printf("\t\tNumero da midia que deseja adicionar na Playlist: ");
    num=LerInteiros();
    m=RetornaMidiaAlbum(a,num);
    AdicionaMidiaPlaylist(p,m);
}
void PreencheUsuario(Usuario *u,Album *a){
    int qtd;
    Playlist *play=AlocaPlaylist();
    DadosPlaylist(play);
    printf("\t\t\nQuantas midias desse album deseja adicionar em sua Playlist? (MAX 50) : ");
    qtd=LerInteiros();    

    for(int i=0;i<qtd;i++){
        PreenchePlaylist(play,a);
    }
        AdicionaPlaylistUsuario(u,play);        
}
void PreencheSistemaComAlbum(Sistema *s){
    Album *alb=AlocaAlbum();
    DadosAlbum(alb);
    AdicionaAlbumSistema(s,alb);  
    printf("\n\n");
    
}
void PreencheSistemaComUsuario(Sistema *s,Usuario *usu){
    AdicionaUsuarioSistema(s,usu);  
}

int main(){    
   Sistema *s=AlocaSistema();

while(1){
    int escolha=0;
    escolha=MenuInicial();

    escolha=LerInteiros(); 
    if(escolha==1){       
        Usuario *usu=DadosUsuario();
        PreencheSistemaComUsuario(s,usu);
        while(1){            
            int id=0,opcao=0; 
            MenuUsuario();
            opcao=LerInteiros();

            if(opcao==1){
                //Criar Playlist Usuario
                ImprimeAlbunsSistema(s);
                printf("\n\t\tDidite o Id do Album que deseja visualizar as Midias: ");
                id=LerInteiros();
                Album *albm=AlocaAlbum();
                albm=RetornaAlbumEscolhido(s,id);
                PreencheUsuario(usu,albm);
                ImprimeUsuarioSistema(s);
                //MenuPlaylistUsuario;
                while(1){
                    int op1=0,id1=0;
                    MenuPlaylist();
                    op1=LerInteiros();
                    if(op1==1){//Apagar Playlist
                    ImprimeUsuario(usu);
                    printf("\n\t\tDigite o id da Playlist que deseja apagar: ");
                    id1=LerInteiros();
                    ApagaPlaylistUsuario(usu,id1);
                    ImprimeUsuario(usu);
                    break;
                    }
                    else if(op1==2){//Editar Playlist

                    }
                    else if(op1==3){break;}//Sair Menu

                    else {printf("\n\t\tOpcao Invalida, tente novamente!"); continue;}
                }
                
            }
            else if(opcao==2){
                //Nada
            }
            else if(opcao==3){break;}
            else {printf("\n\t\tOpcao Invalida, tente novamente!"); continue;}
        }
        continue;
    }

    else if(escolha==2){ 
                  
       //OPçao Desenvolvedor    
       printf("\n\t\tDigite a senha: ");
       int senha;
       senha=LerInteiros();
       if(!(VerificaSenhaDev(s,senha))){printf("\n\t\tSenha Incorreta!\n");continue;}   
       else {
         while(1){
            int id1=0,opcao1=0;  
            MenuDesenvolvedor();
            opcao1=LerInteiros();
            if(opcao1==1){
               //Criar Album
               PreencheSistemaComAlbum(s);
            }
            else if(opcao1==2){break;}
        }
        continue;
        }
    }
    else if(escolha==3){return 0;}
    
    else {printf("\n\t\tOpcao Invalida! Tente Novamente.");continue;}

    }     
return 0;
}

