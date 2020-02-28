/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   command.h
 * Author: haranov
 *
 * Created on 3 janvier 2020, 18:54
 */

#ifndef COMMAND_H
#define COMMAND_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef enum _Command{
        generate,
        run
    } Command;
    
    typedef struct _Operation{
        Command commande;
        char* commandeStringify;
        Command (*fromString)(char*);
        char* (*toString)(Command);
    } Operation;
    
    Operation setOperation(char*, int, ...);
    
    Command commandFromString(char*);
    

    char* toString(Command);


#ifdef __cplusplus
}
#endif

#endif /* COMMAND_H */

