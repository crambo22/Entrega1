#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;

	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char consulta [80];
	//Conexión al servidor MYSQL
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexiￃﾳn: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//Iniciamos la conexión
	conn = mysql_real_connect (conn, "localhost","user", "pass", "Jugador" 0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//Indicamos la base de datos que usaremos 
	err=mysql_query(conn, "use Registro;");
	if (err!=0)
	{
		printf ("Error al crear la base de datos %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//Hacemos la consulta
	printf("Dime el jugador que ha jugado mas partidas\n");
	err=mysql_query(conn, "SELECT usuario FROM Jugador WHERE partidas_jugadas IN ( SELECT MAX(partidas_jugadas) FROM Jugador )");
	if (err!=0){
		printf ("Error al conusltar datos de la base %u %s\n" mysql_errno(conn, mysl_error(conn));
		exit(1);
	}
	//Recogemos el resultado de la consulta 
	resultado = mysql_store_result(conn);
	
	row = mysql_fetch_row (resultado);
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL) {
			printf ("El jugador que ha ganado mas partidas es %s \n", row[0]);
			row = mysql_fetch_row (resultado);
		}
	//Cerramos la conexion con el servidor
	mysql_close(conn);
	exit(0);
	
	
	
	
	
	
	
	
	
	
	
	
	
}
