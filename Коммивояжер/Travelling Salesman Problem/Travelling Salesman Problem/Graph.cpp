#include "Graph.h"
#include <algorithm>
using namespace std;

Graph::Graph() { //����������� ��� ����������
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
	int amount = 0; // �������� �������
	if (!this->isEmpty()) { // ���������, ��� ���� �� ����
		for (int i = 0; i < this->vertexes.size(); ++i) {
			for (int j = 0; j < this->vertexes.size(); ++j) {
				if (this->matrix[i][j] == 1) { // ������� ����
					amount += 1; // ������� ���������� ����
				}
			}
		}
		return amount; // ���������� ���������� ����
	}
	return 0; // ���� ���� ����, ���������� 0
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
		cout << "���� ��� ��������. ���������� �������� ����� ������� " << endl;
		return;
	}
}

void Graph::addEdge(const char& vertex1, const char& vertex2, int weight) {
	if (this->getVertexIndex(vertex1) != (INT_MAX) && this->getVertexIndex(vertex2) != (INT_MAX)) {
		int vertPos1 = getVertexIndex(vertex1);
		int vertPos2 = getVertexIndex(vertex2);
		if (this->matrix[vertPos1][vertPos2] != 0) {
			cout << "����� ����� ����� ��������� ��� ����������" << endl;
		}
		else if (this->matrix[vertPos1][vertPos2] == INT_MAX) {
			cout << "��������� � �������� ������� �����������" << endl;
		}
		else {
			this->matrix[vertPos1][vertPos2] = weight;
		}
	}
	else {
		cout << "����� ��� ���� ������ ��� � ����� " << endl;
	}
	system("cls");
}

void Graph::print() {
	if (!this->isEmpty()) {
		cout << "������� ��������� �����: " << endl << "\t ";
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
		cout << "���� ���� " << endl;
	}
}

//����� ��� �������� ����� �������
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

void Graph::reduceRows(vector<vector<int>>& matrix) { //�������� �����
	// ��������� ����������
	vector<int> constants = getRowsConstans(matrix);
	int min = *std::min_element(constants.begin(), constants.end());

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) { //�������� ������
			if (i != j && matrix[i][j] != INT_MAX) { //���� �� ���� � ��� �� �����
				matrix[i][j] -= constants[i]; //�������� �������
			}
		}

	}
}

//��������� ��������� � ������
vector<int> Graph::getRowsConstans(std::vector<std::vector<int>>& matrix){
	vector<int> constants;
	for (int i = 0; i < matrix.size(); i++) {//������ �� �������
		int min = INT_MAX; //������� ��� ������ ������ 
		for (int j = 0; j < matrix.size(); j++) {
			if (i != j && matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
		constants.push_back(min);
	}
	return constants;
}

//�������� ���������
void Graph::reduceColumns(vector<vector<int>>& matrix) {//�������� ��������
	// ��������� ����������
	vector<int> constants = getColumnsConstants(matrix);
	int min = *std::min_element(constants.begin(), constants.end());

	for (int j = 0; j < matrix.size(); j++) {
		for (int i = 0; i < matrix.size(); i++) { //�������� �������
			if (i != j && matrix[i][j] != INT_MAX) { //���� �� ���� � ��� �� �����
				matrix[i][j] -= constants[j]; //�������� �������
			}
		}
	}
}

//��������� ��������� �� ���������
vector<int> Graph::getColumnsConstants(std::vector<std::vector<int>>& matrix){
	vector<int> constants;
	for (int j = 0; j < matrix.size(); j++) {//������ �� ��������
		int min = INT_MAX; //������� ��� ������� ������� 
		for (int i = 0; i < matrix.size(); i++) {
			if (i != j && matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
		constants.push_back(min);
	}
	return constants;
}

//��������� �����
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

//���������� �����
vector<vector<int>> excludeEdge(vector<vector<int>>& original, Edge edge) {
	auto matrix = makeCopy(original);
	matrix[edge.from][edge.to] = INT_MAX;
	return matrix;
}

// ��������� �� ������� ������� � ���������� �� ��� ������
vector<int> getColumnAsVector(vector<vector<int>>& matrix, int columnIndex) {
	vector<int> column;
	for (int i = 0; i < matrix.size(); i++) {
		column.push_back(matrix[i][columnIndex]);
	}
	return column;
}

// ����������� �������� � ������� �� ����������� i �������
int findMinExceptIndex(vector<int> values, int excludeIndex) {
	// ������� �� ������� ������� ������� ����� ����������
	values.erase(values.begin() + excludeIndex);
	return *std::min_element(values.begin(), values.end());
}


//����� ������ �����
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

//���� ����������
int Graph::hamiltonLoop(vector<vector<int>> matrix) {
	vector<int> rowConstans = getRowsConstans(matrix);
	vector<int> columnsConstans = getColumnsConstants(matrix);
	int sum = 0;
	for (int i = 0; i < rowConstans.size(); i++) {
		sum += rowConstans[i] + columnsConstans[i];
	}
	return sum;
}

//������� ������� ������� ������ ������������
void Graph::solveTSP() {
	auto matrixCopy = makeCopy(matrix);
	int i = 0;
	for (i; i < vertexes.size() - 1; i++) {
		reduceRows(matrixCopy);
		reduceColumns(matrixCopy);
		auto edge = getMaxZero(matrixCopy);
		auto includedEdgeMatrix = includeEdge(matrixCopy, edge);
		auto excludedEdgeMatrix = excludeEdge(matrixCopy, edge);
		if (i == 0 //�� ������ �������� �� �������� ��� ������ ������������� ������
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
	int path = matrix[route[route.size() - 1].to][route[0].from]; // ���������� �� ��������� ������� �� ������
	path += matrix[route[0].from][route[0].to]; // ���������� ������� �����

	for (int i = 1; i < route.size(); i++) { // �������� �� ������� ��������
		path += matrix[route[i].from][route[i].to]; //�������� ���������� i-���� �����
	}
	for (int i = 0; i < route.size() - 1; i++) { //�������� �� ������� ��������
		if (route[i].to != route[i + 1].from) { //���� ���� �����, �� ���������� �� ������� � �� � ������� ������ 0
			path += matrix[route[i].to][route[i + 1].from]; //������� ���������� ����� �������
		}
	}
	cout << "����������� ����������: " << path << '\n';
}

void Graph::printRoute(){
	for (auto edge : route) {
		cout << vertexes[edge.from] << "=>" << vertexes[edge.to] << "\n";
	}
}