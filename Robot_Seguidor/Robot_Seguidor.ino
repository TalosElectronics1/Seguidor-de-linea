/*
 * Talos Electronics
 * Tgo. Rafael Lozano Rolon 
 * Modificado por ultima vez 15 Diciembre 2016
 * Para inicializar el Robot se necesita definir los pines de la siguiente manera
 * Robot_Seguidor Nombre_Robot(In1,In2,Vss1-2,IN3,IN4,Vss3-4,S1,S2,S3,S4,S5,S6) 
 *                   
 * 
 *     /////////////////Parametros///////////////
 *    /            Puente H                     /
 *    /    Parametro -> Numero de pin           /
 *    /    IN1       ->     2                   /
 *    /    In2       ->     7                   /   
 *    /    Vss1-2    ->     1                   /  
 *    /    In3       ->     10                  /   
 *    /    In4       ->     15                  /                                      
 *    /    Vss3-4    ->     9                   /           
 *    / ----------------------------------------/             
 *    /         Modulo seguidor de linea        /   
 *    /    Parametro -> 	Numero de pin       /                     
 *    /    S1        ->  Salida 1 del modulo    /
 *    /                   seguidor de linea     /       
 *    /    S2        ->   Salida 2 ..           /
 *	  /	   S3        ->   Salida 3 ...          /
 *	  /    S4        ->   Salida 4 ....         /
 *	  /    S5        ->   Salida 5 .....        /
 *	  /    S6        ->   Salida 6 ......       /
 *    //////////////////////////////////////////
 */
#include "Robot_Seguidor.h"
Robot_Seguidor Robot(13,12,11,10,8,9,2,3,4,5,6,7);

void setup() 
{
	Robot.Inicializar();
}

void loop() 
{
	Robot.Modo_Seguidor(21,11,30,255);//(int kP,int KI,int KD,int Velocidad)
}   
