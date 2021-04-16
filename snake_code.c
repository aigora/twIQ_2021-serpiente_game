#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define V 30
             	//Tamaño del campo de juego
#define H 70
#define N 100 	//Tamaño de la serpiente
#define n 20 //tamaño del nombre
typedef struct
{
	int x, y;
	int ModX,ModY;
	char imagen;
}sprt; 			//Movimiento de la serpiente

typedef struct
{
	int x,y;
}frt; 			//Coordenadas de la fruta

typedef struct
{
	char nombre[N] ;
	int nota;
}jug;

jug jugador[N];
sprt serpiente[N];
frt fruta;
void inicio(int *lon, char campo[V][H]); 				//Inicia todos los elementos
void Intro_Campo(char campo[V][H]); 					//Dibuja el campo de juego
void Intro_Datos(char campo[V][H], int lon); 			//Introduce los datos en la matriz del campo (serpiente y fruta)
void input(char campo[V][H], int *lon, int *muerto); 	//Programa
void update(char campo[V][H],int lon); 					//Borra los datos de la matriz campo y los reescribe
void Intro_Datos2(char campo[V][H], int lon); 			//Movimiento de la serpiente
//void loop (char campo[V][H], int lon); 					//Ejecuta draw, input y update
char menu(void);
int main(){
        jug jugador[N];
	int lon,puntos;
	char campo[V][H];
	char h;
	int i=0,iMax=0;
	int respuesta, respuesta2, respuesta3, respuesta4, salir;
	char nombre[n];
	
	do{
		printf("--------------------------------------------------------------\n");
		printf("| Bienvenido al juego de la serpiente                        |\n");
		printf("| Si quiere comenzar a jugar pulse 1 sino pulse 2 para salir |\n");
		printf("| Pulse 3 para 'ayuda' y pulse 4 para 'acerca de'            |\n");
		printf("--------------------------------------------------------------\n");
		scanf("%d", &respuesta);
	
		switch (respuesta){
			case 1:
				salir=0;
				printf("Ha seleccionado jugar\n");
				printf("Comienza el juego %s\n", nombre);
				//comenzaria el juego
				inicio(&lon, campo); 
				loop(campo, lon);
			break;
		
			case 2:
				printf("Ha decidido no jugar al juego, vuelva pronto\n");
			return 0;
		
			case 3:
				salir=0;
				printf("Ha elegido ayuda\n");
				printf("Ha elegido saber como funciona el juego, si quiere continuar pulse 1, para volver al menu pulse 2\n");
				scanf("%d", &respuesta2);
				switch (respuesta2){
					case 1:
						printf("Este juego consiste en:\n");
						printf("Comer el mayor numero de manzanas posibles y no tocar asi mismo o el borde\n");
						//despues poner controles cuando los tengamos
						printf("Pulse 1 para volver al menu, 2 para salir\n");
						scanf("%d", &respuesta4);
						switch (respuesta4){
							case 1:
								printf("Ha seleccionado volver al menu\n");
								salir++;
							//return ;
							break;
							case 2:
								printf("Ha decidido salir, vuelva pronto\n");
							return 0;
						}
					break;
					case 2:
						printf("Ha elegido volver al menu\n");
						salir++;
					break;
				}
			break;
		
			case 4:
				salir=0;
				printf ("'Acerca de':\n");
				printf("Juego de la serpiente\n");
				printf("Creadores del juego:\n");
				printf("Martin Nieto Bermejo\n");
				printf("Diego Sillero Villanueva\n");
				printf("Jesus Pereira Serrano\n");
				printf("Pulse 1 para volver al menu, 2 para salir\n");
				scanf("%d", &respuesta3);
				switch (respuesta3){
					case 1:
						printf("Ha seleccionado volver al menu\n");
						salir++;
					//return ;
					break;
					case 2:
						printf("Ha decidido salir, vuelva pronto\n");
					return 0;
				}
			break;	
		}
	}
	while (salir==1);
}
//se inician todos los elementos
void inicio(int*lon,char campo[V][H]
{
	int i;
	//Cabeza de la serpiente
	serpiente[0].x = 35;
	serpiente[0].y = 13;
	//Tama?
	*lon = 4;
	//Coordenadas aleatorias de la fruta
	srand(time(NULL));
	fruta.x = rand() % (H-1);
	fruta.y = rand() % (V-1);
	
	while(fruta.x == 0)
	{
		fruta.x = rand() % (H-1);
	}
	while(fruta.y == 0)
	{
		fruta.y = rand() % (V-1);
	}
	for(i = 0; i < *lon; i++)
	{
		serpiente[i].ModX = 1;
		serpiente[i].ModY = 0;
	}
	
	Intro_Campo(campo);
	Intro_Datos(campo, *lon);
}
//Creacion del campo de juego
void Intro_Campo(char campo[V][H])
{
	int i, j;
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < H; j++)
		{
			if(i == 0 || i == V-1)
			{
				campo[i][j] = '=';
			}
			else if (j == 0 || j == H-1)
			{
				campo[i][j] = '|';
			}
			else
			{
				campo[i][j] = ' ';
			}
		}
	}
}

void Intro_Datos(char campo[V][H], int tam)
{
	int i;
	for (i = 1; i < tam; i++)
	{
		serpiente[i].x = serpiente[i-1].x - 1;
		serpiente[i].y = serpiente[i-1].y - 1;
		
		serpiente[i].imagen = 'O';
	}
	serpiente[0].imagen = 'O';
	
	for(i = 0; i < tam; i++)
	{
		campo[serpiente[i].y][serpiente[i].x] - serpiente[i].imagen;
	}
	campo[fruta.y][fruta.x] - '&';
}

void draw(char campo[V][H])
{
	int i,j;
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < H; j++)
		{
			printf("%c", campo[i][j]);
		}
		printf("\n");
	}
}
