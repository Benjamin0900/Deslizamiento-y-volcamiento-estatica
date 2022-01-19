#include "mainwindow.h"
#include <QApplication>

std::string condicion_sin_inclinacion(DLC_bloque d1){ //funcion que recibe un struct con los datos para evaluar la condicion
    if( d1.h < d1.base/(2*d1.coefroce) ){ //condicion de altura necesaria para deslizar o volcar y deslizar.

        std::string message = "El bloque solo podrá deslizar para toda fuerza mayor a ";
        float concat = d1.froce;
        message.append(to_string(concat));
        message.append("[N] aplicada a una altura ");
        float concat1 = d1.h;
        message.append(to_string(concat1));
        message.append(" [m].");
        return message;
    }else{

        if( (d1.coefroce)*d1.peso < (0.5*d1.base*d1.peso)/d1.h ){ //Condicion para evaluar si el bloque perdera el equilibrio por volcamiento o deslizamiento, segun la magnitud de sus fuerzas.

            std::string message = "La fuerza necesaria para que el bloque pierda el equilibrio por deslizamiento debe ser mayor a ";
            float concat = (d1.coefroce)*d1.peso;
            message.append(to_string(concat));
            message.append(" [N].\n");
            message.append("La fuerza necesaria para que el bloque pierda el equilibrio por volcamiento debe ser mayor a ");
            float concat1 = (0.5*d1.base*d1.peso)/d1.h;
            message.append(to_string(concat1));
            message.append(" [N].");
            return message;
        }else{

            std::string message = "Para los datos ingresados, el bloque perderá el equilibrio solo por volcamiento para toda fuerza mayor a ";
            float concat = (0.5*d1.base*d1.peso)/d1.h;
            message.append(to_string(concat));
            message.append(" [N].");
            return message;

        }

    }


}

std::string condicion_fuerza_descendente(DLC_bloque d1){
    if( d1.coefroce < tan(d1.angulo) ){ //condicion para evidenciar si existe movimiento por el peso del bloque.

        if( d1.altura <= (d1.base/d1.coefroce) ){ //condicion para saber si el bloque tiene dimensiones necesarias para volcar.

            std::string message = "El bloque ya se encuentra deslizando por acción de su peso, y para toda fuerza aplicada a la cara del bloque de altura ";
            float concat = d1.altura;
            message.append(to_string(concat));
            message.append(" [m], solo podra deslizar.");
            return message;


        }else{

            if( d1.h < ( (0.5*d1.base*d1.peso*cos(d1.angulo)) - (0.5*d1.altura*d1.peso*sin(d1.angulo)) )/ ( d1.coefroce*d1.peso*cos(d1.angulo) - d1.peso*sin(d1.angulo) ) ){ //condicion para saber si la altura de la fuerza puede generar volcamiento.

                std::string message = "Para la altura a la que se encuentra la fuerza, el bloque solo puede deslizar, y en este caso, ya se encuentra deslizando por la acción del peso.";
                return message;
            }else{
                std::string message = "El bloque ya se encuentra deslizando por la acción del peso.\n";
                message.append("Para que el bloque vuelque, la fuerza necesaria debe ser mayor a ");
                float concat = ( (0.5*d1.base*d1.peso*cos(d1.angulo)) - (0.5*d1.altura*d1.peso*sin(d1.angulo)) )/d1.h;
                message.append(to_string(concat));
                message.append(" [N].");
                return message;
            }

        }



    }else{

        if( d1.altura < d1.base*(cos(d1.angulo)/sin(d1.angulo)) ){ //condicion para saber si el bloque tiene dimensiones para volcar.

            std::string message = "Para la altura del bloque de ";
            float concat = d1.altura;
            message.append(to_string(concat));
            message.append("[m] el bloque solo podra deslizar desde el equilibrio, y para toda fuerza mayor a ");
            float concat1 =( d1.coefroce*d1.peso*cos(d1.angulo) - d1.peso*sin(d1.angulo) );
            message.append(to_string(concat1));
            message.append(" [N].");
            return message;
        }else{

            if( d1.h < (( (0.5*d1.base*d1.peso*cos(d1.angulo)) - (0.5*d1.altura*d1.peso*sin(d1.angulo)) )/ ( d1.coefroce*d1.peso*cos(d1.angulo) - d1.peso*sin(d1.angulo) )) ){ //condicion para saber si la altura de la fuerza puede provocar volcamiento.

                std::string message = "Para la altura a la que se encuentra la fuerza, el bloque solo puede deslizar con una fuerza mayor a ";
                float concat = ( d1.coefroce*d1.peso*cos(d1.angulo) - d1.peso*sin(d1.angulo) );
                message.append(to_string(concat));
                message.append(" [N].");
                return message;

            }else{

                std::string message = "Para que el bloque deslice, la fuerza necesaria debe ser mayor a ";
                float concat = ( d1.coefroce*d1.peso*cos(d1.angulo) - d1.peso*sin(d1.angulo) );
                message.append(to_string(concat));
                message.append(" [N].\n");
                message.append("Para que el bloque vuelque, la fuerza necesaria debe ser mayor a ");
                float concat1 = ( (0.5*d1.base*d1.peso*cos(d1.angulo)) - (0.5*d1.altura*d1.peso*sin(d1.angulo)) )/d1.h;
                message.append(to_string(concat1));
                message.append(" [N].");
                return message;

            }
        }

    }
}

std::string condicion_fuerza_ascendente(DLC_bloque d1){

    if( d1.coefroce < tan(d1.angulo) ){ //condicion para saber si el bloque esta sujeto a un movimiento

        if( d1.altura <  (d1.base/d1.coefroce) ){ //condicion para saber si el bloque tiene la altura suficiente para poder volcar.

            std::string message = "Para los datos ingresados se prevee que el bloque esta deslizandose contrario a la dirección de la fuerza producto del peso del bloque.\n";

            message.append("Para la altura del bloque se calcula que el bloque solo puede deslizar, independiente de la altura a la que se aplica la fuerza.");
            message.append("Los rangos de fuerza para deslizamiento hacia abajo es desde 0 [N] hasta una fuerza menor a ");
            float concat = ( d1.peso*sin(d1.angulo) - d1.froce );
            message.append(to_string(concat));
            message.append(" [N].\n");
            message.append("Para el deslizamiento hacia arriba se requiere una fuerza mayor a ");
            float concat1 = ( d1.peso*sin(d1.angulo) + d1.froce );
            message.append(to_string(concat1));
            message.append(" [N].\n");
            return message;

        }else{

            if( d1.base < d1.altura*tan(d1.angulo) ){ //condicion para saber si la altura del bloque generara vocamiento

                std::string message = "Para la altura ingresada de la fuerza, se calcula que éste generará volcamiento hacia abajo.\n";
                message.append("Para mantener el volcamiento, la fuerza debe ser menor a ");
                float concat = ( 0.5*d1.altura*d1.peso*sin(d1.angulo) - 0.5*d1.base*d1.normal)/d1.h;
                message.append(to_string(concat));
                message.append(" [N].\n");
                message.append("La fuerza necesaria para deslizar hacia arriba sera mayor a ");
                float concat1 = d1.peso*sin(d1.angulo) + d1.froce;
                message.append(to_string(concat1));
                message.append(" [N].\n");

                if( d1.h < (0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/( d1.froce +d1.peso*sin(d1.angulo) ) ){//condicion para saber si la altura generara volcamiento

                    message.append("Para la altura ingresada de la fuerza, se calcula que éste no generará volcamiento hacia arriba");
                    return message;
                }else{

                    message.append("La fuerza necesaria para el volcamiento hacia arriba debe ser mayor a ");
                    float concat2 = (0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/d1.h;
                    message.append(to_string(concat2));
                    message.append(" [N].\n");
                    return message;
                }

            }else{

                std::string message = "Para la altura ingresada de la fuerza, se calcula que éste no generará volcamiento hacia abajo. \n";
                message.append("Para mantener el deslizamiento hacia abajo, la fuerza tiene que ser menor a ");
                float concat = (d1.peso*sin(d1.angulo) - d1.froce);
                message.append(to_string(concat));
                message.append(" [N].\n");
                message.append("Para generar deslizamiento hacia arriba, la fuerza tiene que ser mayor a ");
                float concat1 = (d1.peso*sin(d1.angulo) + d1.froce);
                message.append(to_string(concat1));
                message.append(" [N].\n");

                if( d1.h  <  ( 0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/( d1.froce +d1.peso*sin(d1.angulo) ) ){//condicion para saber si la altura de la fuerza generara volcamiento
                    message.append("Para la altura ingresada de la fuerza, se calcula que éste no generará volcamiento hacia arriba.\n");
                    return message;
                }else{
                    message.append("Para generar volcamiento hacia arriba se necesita una fuerza mayor a ");
                    float concat2 = ( ( 0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/d1.h );
                    message.append(to_string(concat2));
                    message.append(" [N].\n");
                    return message;
                }
            }
        }

    }else{

        if( d1.altura < d1.base*(cos(d1.angulo)/sin(d1.angulo)) ){ //condicion para saber si el bloque en equilibrio tiene la altura necesaria para generar volcamiento


            std::string message = "El bloque se encuentra en equilibrio.\n";
            message.append("Para la altura ingresada del bloque se calcula que solo podrá deslizar.\n");
            message.append("Para deslizar hacia arriba se requiere una fuerza mayor a ");
            float concat = ( d1.peso*sin(d1.angulo) + d1.froce );
            message.append(to_string(concat));
            message.append(" [N].\n");
            return message;

        }else{

            if( d1.base < d1.altura*tan(d1.angulo) ){//condicion para saber si el bloque tiene volcamiento por accion del peso

                std::string message("El bloque se encuentra en volcamiento hacia la izquierda por acción del peso");
                message.append("Para mantener el volcamiento, la fuerza debe ser menor a ");
                float concat = ( 0.5*d1.altura*d1.peso*sin(d1.angulo) - 0.5*d1.base*d1.normal)/d1.h;
                message.append(to_string(concat));
                message.append(" [N].\n");
                message.append("La fuerza necesaria para deslizar hacia arriba sera mayor a ");
                float concat1 = d1.peso*sin(d1.angulo) + d1.froce;
                message.append(to_string(concat1));
                message.append(" [N].\n");

                if( d1.h < (0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/( d1.froce +d1.peso*sin(d1.angulo) ) ){//condicion para saber si la altura ingresada de la fuerza generara volcamiento

                    message.append("Para la altura ingresada de la fuerza, se calcula que éste no generará volcamiento hacia arriba.\n");
                    return message;
                }else{

                    message.append("La fuerza necesaria para el volcamiento hacia arriba debe ser mayor a ");
                    float concat2 = (0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/d1.h;
                    message.append(to_string(concat2));
                    message.append(" [N].\n");
                    return message;
                }





            }else{

                std::string message = "El bloque se encuentra en equilibrio";
                message.append("Para generar deslizamiento hacia arriba, la fuerza debe ser mayor a ");
                float concat = ( d1.peso*sin(d1.angulo) + d1.froce );
                message.append(to_string(concat));
                message.append(" [N].\n");
                if(  d1.h  <  ( 0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/( d1.froce +d1.peso*sin(d1.angulo) ) ){ //condicion para saber si la altura ingresada de la fuerza generara volcamiento

                    message.append("Para la altura ingresada de la fuerza, se calcula que éste no generará volcamiento hacia arriba\n");
                    return message;
                }else{

                    message.append("Para generar volcamiento hacia arriba, la fuerza necesaria debe ser mayor a ");
                    float concat1 = ( 0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/d1.h;
                    message.append(to_string(concat1));
                    message.append(" [N].\n");
                    return message;
                }
            }
        }

    }
}



puntos funciones(DLC_bloque d1, float i){
        puntos result;
        if(d1.angulo == 0){ //condicion para diferenciar plano con inclinacion.
            if( i < (d1.base/(2*d1.coefroce)) ){ //condicion de altura necesaria para deslizar o volcar y deslizar.

                result.f1 = d1.froce;
                result.h = i;
                return result;

            }else{

                if( (d1.coefroce)*d1.peso < (0.5*d1.base*d1.peso)/i ){ //Condicion para evaluar si el bloque perdera el equilibrio por volcamiento o deslizamiento, segun la magnitud de sus fuerzas.
                    result.h = i;
                    result.f1 = (d1.coefroce)*d1.peso;
                    result.f2 = (0.5*d1.base*d1.peso)/i;
                    return result;

                }else{
                    result.h = i;
                    result.f2 = (0.5*d1.base*d1.peso)/i;
                    return result;
                }

            }

        }
        else
        {

            if(d1.opcion == 2){ //condicion plano inclinado con fuerza descendente
                if( d1.coefroce < tan(d1.angulo) ){ //condicion para evidenciar si existe movimiento por el peso del bloque.

                    if( d1.altura <= (d1.base/d1.coefroce) ){ //condicion para saber si el bloque tiene dimensiones necesarias para volcar.
                        result.h = i;
                        return result;

                    }else{

                        if( i < ( (0.5*d1.base*d1.peso*cos(d1.angulo)) - (0.5*d1.altura*d1.peso*sin(d1.angulo)) )/ ( d1.coefroce*d1.peso*cos(d1.angulo) - d1.peso*sin(d1.angulo) ) ){ //condicion para saber si la altura de la fuerza puede generar volcamiento.
                            result.h = i;
                            return result;

                        }else{
                            result.h = i;
                            result.f2 = ( (0.5*d1.base*d1.peso*cos(d1.angulo)) - (0.5*d1.altura*d1.peso*sin(d1.angulo)) )/i;
                            return result;
                        }

                    }



                }else{

                    if( d1.altura < d1.base*(cos(d1.angulo)/sin(d1.angulo)) ){ //condicion para saber si el bloque tiene dimensiones para volcar.
                        result.h = i;
                        result.f1 = ( d1.coefroce*d1.peso*cos(d1.angulo) - d1.peso*sin(d1.angulo) );
                        return result;
                    }else{

                        if( i < (( (0.5*d1.base*d1.peso*cos(d1.angulo)) - (0.5*d1.altura*d1.peso*sin(d1.angulo)) )/ ( d1.coefroce*d1.peso*cos(d1.angulo) - d1.peso*sin(d1.angulo) )) ){ //condicion para saber si la altura de la fuerza puede provocar volcamiento.
                            result.h = i;
                            result.f1 = ( d1.coefroce*d1.peso*cos(d1.angulo) - d1.peso*sin(d1.angulo) );
                            return result;

                        }else{
                            result.h = i;
                            result.f1 =  ( d1.coefroce*d1.peso*cos(d1.angulo) - d1.peso*sin(d1.angulo) );
                            result.f2 = ( (0.5*d1.base*d1.peso*cos(d1.angulo)) - (0.5*d1.altura*d1.peso*sin(d1.angulo)) )/i;
                            return result;
                        }
                    }

                }


            }else if( d1.opcion == 1 ){ //condicion para plano inclinado con fuerza ascendente
                if( d1.coefroce < tan(d1.angulo) ){ //condicion para saber si el bloque esta sujeto a un movimiento

                    if( d1.altura <  (d1.base/d1.coefroce) ){ //condicion para saber si el bloque tiene la altura suficiente para poder volcar.
                        result.h = i;
                        result.f1 = ( d1.peso*sin(d1.angulo) - d1.froce );
                        result.f2 = ( d1.peso*sin(d1.angulo) + d1.froce );
                        return result;

                    }else{

                        if( d1.base < d1.altura*tan(d1.angulo) ){ //condicion para saber si la altura del bloque generara vocamiento
                            result.h = i;
                            result.f1 =( 0.5*d1.altura*d1.peso*sin(d1.angulo) - 0.5*d1.base*d1.normal)/i;

                            if( i < (0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/( d1.froce +d1.peso*sin(d1.angulo) ) ){//condicion para saber si la altura generara volcamiento

                                result.h = i;
                                return result;
                            }else{
                                result.h = i;
                                result.f2 =   (0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/i;
                                return result;
                            }

                        }else{

                            if( i  <  ( 0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/( d1.froce +d1.peso*sin(d1.angulo) ) ){//condicion para saber si la altura de la fuerza generara volcamiento
                                result.h = i;
                                result.f1 = (d1.peso*sin(d1.angulo) - d1.froce);
                                result.f2 = (d1.peso*sin(d1.angulo) + d1.froce);
                                return result;
                            }else{
                                result.h = i;
                                result.f1 = (d1.peso*sin(d1.angulo) - d1.froce);
                                result.f2 = ( ( 0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/i);
                                return result;
                            }
                        }
                    }

                }else{

                    if( d1.altura < d1.base*(cos(d1.angulo)/sin(d1.angulo)) ){ //condicion para saber si el bloque en equilibrio tiene la altura necesaria para generar volcamiento

                        result.h = i;
                        result.f1 = ( d1.peso*sin(d1.angulo) + d1.froce );
                        return result;
                    }else{

                        if( d1.base < d1.altura*tan(d1.angulo) ){//condicion para saber si el bloque tiene volcamiento por accion del peso

                            if( i < (0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/( d1.froce +d1.peso*sin(d1.angulo) ) ){//condicion para saber si la altura ingresada de la fuerza generara volcamiento

                                result.h = i;
                                result.f1 = ( 0.5*d1.altura*d1.peso*sin(d1.angulo) - 0.5*d1.base*d1.normal)/i;
                                result.f2 = d1.peso*sin(d1.angulo) + d1.froce;
                                return result;

                            }else{
                                result.h = i;
                                result.f1 = ( 0.5*d1.altura*d1.peso*sin(d1.angulo) - 0.5*d1.base*d1.normal)/i;
                                result.f2 =  (0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/i;
                                return result;

                            }





                        }else{
                            result.h = i;
                            result.f1 = ( d1.peso*sin(d1.angulo) + d1.froce );

                            if(  i  <  ( 0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/( d1.froce +d1.peso*sin(d1.angulo) ) ){ //condicion para saber si la altura ingresada de la fuerza generara volcamiento

                                result.f2 = -1;
                                return result;

                            }else{

                                result.f2 = ( 0.5*d1.altura*d1.peso*sin(d1.angulo) + 0.5*d1.base*d1.normal )/i;
                                return result;
                            }
                            return result;
                        }
                    }

                }



            }
        }
        return result;

    }


int main(int argc,char *argv[]){
    QApplication a(argc, argv);

    MainWindow l;
    l.show();
    return a.exec();
}
