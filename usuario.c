/*/#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"


struct usuario{   
    char *login;
    char *senha;
    int qtdplay;    
    //Playlist *play[5];
    //Playlist *favoritos;
};



Usuario* AlocaUsuario(){
    Usuario* u=(Usuario*)malloc(sizeof(Usuario));
    u->login=(char*)malloc(50);
    u->senha=(char*)malloc(50);
    return u;
}

Usuario* CriaUsuario(char* login,char* senha){
    Usuario* u=(Usuario*)malloc(sizeof(Usuario));
    u=AlocauUsuario();
    u->login=login;
    u->senha=senha;
    return u;
}

*/