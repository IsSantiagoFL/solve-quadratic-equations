#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Falta mejorar las funciones, algunas funciones no funcionan, por ello no se usan.

// PROTOTIPADO: Declaracion de las funcions que se usaran
void tipoNoEcuacionCuadratica (); 
void proposicionVerdadera ();
void proposicionFalsa ();
void tipoEcuacionLineal ();
void mostrarUnaSolucion ();
void tipoIncompleta () ;
void mostrarDiscriminante ();
void unaSolucionReal ();
void dosSolucionesReales ();
void discriminantMayorACero ();
void solucionNoReal ();
void discriminantMenorACero ();
void tipoCompleta ();

int main()
{
	double A, B, C, x, x1, x2, discriminant, E, F, G, H, I;

	printf("\n ----------------------------------------------------\n");
	printf("| Para la ecuación cuadratica de la forma: Ax^2+BX+C |\n");
	printf(" ----------------------------------------------------\n\n");

		printf("Ingrese el valor del coeficiente 'A' \n");
		scanf("%lf", &A);
		printf("Ingrese el valor del coeficiente 'B' \n");
		scanf("%lf", &B);
		printf("Ingrese el valor del coeficiente 'C' \n");
		scanf("%lf", &C);
		printf("\n-------------------------------------------------------\n\n");

		if (A == 0){
		//Cuando A=0, no es una ecuacion cuadratica.
			tipoNoEcuacionCuadratica ();
			if (B == 0){
			//Como B=0 entonces no es una ecuacion, es una igualdad
				printf("Es una proposicion de igualdad. P: %f = 0 \n",C);
				if (C == 0) {
					proposicionVerdadera ();
				} else {
					proposicionFalsa ();
				}
			} else {
			// Bx+C=0 Es una ecuacion lineal de una variable:
				tipoEcuacionLineal ();
				if (C == 0) {
					x = 0;
					mostrarUnaSolucion ();
				} else {
					x = -(C/B);
					mostrarUnaSolucion ();
				}
			}
		} else {
		//Como A es diferente de 0, si es una ecuacion cuadratica
			if (B == 0){
				tipoIncompleta () ;
				if (C == 0) {
					discriminant = 0;
					x = 0;
					mostrarUnaSolucion ();
					mostrarDiscriminante ();
					unaSolucionReal ();

					FILE *fp=popen ("gnuplot -persist", "w");
					fprintf(fp, "set title 'Gráfico para la ecuación cuadrática'\n");
					fprintf(fp, "set xzeroaxis linetype 1 linewidth 1.5 linecolor rgb '#69B51C'\n");
					fprintf(fp, "set yzeroaxis linetype 1 linewidth 0.5 linecolor rgb 'black'\n");
					fprintf(fp, "set border 0\n");
					fprintf(fp, "set xtics axis\n");
					fprintf(fp, "set ytics axis\n");
					fprintf(fp, "set tics scale 0.75\n");
					fprintf(fp, "set grid\n");
					fprintf(fp, "set xtics textcolor '#69B51C'\n");


					fprintf(fp, "plot (%.3f*x*x) lc '#2E9BE0' linewidth 1.5\n",A);

					fclose(fp);
				} else {
					discriminant = (-1)*(4*A*C);
					E = -(C/A);
					if (E>0){
						F = sqrt(E);
						x1 = (-1)*F;
						x2 = 1*F;
						printf("Las soluciones de la ecuación son: \nx1 = %f , x2 = %f \n\n",x1 ,x2);
						//mostrarDiscriminante ();
						printf("El discriminante es igual a %f \n",discriminant);
						discriminantMayorACero ();

						double j, k, infx, supx, infy, supy;

						if (x2 > x1){
							j = (abs(x2-x1));
							infx = x1-j;
							supx = x2+j;

							//k = abs(C)*0.2;
							//infy = -C-k;
							//supy = C+k;
							//s = x1+10;
							//y = (abs(s-m))/2;

							//GRAFICAR COMPLETA
							FILE *fp=popen ("gnuplot -persist"	, "w");
							fprintf(fp, "set title 'Gráfico para la ecuación cuadrática'\n");
							//fprintf(fp, "unset key\n");
							fprintf(fp, "set xrange [%f:%f]\n",infx,supx);
							//fprintf(fp, "set yrange [-%f:%f]\n",y,y);
							//fprintf(fp, "set yrange [%f:%f]\n",infy,supy);
							//fprintf(fp, "set zeroaxis linetype 1\n");
							fprintf(fp, "set xzeroaxis linetype 1 linewidth 1.5 linecolor rgb '#69B51C'\n");
							fprintf(fp, "set yzeroaxis linetype 1 linewidth 0.5 linecolor rgb 'black'\n");
							fprintf(fp, "set border 0\n");
							fprintf(fp, "set xtics axis\n");
							fprintf(fp, "set ytics axis\n");
							fprintf(fp, "set tics scale 0.75\n");
							fprintf(fp, "set grid\n");
							//fprintf(fp, "set zoom\n");
							//fprintf(fp, "set xtics x\n");
							fprintf(fp, "set xtics textcolor '#69B51C'\n");
							//fprintf(fp, "set xlabel 'x'\n");
							//fprintf(fp, "set ylabel 'y'\n");
							//Graficando para Ax^2+BX+C
							fprintf(fp, "plot (%.3f*x*x)+(%.3f) lc '#2E9BE0' linewidth 1.5\n",A,C);

							fclose(fp);

						} else {
							j = (abs(x1-x2));
							infx = x2-j;
							supx = x1+j;
							//k = abs(C)*0.2;
							//infy = -C-k;
							//supy = C+k;
							//s = x1+10;
							//y = (abs(s-m))/2;

							//GRAFICAR COMPLETA
							FILE *fp=popen ("gnuplot -persist"	, "w");
							fprintf(fp, "set title 'Gráfico para la ecuación cuadrática'\n");
							//fprintf(fp, "unset key\n");
							fprintf(fp, "set xrange [%f:%f]\n",infx,supx);
							//fprintf(fp, "set yrange [-%f:%f]\n",y,y);
							//fprintf(fp, "set yrange [%f:%f]\n",infy,supy);
							//fprintf(fp, "set zeroaxis linetype 1\n");
							fprintf(fp, "set xzeroaxis linetype 1 linewidth 1.5 linecolor rgb '#69B51C'\n");
							fprintf(fp, "set yzeroaxis linetype 1 linewidth 0.5 linecolor rgb 'black'\n");
							fprintf(fp, "set border 0\n");
							fprintf(fp, "set xtics axis\n");
							fprintf(fp, "set ytics axis\n");
							fprintf(fp, "set tics scale 0.75\n");
							fprintf(fp, "set grid\n");
							//fprintf(fp, "set zoom\n");
							//fprintf(fp, "set xtics x\n");
							fprintf(fp, "set xtics textcolor '#69B51C'\n");
							//fprintf(fp, "set xlabel 'x'\n");
							//fprintf(fp, "set ylabel 'y'\n");
							//Graficando para Ax^2+BX+C
							fprintf(fp, "plot (%.3f*x*x)+(%.3f) lc '#2E9BE0' linewidth 1.5\n",A,C);

							fclose(fp);


							//printf("¿Desea volver a ejecutar este programa? [S/n] \n\n");
							//scanf("%c",&D);
						}

					} else {
						G = (-1)*E;
						H = sqrt(G);
						solucionNoReal ();
						printf("El discriminante es igual a %f \n",discriminant);
						discriminantMenorACero ();
						printf("Las soluciones imaginarias son:\nx1 = -%fi , x2 = %fi \n\n",G,G);
					}
				}
			} else {
				if (C == 0) {
					tipoIncompleta ();
					discriminant = B*B;
					x1 = (-1)*(B/A);
					x2 = 0;
					printf("Las soluciones de la ecuación son: \nx1 = %f , x2 = %f \n\n",x1 ,x2);
					printf("El discriminante es igual a %f \n",discriminant);
					discriminantMayorACero ();

					//GRAFICAR INCOMPLETA PARA Ax^2 + Bx = 0
					double j, k, infx, supx, infy, supy;
					if (x2 > x1){ //X1 NEGATIVO
						j = (abs(x2-x1));
						infx = x1-j;
						supx = x2+j;
						FILE *fp=popen ("gnuplot -persist"	, "w");
						fprintf(fp, "set title 'Gráfico para la ecuación cuadrática'\n");
						//fprintf(fp, "unset key\n");
						fprintf(fp, "set xrange [%f:%f]\n",infx,supx);
						//fprintf(fp, "set yrange [-%f:%f]\n",y,y);
						//fprintf(fp, "set yrange [%f:%f]\n",infy,supy);
						//fprintf(fp, "set zeroaxis linetype 1\n");
						fprintf(fp, "set xzeroaxis linetype 1 linewidth 1.5 linecolor rgb '#69B51C'\n");
						fprintf(fp, "set yzeroaxis linetype 1 linewidth 0.5 linecolor rgb 'black'\n");
						fprintf(fp, "set border 0\n");
						fprintf(fp, "set xtics axis\n");
						fprintf(fp, "set ytics axis\n");
						fprintf(fp, "set tics scale 0.75\n");
						fprintf(fp, "set grid\n");
						//fprintf(fp, "set zoom\n");
						//fprintf(fp, "set xtics x\n");
						fprintf(fp, "set xtics textcolor '#69B51C'\n");
						//fprintf(fp, "set xlabel 'x'\n");
						//fprintf(fp, "set ylabel 'y'\n");
						//Graficando para Ax^2+BX+C
						fprintf(fp, "plot (%.3f*x*x)+(%.3f*x) lc '#2E9BE0' linewidth 1.5\n",A,B);

						fclose(fp);

					} else { //X1 POSITIVO
						j = (abs(x1-x2));
						infx = x2-j;
						supx = x1+j;
						//k = abs(C)*0.2;
						//infy = -C-k;
						//supy = C+k;
						//s = x1+10;
						//y = (abs(s-m))/2;

						//GRAFICAR COMPLETA
						FILE *fp=popen ("gnuplot -persist"	, "w");
						fprintf(fp, "set title 'Gráfico para la ecuación cuadrática'\n");
						//fprintf(fp, "unset key\n");
						fprintf(fp, "set xrange [%f:%f]\n",infx,supx);
						//fprintf(fp, "set yrange [-%f:%f]\n",y,y);
						//fprintf(fp, "set yrange [%f:%f]\n",infy,supy);
						//fprintf(fp, "set zeroaxis linetype 1\n");
						fprintf(fp, "set xzeroaxis linetype 1 linewidth 1.5 linecolor rgb '#69B51C'\n");
						fprintf(fp, "set yzeroaxis linetype 1 linewidth 0.5 linecolor rgb 'black'\n");
						fprintf(fp, "set border 0\n");
						fprintf(fp, "set xtics axis\n");
						fprintf(fp, "set ytics axis\n");
						fprintf(fp, "set tics scale 0.75\n");
						fprintf(fp, "set grid\n");
						//fprintf(fp, "set zoom\n");
						//fprintf(fp, "set xtics x\n");
						fprintf(fp, "set xtics textcolor '#69B51C'\n");
						//fprintf(fp, "set xlabel 'x'\n");
						//fprintf(fp, "set ylabel 'y'\n");
						//Graficando para Ax^2+BX+C
						fprintf(fp, "plot (%.3f*x*x)+(%.3f*x) lc '#2E9BE0' linewidth 1.5\n",A,B);

						fclose(fp);


								//printf("¿Desea volver a ejecutar este programa? [S/n] \n\n");
								//scanf("%c",&D);
					}

				} else {
				//Solo en este caso es una ecuacion cuadratica completa
					tipoCompleta ();
					E = 2*A;
					discriminant = (B*B)-(2*E*C);
					F = (-1)*(B/E);
					if (discriminant == 0) {
						x = F;
						printf("La solucion de la ecuacion es: \nx = %f \n\n",x);
						printf("El discriminante es igual a %f \n",discriminant);
						unaSolucionReal ();

						//GRAFICAR COMPLETA PARA DISCRIMINANE = 0
						FILE *fp=popen ("gnuplot -persist"	, "w");

						//Configuración visual de la gráfica, grid y ejes coordenadas rectangulares
						fprintf(fp, "set title 'Gráfico para la ecuación cuadrática'\n");
						//printf(fp, "set xrange [%f:%f]\n",infx,supx);
						fprintf(fp, "set xzeroaxis linetype 1 linewidth 1.5 linecolor rgb '#69B51C'\n");
						fprintf(fp, "set yzeroaxis linetype 1 linewidth 0.5 linecolor rgb 'black'\n");
						fprintf(fp, "set border 0\n");
						fprintf(fp, "set xtics axis\n");
						fprintf(fp, "set ytics axis\n");
						fprintf(fp, "set tics scale 0.75\n");
						fprintf(fp, "set grid\n");
						fprintf(fp, "set xtics textcolor '#69B51C'\n");


						fprintf(fp, "plot (%.3f*x*x)+(%.3f*x)+(%.3f) lc '#2E9BE0' linewidth 1.5\n",A,B,C);

						fclose(fp);

					} else {
						if (discriminant > 0) {
							G = (sqrt(discriminant)/E);
							x1 = F + G;
							x2 = F - G;
							printf("Las soluciones de la ecuación son: \nx1 = %f , x2 = %f \n\n",x1 ,x2);
							printf("El discriminante es igual a %f \n",discriminant);
							discriminantMayorACero ();

							//GRAFICAR COMPLETA
							//FILE *fp=popen ("gnuplot -persist"	, "w");
							//fprintf(fp, "set title 'Gráfico para la ecuación cuadrática'\n");
							//fprintf(fp, "set xlabel 'x'\n");
							//fprintf(fp, "set ylabel 'y'\n");
							//fprintf(fp, "plot (%f*x*x)+(%f*x)\n",A,B);

							//Declaración de variables
							double j, k, infx, supx, infy, supy;

							if (x2 > x1){


								j = (abs(x2-x1));
								infx = x1-j;
								supx = x2+j;

								//k = abs(C)*0.2;
								//infy = -C-k;
								//supy = C+k;
								//s = x1+10;
								//y = (abs(s-m))/2;

								//GRAFICAR COMPLETA
								FILE *fp=popen ("gnuplot -persist"	, "w");
								fprintf(fp, "set title 'Gráfico para la ecuación cuadrática'\n");
								//fprintf(fp, "unset key\n");
								fprintf(fp, "set xrange [%f:%f]\n",infx,supx);
								//fprintf(fp, "set yrange [-%f:%f]\n",y,y);
								//fprintf(fp, "set yrange [%f:%f]\n",infy,supy);
								//fprintf(fp, "set zeroaxis linetype 1\n");
								fprintf(fp, "set xzeroaxis linetype 1 linewidth 1.5 linecolor rgb '#69B51C'\n");
								fprintf(fp, "set yzeroaxis linetype 1 linewidth 0.5 linecolor rgb 'black'\n");
								fprintf(fp, "set border 0\n");
								fprintf(fp, "set xtics axis\n");
								fprintf(fp, "set ytics axis\n");
								fprintf(fp, "set tics scale 0.75\n");
								fprintf(fp, "set grid\n");
								//fprintf(fp, "set zoom\n");
								//fprintf(fp, "set xtics x\n");
								fprintf(fp, "set xtics textcolor '#69B51C'\n");
								//fprintf(fp, "set xlabel 'x'\n");
								//fprintf(fp, "set ylabel 'y'\n");
								//Graficando para Ax^2+BX+C
								fprintf(fp, "plot (%.3f*x*x)+(%.3f*x)+(%.3f) lc '#2E9BE0' linewidth 1.5\n",A,B,C);

								fclose(fp);

							} else {
								j = (abs(x1-x2));
								infx = x2-j;
								supx = x1+j;
								//k = abs(C)*0.2;
								//infy = -C-k;
								//supy = C+k;
								//s = x1+10;
								//y = (abs(s-m))/2;

								//GRAFICAR COMPLETA
								FILE *fp=popen ("gnuplot -persist"	, "w");
								fprintf(fp, "set title 'Gráfico para la ecuación cuadrática'\n");
								//fprintf(fp, "unset key\n");
								fprintf(fp, "set xrange [%f:%f]\n",infx,supx);
								//fprintf(fp, "set yrange [-%f:%f]\n",y,y);
								//fprintf(fp, "set yrange [%f:%f]\n",infy,supy);
								//fprintf(fp, "set zeroaxis linetype 1\n");
								fprintf(fp, "set xzeroaxis linetype 1 linewidth 1.5 linecolor rgb '#69B51C'\n");
								fprintf(fp, "set yzeroaxis linetype 1 linewidth 0.5 linecolor rgb 'black'\n");
								fprintf(fp, "set border 0\n");
								fprintf(fp, "set xtics axis\n");
								fprintf(fp, "set ytics axis\n");
								fprintf(fp, "set tics scale 0.75\n");
								fprintf(fp, "set grid\n");
								//fprintf(fp, "set zoom\n");
								//fprintf(fp, "set xtics x\n");
								fprintf(fp, "set xtics textcolor '#69B51C'\n");
								//fprintf(fp, "set xlabel 'x'\n");
								//fprintf(fp, "set ylabel 'y'\n");
								//Graficando para Ax^2+BX+C
								fprintf(fp, "plot (%.3f*x*x)+(%.3f*x)+(%.3f) lc '#2E9BE0' linewidth 1.5\n",A,B,C);

								fclose(fp);


								//printf("¿Desea volver a ejecutar este programa? [S/n] \n\n");
								//scanf("%c",&D);
							}

						} else {
							H = (-1)*discriminant;
							I = (sqrt(H)/E);
							solucionNoReal ();
							printf("El discriminante es igual a %f \n",discriminant);
							discriminantMenorACero ();
							printf("Las soluciones imaginarias son:\nx1 = %f+%fi , x2 = %f-%fi \n\n",F,H,F,H);
						}
					}
				}
			}
		}

	return 0;
}

// FUNCIONES
void tipoNoEcuacionCuadratica ()
{
	printf("No es una ecuación cuadratica, debido a que 'A' no es diferente de 0. \n\n");
}
void proposicionVerdadera ()
{
	printf("La proposicion es verdadera para cualquier valor de 'x'. \nPor lo tanto 'x'pertenece al conjunto de los numeros reales.\n\n");
}
void proposicionFalsa ()
{
	printf("La proposicion es falsa para cualquier valor de 'x'. \nPor lo tanto 'x' pertenece al conjunto vacio o nulo.\n\n");
}
void tipoEcuacionLineal ()
{
	printf("Es una ecuacion lineal de de una variable, de la forma: Bx+C=0 \n\n");
}
void mostrarUnaSolucion (double x)
{
	printf("La solucion de la ecuacion es: \nx = %f \n\n",x);	
}
void tipoIncompleta ()
{
	printf("La ecuación a resolver es una Ecuacion Cuadratica Incompleta de una variable. \n\n");
}
void mostrarDiscriminante (double discriminant)	
{
	printf("El discriminante es igual a %f \n",discriminant);
}
void unaSolucionReal ()
{
	printf("Por lo tanto la ecuacion cuadratica tiene solo una solucion real.\n\n");
}
void dosSolucionesReales (double x1, double x2)
{
	printf("Las soluciones de la ecuación son: \nx1 = %f , x2 = %f \n",x1 ,x2);
}
void discriminantMayorACero ()
{
	printf("El discriminate es mayor a 0, así que la ecuación cuadrática tiene dos soluciones reales. \n\n");
}
void solucionNoReal ()
{
	printf("La solución no esta definida en los reales.\n");
}
void discriminantMenorACero ()
{
	printf("El discriminate es menor que 0. Por lo tanto la ecuación cuadrática no tiene soluciones reales, \ntiene dos soluciones imaginarias.\n\n");
}
void tipoCompleta ()
{
	printf("Es una ecuación cuadrática completa.\n\n");
}
