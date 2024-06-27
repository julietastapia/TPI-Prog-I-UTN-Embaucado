
#include <iostream>
#include <cstdlib>
#include <wchar.h>
#include "funciones.h"    // el header de mis funciones
#include "rlutil.h"       // libreria pra mejorar la salida por pantalla
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------ FUNCIONES DEL JUEGO --------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------








//------------------------------------------------------ guardar nombres() ---------------------------------------------------------------


void guardarNombres(string &nombreJ1, string &nombreJ2)
{
    char opc;

    cout<<"Para comenzar se debe registrar sus nombres: " <<endl;
    cout<<endl;

    do
    {
        cout<<"Nombre del Jugador 1? ";
        cin>>nombreJ1;

        cout<<"Nombre del Jugador 2? ";
        cin>>nombreJ2;

        cout<<endl;
        cout<<"Confirma los nombres? (S/N) ";
        cin>>opc;

        cout<<endl;
        system("cls");

    }

    while(opc == 'N' || opc == 'n');

}
//------------------------------------------------------ cargarVectores() ---------------------------------------------------------------

void cargarVectores( int puntos[], int cantP )
{


    puntos[ 0 ] = 0 ;
    int rango;
    for ( int i=1 ; i<cantP ; i++ )
    {
        if ( i<6 )
        {
            rango = i;
        }
        else
        {
            if ( i<11 )
            {
                rango = i-5 ;
            }
            else
            {
                if( i<16 )
                {
                    rango = i-10 ;
                }
                else
                {
                    rango = i-15 ;
                }
            }
        }

        switch ( rango )         // asigno valores segun el rango 1-5 , 6-10 , 11-15 , 16-20
        {
        case 1:
            puntos[ i ] = 10 ;
            break;
        case 2:
            puntos[ i ] = 11 ;
            break;
        case 3:
            puntos[ i ] = 12 ;
            break;
        case 4:
            puntos[ i ] = 15 ;
            break;
        case 5:
            puntos[ i ] = 20 ;
            break;
        }
    }
}

//------------------------------------------------------- sortearMano() -------------------------------------------------------

void sortearMano( int ronda, int vJ1[], int vJ2[], int cartas, int puntaje)
{

    int rangoTope;
    int numAlAzar = ( rand()% puntaje ) + 1 ;    //hacer pruebas de los resultados
    int rangoInicio;

    if( ronda == 1 )
    {
        rangoTope = 4 ;

    }
    else
    {
        if ( ronda == 2 )
        {
            rangoTope = 9 ;
        }
        else
        {
            rangoTope = 14 ;
        }
    }

    rangoInicio = rangoTope - 4 ;



    for ( int i=rangoInicio; i<=rangoTope; i++ )
    {

        if ( i != rangoInicio )
        {

            buscarCoincidencia(  rangoTope, rangoInicio, vJ1, vJ2, numAlAzar, cartas ) ;
            vJ1[ i ]= numAlAzar;
            buscarCoincidencia(  rangoTope, rangoInicio, vJ1, vJ2, numAlAzar, cartas ) ;
        }
        else
        {
            vJ1[ i ] =  numAlAzar;
            numAlAzar = ( rand()%cartas ) + 1 ;

            while( numAlAzar == vJ1[ i ] )
            {
                numAlAzar = ( rand()%cartas ) + 1 ;
            }
        }
        vJ2[ i ] =  numAlAzar;
    }


}

//------------------------------------------------- buscarCoincidencia() -------------------------------------------------

void  buscarCoincidencia(  int rangoTope, int rangoInicio, int vJ1[], int vJ2[], int &numAlAzar, int puntaje )
{

    bool coincidencia = true;

    while( coincidencia==true )
    {
        numAlAzar = ( rand()% puntaje ) + 1 ;
        coincidencia=false;
        for (int i=rangoInicio; i<=rangoTope; i++ )
        {
            if ( numAlAzar==vJ1[ i ] || numAlAzar==vJ2[ i ]|| numAlAzar==0 )
            {
                coincidencia = true;
            }
        }
    }

}

//------------------------------------------------- sortearEmbaucadora() -------------------------------------------------

void sortearEmbaucadora( int &cartaEmbaucadora)
{
    for(int j=0; j<5; j++)
    {
        rlutil::msleep(80);
    }
    int estadoLinea[ 2 ]= {};
    cartaEmbaucadora= ((rand()%4)+1)*5;
    posicionarDescripcion( 21, rlutil::trows()-9, estadoLinea, -1, -1 );
    cout<<"Carta embaucadora "<<endl;
    rlutil::locate(12,21);
    cout<<"El siguiente palo NO va a sumar:"<<endl;

    dibujarEmbaucadora( 21,rlutil::trows()-8, cartaEmbaucadora );

    rlutil::setColor(15);
    rlutil::setBackgroundColor(0);
    cout<<endl<<endl;
    posicionarDescripcion( rlutil::tcols()/2-20, rlutil::trows()-1, estadoLinea, -1, -1 );
    system("pause");
    //limpiar( rlutil::tcols()/2-21,  rlutil::trows()-2, 0,0 );
    posicionarDescripcion( rlutil::tcols()/2-20, rlutil::trows()-1, estadoLinea, 0, 0 );

}


//------------------------------------------------- mostrarMano() -------------------------------------------------


void mostrarMano(string estado, int cartaEmbaucadora, int ronda, string &nombreJ1, string &nombreJ2, int vJugador1[], int vJugador2[], int vPuntos[], int vPuntajeJ1[], int vPuntajeJ2[])
{


    int contCartasJugadas;
    int vCartasJugadas[5]= {} ;
    int estadoLinea[ 2 ]= {};

    int cartaInicial;

    vPuntajeJ1[ronda-1]=0;
    vPuntajeJ2[ronda-1]=0;

    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);

    switch( ronda )
    {
    case 1:
        cartaInicial=0 ;
        break;
    case 2:
        cartaInicial=5 ;
        limpiar( 3, 3, rlutil::tcols(),12  );
        break;
    case 3:
        cartaInicial=10 ;
        limpiar( 3, 3, rlutil::tcols(),12  );
        break;
    }
    rlutil::locate(  1,1 );
    //limpiar( 1,1,rlutil::tcols(),0 )    ;
    posicionarDescripcion( 1, 1, estadoLinea, -1, -1 );
    cout<<"RONDA #" <<ronda<<endl;

    posicionarDescripcion( 1, 1, estadoLinea, 6, 3 );
    cout<<nombreJ1 <<" ("<<vPuntajeJ1[0]+vPuntajeJ1[1] <<" PUNTOS)" ;

    posicionarDescripcion( 1, 1, estadoLinea, 56, 0 );
    cout<<nombreJ2 <<" ("<<vPuntajeJ2[0]+vPuntajeJ2[1] <<" PUNTOS)"<<endl;




    for( int i=cartaInicial; i<cartaInicial+5; i++ )
    {
        if( cartaInicial==i )
        {
            contCartasJugadas=0;
        }
        if( estado=="restar" )
        {
            if( vJugador1[ i ]>cartaEmbaucadora-5 && vJugador1[ i ]<=cartaEmbaucadora )
            {
                vJugador1[ i ]= 0 ;       //Ac├í se podr├¡a llamar al vector vPuntaje[0]
                vCartasJugadas[ contCartasJugadas ]= vJugador1[ i ];
            }
        }
        vPuntajeJ1[ronda-1] +=  vPuntos[vJugador1[ i ] ];
        vCartasJugadas[ contCartasJugadas ]= vJugador1[ i ];
        contCartasJugadas++;
    }

    posicionarCartas( 3,3,vCartasJugadas );
    posicionarPuntaje( vJugador1, estadoLinea, vPuntos, cartaInicial, 6, 12 ) ;

    posicionarDescripcion( 3, 17, estadoLinea, -1, -1 );
    cout<<"--------------------------------------------------"<<endl;
    posicionarDescripcion( 3, 17, estadoLinea, 0, 1 );
    cout<<"Puntos acumulados de "<<nombreJ1 <<" RONDA #"<<ronda <<"--->  "  <<vPuntajeJ1[ronda-1] <<" pts."<<endl;
    posicionarDescripcion( 3, 17, estadoLinea, 0, 1 );
    cout<<"--------------------------------------------------"<<endl;


    for( int i=cartaInicial; i<cartaInicial+5; i++ )
    {
        if( cartaInicial==i )
        {
            contCartasJugadas=0;
        }
        if( estado=="restar" )
        {
            if( vJugador2[ i ]>cartaEmbaucadora-5 && vJugador2[ i ]<=cartaEmbaucadora )
            {
                vJugador2[ i ]= 0 ;
                vCartasJugadas[ contCartasJugadas ]= vJugador2[ i ];
            }
        }
        vPuntajeJ2[ronda-1] +=  vPuntos[vJugador2[ i ] ];
        vCartasJugadas[ contCartasJugadas ]= vJugador2[ i ];
        contCartasJugadas++;
    }

    posicionarCartas( 59,3,vCartasJugadas );
    posicionarPuntaje( vJugador2, estadoLinea, vPuntos, cartaInicial, 62, 12 ) ;


    posicionarDescripcion( 59, 17, estadoLinea, -1, -1 );
    cout<<"--------------------------------------------------"<<endl;
    posicionarDescripcion( 59, 17, estadoLinea, 0, 1 );
    cout<<"Puntos acumulados de "<<nombreJ2 <<" Ronda #" <<ronda<< "--->  "  <<vPuntajeJ2[ronda-1] <<" pts."<<endl;
    posicionarDescripcion( 59, 17, estadoLinea, 0, 1 );
    cout<<"--------------------------------------------------"<<endl;



    cout<<endl;
    rlutil::setColor( 15 );
    rlutil::setBackgroundColor( 0 );

    posicionarDescripcion( rlutil::tcols()/2-20, rlutil::trows()-1, estadoLinea, -1, -1 );
    system("pause");
  // limpiar( rlutil::tcols()/2-21,  rlutil::trows()-2, 0,0 );
    posicionarDescripcion( rlutil::tcols()/2-20, rlutil::trows()-1, estadoLinea, 0, 0 );
}


//------------------------------------------------- cambioEmbaucadora() -------------------------------------------------

void cambioEmbaucadora(int ronda, std::string &nombreJ1, std::string &nombreJ2,  int vPuntajeJ1[], int vPuntajeJ2[], int &cartaEmbaucadora,int vJugador1[], int vJugador2[], int vPuntos[])

{
    char cambio;
    int estadoLinea[ 2 ]= {};

    if(ronda == 2 && vPuntajeJ1[0]>=20)
    {

        posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, -1 );
        cout<<nombreJ1 <<": "<<endl;

        posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
        cout<<"Deseas sacrificar 20 puntos "<<endl;

        posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
        cout<<"de la ronda anterior. "<<endl;

        posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
        cout<< "Tienes "<<vPuntajeJ1[0] <<" puntos acumulados."<<endl;

        posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
        cout<< "(S/N): ";
        rlutil::showcursor();
        cin>> cambio;
        rlutil::hidecursor();

        if(cambio == 's' || cambio == 'S')
        {
            vPuntajeJ1[0] = vPuntajeJ1[0]-20;
            for(int j=0; j<5; j++)
            {
                rlutil::msleep(80);
            }
            sortearEmbaucadora(cartaEmbaucadora);
        }


        else
        {
            limpiar( 48, rlutil::trows()-8, 0, 0 );
            if( vPuntajeJ2[0]>=20 )
            {

                posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, -1 );
                cout<<nombreJ2 <<": "<<endl;

                posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
                cout<<"Deseas sacrificar 20 puntos "<<endl;

                posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
                cout<<"de la ronda anterior. "<<endl;

                posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
                cout<< "Tienes "<<vPuntajeJ2[0] <<" puntos acumulados."<<endl;

                posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
                cout<< "(S/N): ";
                rlutil::showcursor();
                cin>> cambio;
                rlutil::hidecursor();

                if(cambio == 's' || cambio == 'S')
                {
                    for(int j=0; j<5; j++)
                    {
                        rlutil::msleep(80);
                    }
                    sortearEmbaucadora(cartaEmbaucadora);
                }
            }
        }
    }
    if(ronda == 3 && vPuntajeJ2[1]>=20)
    {
        posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, -1 );
        cout<<nombreJ2 <<": "<<endl;

        posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
        cout<<"Deseas sacrificar 20 puntos "<<endl;

        posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
        cout<<"de la ronda anterior. "<<endl;

        posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
        cout<< "Tienes "<<vPuntajeJ2[1]+ vPuntajeJ2[0] <<" puntos acumulados."<<endl;

        posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
        cout<< "(S/N): ";
        rlutil::showcursor();
        cin>> cambio;
        rlutil::hidecursor();

        if(cambio == 's' || cambio == 'S')
        {
            vPuntajeJ2[1] = vPuntajeJ2[1]-20;
            for(int j=0; j<5; j++)
            {
                rlutil::msleep(80);
            }
            sortearEmbaucadora(cartaEmbaucadora);

        }
        else if(vPuntajeJ1[1]>=20)
        {
            limpiar( 48, rlutil::trows()-8, 0, 0 );

            posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, -1 );
            cout<<nombreJ1 <<": "<<endl;

            posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
            cout<<"Deseas sacrificar 20 puntos "<<endl;

            posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
            cout<<"de la ronda anterior. "<<endl;

            posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
            cout<< "Tienes "<<vPuntajeJ1[1]+ vPuntajeJ1[0] <<" puntos acumulados."<<endl;

            posicionarDescripcion( 49, rlutil::trows()-8, estadoLinea, -1, 1 );
            cout<< "(S/N): ";
            rlutil::showcursor();
            cin>> cambio;
            rlutil::hidecursor();

            if(cambio == 's' || cambio == 'S')
            {
                vPuntajeJ1[1] = vPuntajeJ1[1]-20;
                for(int j=0; j<5; j++)
                {
                    rlutil::msleep(80);
                }
                sortearEmbaucadora(cartaEmbaucadora);
            }
        }
    }
    rlutil::setColor( 15 );
    rlutil::setBackgroundColor( 0 );

}


//------------------------------------------------- mostrarPuntajesFinales() -------------------------------------------------

void mostrarPuntajesFinales(int vPuntajeJ1[], int vPuntajeJ2[], string &nombreJ1, string &nombreJ2, string &ganador, int &puntajeMaximo )
{
    int TotalPuntajeJ1;
    int TotalPuntajeJ2;





    cout<<"FIN DE LA PARTIDA!!!"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<endl;


    cout<<nombreJ1<<endl;
    cout<<"Ronda#1: " <<vPuntajeJ1[0] <<" pts."<<endl;
    cout<<"Ronda#2: " <<vPuntajeJ1[1] <<" pts."<<endl;
    cout<<"Ronda#3: " <<vPuntajeJ1[2] <<" pts."<<endl;
    cout<<"-------------------"<<endl;
    cout<<"Total ";

    TotalPuntajeJ1 =vPuntajeJ1[0] + vPuntajeJ1[1] +vPuntajeJ1[2];
    cout<<TotalPuntajeJ1<<endl;



    rlutil::locate(25,4);

    cout<<nombreJ2<<endl;
    rlutil::locate(25,5);
    cout<<"Ronda#1: " <<vPuntajeJ2[0] <<" pts."<<endl;
    rlutil::locate(25,6);
    cout<<"Ronda#2: " <<vPuntajeJ2[1] <<" pts."<<endl;
    rlutil::locate(25,7);
    cout<<"Ronda#3: " <<vPuntajeJ2[2] <<" pts."<<endl;
    rlutil::locate(25,8);
    cout<<"-------------------"<<endl;
    rlutil::locate(25,9);
    cout<<"Total ";

    TotalPuntajeJ2 =vPuntajeJ2[0] + vPuntajeJ2[1] +vPuntajeJ2[2];
    rlutil::locate(32,9);
    cout<<TotalPuntajeJ2<<endl;

    cout<<endl;
    cout<<endl;

    if (TotalPuntajeJ1==TotalPuntajeJ2 )
    {

        ganador = "EMPATE";
        anunciar( "¡¡¡EMPATE!!", 40, 13 ) ;
        puntajeMaximo = TotalPuntajeJ1;

    }
    else
    {

        if(TotalPuntajeJ1 > TotalPuntajeJ2)
        {
            ganador = nombreJ1;
            puntajeMaximo = TotalPuntajeJ1;
        }
        else
        {
            ganador = nombreJ2;
            puntajeMaximo = TotalPuntajeJ2;
        }
        anunciar( ganador+" GANASTE!!!", 40, 13)  ;
    }

    rlutil::locate(1,30);


}
//------------------------------------------------- mostrarEstadisticas() -------------------------------------------------

void mostrarEstadisticas( string  vHistoricoNom[], int vHistoricoPje[] )
{
    cout<<"Jugadores con mayor puntaje: "<<endl<<endl;

    cout<<"   NOMBRE" <<"\t" <<"\t"<<"PUNTOS:"<<endl;
    for( int i=0; i<3; i++ )
    {

        cout<<i+1<<"°: "<<vHistoricoNom[ i ] <<"\t"<<"\t"<<"\t"<< vHistoricoPje[ i ] <<endl;
        cout<<endl;
    }

    system("pause");
    system("cls");
}



void desempate( string nombreJ1, string nombreJ2, int vJugador1[], int vJugador2[], string &ganador, int CARTASJUGADORES )
{

    int maxJ1;
    int maxJ2;

    for(int i=0; i<CARTASJUGADORES; i++ )
    {
        if( i==0 )
        {
            maxJ1=vJugador1[ i ] ;
            maxJ2=vJugador2[ i ] ;
        }
        else
        {
            if( vJugador1[ i ]>maxJ1 )
            {
                maxJ1=vJugador1[ i ] ;
            }
            if( vJugador2[ i ]>maxJ2 )
            {
                maxJ2=vJugador2[ i ] ;
            }
        }
    }
    if( maxJ1==maxJ2 )
    {
        ganador =nombreJ1 + " y " + nombreJ2;
    }
    else
    {
        if( maxJ1>maxJ2 )
        {
            ganador=  nombreJ1 ;
        }
        else
        {
            ganador=  nombreJ2 ;
        }
    }

}

void compararHistoricos( string ganador, int puntajeMaximo, string  vHistoricoNom[], int vHistoricoPje[] )
{

    int auxPje;
    int posicion=4;
    string auxNom;

//Pregunta la posisción en la que estaría

    for( int i=2; i>=0; i--)
    {
        if( puntajeMaximo>vHistoricoPje[ i ] )
        {
            posicion=i;
        }
    }


//------ lo ubica-----------


    if( posicion==2 )
    {
        vHistoricoNom[ 2 ]= ganador ;
        vHistoricoPje[ 2 ]= puntajeMaximo;
    }
    if( posicion==1 )
    {
        auxNom= vHistoricoNom[ 1 ] ;
        auxPje= vHistoricoPje[ 1 ] ;

        vHistoricoNom[ 1 ]= ganador;
        vHistoricoPje[ 1 ]=  puntajeMaximo;

        vHistoricoNom[ 2 ]= auxNom ;
        vHistoricoPje[ 2 ]= auxPje;
    }
    if( posicion==0 )
    {
        auxNom= vHistoricoNom[ 1 ] ;
        auxPje= vHistoricoPje[ 1 ] ;

        vHistoricoNom[ 1 ]=  vHistoricoNom[ 0 ]  ;
        vHistoricoPje[ 1 ]= vHistoricoPje[ 0 ] ;

        vHistoricoNom[ 0 ]= ganador;
        vHistoricoPje[ 0 ]=  puntajeMaximo;

        vHistoricoNom[ 2 ]= auxNom ;
        vHistoricoPje[ 2 ]= auxPje;
    }
    rlutil::locate(1,30);

}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------funciones para graficar -------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------- anunciar() --------------------------------------------------------

void anunciar( string mje, int x, int y )
{
    for(int i=1; i<25; i++)
    {
        if(i%2==0)
        {
            rlutil::setColor(rlutil::BLACK);
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::hidecursor();

        }
        else
        {
            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::hidecursor();
        }
        rlutil::msleep(300);
        rlutil::locate(x,y);

        cout<<mje<<endl;


    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
}

//-------------------------------------------- posicionarDescripcion() --------------------------------------------------------

void posicionarDescripcion(  int posX, int posY, int estadoLinea[], int lineasX, int lineasY )
{

    if( lineasX==-1 )
    {
        estadoLinea[ 0 ]=0;
    }
    if( lineasY==-1 )
    {
        estadoLinea[ 1 ]=0;
    }

    estadoLinea[ 0 ]+=lineasX;
    estadoLinea[ 1 ]+=lineasY ;

    rlutil::locate( posX+ estadoLinea[ 0 ], posY+ estadoLinea[ 1 ] );
}




void posicionarCartas( int posX, int posY, int vecMano[] )
{

    rlutil::locate( posX, posY ) ;
    rlutil::hidecursor();

    int separadorX= posX+3;
    int separadorY= posY+3;

    for ( int i=0; i<5; i++ )
    {

        //rlutil::msleep(100);                                       //--------------animar

        if( vecMano[ i ]==0 )                                                                                       // si hay que darla vuelta
        {
            if( i==0 )
            {
                dibujarDorsoCarta( separadorX, separadorY, vecMano[ i ],false );             // si van las sombras
            }
            else
            {
                dibujarDorsoCarta( separadorX+i*5, separadorY+i, vecMano[ i ], true );
            }
        }
        else
        {

            if( i==0 )
            {
                dibujarFrenteCarta( separadorX, separadorY, vecMano[ i ],false );
            }
            else
            {
                dibujarFrenteCarta( separadorX+i*5, separadorY+i, vecMano[ i ], true );
            }
        }

    }
}

void dibujarFrenteCarta( int posX, int posY, int dato, bool sombra )
{

    rlutil::setColor( 15 ) ;
    for( int i=posY; i<posY+5; i++ )
    {
        rlutil::locate( posX, i ) ;
        for( int h=posX; h<posX+7; h++ )
        {
            cout<<"█";
        }
        cout<<endl;
    }


    if( sombra )
    {
        rlutil::setColor( 8 ) ;
        rlutil::locate( posX-1, posY ) ;
        for( int i=posY; i<posY+4; i++ )
        {
            rlutil::locate( posX-1, i ) ;

            cout<<"█";
        }
        rlutil::locate( posX-1, posY-1 ) ;
        for( int h=posX-1; h<posX+3; h++ )
        {
            rlutil::setBackgroundColor( 15 ) ;
            cout<<"▄";
        }
    }

    string texto1;
    string texto2;

    int valor;
    if( dato!=0 )
    {
        if( dato<6 )
        {
            valor=dato ;
            rlutil::setColor(rlutil::LIGHTRED) ;
            texto2="♥";
        }
        else
        {
            if( dato<11 )
            {
                valor=dato-5 ;
                rlutil::setColor(rlutil::LIGHTRED) ;
                texto2="♦";
            }
            else
            {
                if( dato<16 )
                {
                    valor=dato-10 ;
                    rlutil::setColor( 0 ) ;
                    texto2="♣";
                }
                else
                {
                    valor=dato-15 ;
                    rlutil::setColor( 0 ) ;
                    texto2="♠";
                }
            }
        }
        switch ( valor )
        {
        case 1:
            texto1 = "10" ;
            break;
        case 2:
            texto1 = "J" ;
            break;
        case 3:
            texto1 = "Q" ;
            break;
        case 4:
            texto1 = "K" ;
            break;
        case 5:
            texto1 = "A" ;
            break;
        }
    }
    rlutil::setBackgroundColor( 15 ) ;

    rlutil::locate( posX+5, posY+4 ) ;
    cout<<texto1;

    rlutil::locate( posX+3, posY+2 ) ;
    cout<<texto2;

    rlutil::locate( posX, posY ) ;
    cout<<texto1;

    cout<<endl;

    rlutil::setColor( 15 );
    rlutil::setBackgroundColor( 0 );
}

void dibujarDorsoCarta( int posX, int posY, int dato, bool sombra )
{
    rlutil::setColor( 12 ) ;
    for( int i=posY; i<posY+5; i++ )
    {
        rlutil::locate( posX, i ) ;
        for( int h=posX; h<posX+7; h++ )
        {
            cout<<"█";
        }
        cout<<endl;
    }

//----------------------------- Borde-----------------------

    rlutil::setBackgroundColor( 12 ) ;
    rlutil::setColor( 15 ) ;
    rlutil::locate( posX, posY ) ;
    for( int i=posY; i<posY+5; i++ )
    {
        rlutil::locate( posX, i ) ;
        cout<<"█";
        rlutil::locate( posX+6, i ) ;
        cout<<"█";
    }
    rlutil::locate( posX+1, posY ) ;
    for( int h=posX+1; h<posX+6; h++ )
    {
        rlutil::locate( h, posY ) ;
        cout<<"▀";
        rlutil::locate( h, posY+4 ) ;
        cout<<"▄";
    }
//----------------------------- Símbolo-----------------------

    rlutil::locate( posX+3, posY+2 ) ;
    cout<< "§" ;

//----------------------------- Sombra-----------------------

    rlutil::setBackgroundColor( 15 ) ;
    if( sombra )
    {
        rlutil::setColor( 8 ) ;
        rlutil::locate( posX-1, posY ) ;
        for( int i=posY; i<posY+4; i++ )
        {
            rlutil::locate( posX-1, i ) ;

            cout<<"█";
        }
        rlutil::locate( posX-1, posY-1 ) ;
        for( int h=posX-1; h<posX+3; h++ )
        {
            cout<<"▄";
        }
    }
}
void dibujarEmbaucadora( int posX, int posY, int &cartaEmbaucadora )
{


    rlutil::setColor( 15 ) ;
    for( int i=posY; i<posY+5; i++ )
    {
        rlutil::locate( posX, i ) ;
        for( int h=posX; h<posX+7; h++ )
        {
            cout<<"█";
        }
        cout<<endl;
    }

    string carta;
    switch( cartaEmbaucadora )
    {
    case 5:
        carta="♥" ;
        break;
    case 10:
        carta= "♦" ;
        break;
    case 15:
        carta= "♣" ;
        break;
    case 20:
        carta= "♠" ;
        break;
    }
    rlutil::setColor(15);




    rlutil::locate( posX+3, posY+2 ) ;
    if(cartaEmbaucadora== 5 || cartaEmbaucadora == 10)
    {
        rlutil::setColor(rlutil::LIGHTRED);
        rlutil::setBackgroundColor(rlutil::WHITE);
        for(int j=0; j<5; j++)
        {
            rlutil::msleep(80);
        }

        cout<<carta;
    }
    else
    {
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        for(int j=0; j<5; j++)
        {
            rlutil::msleep(80);
        }

        cout<<carta;
    }


}

void posicionarPuntaje( int Jugador[], int estadoLinea[], int vPuntos[], int cartaInicial, int posX, int posY )
{

    rlutil::hidecursor();

    int espacio=0;
    for( int i=posY-1; i<=posY+4; i++ )
    {
        limpiar( posX-1+espacio, i, posX+3+espacio, i );
        espacio+=5;


    }

    rlutil::setColor( 10 );

    posicionarDescripcion( posX, posY, estadoLinea, -1, -1 ) ;
    for( int i=cartaInicial; i<cartaInicial+5; i++ )
    {

        //rlutil::msleep(700);                                  //---animar

        cout<<"+"<<vPuntos[Jugador[ i ] ];
        posicionarDescripcion( posX, posY, estadoLinea, 5, 1 );
    }
    rlutil::setColor( 15 );
}

void limpiar( int posX, int posY, int topeX, int topeY )
{


    rlutil::setColor(0) ;

    if(topeX==0 && topeY==0)
    {

        for( int y=posY; y<=rlutil::trows(); y++ )
        {
            rlutil::locate( posX, y ) ;

            for( int x=posX; x<=rlutil::tcols(); x++ )
            {
                cout<<"█";
            }

        }
    }
    else
    {
        for( int y=posY; y<=topeY; y++ )
        {
            rlutil::locate( posX, y ) ;

            for( int x=posX; x<=topeX; x++ )
            {
                cout<<"█";
            }

        }
    }
    rlutil::setColor( 15 ) ;
    rlutil::setBackgroundColor( 0 ) ;
}



