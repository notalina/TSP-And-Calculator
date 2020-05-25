#include "Graph.h"
#include <algorithm>
using namespace std;

Graph::Graph() { //конструктор без параметров
}
int Graph::getVertexIndex(const char& vertex) {
	for (int i = 0; i < this->vertexes.size(); ++i) {
		if (this->vertexes[i] == vertex)
			return i;
	}
	return -1;
}
bool Graph::isEmpty() {
	return this->vertexes.size() == 0;
}

bool Graph::isFull() {
	return vertexes.size() == maxSize;
}

int Graph::getAmountEdges() {
	int amount = 0; // обнуляем счетчик
	if (!this->isEmpty()) { // проверяем, что граф не пуст
		for (int i = 0; i < this->vertexes.size(); ++i) {
			for (int j = 0; j < this->vertexes.size(); ++j) {
				if (this->matrix[i][j] == 1) { // находим рёбра
					amount += 1; // считаем количество рёбер
				}
			}
		}
		return amount; // возвращаем количество рёбер
	}
	return 0; // если граф пуст, возвращаем 0
}

int Graph::getWeight(const char& vertex1, const char& vertex2) {
	if (!this->isEmpty()) {
		int vertPos1 = getVertexIndex(vertex1);
		int vertPos2 = getVertexIndex(vertex2);
		return matrix[vertPos1][vertPos2];
	}
	return 0;
}

void Graph::addVertex(const char& vertex) {
	if (!this->isFull() && getVertexIndex(vertex) == -1) {
		matrix.push_back(vector<int>(vertexes.size(), 0));
		for (int i = 0; i < vertexes.size(); i++) {
			matrix[i].push_back(0);
		}
		matrix[vertexes.size()].push_back(INT_MAX);
		this->vertexes.push_back(vertex);
	}
	else {
		cout << "Граф уже заполнен. Невозможно добавить новую вершину " << endl;
		return;
	}
}

void Graph::addEdge(const char& vertex1, const char& vertex2, int weight) {
	if (this->getVertexIndex(vertex1) != (INT_MAX) && this->getVertexIndex(vertex2) != (INT_MAX)) {
		int vertPos1 = getVertexIndex(vertex1);
		int vertPos2 = getVertexIndex(vertex2);
		if (this->matrix[vertPos1][vertPos2] != 0) {
			cout << "Ребро между этими вершинами уже существует" << endl;
		}
		else if (this->matrix[vertPos1][vertPos2] == INT_MAX) {
			cout << "Начальная и конечная вершины одинаковыые" << endl;
		}
		else {
			this->matrix[vertPos1][vertPos2] = weight;
		}
	}
	else {
		cout << "Одной или двух вершин нет в графе " << endl;
	}
	system("cls");
}

void Graph::print() {
	if (!this->isEmpty()) {
		cout << "Матрица смежности графа: " << endl << "\t ";
		for(auto vertex: vertexes){
			cout << vertex << " \t ";
		}
		cout << endl;
		for (int i = 0; i < this->vertexes.size(); ++i) {
			cout << this->vertexes[i] << "\t";
			for (int j = 0; j < this->vertexes.size(); ++j) {
				if (matrix[i][j] != INT_MAX) {
					cout << " " << this->matrix[i][j] << "\t";
				}
				else {
					cout << " " << "M " << "\t";
				}
			}
			cout << endl;
		}
	} else {
		cout << "Граф пуст " << endl;
	}
}

//метод для создания копии матрицы
vector<vector<int>> makeCopy(vector<vector<int>> matrix) {
	int capacity = matrix.size();
	vector<vector<int>> matrixCopy(capacity);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			matrixCopy[i].push_back(matrix[i][j]);
		}
	}
	return matrixCopy;
}

void Graph::reduceRows(vector<vector<int>>& matrix) { //Редукция строк
	// константы приведения
	vector<int> constants = getRowsConstans(matrix);
	int min = *std::min_element(constants.begin(), constants.end());

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) { //Редукция строки
			if (i != j && matrix[i][j] != INT_MAX) { //Если не путь в тот же город
				matrix[i][j] -= constants[i]; //вычитаем минимум
			}
		}

	}
}

//получение минимумов в строке
vector<int> Graph::getRowsConstans(std::vector<std::vector<int>>& matrix){
	vector<int> constants;
	for (int i = 0; i < matrix.size(); i++) {//Проход по строкам
		int min = INT_MAX; //Минимум для каждой строки 
		for (int j = 0; j < matrix.size(); j++) {
			if (i != j && matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
		constants.push_back(min);
	}
	return constants;
}

//редукция столбиков
void Graph::reduceColumns(vector<vector<int>>& matrix) {//Редукция столбцов
	// константы приведения
	vector<int> constants = getColumnsConstants(matrix);
	int min = *std::min_element(constants.begin(), constants.end());

	for (int j = 0; j < matrix.size(); j++) {
		for (int i = 0; i < matrix.size(); i++) { //Редукция столбца
			if (i != j && matrix[i][j] != INT_MAX) { //Если не путь в тот же город
				matrix[i][j] -= constants[j]; //вычитаем минимум
			}
		}
	}
}

//получение минимумов по столбикам
vector<int> Graph::getColumnsConstants(std::vector<std::vector<int>>& matrix){
	vector<int> constants;
	for (int j = 0; j < matrix.size(); j++) {//Проход по столбцам
		int min = INT_MAX; //Минимум для каждого столбца 
		for (int i = 0; i < matrix.size(); i++) {
			if (i != j && matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
		constants.push_back(min);
	}
	return constants;
}

//включение ребра
vector<vector<int>> includeEdge(vector<vector<int>>& original, Edge edge) {
	auto matrix = makeCopy(original);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (i == edge.from) {
				matrix[i][j] = INT_MAX;
			}
			if (j == edge.to) {
				matrix[i][j] = INT_MAX;
			}
		}
	}
	return matrix;
}

//исключение ребра
vector<vector<int>> excludeEdge(vector<vector<int>>& original, Edge edge) {
	auto matrix = makeCopy(original);
	matrix[edge.from][edge.to] = INT_MAX;
	return matrix;
}

// извлекает из матрицы колонку и возвращает ее как вектор
vector<int> getColumnAsVector(vector<vector<int>>& matrix, int columnIndex) {
	vector<int> column;
	for (int i = 0; i < matrix.size(); i++) {
		column.push_back(matrix[i][columnIndex]);
	}
	return column;
}

// нахождениее минимума в векторе за исключением i индекса
int findMinExceptIndex(vector<int> values, int excludeIndex) {
	// удаляем из вектора элемент который нужно пропустить
	values.erase(values.begin() + excludeIndex);
	return *std::min_element(values.begin(), values.end());
}


//метод оценки нулей
Edge Graph::getMaxZero(vector<vector<int>>& matrix) {
	int max = INT_MIN, selectedRow, selectedColumn;
	for (int row = 0; row < matrix.size(); row++) {
		for (int column = 0; column < matrix.size(); column++) {
			if (matrix[row][column] == 0) {
				int rowMinimum = findMinExceptIndex(matrix[row], column);
				int columnMinimum = findMinExceptIndex(getColumnAsVector(matrix, column), row);
				int sum = rowMinimum + columnMinimum;
				if (sum > max) {
					max = sum;
					selectedRow = row;
					selectedColumn = column;
				}
			}
		}
	}
	return Edge(selectedRow, selectedColumn);
}

//цикл гамильтона
int Graph::hamiltonLoop(vector<vector<int>> matrix) {
	vector<int> rowConstans = getRowsConstans(matrix);
	vector<int> columnsConstans = getColumnsConstants(matrix);
	int sum = 0;
	for (int i = 0; i < rowConstans.size(); i++) {
		sum += rowConstans[i] + columnsConstans[i];
	}
	return sum;
}

//главная функция решения задачи коммивояжера
void Graph::solveTSP() {
	auto matrixCopy = makeCopy(matrix);
	int i = 0;
	for (i; i < vertexes.size() - 1; i++) {
		reduceRows(matrixCopy);
		reduceColumns(matrixCopy);
		auto edge = getMaxZero(matrixCopy);
		auto includedEdgeMatrix = includeEdge(matrixCopy, edge);
		auto excludedEdgeMatrix = excludeEdge(matrixCopy, edge);
		if (i == 0 //на первой итерации мы выбираем без оценки гамельтоновых циклов
			|| hamiltonLoop(includedEdgeMatrix) <= hamiltonLoop(excludedEdgeMatrix)) {
			route.push_back(edge);
			matrixCopy = includedEdgeMatrix;
		}
		else {
			matrixCopy = excludedEdgeMatrix;
		}
	}
	printRoute();
	calculateRouteLength();
}

void Graph::calculateRouteLength(){
	int path = matrix[route[route.size() - 1].to][route[0].from]; // расстояние от последней вершины до первой
	path += matrix[route[0].from][route[0].to]; // расстояние первого ребра

	for (int i = 1; i < route.size(); i++) { // проходим по массиву структур
		path += matrix[route[i].from][route[i].to]; //прибавим расстояние i-того ребра
	}
	for (int i = 0; i < route.size() - 1; i++) { //проходим по массиву структур
		if (route[i].to != route[i + 1].from) { //если поля равны, то расстояние от вершины А до А считаем равным 0
			path += matrix[route[i].to][route[i + 1].from]; //считаем расстояние между ребрами
		}
	}
	cout << "Вычисленное расстояние: " << path << '\n';
}

void Graph::printRoute(){
	for (auto edge : route) {
		cout << vertexes[edge.from] << "=>" << vertexes[edge.to] << "\n";
	}
}