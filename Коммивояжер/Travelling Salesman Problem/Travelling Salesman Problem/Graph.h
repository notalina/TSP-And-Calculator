#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
const int maxSize = 10;
//структура ребра
struct Edge {
	int from;
	int to;
	Edge(int _from, int _to) {
		from = _from;
		to = _to;
	}
};
class Graph {
private:
	//методы необходимые для заполнения
	
	bool isEmpty();
	bool isFull();
	int getVertexIndex(const char& vertex);
	
	//методы необходимые для решения задачи коммивояжера

	void reduceRows(vector<vector<int>>& matrix); //редукция строк
	vector<int> getRowsConstans(vector<vector<int>>& matrix); //получение минимумов по строкам
	void reduceColumns(vector<vector<int>>& matrix); //редукция столбцов
	vector<int> getColumnsConstants(vector<vector<int>>& matrix); //получение минимумов по столбцам
	Edge getMaxZero(vector<vector<int>>& matrix); //удаление строки и столбца с наиболльшим нулём
	void printRoute(); //печать маршрута
	int hamiltonLoop(vector<vector<int>>); //вычисление нижней границы
	void calculateRouteLength(); //вычисление длины получившегося маршрута
public:
	vector<Edge> route; //вектор ребёр получившегося маршрута
	vector<char> vertexes; //вектор вершин
	vector<vector<int>> matrix; //матрица смежности графа

public:
	Graph(); //конструктор без параметров
	void print(); //печать матрицы
	int getAmountVerts() { return this->vertexes.size(); } //получение количество вершин
	int getAmountEdges(); //получение количество ребер графа
	int getWeight(const char& vertex1, const char& vertex2); //получение веса ребра графа
	void addVertex(const char&);//добавление вершины
	void addEdge(const char& vertex1, const char& vertex2, int weight); //добавление ребра
	void solveTSP(); //метод для решения задачи коммивояжера (Travelling Salesman Problem)

	
};