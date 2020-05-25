#pragma once
#include "Graph.h"
#include "glut.h"
const int MAX_VERTEX_COUNT = 10;
//cтруктура цвета 
struct ColorRGB {
    float red;
    float green;
    float blue;
    ColorRGB() {
        red = 0.6 + ((rand() % 60) / 100.f);
        green = 0.6 + ((rand() % 60) / 100.f);
        blue = 0.6 + ((rand() % 60) / 100.f);
    }
    ColorRGB(float r, float g, float b) {
        red = r;
        green = g;
        blue = b;
    }
};
//структура координат
struct Coord2d {
    float x, y;
};

class OpenGLHelper {
private:
    Graph* graph; 
    vector<ColorRGB> colors;
    Coord2d vertexCoordinats[MAX_VERTEX_COUNT];
    int vertexRadius; 
    int windowHeight;
    int windowWidth;
    void setColors(); //получение цвета
    void obtainVertextCoords(int vertexAmout); //получение координат вершины
    void drawCircle(float x, float y, ColorRGB); //рисование круга
    void drawVertex(int n); //рисование вершины
    void drawLine(int lineWeight, float x0, float y0, float x1, float y1, ColorRGB someColor); //отрисовка линий
    void drawText(string text, float x, float y); //вывод текста
    void drawGraph(); //главный метод дл€ отрисовки графа

public:
    OpenGLHelper(Graph* graph);
    void initWindow(int argc, char* argv[]);
    void reshape(int w, int h);
    void display(void);

};


