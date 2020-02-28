/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: haranov
 *
 * Created on 3 janvier 2020, 18:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "includes/command/command.h"
#include "includes/command/action.h"
#include "includes/core.h"
#include "includes/sys/sys.h"

void printProgName(char* fullPath){
    char* begin = rindex(fullPath, (int)'/');
    short i=0;
    if(begin != NULL){
        begin = begin+1;
        printf("%s",begin);
    }
    /*
    if(begin != NULL){
        begin = begin+1;
        while(begin !reflectable: any\n"
                        "\tbuild_runner: any\n"
                        "\tbuild: '>=0.12.0 <2.0.0'\n"  
                        "\tsource_gen: ^0.9.0\n"
                        "\tview_reporter: \n" 
                        "\t\tpath: lib/core/view/= NULL && *begin != '\0'){
//        for(i=begin+1; i<strlen(fullPath); i++)
            printf("%c",*begin);
            begin = begin+1;
        }
    }
    */
}
/*
 * 
 */
int main(int argc, char** argv) {
    /**
     * Modification du pubspec.yaml
     * 
     * creer le dossier app
     * creer app/routes/Routes.dart
     * creer app/app.module.dart
     * copier core
     * changer le nom du projet pour l'import 'package:kari/core/view/view_reporter.dart dans core/view/generator/lib/src/view_reporter_generator.dart 
     * changer le nom du projet pour l'import 'package:kari/core/view/generator/lib/src/view_reporter_generator.dart dans core/view/generator/lib/builder.dart 
     * changer le nom du projet pour l'import 'package:kari/core/view/generator/lib/builder.dart dans core/view/generator/build.yaml
     * executer flutter package get et flutter pub get ds core
     */
    
    short commande = -1, action = -1;
    char *arg, *param, code[6];
    
    getFlutterProjectName();
    checkSupportedOs();
    
    
    
    if(argc == 2){
        commande = commandFromString(*(argv+1));
        if(commande == 1){
            if(system("flutter packages pub run build_runner build --delete-conflicting-outputs ") == 0)
                system("flutter run");
            exit(EXIT_SUCCESS);
        }
        if(commande == 2){
            if(system("flutter packages pub run build_runner build --delete-conflicting-outputs") == 0)
                system("flutter build");
            exit(EXIT_SUCCESS);
        }
        if(commande == 3){
            generateAppDir();
            generateAppModule();
            generateAppRoute();
            setDependencies();
            exit(EXIT_SUCCESS);
        }
        printf("\n>>Usage: ");
        printProgName(*argv);
        printf(" help");
        return (EXIT_SUCCESS);
    }
    if(argc == 4){
        commande = commandFromString(*(argv+1));
        action = actionForString(*(argv+2));
        arg = *(argv+3); 
        if(commande == -1 || action == -1){
            printf("\n>>Usage: ");
            printProgName(*argv);
            printf(" help");
            return (EXIT_SUCCESS);
        }
        sprintf(code, "%d%d",commande, action);
        printf("code = '%s'\n", code);
        if(strcmp(code,"00") != 0){
            printf("\n>>Usage: ");
            printProgName(*argv);
            printf(" help");
            return (EXIT_SUCCESS);
        }
        generateController(arg);
        return (EXIT_SUCCESS);
    }
    if(argc == 5){
        
        printf("%s e",*(argv+1));
        commande = commandFromString(*(argv+1));
        action = actionForString(*(argv+2));
        arg = *(argv+3);
        param = *(argv+4);
        if(commande == -1 || action == -1){
            printf("%s help", *(argv));
            return (EXIT_SUCCESS);
        }
        sprintf(code, "%d%d",commande, action);
        generateScreen(arg, param);
        return (EXIT_SUCCESS);
    
    }
    printf("nbr = %d",argc);
    setOperation("generate", 3, "controller", "view", "item");
    return (EXIT_SUCCESS);
}

/**
 * karee generate controller PatController
 * karee generate view       PatPage        pat
 **/