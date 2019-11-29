/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "playlist.h"
#include "midia.h"
#include "album.h"
#include "servidor.h"
#include "usuario.h"


#define TAM2 51
#define TAM 20

struct album{
    char *nomeDoAlbum;
    char *artista;
    int anoDoAlbum;
    char *genero;
    char* compositores[3];
    Midia *midia[50];  
    int qtdCompositores;
    int qtdMidias;   
};
struct midia{
    char *nomeDaMidia; 
    char *nomeDoCantor;
    char *nomeDoCompositor[3];
    int qtdCompositores;
    char *genero;
    char *gravadora;
    float duracao;
    char *artista;
    char *produtor;
    int tipo; //1.musica,2.video,3.podcast;
};

struct playlist{
    char *nomePlaylist;
    int tipo;//1publica,2privada;
    char *donoPlaylist[2];
    int quantDeDonos;
    int quantDeMidias;
    Midia *midias[TAM2];
};

struct usuario{
    char *nome;
    char *login;
    char *senha;    
    Playlist *play[11];
    int quantplay;
    Playlist *favoritos;
};

 struct servidor{
    Album *listaalbum[20];         //Leitura do arquivo p/struct servidor ta funcionando!!
    int qtdAlbum;
    int qtdUsuario;
    int ID;
    Usuario *atual;
    Usuario *users[20]; 

};

int MenuInicial(){
    
    printf("\n\t\tBem Vindo!\t\t\n");
    printf("\t\t|----------Ufes Music----------|\t\t\n");    
    printf("\t\t|[01]------Cria Usuario--------|\t\t\n");     
    printf("\t\t|[02]--Opçao de Desenvolvedor--|\t\t\n");   
    printf("\t\t|[03]-----Sair do Programa-----|\t\t\n\n"); 

    printf("\t\tDigite uma das Opcoes: ");
    
}



void OpcaoPesquisar(Servidor *server){
    char opcao,lixo;
    int op;    
    
    printf("\t\t|[01]---Usuarios---|\t\t\n");
    printf("\t\t|[02]----Albuns----|\t\t\n");
    printf("\t\tO que gostaria de pesquisar?: ");
    scanf("%c",&opcao);
    scanf("%c",&lixo);
    while (opcao<'1' || opcao>'2'){
        printf("\t\tOpcao Invalida, tente novamente: ");
        scanf("%c",&opcao);
        scanf("%c",&lixo);          
    }
    printf("\n\n");
    
    if(opcao=='1'){
        if(server->qtdUsuario==0){
            printf("\t\tNao ha Usuarios\n");
            printf("\t\tDeseja Voltar para o menu Inicial? [01]Sim [02]Nao: ");
            scanf("%c",&opcao);
            scanf("%c",&lixo);
            while (opcao<'1' || opcao>'2'){
                printf("\t\tOpcao Invalida, tente novamente: ");
                scanf("%c",&opcao);
                scanf("%c",&lixo);          
            }
            if(opcao=='1'){
                MenuInicial(server);
            }
            else if(opcao=='2'){
                OpcaoPesquisar(server);
            }
        
        }
        else{
            for(int i=0;i<server->qtdUsuario;i++){                
                printf("\t\t|[%02d] %s\n",i,server->users[i]->nome);
                
            }
        }

    }
    
    else if(opcao=='2'){
        
        for(int i=0;i<server->qtdAlbum;i++){
            printf("\t\t[%02d] %s\n",i,server->listaalbum[i]->nomeDoAlbum);                     
            }
            printf("\n\t\tQual album deseja acessar?: ");
            scanf("%d",&op);
            scanf("%c",&lixo);
            while (op<0|| op>server->qtdAlbum){
                printf("\t\tOpcao Invalida, tente novamente: ");
                scanf("%d",&op);
                scanf("%c",&lixo);           
            
        }
         ImprimeAlbumDados(server->listaalbum[op]);
    }
}

void OpcaoUsuario(Servidor *server){
    char opcao,lixo;
    
    printf("\t\t|[01]------Cria Playlist--------|\t\t\n");
    printf("\t\t|[02]-------Pesquisar-----------|\t\t\n");
    printf("\t\t|[03]-----Sair do Programa------|\t\t\n");
    printf("\t\tO que gostaria de fazer ?: ");
    
    scanf("%c",&opcao);
    scanf("%c",&lixo);
    while (opcao<'1' || opcao>'3'){
        printf("\t\tOpcao Invalida, tente novamente: ");
        scanf("%c",&opcao);
        scanf("%c",&lixo);          
    }
    if(opcao=='1'){

        server->users[server->qtdUsuario-1]->play[server->users[server->qtdUsuario-1]->quantplay]=CriaPlaylist();
        server->users[server->qtdUsuario-1]->quantplay++;
        MenuPlaylist(server);
    }

    else if(opcao=='2'){ OpcaoPesquisar(server);OpcaoUsuario(server);}        
             
    
    else if(opcao=='3'){
        printf("\t\tEncerrar Ufes Music: \n\t\t[01]--Sim\n\t\t[02]--Nao\n");
        scanf("%c",&opcao);
        scanf("%c",&lixo);
        while (opcao<'1' || opcao>'2'){
            printf("\t\tOpcao Invalida, tente novamente: ");
            scanf("%c",&opcao);
            scanf("%c",&lixo);          
        }
        if(opcao=='1'){exit (1);}
        else if(opcao=='2'){MenuInicial(server);}       

    }
}


void MenuPlaylist (Servidor *server){
    char opcao,lixo;
    printf("\n");
    printf("\t\t|[01]---------Adicionar Midias----------|\t\t\n");
    printf("\t\t|[02]------------Pesquisar--------------|\t\t\n");
    printf("\t\t|[03]------Voltar ao Menu da Conta------|\t\t\n");
    printf("\t\tO que gostaria de fazer ?: ");

    scanf("%c",&opcao);
    scanf("%c",&lixo);
    while (opcao<'1' || opcao>'3'){
        printf("\t\tOpcao Invalida, tente novamente: ");
        scanf("%c",&opcao);
        scanf("%c",&lixo);          
    }

    if(opcao=='1'){       
         AdicionaMidiaPlaylist(server);
        printf("\n\t\tDeseja Visualizar Playlist: [01] Sim [02]Nao");
        scanf("%c",&opcao);
        scanf("%c",&lixo);
        while (opcao<'1' || opcao>'3'){
            printf("\t\tOpcao Invalida, tente novamente: ");
            scanf("%c",&opcao);
            scanf("%c",&lixo);          
        }
        if(opcao=='1'){
            ImprimePlaylist(server->users[server->qtdUsuario-1]->play[server->users[server->qtdUsuario-1]->quantplay-1]);
        }
        else if(opcao=='2'){MenuPlaylist(server);}
        
    }
    else if(opcao=='2'){ OpcaoPesquisar(server);MenuPlaylist(server);}  

    else if(opcao=='3'){OpcaoUsuario(server);}

}
*/