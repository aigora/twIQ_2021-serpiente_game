#include <stdio.h>
#include <string.h>
#define V 30
             	//Tamano del campo de juego
#define H 70
#define N 100 	//Tamano de la serpiente

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
void loop (char campo[V][H], int lon); 					//Ejecuta draw, input y update
char menu(void);

int main()
{
	jug jugador[N];
	char nombre[N];
	int lon,puntos;
	char campo[V][H];
	char h;
	int i=0,iMax=0;
	int respuesta, respuesta2, respuesta3, respuesta4, salir;
	do
	{
		system("color 10");
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
				printf("Introduzca su nombre para empezar a jugar\n");
				scanf("%s", nombre);
				printf("Comienza el juego %s\n", nombre);
				inicio(&lon, campo); 
				loop(campo, lon);
				//comenzaria el juego
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
						printf("Para mover la serpiente use a,s,d,w donde a sera hacia la izquierda,s sera hacia abajo,d sera hacia la derecha y w hacia arriba.\n");
						printf("Ha medida que coma manzanas su puntuacion aumentara \n");
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
	
//Inicia todos los elementos
void inicio (int *lon, char campo[V][H])
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

//Datos en matriz de campo
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

void loop (char campo[V][H], int lon)
{
	int muerto = 0;
	do
	{
		system("cls");
		draw(campo);
		input(campo,&lon,&muerto);
		update(campo,lon);
	}while(muerto == 0);
	
}

void input(char campo[V][H], int *lon, int *muerto)
{
	int i, punt;
	char key;
	char nombre[10];
	FILE *f;
	//Comprobacion de si hemos muerto
	if(serpiente[0].x == 0 || serpiente[0].x == H-1 || serpiente[0].y == 0 || serpiente[0].y == V-1)
	{
		*muerto = 1;
		system("color 0A");
		printf("GAME OVER\n");
	}
	for(i = 1; i < *lon && *muerto == 0; i++)
	{
		if(serpiente[0].x == serpiente[i].x && serpiente[0].y == serpiente[i].y)
		{
			*muerto = 1;
			system("color 0A");
			printf("GAME OVER\n");
		}
	}
	//Comprobar si nos hemos comido la fruta
	if(serpiente[0].x == fruta.x && serpiente[0].y == fruta.y)
	{
		*lon +=1;
		serpiente[*lon-1].imagen = 'O';
		fruta.x = rand()%(H-1);
		fruta.y = rand()%(V-1);
		while(fruta.x == 0)
		{
			fruta.x = rand()%(H-1);
		}
		while(fruta.y == 0)
		{
			fruta.y = rand()%(V-1);
		}
	}
	
	if(*muerto == 1)
	{
		float puntuacion;
		printf("Vuelva a introducir su nombre para saber lo puntos obtenidos y si ha batido el record:\n");
		scanf ("%s", nombre);
		punt=(*lon-4);
		printf ("%s has ganado %i puntos!!!\n", nombre, punt);
		FILE *pf;
		pf=fopen("puntos.txt", "r");
		fscanf(pf, "%f\n", puntuacion);
		if (puntuacion<punt){
			printf("Nuevo record!!!");
			FILE *nf;
			nf=fopen("nombre.txt", "w");
			fprintf(nf, "%s\n", nombre);
			fclose(nf);
			FILE *pf;
			pf=fopen("puntos.txt", "w");
			fscanf(pf, "%f\n", punt);
		}
	}
	
	if(*muerto == 0)
	{
		if(kbhit() == 1)
		{
			key = getch();
			if(( key == 's') && serpiente[0].ModY != -1)
			{
				serpiente[0].ModX = 0;
				serpiente[0].ModY = 1;
			}
			if(( key == 'w') && serpiente[0].ModY != 1)
			{
				serpiente[0].ModX = 0;
				serpiente[0].ModY = -1;
			}
			if(( key == 'a' ) && serpiente[0].ModX != 1)
			{
				serpiente[0].ModX = -1;
				serpiente[0].ModY = 0;
			}
			if(( key == 'd') && serpiente[0].ModX != -1)
			{
				serpiente[0].ModX = 1;
				serpiente[0].ModY = 0;
			}
			if(key == 'p') 
			{
				system("color 03");
				printf("Pause\n");
				system("pause");
			}
			
		}
	}
}

void update(char campo[V][H],int lon)
{
	//Borrar los datos de la matriz
	Intro_Campo(campo);
	//Introducir nuevos datos
	Intro_Datos2(campo,lon);
}

void Intro_Datos2(char campo[V][H], int lon)
{
	//Hacer que el cuerpo siga a la cabeza. Cada elemento copia al anterior menos la cabeza
	int i;
	for(i = lon-1 ; i > 0 ; i--)
	{
		serpiente[i].x = serpiente[i-1].x;
		serpiente[i].y = serpiente[i-1].y;
	}
	serpiente[0].x += serpiente[0].ModX;
	serpiente[0].y += serpiente[0].ModY;
	
	for(i = 0 ; i < lon ; i++)
	{
		campo[serpiente[i].y][serpiente[i].x] = serpiente[i].imagen;
	}
	
	campo[fruta.y][fruta.x] = '#';
}
