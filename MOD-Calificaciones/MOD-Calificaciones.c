//MODULO CALIFICACIONES - (.C)

#include "MOD-Calificaciones.h"

typedef struct calificaciones
{
    char Fecha_calif[11];
    char Descrip_calif[32];
    char Id_materia[5];
    char Id_alum[7];
    char Valor_calif[3];
} calif;

char * menu_calif()
{
    char *s;

    if((s=(char*)malloc(230*sizeof(char)))!=NULL)
    {
        strcpy(s,"*********** CALIFICACIONES ***********\n\nSeleccione una opcion:\n\n( 1 ) - Visualizar calificaciones.\n\n( 2 ) - Agregar calificacion.\n\n( 3 ) - Eliminar calificacion.\n");
        return s;
    }
    else
    {
        return("Error. Fallo al mostrar el menú.");
    }
}

void calif_main() //Función main del módulo "Calificaciones"
{
    int i=0,j=0;
    char b = '#';
    FILE *f;
    calif *c;

    if((c=(calif*)malloc(sizeof(calif)))!=NULL) // A ALEX LE PARECE UNA SALVAJADA
    {
        if((f=fopen("Calificaciones.txt","r"))!=NULL)
        {
            while(b!=EOF)
            {
                if((c=(calif*)realloc(c,((i+1)*sizeof(calif))))!=NULL) // A ALEX LE PARECE UNA SALVAJADA
                {

                    while((b=fgetc(f))!='-')
                    {
                        c[i].Fecha_calif[j] = b;
                        j++;
                    }
                    c[i].Fecha_calif[j] = '\0';
                    j = 0;

                    while((b=fgetc(f))!='-')
                    {
                        c[i].Descrip_calif[j] = b;
                        j++;
                    }
                    c[i].Descrip_calif[j] = '\0';
                    j = 0;

                    while((b=fgetc(f))!='-')
                    {
                        c[i].Id_materia[j] = b;
                        j++;
                    }
                    c[i].Id_materia[j] = '\0';
                    j = 0;

                    while((b=fgetc(f))!='-')
                    {
                        c[i].Id_alum[j] = b;
                        j++;
                    }
                    c[i].Id_alum[j] = '\0';
                    j = 0;

                    b=fgetc(f);
                    while(b!='\n' && b!=EOF)
                    {
                        c[i].Valor_calif[j] = b;
                        j++;
                        b=fgetc(f);
                    }
                    c[i].Valor_calif[j] = '\0';
                    j = 0;

                    i++;
                }
                else
                    puts("Error. No se ha reservado memoria");
            }
            fclose(f);
        }
        else
            puts("Error de apertura.");
    }
    else
        puts("Error. No se ha reservado memoria");


  //  scanf("%d",&select);
  //  switch (select)
  //  {
  //     case 1:
  //     {

  //     }
  //  }

}
