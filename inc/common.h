/* common header file for project */

#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <personal_d.h>

#define BUFF 256
#define MAXBUFF 1024

int signUpInMenu();

int signIn();
int mainMenu();
void welcomeScreen();
void rLeadingWS(char *, char *);

#endif