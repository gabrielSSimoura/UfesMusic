#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"



void MenuInicial(){
   // system("clear");
    printf("\n\t\tBem Vindo!\t\t\n");
    printf("\t\t|----------Ufes Music----------|\t\t\n");    
    printf("\t\t|[01]------Cria Usuario--------|\t\t\n");     
    printf("\t\t|[02]--Opcao de Desenvolvedor--|\t\t\n"); 
    printf("\t\t|[03]----------Login-----------|\t\t\n");
    printf("\t\t|[04]-----Sair do Programa-----|\t\t\n\n"); 

    printf("\t\tDigite uma das Opcoes: ");
    setbuf(stdin, NULL); 
    
}

void MenuUsuario(){
   // system("clear");
    printf("\n\t\t|[01]------Cria Playlist--------|\t\t\n");
    printf("\t\t|[02]----Pesquisar Usuarios-----|\t\t\n");
    printf("\t\t|[03]--Criar Playlist Favorita--|\t\t\n");
    printf("\t\t|[04]--------Ver Conta----------|\t\t\n");
    printf("\t\t|[05]-----Sair do Programa------|\t\t\n");
    printf("\t\tO que gostaria de fazer ?: ");  
    setbuf(stdin, NULL);  
}


void MenuPlaylist (){
    
    printf("\n\t\t|[01]-------Apagar Playlist-------|\t\t\n");
    printf("\t\t|[02]-------Editar Playlist-------|\t\t\n");
    printf("\t\t|[03]--------Sair do Menu---------|\t\t\n");
    printf("\t\tO que gostaria de fazer ?: ");
    setbuf(stdin, NULL); 
        
}


void MenuDesenvolvedor(){
   // system("clear");
    printf("\n\t\tBem Vindo Desenvolvedor ! O que deseja fazer?\n");
    printf("\t\t|-----------Ufes Music---------|\t\t\n");    
    printf("\t\t|[01]-------Criar Album--------|\t\t\n");
    printf("\t\t|[02]-------Editar Midia-------|\t\t\n");
    printf("\t\t|[03]-------Editar Album-------|\t\t\n");     
    printf("\t\t|[04]------Sair do Menu--------|\t\t\n");   

    printf("\t\tDigite uma das Opcoes: ");   
    setbuf(stdin, NULL);  
}

void MenuPesquisar(){
    
    printf("\n\t\tPesquisar por: ");    
    printf("\n\t\t|[01]-------Nome do Album--------|\t\t\n");
    printf("\t\t|[02]-------Nome da Midia--------|\t\t\n");     
    printf("\t\t|[03]----------Artista-----------|\t\t\n");    
    printf("\t\t|[04]---------Compositor---------|\t\t\n");
    printf("\t\t|[05]---------Produtora----------|\t\t\n");
    printf("\t\t|[06]-----------Genero-----------|\t\t\n"); 
    printf("\t\t|[07]--------Sair do Menu--------|\t\t\n");     

    printf("\t\tDigite uma das Opcoes: "); 
    setbuf(stdin, NULL);    
}

void MenuAlteraAlbum(){
    
    printf("\n\t\tO que deseja Alterar: ");    
    printf("\n\t\t|[01]--------Nome do Album--------|\t\t\n");    
    printf("\t\t|[02]-----------Artista-----------|\t\t\n");    
    printf("\t\t|[03]------------Genero-----------|\t\t\n");
    printf("\t\t|[04]----------Produtora----------|\t\t\n"); 
    printf("\t\t|[05]---------Ano do Album--------|\t\t\n");
    printf("\t\t|[06]---------Sair do Menu--------|\t\t\n");     

    printf("\t\tDigite uma das Opcoes: "); 
    setbuf(stdin, NULL);  
}

void MenuAlteraMidia(){
    
    printf("\n\t\tO que deseja Alterar: ");    
    printf("\n\t\t|[01]--------Nome da Midia--------|\t\t\n");    
    printf("\t\t|[02]-----------Artista-----------|\t\t\n");    
    printf("\t\t|[03]-----------Compositor--------|\t\t\n");
    printf("\t\t|[04]------------Genero-----------|\t\t\n"); 
    printf("\t\t|[05]-------------Tipo------------|\t\t\n");
    printf("\t\t|[06]------------Duracao----------|\t\t\n");  
    printf("\t\t|[07]-----------Produtora---------|\t\t\n");     
    printf("\t\t|[08]---------Sair do Menu--------|\t\t\n");     


    printf("\t\tDigite uma das Opcoes: "); 
    setbuf(stdin, NULL);  
}

void MenuAlteraPlaylist(){
    
    printf("\n\t\tO que deseja Alterar: ");    
    printf("\n\t\t|[01]----Nome da Playlist---|\t\t\n");
    printf("\t\t|[02]------Apagar Midia-----|\t\t\n");      
    printf("\t\t|[03]------Sair do Menu-----|\t\t\n");
    printf("\t\tDigite uma das Opcoes: "); 
    setbuf(stdin, NULL);  

}