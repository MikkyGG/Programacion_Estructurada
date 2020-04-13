#include <iostream>
#include <stdlib.h>
#include <fstream>


using namespace std;

void lista_nombres(string l_nombres[],int n_a);
void lista_tareas(float t[][5], int n_a, int cont);
void leer_califs();
void califs_finales(int n_alum);




int main(){

    fstream archivo("Calificaciones_Finales.txt",ios::in | ios::out | ios::app);

    if(!archivo.is_open()){

        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    int choice;
    int n_alum;
    float c_final;
    float promedio_tareas;
    float exam;


    cout << "**************************************************************************" << endl;
    cout << endl;
    cout << "                       CALCULADOR DE PROMEDIOS" << endl;
    cout << endl;
    cout << "**************************************************************************" << endl;

    cout << endl;

    cout << "Que proceso desea realizar?\n" << endl;
    cout << "1) Leer lista de calificaciones finales\n" << endl;
    cout << "2) Crear una lista de calificaciones finales\n" << endl;
    cout << "Numero de eleccion: ";
    cin >> choice;
    cout << endl;
    cout << "--------------------------------------------------------------------------\n" << endl;

    switch(choice){

        case 1:

            leer_califs();
            break;

        case 2:

            cout << "Ingresa el numero de alumnos a Evaluar: ";

            cin >> n_alum;

            system("cls");

            string c_nombres[n_alum];
            float c_tareas[n_alum][5];

            lista_nombres(c_nombres, n_alum);

            system("cls");


            for(int i = 0; i < n_alum; i++){

                cout << "Tareas de " << c_nombres[i] << ": " << endl;

                cout << endl;

                lista_tareas(c_tareas, n_alum, i);
            }

            system("cls");


            archivo << "Nombre | T1 | T2 | T3 | T4 | Examen | C.F." << endl;
            archivo << endl;



            for(int i = 0; i < n_alum; i++){


                promedio_tareas = (c_tareas[i][0] + c_tareas[i][1] + c_tareas[i][2] + c_tareas[i][3])/4 * 0.40;

                exam = c_tareas[i][4] * 0.60;

                c_final = promedio_tareas + exam;

                archivo << c_nombres[i] << " | ";

                archivo << c_tareas[i][0] << "  |  ";
                archivo << c_tareas[i][1] << "  |  ";
                archivo << c_tareas[i][2] << "  |  ";
                archivo << c_tareas[i][3] << "  |  ";
                archivo << c_tareas[i][4] << "  |  ";

                archivo << c_final << endl;

            }

            califs_finales(n_alum);

            cout << endl;

            cout << "CALIFICACIONES GUARDADAS EN ARCHIVO: Calificaciones_Finales.txt" << endl;

            break;

    }
}




void lista_nombres(string l_nombres[], int n_a){

    string nombre_a;


    for(int i = 0; i < n_a; i++) {

        cout << "Nombre del alumno " << (i+1) << ": ";
        cin >> nombre_a;
        l_nombres[i] = {nombre_a};

    }

}


void lista_tareas(float t[][5], int n_a, int cont){

    float tareas;
    int c = 0;

    for(int j = 0; j < 5; j++){

        if(j != 4){

            cout << "Tarea " << (j+1) << ": ";
            cin >> tareas;
            t[cont][c] = {tareas};
        }

        else{

            cout << endl;

            cout << "Examen: ";
            cin >> tareas;
            t[cont][c] = {tareas};
            cout << endl;
            cout << "_________________________________________________________________________" << endl;
            cout << endl;

        }
        c = c + 1;
    }

}


void leer_califs(){

    ifstream calif_l;
    string texto;


    calif_l.open("Calificaciones_Finales.txt", ios::in);

    if(calif_l.fail()){

        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while(!calif_l.eof()){

        getline(calif_l, texto);

        cout << texto << endl;
    }

    calif_l.close();

}


void califs_finales(int n_alum){

    int m_size = n_alum + 2;

    string calif_final[m_size];

    short loop=0;

    string line;

    ifstream califs ("Calificaciones_Finales.txt");
    if (califs.is_open()){

        while(!califs.eof()){

            getline(califs, line);
            calif_final[loop] = line;
            cout << calif_final[loop] << endl;
            loop++;

        }
        califs.close();
    }

    else cout << "No se pudo abrir el archivo de texto";

}
