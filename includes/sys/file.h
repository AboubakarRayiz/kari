/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   file.h
 * Author: haranov
 *
 * Created on 16 janvier 2020, 23:19
 */

#ifndef KAREE_FILE_H
#define KAREE_FILE_H

#ifdef __cplusplus
extern "C" {
#endif
    #define true 0
    #define false 1
    #define null NULL
    #define SAVE_CONTROLLER ".save-controller"
    #define SAVE_SCREENS ".save-screens"

    #define APP_CONTROLLERS_DIR "/app/controllers/"
    #define APP_SCREENS_DIR "/app/screens/"
    #define APP_ROUTES_DIR "lib/app/routes/"
    #define APP_DIR "lib/app/"

    #define APP_SCREENS_FILE "lib/app/screens.dart"
    #define APP_CONTROLLERS_FILE "lib/app/controllers.dart"
    #define APP_ROUTES_FILE "lib/app/Routes.dart"
    #define APP_MODULE_FILE "lib/app/app.module.dart"
    
    

#ifdef __cplusplus
}
#endif

#endif /* FILE_H */

