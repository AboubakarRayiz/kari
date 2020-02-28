#include "../../includes/command/command.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

Command commandFromString(char* commandName){
    if(strcmp(commandName, "generate") == 0)
        return generate;   
    if(strcmp(commandName, "run") == 0)
        return 1;
    if(strcmp(commandName, "build") == 0)
        return 2;
    if(strcmp(commandName, "init") == 0)
        return 3;
    return -1;
}

Operation setOperation(char* command, int argNumber, ...){
    
   va_list args;
   int i;
   va_start(args, argNumber);
   for (i = 0; i < argNumber; i++) ;
   va_end(args);

}

int getCommande(char* commande){
    return commandFromString(commande);
}


char* toString(Command);