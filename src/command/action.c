#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../../includes/command/action.h"
#include "../../includes/core.h"
#include "../../includes/sys/sys.h"


Action actionForString(char* action){
    
    if(strcmp("screen", action) == 0){
        return screen;
    }
    if(strcmp("controller", action) == 0){
        return controller;
    }
    return -1;
}


    void generateController(char* name){
        
        char path[1000], uri[1000];
        char charRead;
        FILE* screenTemplate;
        char* controllerClassName;
        char* subPath = rindex(name, '/');
        char  additionalPath[1000], command[1010];
        char* counter;
        int   i = 0;
        FILE *controllerTemplate, *controllerManager, *save;
        
        if(subPath != NULL){
            controllerClassName = (subPath+1);
            subPath = (char*) malloc(sizeof(char)*(strlen(name)-strlen(controllerClassName))+1);
            counter = name;
            while( counter[0] == '/')
                counter = counter+1;
            while(counter != controllerClassName){
                subPath[i] = counter[0];
                counter = counter+1;
                i++;
            }
            subPath[i] = '\0';
        }else{
            controllerClassName = name;
            subPath = (char*) malloc(sizeof(char)*1);
            subPath[0] = '\0';
        }
        sprintf(uri, "%s%s",APP_CONTROLLERS_DIR,subPath);
        sprintf(additionalPath, "lib%s",uri);
        sprintf(path,"%s%sController.dart", additionalPath,controllerClassName);
        makedir(additionalPath);
        sprintf(uri, "%s%sController.dart",uri,controllerClassName);
        free(subPath);
        
        controllerTemplate = fopen(path, "w+");
        fprintf(controllerTemplate,""
        "import \"package:%s/core/core.dart\";\n\n"
        "@controller\n"
        "class %sController{\n\n"
        "   String index(){\n"
        "       return \"Hello Welcome to %sController\";\n"
        "   }\n"
        "}\n", flutterProjetName, controllerClassName, controllerClassName);
        fclose(controllerTemplate);
                
        if( access( APP_CONTROLLERS_FILE, F_OK ) == -1){
            controllerManager = fopen(APP_CONTROLLERS_FILE, "w+");
            fprintf(controllerManager, "\n"
                "List<dynamic> controllers = [\n"
                "\n"
            "];");
            fclose(controllerManager);
        }
        
        mv(APP_CONTROLLERS_FILE, SAVE_CONTROLLER);
        controllerManager = fopen(APP_CONTROLLERS_FILE, "w+");
        save = fopen(SAVE_CONTROLLER, "r");
        
        if(controllerManager != NULL && save != NULL){
            fseek(controllerManager, 0, SEEK_SET);
            fprintf(controllerManager, "import \"package:%s%s\";\n",flutterProjetName, uri);
            while((charRead = fgetc(save)) != EOF){
                fprintf(controllerManager, "%c",charRead);
            }
            fseek(controllerManager, -3, SEEK_CUR);
            fprintf(controllerManager, "\n\t%sController(),\n];", controllerClassName);
            fclose(controllerManager);
            fclose(save);
        }else{
            fprintf(stderr, "Error occurs while subscribing %sController in Karee core", controllerClassName);
            exit(EXIT_FAILURE);
        }
        
    }



    void generateScreen(char* screenName, char* name){
        char path[1000], uri[1000];
        FILE* screenTemplate, *screenManager, *save;
        char charRead;
        char* screenClassName;
        char* subPath = rindex(screenName, '/');
        char  additionalPath[1000], command[1010];
        char* counter;
        int   i = 0;
        if(subPath != NULL){
            screenClassName = (subPath+1);
            subPath = (char*) malloc(sizeof(char)*(strlen(screenName)-strlen(screenClassName))+1);
            counter = screenName;
            while( counter[0] == '/')
                counter = counter+1;
            while(counter != screenClassName){
                subPath[i] = counter[0];
                counter = counter+1;
                i++;
            }
            subPath[i] = '\0';
        }else{
            screenClassName = screenName;
            subPath = (char*) malloc(sizeof(char)*1);
            subPath[0] = '\0';
        }
        sprintf(uri, "%s%s",APP_SCREENS_DIR, subPath);
        sprintf(additionalPath, "lib%s",uri);
        sprintf(path,"%s%s-screen.dart", additionalPath,screenClassName);
        makedir(additionalPath); //sprintf(command, "mkdir -p %s",additionalPath);
        //system(command);
        sprintf(uri, "%s%s-screen.dart",uri,screenClassName);
        free(subPath);

        screenTemplate = fopen(path, "w+");
        fprintf(screenTemplate,
        " " 
        "\n\nimport \"package:flutter/material.dart\";\n"
        "import \"package:%s/core/core.dart\";\n\n"
        "@Screen(\"%s\")\n"
        "class %sScreen extends StatefulWidget{\n"
        "   @override\n"
        "   _%sScreenState createState() => _%sScreenState();\n"
        "}\n\n"
        "class _%sScreenState extends State<%sScreen> {\n\n"
        "   @override\n"
        "   Widget build(BuildContext context) {\n"
        "       return Scaffold(\n"
        "           body: Center(\n"
        "               child: Text(\"%sScreen Works!!! :)\")\n"
        "           )\n"
        "       );\n"
        "   }\n"
        "\n"
        "}\n", flutterProjetName, name, screenClassName, screenClassName, screenClassName, screenClassName, screenClassName, screenClassName);
        
        fclose(screenTemplate);
                
        if( access(APP_SCREENS_FILE, F_OK ) == -1){
            screenManager = fopen(APP_SCREENS_FILE, "w+");
            fprintf(screenManager, "import 'package:flutter/widgets.dart';\n\n"
                "Map<String, Widget> screens = {\n"
                "\n"
            "};");
            fclose(screenManager);
        }
        
        mv(APP_SCREENS_FILE, SAVE_SCREENS);
        screenManager = fopen(APP_SCREENS_FILE, "w+");
        save = fopen(SAVE_SCREENS, "r");
        
        if(screenManager != NULL && save != NULL){
            fseek(screenManager, 0, SEEK_SET);
            fprintf(screenManager, "import \"package:%s%s\";\n",flutterProjetName, uri);
            while((charRead = fgetc(save)) != EOF){
                fprintf(screenManager, "%c",charRead);
            }
            //fseek(screenManager, 2, SEEK_END);
            fseek(screenManager, -3, SEEK_CUR);
            fprintf(screenManager, "\n\t\"%s\": %sScreen(),\n};", name, screenClassName);
            fclose(screenManager);
            fclose(save);
        }else{
            fprintf(stderr, "Error occurs while subscribing %sScreen in Karee core", screenClassName);
            exit(EXIT_FAILURE);
        }
        
    }

    
    
    void generateAppRoute(){
        FILE* routeFile;
        
        makedir(APP_ROUTES_DIR);
        routeFile = fopen(APP_ROUTES_FILE, "w+");
        fclose(routeFile);
        
    }
    
    void generateAppDir(){        
        makedir(APP_DIR);
    }
    
    void generateAppModule(){
        FILE* moduleFile;
        moduleFile = fopen(APP_MODULE_FILE, "w+");
            fprintf(moduleFile, "export 'controllers.dart';\nexport 'screens.dart';\n");
        fclose(moduleFile);
        
    }
