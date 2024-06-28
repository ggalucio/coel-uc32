/*
 * user.cpp
 *
 *  Created on: 28 lug 2021
 *      Author: paoloc
 */


#include "../Inc/user.hpp"

uint8_t isLogged;

void Login(uint8_t login){
	isLogged = login;
}

uint8_t IsLogged(){
	return isLogged;
}

void Logout(){
	isLogged = 0;
}
