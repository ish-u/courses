#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;
#include "threeDimObject.h"

int main()
{
    int gd = DETECT, gm;
    // initgraph(&gd, &gm, NULL);
    initwindow(1000, 600);

    // cout << "Enter the Number of Co-ordinates : ";
    // int coOrdinates = 0;
    // cin >> coOrdinates;
    // ThreeDimObject *object = new ThreeDimObject(coOrdinates);
    // Default Constructor that draws a Cube with one cutted corner
    ThreeDimObject *object = new ThreeDimObject();

    // Menu
    int flag = 1;
    int option = 0;
    do
    {

        cout << "Choose Option\n"
             << "1. Scaling\n"
             << "2. Shearing\n"
             << "3. Reflection\n"
             << "4. Rotation\n"
             << "5. Translation\n"
             << "6. General Transformation Matrix\n"
             << "7. Object Animation\n"
             << "8. Orthographic Projection Demonstration\n"
             << "9. Axonometric Projection Demonstration\n"
             << "10. Oblique Projection Demonstration\n"
             << "11. Perspective Projection Demonstration\n"
             << "12. Exit\n"
             << " : ";
        cin >> option;
        cout << "\n";
        switch (option)
        {
        case 1:
            object->scaling();
            break;
        case 2:
            object->shearing();
            break;
        case 3:
            object->reflection();
            break;
        case 4:
            object->rotation();
            break;
        case 5:
            object->translation();
            break;
        case 6:
            object->transformationMatrix();
            break;
        case 7:
            object->animation();
            break;
        case 8:
            object->orthographicProjectionDemo();
            break;
        case 9:
            object->axonometricProjectionDemo();
            break;
        case 10:
            object->obliqueProjectionDemo();
            break;
        case 11:
            object->perspectiveProjectionDemo();
            break;
        case 12:
            flag = 0;
            cout << "EXITING\n";
            break;
        default:
            cout << " INVALID\n";
            break;
        }
        system("pause");
        system("cls");
        cleardevice();
        setcolor(15);
    } while (flag);

    // getch();
    closegraph();

    delete object;
    cout << Matrix::deleted << "\t" << Matrix::created << "\n";
    return 0;
}