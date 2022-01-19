# Proyecto deslizamiento y volcamiento

## Fecha 
05-12-2021

## Integrantes

ESPINOZA PINO, BENJAMIN GASPAR (202030547-1).  
MAMANI PAUCAR, JUAN GABRIEL (202004631-k).  
RIVERA VERGARA, CAMILA FRANCISCA (202030508-0).  

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
[CamScanner_10-17-2021_18.58.pdf](/uploads/4adf675061109861c3c6ab5cfbe0a354/CamScanner_10-17-2021_18.58.pdf)
[CamScanner_10-17-2021_19.53_1_.pdf](/uploads/44ce3a98ce4333ddd7c7c7c1d9634b92/CamScanner_10-17-2021_19.53_1_.pdf)
[CamScanner_10-17-2021_20.47.pdf](/uploads/3139722001c6d46a8c8824e8444e7958/CamScanner_10-17-2021_20.47.pdf)

## Diagrama de componentes:


![imagen_final](/uploads/635633075dd01a392774cd7888322800/imagen_final.jpg)
![Untitled__1_](/uploads/44b3dafb1ac124156a0389d152b1017b/Untitled__1_.jpg)
![Untitled__3_](/uploads/58bd8d0c0f47ac653b9ef57b339dfc11/Untitled__3_.jpg)
![Untitled__4_](/uploads/e7d7987ff519547ce7c6e07fb665c9a5/Untitled__4_.jpg)



## Requisitos de compilación o plataforma :

Entorno de trabajo en qt 5.15.12.  
El programa se encuentra disponible en plataformas que permitan la visualizacion de codigos creados atraves de Qt Creator,
ademas de poseer un compilador compatible con el lenguaje de programacion C++ (MinGW, Cygwin, Bash, etc.) , y también debe incluir los respectivos modulos de Qt(QtCharts,QtCore y QtWidgets) y las librerias del programa (iostream y cmath).

## ¿Como compilar?

Por medio de QtCreator abrir el directorio del codigo como proyecto.  
Seleccionar la opcion RUN o control+R la cual compilara y ejecutara el programa desde la consola.

## Conclusión

A modo de conclusión se puede decir que se lograron los objetivos a cabalidad, se logró añadir la interfaz gráfica con éxito y se integraron las clases necesarias en el código fuente. De esta manera podemos decir que nuestro proyecto se ha completado y está listo para una futura comercialización en el mercado.

## Referencias Bibliográficas

- Sistemas simples de sólidos rígidos-http://laplace.us.es/wiki/index.php/Sistemas_simples_de_s%C3%B3lidos_r%C3%ADgidos  
- Vuelco en un plano inclinado-http://laplace.us.es/wiki/index.php/Vuelco_en_un_plano_inclinado  
- Fuerza de rozamiento (GIE)-http://laplace.us.es/wiki/index.php/Fuerzas_de_rozamiento_(GIE)#Rozamiento_est.C3.A1tico  
- ¿Qué son los planos inclinados?-https://es.khanacademy.org/science/physics/forces-newtons-laws/inclined-planes-friction/a/what-are-inclines  


