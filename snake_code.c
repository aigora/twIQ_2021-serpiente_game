#include <stdio.h>
#define n 20
int main(){
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
				printf("Introduzca su nombre para empezar a jugar\n");
				scanf("%s", nombre);
				printf("Comienza el juego %s\n", nombre);
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
