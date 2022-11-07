/*
 ============================================================================
 Name        : Hello.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{

	int id;
	char nombre[20];
	char apellido[20];
	char sexo;
	float altura;
}ePersona;

ePersona* new_persona();
ePersona* newPersonaParam(int id, char nombre[],char apellido[],char sexo, float altura);
int mostrarPersona(ePersona* p);
void daletePersona(ePersona* p);

//getters y setters

int personaSetId(ePersona* p, int id);
int personaSetNombre(ePersona* p, char nombre[]);
int personaSetApellido(ePersona* p, char apellido[]);
int personaSetSexo(ePersona* p, char sexo);
int personaSetAltura(ePersona* p, float altura);
//---------------------------------------------------------------------
int personaGetId(ePersona* p, int* pId);
int personaGetNombre(ePersona* p, char* pNombre);
int personaGetApellido(ePersona* p, char* pApellido);
int personaGetSexo(ePersona* p, char* pSexo);
int personaGetSexoString(ePersona* p, char pSexo[]);
int personaGetAltura(ePersona* p, float* pAltura);
int personaGetFullName(ePersona* p, char fullName[]);


int main(void) {

	setbuf(stdout,NULL);


	ePersona* p = new_persona();
	if(p == NULL){
		printf("No se consiguio mnemoria\n");
		exit(1);
	}else{
		printf("Se cargo una persona con exito!!!\n");
	}



	p = newPersonaParam(20000,"juan","Perez",'m',2.00);
	if(p != NULL){


		mostrarPersona(p);
	}


 personaSetNombre(p,"mario");
 mostrarPersona(p);







	return EXIT_SUCCESS;
}

ePersona* new_persona(){


 ePersona* p =  (ePersona*) malloc(sizeof(ePersona));


	p->id = 0;
	strcpy(p->nombre, " "); // *(p->nombre) = '\0';
	strcpy(p->apellido, " ");
	p->sexo = ' ';
	p->altura = 0;


 return p;
}

int mostrarPersona(ePersona* p){

	int todoOk = 0;

	if(p != NULL ){

		printf("id: %d  nombre: %s apellido: %s sexo: %c  altura: %.2f\n", p->id, p->nombre,p->apellido, p->sexo, p->altura);

		todoOk = 1;
	}

	return todoOk;
}

ePersona* newPersonaParam(int id, char nombre[],char apellido[],char sexo, float altura){

	ePersona* p = new_persona();

 if(!(personaSetId(p,id),personaSetNombre(p,nombre),personaSetApellido(p,apellido),personaSetSexo(p,sexo),personaSetAltura(p,altura)))
 {

      daletePersona(p);
 }
	return p;
}

void daletePersona(ePersona* p){

	free(p);
}

int personaSetId(ePersona* p, int id){
int todoOk = 0;

if(p != NULL && id >= 20000 && id <= 30000){

	p->id = id;
	todoOk = 1;
}

return todoOk;

}

int personaSetNombre(ePersona* p, char nombre[]){

	int todoOk = 0;

	if(p != NULL && strlen(nombre) < 20){


		strcpy(p->nombre,nombre);
		strlwr(p->nombre);
		p->nombre[0]= toupper(p->nombre[0]);
		todoOk = 1;
	}

	return todoOk;

}

int personaSetApellido(ePersona* p, char apellido[]){

	int todoOk = 0;

		if(p != NULL && strlen(apellido) < 20){


			strcpy(p->apellido,apellido);
			strlwr(p->apellido);
			p->apellido[0]= toupper(p->apellido[0]);
			todoOk = 1;
		}

		return todoOk;
}
int personaSetSexo(ePersona* p, char sexo){

	int todoOk = 0;

	sexo = tolower(sexo);

	if(p != NULL && (sexo == 'f' || sexo == 'm')){

		p->sexo = sexo;
		todoOk = 1;
	}

	return todoOk;

}

int personaSetAltura(ePersona* p, float altura) {

	int todoOk = 0;

	if(p != NULL && (altura > 0 && altura < 2.50)){

		p->altura = altura;
		todoOk = 1;
	}

	return todoOk;

}

int personaGetId(ePersona* p, int* pId){

	int todoOk = 0;

	if(p != NULL && pId != NULL){

		*pId = p->id;
		todoOk = 1;
	}

	return todoOk;


}

int personaGetNombre(ePersona* p, char* pNombre){

	int todoOk = 0;

		if(p != NULL && pNombre != NULL){


			strcpy(pNombre,p->nombre);

			todoOk = 1;
		}

		return todoOk;


}

int personaGetApellido(ePersona* p, char* pApellido){

	int todoOk = 0;

			if(p != NULL && pApellido != NULL){


				strcpy(pApellido,p->apellido);

			}

			return todoOk;
}

int personaGetSexo(ePersona* p, char* pSexo){



	int todoOk = 0;


		if(p != NULL && pSexo != NULL){

			*pSexo = p->sexo;
			todoOk = 1;
		}

		return todoOk;

}

int personaGetSexoString(ePersona* p, char pSexo[]){


	int todoOk = 0;


		if(p != NULL && pSexo != NULL){

			if(p->sexo == 'f'){
			strcpy(pSexo,"Femenino");

			}else{

				strcpy(pSexo,"Masculino");
			}

			todoOk = 1;
		}

		return todoOk;


}

int personaGetAltura(ePersona* p, float* pAltura){


	int todoOk = 0;


		if(p != NULL && pAltura != NULL){

			*pAltura = p->altura;
			todoOk = 1;
		}

		return todoOk;

}


