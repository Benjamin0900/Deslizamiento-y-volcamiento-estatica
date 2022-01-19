#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <stdlib.h>
#include <cmath>
#define PI 3.141592
#define gravedad 9.8

using namespace std;

typedef struct{

    float masa, coefroce, angulo, base, altura, h, peso, froce, normal;
    int opcion;

}DLC_bloque; //Estructura creada para contener todas las variables que participan en el modelo físico.

typedef struct{

    float h=0;
    float f1 = -1;
    float f2 = -1;
    float f3 = -1;
}puntos; //Estructura creada para almacenar pares de coordenadas (x,y) para graficar.


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    double on_button_angulo_clicked();

    double on_button_coeficiente_clicked();

    double on_button_masa_clicked();

    double on_button_base_obj_2_clicked();

    double on_button_altura_obj_clicked();

    double on_button_altura_force_clicked();

    void on_buttonsimulate_clicked();

    double on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    QChart *Grafico(DLC_bloque condiciones);

    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H




DLC_bloque tomar_datos();//Función que toma datos por input y los almacena en un struct definido que luego retorna, además calcula otros datos a partir de los ingresados.
puntos funciones(DLC_bloque d1, float i); //Funcion que genera las coordenadas que son usadas para generar una salida grafica

std::string condicion_sin_inclinacion(DLC_bloque d1); //Funcion que estudia el primer modelo con inclinacion 0[°] en la superficie

std::string condicion_fuerza_descendente(DLC_bloque d1); //Funcion que estudia el tercer modelo estudiado que corresponde cuando la fuerza se aplica desde la cara alta

std::string condicion_fuerza_ascendente(DLC_bloque d1); //Funcion que estudia el segundo modelo estudiado que corresponde cuando la fuerza se aplica desde la cara baja
