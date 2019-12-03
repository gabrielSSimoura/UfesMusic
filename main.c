#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "sistema.h"

void DadosMidia(Midia *m);
void DadosAlbum(Album *alb);
void DadosPlaylist(Playlist *play);
void DadosUsuario(Usuario *usu);



void AlteraMidia(Midia *m,int escolha);
void AlteraAlbum(Album *a,int escolha);
void AlteraPlaylist(Playlist *p, int escolha);

void PreencheSistemaComAlbum(Sistema *s);
void PreencheSistemaComUsuario(Sistema *s,Usuario *usu);
void PreencheAlbum(Album *a, int qtd);
void PreenchePlaylst(Playlist* p,Album *a);

char* LeDados();
int LerInteiros();
int VerificaOpcao(int opinicial, int opfinal);
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
        DadosMidia(m);        
        AdicionaMidiaAlbum(alb,m);
    }
}
 void DadosUsuario(Usuario *usu){
    
    char* lgin=(char*)malloc(50);
    char* snha=(char*)malloc(50);
    printf("\n\t\tLogin : ");
    lgin=LeDados();
    printf("\t\tSenha: ");
    snha=LeDados();
    CriaUsuario(usu,lgin,snha);    
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
void DadosMidia(Midia *m){
    
    char* nome=(char*)malloc(50);
    char* nomeArtista=(char*)malloc(50);
    char* nomeArtista2=(char*)malloc(50);
    char* nomeCompositor=(char*)malloc(50);
    char* nomeCompositor2=(char*)malloc(50);
    char* genero=(char*)malloc(50);
    char* produtora=(char*)malloc(50);
    int tipo,qtdA, qtdC;
    float duracao;

    printf("\n\t\tTipo da midia [01]Musica, [02]Video, [03]Podcast: ");
    tipo=LerInteiros();
    printf("\t\tNome da midia: ");
    nome=LeDados();
    printf("\t\tQuantidade de artistas (MAX 2): ");
    qtdA=LerInteiros();
    if(qtdA==1){
        printf("\t\tArtista [00]: ");
        nomeArtista=LeDados();
    }
    else if(qtdA==2){
         printf("\t\tArtista [00]: ");
        nomeArtista=LeDados();
         printf("\t\tArtista [01]: ");
        nomeArtista2=LeDados();
    }
    printf("\t\tQuantidade de Compositores (MAX 2): ");
    qtdC=LerInteiros();
    if(qtdC==1){
        printf("\t\tCompositor [00]: ");
        nomeCompositor=LeDados();
    }
    else if(qtdC==2){
         printf("\t\tCompositor [00]: ");
        nomeCompositor=LeDados();
         printf("\t\tCompositor [01]: ");
        nomeCompositor2=LeDados();
    }    
    printf("\t\tNome produtora: ");
    produtora=LeDados();
    printf("\t\tGenero: ");
    genero=LeDados();
    printf("\t\tDuracao: ");
    duracao=LerFloat();

    CriaMidia(m, nome, nomeArtista, nomeArtista2, nomeCompositor, nomeCompositor2,genero, produtora, tipo,duracao, qtdA,qtdC);
}
void DadosPlaylist(Playlist *play){
    
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

    CriaPlaylist(play,nomep,nomeColab1, nomeColab2, qtdColab, qtdMidia);
   
}
void AlteraMidia(Midia *m,int escolha){
    char *nome=(char*)malloc(50);
    int num,op,qtdA,qtdC;
    float fnum;
    if(escolha==1){
        printf("\n\t\tNome da midia: ");
        nome=LeDados();
        AtribuiNomeMidia(m,nome);
    }
    else if(escolha==2){   
            qtdA=RetornaQtdArtista(m);
            if(qtdA==1){     
                printf("\n\t\tNome do artista: ");
                nome=LeDados();
                AtribuiNomeArtista1(m,nome);
            }
            else if(qtdA==2){
                printf("\n\t\tQual dos Artistas deseja alterar (0 ou 1): ");
                op=LerInteiros();
                if(op==1){
                    printf("\n\t\tNome do artista: ");
                    nome=LeDados();
                    AtribuiNomeArtista1(m,nome);
                }
                else if(op==2){
                    printf("\n\t\tNome do artista: ");
                    nome=LeDados();
                    AtribuiNomeArtista2(m,nome);
                }
            }
        }
    else if(escolha==3){
        qtdC=RetornaQtdCompositor(m);
        if(qtdC==1){
            printf("\n\t\tNome Compositor: ");
            nome=LeDados();
            AtribuiNomeCompositor1(m,nome);
        }
        else if(qtdC==2){
            printf("\n\t\tQual dos Compositores deseja alterar (0 ou 1): ");
            op=LerInteiros();        
            if(op==1){
                printf("\n\t\tNome Compositor: ");
                nome=LeDados();
                AtribuiNomeCompositor1(m,nome);
            }
            else if(op==2){
                printf("\n\t\tNome Compositor: ");
                nome=LeDados();
                AtribuiNomeCompositor2(m,nome);
            }
        
        }
    }
        
    else if(escolha==4){
        printf("\n\t\tGenero: ");
        nome=LeDados();
        AtribuiNomeGenero(m,nome);
    }
    else if(escolha==5){
        printf("\n\t\tTipo, [01]Musica [02]Video [03]Podcast:  ");
        num=LerInteiros();
        AtribuiTipo(m,num);
    }
    else if(escolha==6){
        printf("\n\t\tDuracao: ");
        fnum=LerFloat();
        AtribuiDuracao(m,fnum);
    }
    else if(escolha==7){
       printf("\n\t\tNome produtora: ");
       nome=LeDados();
       AtribuiNomeProdutora(m,nome);
    }
}
void AlteraAlbum(Album *a,int escolha){
    char *nome=(char*)malloc(50);
    int num;    
    if(escolha==1){
        printf("\n\t\tNome do Album: ");
        nome=LeDados();
        AtribuiNomeAlbum(a,nome);
    }
    else if(escolha==2){
        printf("\n\t\tNome do artista: ");
        nome=LeDados();
        AtribuiArtistaAlbum(a,nome);
    }
    else if(escolha==3){
        printf("\n\t\tGenero: ");
        nome=LeDados();
        AtribuiGenero(a,nome);
    }
    else if(escolha==4){
       printf("\n\t\tNome produtora: ");
       nome=LeDados();
       AtribuiProdutoraAlbum(a,nome); 
    }
    else if(escolha==5){
        printf("\n\t\tAno do Album: ");
        num=LerInteiros();
        AtribuiAnoAlbum(a,num);
    }
}
void AlteraPlaylist(Playlist *p, int escolha){
    char *nome=(char*)malloc(50);
    int num;
    if(escolha==1){
        printf("\n\t\tNome da Playlist: ");
        nome=LeDados();
        AtribuiNomePlaylist(p,nome);        
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
        Usuario *usu=AlocaUsuario();
        DadosUsuario(usu);
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
                
                while(1){
                    int op1=0,id1=0,opMenuAltera=0;
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
                    else if(op1==2){
                        Playlist* play=AlocaPlaylist();
                        ImprimeUsuario(usu);
                        printf("\n\t\tDigite o id da Playlist que deseja editar: ");
                        id1=LerInteiros();
                        play=RetornaPlaylistUsuario(usu,id1);
                        while(1){
                            opMenuAltera=0;
                            MenuAlteraPlaylist();
                            opMenuAltera=LerInteiros();
                            if(opMenuAltera<1 || opMenuAltera>2){continue;}
                            else if(opMenuAltera==2){opMenuAltera=0;break;}
                            else {AlteraPlaylist(play,opMenuAltera);opMenuAltera=0;break;}
                        }
                    }
                    else if(op1==3){break;}//Sair Menu

                    else {printf("\n\t\tOpcao Invalida, tente novamente!"); continue;}
                }                
            }
            else if(opcao==2){
                //Pesquisar:
                while(1){
                    int op=0;
                    char *nomes;
                    MenuPesquisar();
                    op=LerInteiros();
                    if(op==1){//Nome Album
                        printf("\n\t\tDigite o nome do Album que deseja pesquisar: ");
                        nomes=LeDados();
                        PequisarNomeAlbum(s,nomes);
                        continue;
                    }
                    else if(op==2){//Nome Midia
                        printf("\n\t\tDigite o nome da Midia que deseja pesquisar: ");
                        nomes=LeDados();
                        PesquisarNomeMidia(s,nomes);
                        continue;
                    }
                    else if(op==3){//Nome Artista
                        printf("\n\t\tDigite o nome do Artista que deseja pesquisar: ");
                        nomes=LeDados();
                        PesquisarNomeArtista(s,nomes);
                        continue;
                    }
                    else if(op==4){
                        printf("\n\t\tDigite o nome do Compositor que deseja pesquisar: ");
                        nomes=LeDados();
                        PesquisarNomeCompositor(s,nomes);
                    }
                    else if(op==5){
                        printf("\n\t\tDigite o nome da Produtora que deseja pesquisar: ");
                        nomes=LeDados();
                        PesquisarProdutora(s,nomes);
                        
                    }
                    else if(op==6){
                        printf("\n\t\tDigite o Genero que deseja pesquisar: ");
                        nomes=LeDados();
                        PesquisarGenero(s,nomes);
                    }
                    else if(op==7){break;}
                    else continue;
                }            
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
               PreencheSistemaComAlbum(s);
            }
            else if(opcao1==3){//Editar Album;
                int alb=0;
                 int opA=0;
                Album *alterar=AlocaAlbum();
                ImprimeAlbunsSistema(s);
                printf("Escolha o Album que deseja editar: ");
                alb=LerInteiros();
                alterar=RetornaAlbumEscolhido(s,alb);
                while(1){
                    opA=0;
                    MenuAlteraAlbum();
                    opA=LerInteiros();
                    if(opA<1 ||opA>6){continue;}
                    else if(opA==6){opA=0;break;}
                    else{AlteraAlbum(alterar,opA); opA=0; break;}
                }                
            }
            else if(opcao1==2){//EditarMidia
                int mid=0,alb=0, opM=0;
                Album *alterar=AlocaAlbum();
                Midia *midiaAltera=AlocaMidia();
                ImprimeAlbunsSistema(s);
                printf("\n\t\tSelecione o Album: ");
                alb=LerInteiros();
                alterar=RetornaAlbumEscolhido(s,alb);
                ImprimeAlbum(alterar);
                printf("Escolha a Midia que deseja editar: ");
                mid=LerInteiros();
                midiaAltera=RetornaMidia(s,alb,mid);
                while(1){
                    opM=0;
                    MenuAlteraMidia();
                    opM=LerInteiros();
                    if(opM<1 || opM>8){continue;}
                    else if(opM==8){opM=0;break;}
                    else{AlteraMidia(midiaAltera,opM);opM=0; break;}
                }
                
            }
         if(opcao1==4){break;}   
        }
        continue;
        }
    }
    else if(escolha==3){return 0;}    
    else {printf("\n\t\tOpcao Invalida! Tente Novamente.");continue;}
    }     
return 0;
}

