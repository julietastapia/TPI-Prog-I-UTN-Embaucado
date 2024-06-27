#include <iostream>
#include <wchar.h>
#include "funciones.h"    // el header de mis funciones
#include "rlutil.h"               // libreria pra mejorar la salida por pantalla

using namespace std;

//void pruebaConeccion( std::string texto ) { cout<<texto; }

void encabezado()
{
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::locate(45,2);
    cout<<"-----------------------------"<<endl;

    rlutil::locate(55,3);
    cout<<"EMBAUCADO"<<endl;

    rlutil::locate(45,4);
    cout<<"-----------------------------"<<endl;

    //dibujarRectangulo(27, 2, 5,3);
    //dibujarNumero("A",27,2);

    dibujarFrenteCarta( 26, 1,  5, false ) ;
    dibujarFrenteCarta( 35, 1,  15, false ) ;
    dibujarFrenteCarta( 77, 1,  10, false ) ;
    dibujarFrenteCarta( 86, 1,  20, false ) ;
}
void dibujarRectangulo(int posx, int posy, int ancho, int alto)
{
    rlutil::setColor(rlutil::WHITE);

    for(int x=posx+1; x<posx+1+ancho; x++)
    {
        for(int y=posy; y<posy+alto; y++)
        {
            rlutil::locate(x,y);
            cout<< "█";
        }
    }

    for(int x=posx+8; x<posx+8+ancho; x++)
    {
        for(int y=posy; y<posy+alto; y++)
        {
            rlutil::locate(x,y);
            cout<<"█";
        }
    }
    for(int x=posx+52; x<posx+52+ancho; x++)
    {
        for(int y=posy; y<posy+alto; y++)
        {
            rlutil::locate(x,y);
            cout<< "█";
        }
    }
    for(int x=posx+59; x<posx+59+ancho; x++)
    {
        for(int y=posy; y<posy+alto; y++)
        {
            rlutil::locate(x,y);
            cout<< "█";
        }
    }
}


void Jugar(string &nombreJ1, string &nombreJ2, string vHistoricoNom[], int vHistoricoPje[] )
{
    int ronda=1;
    const int CARTASJUGADORES= 15, PUNTAJE= 21;
    int vJugador1[CARTASJUGADORES]= {};
    int vJugador2[CARTASJUGADORES]= {};
    int vPuntos[PUNTAJE] ;
    int cartaEmbaucadora;
    int vPuntajeJ1[3]= {};
    int vPuntajeJ2[3]= {};
    string ganador="";
    int puntajeMaximo=0;

    string restar;
    bool cierre=false;

    guardarNombres(nombreJ1,nombreJ2);
    cargarVectores(vPuntos, PUNTAJE ) ;

    sortearMano(ronda, vJugador1, vJugador2, CARTASJUGADORES, PUNTAJE-1) ;
    mostrarMano("",0, ronda, nombreJ1, nombreJ2, vJugador1, vJugador2,vPuntos, vPuntajeJ1, vPuntajeJ2); // Para mostrar dejo vacío el 1er argumento y en cero el último
    sortearEmbaucadora( cartaEmbaucadora ) ; // Obtenemos el máximo del rango de cartas 5: 1-5 (corazón); 10: 6-10 (diamante); etc.
    mostrarMano("restar", cartaEmbaucadora, ronda, nombreJ1, nombreJ2, vJugador1, vJugador2, vPuntos, vPuntajeJ1, vPuntajeJ2) ;    // "restar" indica que hay que restar la carta embaucadora
    system("cls");

    ronda=2;
    sortearMano(ronda, vJugador1, vJugador2, CARTASJUGADORES, PUNTAJE-1);
    mostrarMano("",0, ronda, nombreJ1, nombreJ2, vJugador1, vJugador2,vPuntos, vPuntajeJ1, vPuntajeJ2);
    sortearEmbaucadora( cartaEmbaucadora);
    cambioEmbaucadora(ronda,nombreJ1, nombreJ2, vPuntajeJ1, vPuntajeJ2, cartaEmbaucadora,vJugador1,vJugador2, vPuntos);
    mostrarMano("restar",cartaEmbaucadora, ronda, nombreJ1, nombreJ2, vJugador1, vJugador2,vPuntos, vPuntajeJ1, vPuntajeJ2);
    system("cls");

    ronda=3;
    sortearMano(ronda, vJugador1, vJugador2, CARTASJUGADORES, PUNTAJE-1);
    mostrarMano("",0, ronda, nombreJ1, nombreJ2, vJugador1, vJugador2,vPuntos, vPuntajeJ1, vPuntajeJ2);
    sortearEmbaucadora( cartaEmbaucadora);
    cambioEmbaucadora(ronda,nombreJ1, nombreJ2, vPuntajeJ1, vPuntajeJ2, cartaEmbaucadora,vJugador1,vJugador2, vPuntos);
    mostrarMano("restar",cartaEmbaucadora, ronda, nombreJ1, nombreJ2, vJugador1, vJugador2,vPuntos, vPuntajeJ1, vPuntajeJ2);
    system("cls");

   //-------------------------------prueba de empate 1 ----------------------
/*
   vPuntajeJ1[ 0 ] = 2 ;
   vPuntajeJ2[ 0 ] = 15 ;
    vPuntajeJ1[ 1 ] = 40 ;
   vPuntajeJ2[ 1 ] = 15 ;
   vPuntajeJ1[ 2 ] = 3 ;
   vPuntajeJ2[ 2 ] = 15 ;
  */

   //-------------------------------prueba de empate 2 ----------------------
 /*
   vPuntajeJ1[ 0 ] = 15 ;
   vPuntajeJ2[ 0 ] = 15 ;
    vPuntajeJ1[ 1 ] = 15 ;
   vPuntajeJ2[ 1 ] = 15 ;
   vPuntajeJ1[ 2 ] = 15 ;
   vPuntajeJ2[ 2 ] = 15 ;

   for(int i=0; i<15; i++ ){
        vJugador1[ i ]= 15 ;
        vJugador2[ i ]= 15 ;
   }
  */

   //-------------------------------------------------------------------------
    mostrarPuntajesFinales( vPuntajeJ1, vPuntajeJ2, nombreJ1, nombreJ2, ganador, puntajeMaximo );

    if( ganador=="EMPATE" ){

       desempate( nombreJ1, nombreJ2, vJugador1, vJugador2, ganador, CARTASJUGADORES ) ;
       rlutil::locate(45,22);
        cout<<endl<<"El resultado del juego es: "<<endl;
        anunciar(ganador + " han empatado nuevamente. ", 40, 23);    // cartel titilante se define el texto en el primer argumento y en el 2° y 3° la posicion.

    }
    compararHistoricos( ganador, puntajeMaximo, vHistoricoNom, vHistoricoPje ) ;



    system("cls");
}







