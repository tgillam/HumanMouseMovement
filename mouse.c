#include <stdio.h>
#include <stdlib.h>
#define WINVER 0x0500
#include <windows.h>
#include "mouse.h"

/*
 * Created by Tyler Gillam in Fall 2018 as a side project
 * Code needs to be refactored to be more readable as well as refactoring all of the if-elses
 * Free to use and modify
 */
//TODO: Refactor code into multiple methods and files to improve readability and modularity
//moves mouse to position x,y using a human like algorithm
void moveMouse(int x, int y){
	int a = 0;
	int b = 0;
	int mouseTimes = rand()%10;
	for(int i = 0; i<mouseTimes; i++){
		int speed = rand()%3+3;
	    POINT cursor;
	    GetCursorPos(&cursor);
	    int startX = cursor.x;
	    int startY = cursor.y;
	    int xDiff = 0;
	    int yDiff = 0;
	    int xRand = 0;
	    int yRand = 0;
	    if(x>cursor.x){
	    	xDiff = (x-cursor.x)*.5;
	    }
	    else{
	    	xDiff = (cursor.x - x)*.5;
	    }
	    if(y>cursor.y){
	    	yDiff = (y-cursor.y)*.5;
	    }
	    else{
	    	yDiff = (cursor.y - y)*.5;
	    }
	    if(xDiff != 0){
	    	xRand = rand()%xDiff;
	    }
	    else{
	    	xRand = 0;
	    }
	    if(yDiff != 0){
	    	yRand = rand()%yDiff;
	    }
	    else{
	    	yRand = 0;
	    }
	    if(x>startX && y>startY){
	    	randomizeMouse(startX+xRand, startY+yRand, speed);
	    }
	    else if(x>startX && y<startY){
	    	if((startY - yRand) <= 0){
	    		b = 0;
	    	}
	    	else{
	    		b = (startY - yRand);
	    	}
	    	randomizeMouse(startX+xRand, b, speed);
	    }
	    else if(x<startX &&y>startY){
	    	if((startX - xRand) <= 0){
	    		a = 0;
	    	}
	    	else{
	    		a = (startX - xRand);
	    	}
	    	randomizeMouse(a, startY+yRand, speed);
	    }
	    else if(x<startX &&y<startY){
	    	if((startY - yRand) <= 0){
	    		b = 0;
	    	}
	    	else{
	    		b = (startY - yRand);
	    	}
	    	randomizeMouse(startX-xRand, b, speed);
	    }
	    else{
	    	if((startY - yRand) <= 0){
	    		b = 0;
	    	}
	    	else{
	    		b = (startY - yRand);
	    	}
	    	randomizeMouse(startX-xRand, b, speed);
	    }
	}
	int speed = rand()%3+3;
    randomizeMouse(x, y, speed);
}

//moves mouse in a predictable motion to x,y with a specific speed
void randomizeMouse(int x, int y, int speed){
	POINT p;
	GetCursorPos(&p);
	int z = 0;
	int b = 0;
	int xDiff = 0;
	int yDiff = 0;
	int newRand = 0;
	while(p.x!=x || p.y!=y){
		if(p.x>x){
			xDiff = p.x - x;
		}
		else{
			xDiff = x-p.x;
		}
		if(p.y>y){
			yDiff = p.y - y;
		}
		else{
			yDiff = y - p.y;
		}
		newRand = rand()%2+4;
		z = rand()%newRand;
		b = rand()%speed;
		if(xDiff>yDiff){
			if(z!=0){
				if(p.x != x){
					if(p.x < x){
						SetCursorPos(p.x+1, p.y);
					}
					else{
						SetCursorPos(p.x-1, p.y);
					}
			}
		}
		else{
			if(p.y != y){
				if(p.y < y){
					SetCursorPos(p.x, p.y+1);
				}
				else{
					SetCursorPos(p.x, p.y-1);
				}
			}
		}
		}
		else{
			if(z==0){
				if(p.x != x){
					if(p.x < x){
						SetCursorPos(p.x+1, p.y);
					}
					else{
						SetCursorPos(p.x-1, p.y);
					}

				}
			}
			else{
				if(p.y != y){
					if(p.y < y){
						SetCursorPos(p.x, p.y+1);
					}
					else{
						SetCursorPos(p.x, p.y-1);
					}
				}
			}
		}
		if(b == 1){
			Sleep(1);
		}
		GetCursorPos(&p);
	}
}
