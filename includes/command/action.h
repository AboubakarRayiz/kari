/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   action.h
 * Author: haranov
 *
 * Created on 3 janvier 2020, 22:45
 */

#ifndef ACTION_H
#define ACTION_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef enum _Action{
        controller,
        screen
    } Action;


    Action actionForString(char*);

    void generateController(char*);
    
    void generateScreen(char*, char*);
    
    void generateAppRoute();
    
    void generateAppDir();
    
    void generateAppModule();
    

#ifdef __cplusplus
}
#endif

#endif /* ACTION_H */

