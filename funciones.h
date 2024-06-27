#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



 //------------------------------ MENÚ ----------------------------------
void encabezado();
void Jugar(std::string &nombreJ1, std::string &nombreJ2, std::string vHistoricoNom[], int vHistoricoPje[] );
void guardarNombres(std::string &nombreJ1, std::string &nombreJ2);
void dibujarRectangulo(int posx, int posy, int ancho, int alto);
void dibujarNumero(std::string numero, int posx, int posy);


 //------------------------------ JUEGO ----------------------------------

 void cargarVectores( int puntos[], int cantP ) ;
 void sortearMano( int ronda, int vJ1[], int vJ2[], int cartas, int puntaje ) ;
 void buscarCoincidencia( int rangoTope, int rangoInicio, int vJ1[], int vJ2[], int &numAlAzar, int cartas )  ;
 std::string formarCarta( int dato ) ;
 void sortearEmbaucadora(int &cartaEmbaucadora ) ;
 void mostrarMano( std::string estado, int cartaEmbaucadora, int ronda,std::string &nombreJ1, std::string &nombreJ2, int vJugador1[], int vJugador2[], int vPuntos[] ,int vPuntajeJ1[], int vPuntajeJ2[] ) ;
 void cambioEmbaucadora( int ronda,std:: string &nombreJ1, std::string &nombreJ2, int vPuntajeJ1[], int vPuntajeJ2[], int &cartaEmbaucadora,int vJugador1[], int vJugador2[], int vPuntos[] ) ;
 void mostrarPuntajesFinales( int vPuntajeJ1[], int vPuntajeJ2[], std::string &nombreJ1, std::string &nombreJ2,std::string &ganador, int &puntajeMaximo ) ;
 void mostrarEstadisticas( std::string  vHistoricoNom[], int vHistoricoPje[] ) ;
 void desempate( std::string nombreJ1, std::string nombreJ2, int vJugador1[], int vJugador2[], std::string &ganador, int CARTASJUGADORES ) ;
 void compararHistoricos( std::string ganador, int puntajeMaximo, std::string  vHistoricoNom[], int vHistoricoPje[] ) ;

 //------------------------------------------ graficar ------------------------------------------

 void anunciar( std::string mje, int x, int y ) ;
 void posicionarDescripcion(  int posX, int posY, int estadoLinea[], int lineasX, int lineasY );
 void posicionarPuntaje( int Jugador[], int estadoLinea[], int vPuntos[], int cartaInicial, int posX, int posY );

 void dibujarEmbaucadora( int posx, int posy, int &cartaEmbaucadora );

 void dibujarFrenteCarta( int posX, int posY, int dato, bool sombra) ;
 void posicionarCartas( int posX, int posY,int vJugador1[] );
 void dibujarDorsoCarta( int posX, int posY, int dato, bool sombra) ;

 void limpiar( int posX, int posY, int topeX, int topeY ) ;

#endif // FUNCIONES_H_INCLUDED
