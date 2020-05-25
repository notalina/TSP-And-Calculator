#include "OpenGLHelper.h"
using namespace std;
int windowNumber;
OpenGLHelper* openGLHelper;

void mainDisplay() {
	openGLHelper->display();
}

void onWindowResize(int newWidth, int newHeight) {
	openGLHelper->reshape(newWidth, newHeight);
}

void OpenGLHelper::setColors() {
	for (int i = 0; i < this->graph->getAmountVerts(); i++) {
		ColorRGB someColor;
		colors.push_back(someColor);
	}
}

//конструктор

OpenGLHelper::OpenGLHelper(Graph* graph) {
	this->windowHeight = 600;
	this->windowWidth = 600;
	this->graph = graph;
	openGLHelper = this;
}

//инициализация окна

void OpenGLHelper::initWindow(int argc, char* argv[]) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(this->windowWidth, this->windowHeight);
	windowNumber = glutCreateWindow("The Graph");
	
	glutDisplayFunc(mainDisplay);
	glutReshapeFunc(onWindowResize);
	
	glutMainLoop();
}

void OpenGLHelper::display() {
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, this->windowWidth, 0, this->windowHeight);
	glViewport(0, 0, this->windowWidth, this->windowHeight);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	this->obtainVertextCoords(this->graph->getAmountVerts());
	this->drawGraph();
	
	glutSwapBuffers();
};

void OpenGLHelper::reshape(int w, int h) {
	this->windowWidth = w;
	this->windowHeight = h;
	glViewport(0, 0, (GLsizei)this->windowWidth, (GLsizei)this->windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)this->windowWidth, 0, (GLdouble)this->windowHeight);
	glutPostRedisplay();
};

//главный метод отрисовки графа

void OpenGLHelper::drawGraph() {
	setColors();
	ColorRGB blackColor(0,0,0);
	int vertexAmount = this->graph->getAmountVerts();
	for (int vertexI = 0; vertexI < vertexAmount; vertexI++) {
		for (int vertexJ = 0; vertexJ < vertexAmount; vertexJ++) {
			int routeWeight = this->graph->matrix[vertexI][vertexJ];
			if (routeWeight > 0) {
				this->drawLine(routeWeight,
					this->vertexCoordinats[vertexI].x,
					this->vertexCoordinats[vertexI].y,
					this->vertexCoordinats[vertexJ].x,
					this->vertexCoordinats[vertexJ].y, blackColor);
			}
		}
	}
	for (int vertexI = 0; vertexI < vertexAmount; vertexI++) {
		this->drawVertex(vertexI);
	}
}

//получение координат для вершин

void OpenGLHelper::obtainVertextCoords(int vertexCount) {
	float graphRadius;
	float windowCenterY = this->windowHeight / 2;
	float windowCenterX = this->windowWidth / 2;
	int canvasHeight = this->windowHeight;
	int canvasWidth = this->windowWidth;

	int shortestSide = canvasWidth < canvasHeight ? canvasWidth : canvasHeight;
	this->vertexRadius = 5 * (shortestSide / MAX_VERTEX_COUNT) / vertexCount - 20; 
	graphRadius = shortestSide / 2 -this->vertexRadius * 2;

	if (vertexCount > 0) {
		for (int i = 0; i < vertexCount; i++) {
			float degree = 2.0f * 3.1415926f / float(vertexCount) * float(i);
			this->vertexCoordinats[i].y = windowCenterY + graphRadius * cos(degree);
			this->vertexCoordinats[i].x = windowCenterX + graphRadius * sin(degree);
		}
	}
};

//отрисовка вершин

void OpenGLHelper::drawVertex(int index) {
	this->drawCircle(this->vertexCoordinats[index].x, this->vertexCoordinats[index].y, colors[index]);
	this->drawText(string(1, this->graph->vertexes[index]), this->vertexCoordinats[index].x, this->vertexCoordinats[index].y);
};

//отрисовкка круга

void OpenGLHelper::drawCircle(float x, float y, ColorRGB color) {
	glColor3f(color.red, color.green, color.blue);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		float degree = 2.0f * 3.1415926f / 360.0f * i;
		y1 = y + vertexRadius * cos(degree);
		x1 = x + vertexRadius * sin(degree);
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = vertexRadius * cos(theta) + y;
		x2 = vertexRadius * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
};

//отрисовка линий

void OpenGLHelper::drawLine(int number, float x0, float y0, float x1, float y1, ColorRGB someColor) {
	string text = to_string(number);

	x1 = (x0 + x1) / 2;
	y1 = (y0 + y1) / 2;

	glColor3f(someColor.red, someColor.green, someColor.blue);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
 
	float vx = x0 - x1;
	float vy = y0 - y1;
	float s = 1.0f / sqrt(vx * vx + vy * vy);
	vx *= s;
	vy *= s;
	this->drawText(text, (x0 + x1) / 2 - 10 * (vx + vy), (y0 + y1) / 2 - 10 * (vx + vy));

	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x1 + 10 * (vx + vy), y1 + 10 * (vy - vx));
	glVertex2f(x1 + 10 * (vx - vy), y1 + 10 * (vy + vx));
	glEnd();
};

//отрисовка текста

void OpenGLHelper::drawText(string text, float x, float y) {
	glRasterPos2i(x - 5, y - 5);
	glRasterPos2i(x - 5, y - 5);
	for (int j = 0; j < text.length(); j++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[j]);
	}
};
