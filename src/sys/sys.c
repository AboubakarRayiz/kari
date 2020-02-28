/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../../includes/sys/sys.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


const char *getPlatformName() {
    return (PLATFORM_NAME == NULL) ? "UNKNOWN" : PLATFORM_NAME;
}

void checkSupportedOs(){
    
    if(strcmp(PLATFORM_NAME, "linux") == 0){
        
    }else if(strcmp(PLATFORM_NAME, "windows") == 0){
        
    }else if(strcmp(PLATFORM_NAME, "osx") == 0){
        
    }else {
        fprintf(stderr, "System %s not supported", getPlatformName());
        exit(EXIT_FAILURE);
    }
}

int isRegularFile(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode) != 0 ? true : false;
}


int isDirectory(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode) != 0 ? true : false;
}

int rm(char* path){
    char* command;
    checkSupportedOs();
    if(path != null && access(path, F_OK)  == 0){
        if(command != null){
            if(strcmp(PLATFORM_NAME, "linux") == true || strcmp(PLATFORM_NAME, "osx") == true){
                if(isDirectory(path) == true || isRegularFile(path) == true){
                    command = (char*) malloc(sizeof(char)*(strlen(path)+6));
                    if(command != null){
                        sprintf(command, "rm -r %s", path);
                        system(command);
                        free(command);
                    }
                }
            }else if(strcmp(PLATFORM_NAME, "windows")){
                if(isDirectory(path) == true){
                    command = (char*) malloc(sizeof(char)*(strlen(path)+13));
                    if(command != null){
                        sprintf(command, "rmdir \"%s\" /s /q", path);
                        system(command);
                        free(command);
                    }
                }
                if(isRegularFile(path) == true){
                    command = (char*) malloc(sizeof(char)*(strlen(path)+7));
                    if(command != null){
                        sprintf(command, "del %s", path);
                        system(command);
                        free(command);
                    }
                }
                sprintf(command, "%s", path);
            }else {//(strcmp(PLATFORM_NAME, "osx")){
                
            }
            free(command);
        }
    }
   
    return true;
}
    
int makedir(char* path){
    char* command;
    if(path != null){
        if(strcmp(PLATFORM_NAME, "linux") == true || strcmp(PLATFORM_NAME, "osx") == true){
            command = (char*) malloc(sizeof(char)*(strlen(path)+10));
            if(command != null){
                sprintf(command, "mkdir -p %s",path);
                system(command);
                free(command);
                return true;
            }else
                return false;
        }else { // windows
            command = (char*) malloc(sizeof(char)*(strlen(path)+10));
            if(command != null){
                sprintf(command, "mkdir \"%s\"",path);
                system(command);
                free(command);
                return true;
            }else
                return false;
        }
    }
    return true;
}

int mv(char* from, char* to){
    char* command;
    if(from != null && to != null){
        if(strcmp(PLATFORM_NAME, "linux") == true || strcmp(PLATFORM_NAME, "osx") == true){
            command = (char*) malloc(sizeof(char)*(strlen(from)+5+strlen(to)));
            if(command != null){
                sprintf(command, "mv %s %s",from, to);
                system(command);
                free(command);
                return true;
            }else
                return false;
        }else { // windows
            command = (char*) malloc(sizeof(char)*(strlen(from)+10+strlen(to)));
            if(command != null){
                sprintf(command, "move %s %s",from, to);
                system(command);
                free(command);
                return true;
            }else
                return false;
        }
    }else
        return false;
    return true;
}
