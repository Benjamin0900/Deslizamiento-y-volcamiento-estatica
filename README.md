# Proyecto deslizamiento y volcamiento

## Fecha 
05-12-2021

## Integrantes

ESPINOZA PINO, BENJAMIN GASPAR gitlab.com/BenjaminEspinoza .  
MAMANI PAUCAR, JUAN GABRIEL gitlab.com/nijoko.  
RIVERA VERGARA, CAMILA FRANCISCA gitlab.com/Cami_727.  

## Introducción

Este proyecto se hizo con la finalidad de responder a la necesidad de las personas que requieren calcular la fuerza necesaria para volcar o deslizar un bloque, es así como nosotros con nuestro programa logramos hacer el cálculo al instante. En las siguientes líneas se explicará en qué consiste el programa, que variables se utilizaron, los cálculos físicos realizados, el diagrama de componentes del código fuente y los requisitos de compilación.

## Descripción

El siguiente programa permite el cálculo de la fuerza necesaria para volcar o deslizar un bloque en un plano con o sin inclinación, y además la visualización gráfica de la fuerza necesaria para deslizar o volcar para cada altura del bloque. También, tenemos como objetivo principal añadir una interfaz gráfica en la cual se le soliciten los datos al usuario, y además tenemos como objetivo perfeccionar el código fuente añadiendo clases para lograr un correcto funcionamiento de la interfaz gráfica.

Los datos que se le piden al usuario son los siguientes:
- Masa del bloque [kg]
- Ángulo de inclinación del plano [°]
- Base del bloque [m]
- Altura del bloque [m]
- Altura a la que se aplica la fuerza [m]
- Dirección de la fuerza (en caso de que exista inclinación en el plano)
- Coeficiente de rozamiento [ ]

##### Datos utlizados:
- Gravedad == g = 10.0
- PI = 3.141592
##### Datos como variables:
- μ == Coeficiente de rozamiento
- θ == Ángulo de inclinación del plano = θ*PI/180
- Peso == W = masa*g
- Normal == N = masa*g*cos(θ)
- Fuerza de roce == fr = masa*g*cos(θ)*μ

##### Casos analizados completamente con respecto al programa:

- Sistemas simples de sólidos rígidos-http://laplace.us.es/wiki/index.php/Sistemas_simples_de_s%C3%B3lidos_r%C3%ADgidos  
- Vuelco en un plano inclinado-http://laplace.us.es/wiki/index.php/Vuelco_en_un_plano_inclinado  
- Fuerza de rozamiento (GIE)-http://laplace.us.es/wiki/index.php/Fuerzas_de_rozamiento_(GIE)#Rozamiento_est.C3.A1tico  

## Requisitos de compilación o plataforma :

Entorno de trabajo en qt 5.15.12.  
El programa se encuentra disponible en plataformas que permitan la visualizacion de codigos creados atraves de Qt Creator,
ademas de poseer un compilador compatible con el lenguaje de programacion C++ (MinGW, Cygwin, Bash, etc.) , y también debe incluir los respectivos modulos de Qt(QtCharts,QtCore y QtWidgets) y las librerias del programa (iostream y cmath).

## Instrucciones de compilación y lanzamiento

Por medio de QtCreator abrir el directorio del codigo como proyecto.  
Seleccionar la opcion RUN o control+R la cual compilara y ejecutara el programa desde la consola.

## Conclusión

A modo de conclusión se puede decir que se lograron los objetivos a cabalidad, se logró añadir la interfaz gráfica con éxito y se integraron las clases necesarias en el código fuente. De esta manera podemos decir que nuestro proyecto se ha completado y está listo para una futura comercialización en el mercado.
