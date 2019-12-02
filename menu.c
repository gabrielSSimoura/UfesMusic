#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "sistema.h"


int MenuInicial(){
    
    printf("\n\t\tBem Vindo!\t\t\n");
    printf("\t\t|----------Ufes Music----------|\t\t\n");    
    printf("\t\t|[01]------Cria Usuario--------|\t\t\n");     
    printf("\t\t|[02]--Opcao de Desenvolvedor--|\t\t\n");   
    printf("\t\t|[03]-----Sair do Programa-----|\t\t\n\n"); 

    printf("\t\tDigite uma das Opcoes: ");
    
}

void MenuUsuario(){
    char opcao,lixo;
    
    printf("\n\t\t|[01]------Cria Playlist--------|\t\t\n");
    printf("\t\t|[02]-------Pesquisar-----------|\t\t\n");
    printf("\t\t|[03]-----Sair do Programa------|\t\t\n");
    printf("\t\tO que gostaria de fazer ?: ");   
}


void MenuPlaylist (){
    printf("\n\t\t|[01]-------Apagar Playlist-------|\t\t\n");
    printf("\t\t|[02]-------Editar Playlist-------|\t\t\n");
    printf("\t\t|[03]--------Sair do Menu---------|\t\t\n");
    printf("\t\tO que gostaria de fazer ?: ");
        
}


void MenuDesenvolvedor(){
    printf("\n\t\tBem Vindo Desenvolvedor ! O que deseja fazer?\n");
    printf("\t\t|-----------Ufes Music---------|\t\t\n");    
    printf("\t\t|[01]-------Criar Album--------|\t\t\n");     
    printf("\t\t|[02]------Sair do Menu--------|\t\t\n");   

    printf("\t\tDigite uma das Opcoes: ");    
}

void MenuPesquisar(){
    printf("\n\t\tPesquisar por: ");    
    printf("\t\t|[01]-------Nome do Album--------|\t\t\n");
    printf("\t\t|[02]-------Nome da Midia--------|\t\t\n");     
    printf("\t\t|[03]----------Artista-----------|\t\t\n");
    printf("\t\t|[04]---------Compositor---------|\t\t\n");
    printf("\t\t|[05]---------Produtora----------|\t\t\n");
    printf("\t\t|[06]----------Genero------------|\t\t\n");
    printf("\t\t|[07]--------Sair do Menu--------|\t\t\n");   

    printf("\t\tDigite uma das Opcoes: ");    


}