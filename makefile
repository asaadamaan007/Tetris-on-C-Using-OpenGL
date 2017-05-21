
#Author :Asaad Amaan
#Project:tetris using openGL and c
#Date   :21/05/2017

CC    = gcc
FILES = tetgl.c
FLAGS = -lGL -lglut -lGLU

all:	
	$(CC) -o tetris $(FILES) $(FLAGS)
