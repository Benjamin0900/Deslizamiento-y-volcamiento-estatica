#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Alertmsg_2->setText("");
    ui->ok_1->setText("undefined");
    ui->ok_2->setText("undefined");
    ui->ok_3->setText("undefined");
    ui->ok_4->setText("undefined");
    ui->ok_5->setText("undefined");
    ui->ok_6->setText("undefined");
    ui->okissue_7->setText("__");

}

QChart *MainWindow::Grafico(DLC_bloque condiciones)//Se crea el Gráfico en un chart para mostrarse por la interfaz
{
    std::vector<puntos> plot1;
    int k;
    float i;

    for(i=1; i<= condiciones.altura;  i++){
        puntos guardar;
        guardar = funciones(condiciones, i);
        plot1.push_back(guardar);
        }
    QLineSeries *series = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *serieprin = new QLineSeries();
    for(k=0;k<(plot1.size());k++){
        puntos abrir = plot1[k];
        if(abrir.f1==-1){
            series1->append(abrir.h,abrir.f2);
        }else if(abrir.f2 == -1){
            series->append(abrir.h,abrir.f1);
        }else{
            series->append(abrir.h,abrir.f1);
            series1->append(abrir.h,abrir.f2);
        }
    }
    puntos punto_h;
    punto_h = funciones(condiciones, condiciones.h);
    if(punto_h.f1==-1){
        serieprin->append(punto_h.h, punto_h.f2);
    }else if(punto_h.f2==-1){
        serieprin->append(punto_h.h, punto_h.f1);
    }else{
        serieprin->append(punto_h.h, punto_h.f1);
        serieprin->append(punto_h.h, punto_h.f2);
    }
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->addSeries(series1);
    chart->addSeries(serieprin);
    chart->createDefaultAxes();
    chart->setTitle("Grafico de altura de la fuerza vs Magnitud de la Fuerza");

    return chart;
}

void MainWindow::on_buttonsimulate_clicked(){//Se lanza los resultados analizados a partir de las variables ingresadas

    //DLC variables para analizar las condiciones de deslizamiento o volcamiento respecto a la altura de la fuerza
    DLC_bloque condiciones;
    condiciones.angulo = on_button_angulo_clicked();
    condiciones.coefroce = on_button_coeficiente_clicked();
    condiciones.masa = on_button_masa_clicked();
    condiciones.base = on_button_base_obj_2_clicked();
    condiciones.altura = on_button_altura_obj_clicked();
    condiciones.h = on_button_altura_force_clicked();
    condiciones.peso = condiciones.masa*gravedad;
    condiciones.normal = condiciones.peso*cos(condiciones.angulo*PI/180.0);
    condiciones.froce = condiciones.coefroce*condiciones.normal*cos(condiciones.angulo*PI/180.0);
    condiciones.opcion = on_pushButton_2_clicked();

    std::string chek1 = ui->ok_1->text().toStdString();
    std::string chek2 = ui->ok_2->text().toStdString();
    std::string chek3 = ui->ok_3->text().toStdString();
    std::string chek4 = ui->ok_4->text().toStdString();
    std::string chek5 = ui->ok_5->text().toStdString();
    std::string chek6 = ui->ok_6->text().toStdString();
    std::string chek7 = ui->okissue_7->text().toStdString();

    std::string pass = "ok";
    if( chek1 == pass && chek2 == pass && chek3 == pass && chek4 == pass && chek5 == pass && chek6 == pass && chek7 == pass ){
    QChartView *chartViewgraph = new QChartView(Grafico(condiciones));
    chartViewgraph->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout->addWidget(chartViewgraph);
    if(condiciones.angulo == 0){ //condicion para diferenciar plano con inclinacion.
        std::string message = condicion_sin_inclinacion(condiciones);
        char* evaluando = strdup(message.c_str());
        ui->Alertmsg_2->setText(evaluando); //Se evalua la condicion de plano sin inclinacion con los datos ingresados por el usuario

    }
    else
    {

        if(condiciones.opcion == 2){ //condicion plano inclinado con fuerza descendente

            std::string message = condicion_fuerza_descendente(condiciones);
            char* evaluando = strdup(message.c_str());
            ui->Alertmsg_2->setText(evaluando);

        }else if( condiciones.opcion == 1 ){ //condicion para plano inclinado con fuerza ascendente

            std::string message = condicion_fuerza_ascendente(condiciones);
            char* evaluando = strdup(message.c_str());
            ui->Alertmsg_2->setText(evaluando);

        }
    }
    }else{
        ui->Alertmsg_2->setText("Las variables ingresadas no cumplen con requisitos para la simulación");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


double MainWindow::on_button_angulo_clicked()//boton que parametriza la variable
{
    char message[] = "Variable definida correctamente";
    char error[] = "Error: ingrese un valor entre 0° y menor que 90° para el ángulo.";
    double cond;
    cond = ui->spin_box_ang->value();
    if(  (cond < 0) || (cond >= 90 ) ){
        ui->Alertmsg_2->setText(error);
        ui->ok_1->setText("undefined");
    }else{
        ui->Alertmsg_2->setText(message);
        ui->ok_1->setText("ok");
    }
    return ui->spin_box_ang->value();
}


double MainWindow::on_button_coeficiente_clicked()//boton que parametriza la variable
{
    char message[] = "Variable definida correctamente";
    char error[] = "Error: ingrese un valor entre 0 y 1 para el coeficiente de roce.";
    double cond;
    cond = ui->dspinbox_coef->value();
    if(  (cond < 0) || (cond >1 ) ){
        ui->Alertmsg_2->setText(error);
        ui->ok_2->setText("undefined");
    }else{
        ui->Alertmsg_2->setText(message);
        ui->ok_2->setText("ok");
    }
    return ui->dspinbox_coef->value();
}


double MainWindow::on_button_masa_clicked()//boton que parametriza la variable
{

    char message[] = "Variable definida correctamente";
    char error[] = "Error: ingrese un valor mayor a 0[kg] para la masa.";
    double cond;
    cond = ui->dspinbox_m->value();
    if(  (cond <= 0) ){
        ui->Alertmsg_2->setText(error);
        ui->ok_3->setText("undefined");
    }else{
        ui->Alertmsg_2->setText(message);
        ui->ok_3->setText("ok");
    }
    return ui->dspinbox_m->value();
}


double MainWindow::on_button_base_obj_2_clicked()//boton que parametriza la variable
{

    char message[] = "Variable definida correctamente";
    char error[] = "Error: ingrese un valor mayor a 0[m] para la base del objeto";
    double cond;
    cond = ui->dspinbox_bo->value();
    if(  (cond <= 0) ){
        ui->Alertmsg_2->setText(error);
        ui->ok_4->setText("undefined");
    }else{
        ui->Alertmsg_2->setText(message);
        ui->ok_4->setText("ok");
    }
    return ui->dspinbox_bo->value();
}


double MainWindow::on_button_altura_obj_clicked()//boton que parametriza la variable
{

    char message[] = "Variable definida correctamente";
    char error[] = "Error: ingrese un valor mayor a 0[m]";
    double cond;
    cond = ui->dspinbox_ao->value();
    if(  (cond <= 0) ){
        ui->Alertmsg_2->setText(error);
        ui->ok_5->setText("undefined");
    }else{
        ui->Alertmsg_2->setText(message);
        ui->ok_5->setText("ok");
    }
    return ui->dspinbox_ao->value();
}


double MainWindow::on_button_altura_force_clicked()//boton que parametriza la variable
{

    char message[] = "Variable definida correctamente";
    char error[] = "Error: ingrese un valor mayor a 0[m] para la altura de la fuerza";
    double cond;
    cond = ui->dspinbox_af->value();
    if(  (cond <= 0) && (cond >  ui->dspinbox_ao->value())  ){
        ui->Alertmsg_2->setText(error);
        ui->ok_6->setText("undefined");
    }else{
        ui->Alertmsg_2->setText(message);
        ui->ok_6->setText("ok");
    }
    return ui->dspinbox_af->value();
}

double MainWindow::on_pushButton_2_clicked()//boton que parametriza la variable
{
    char message_issue[] = "La fuerza esta siendo ingresada por el lado izquierdo de la cara";
    char message_issue1[] = "La fuerza esta siendo ingresada por el lado derecho de la cara";
    double cond;
    cond = ui->set_direccion->value();
    if(  cond == 1  ){
        ui->Alertmsg_2->setText(message_issue);
        ui->okissue_7->setText("ok");
    }else{
        ui->Alertmsg_2->setText(message_issue1);
        ui->okissue_7->setText("ok");
    }
    return ui->set_direccion->value();
}


void MainWindow::on_pushButton_3_clicked()//boton que limpia el layout del Gráfico
{
    ui->gridLayout->removeWidget(ui->gridLayout->widget());
}

