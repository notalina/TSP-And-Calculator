#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
const int maxSize = 10;
//��������� �����
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
	//������ ����������� ��� ����������
	
	bool isEmpty();
	bool isFull();
	int getVertexIndex(const char& vertex);
	
	//������ ����������� ��� ������� ������ ������������

	void reduceRows(vector<vector<int>>& matrix); //�������� �����
	vector<int> getRowsConstans(vector<vector<int>>& matrix); //��������� ��������� �� �������
	void reduceColumns(vector<vector<int>>& matrix); //�������� ��������
	vector<int> getColumnsConstants(vector<vector<int>>& matrix); //��������� ��������� �� ��������
	Edge getMaxZero(vector<vector<int>>& matrix); //�������� ������ � ������� � ����������� ����
	void printRoute(); //������ ��������
	int hamiltonLoop(vector<vector<int>>); //���������� ������ �������
	void calculateRouteLength(); //���������� ����� ������������� ��������
public:
	vector<Edge> route; //������ ���� ������������� ��������
	vector<char> vertexes; //������ ������
	vector<vector<int>> matrix; //������� ��������� �����

public:
	Graph(); //����������� ��� ����������
	void print(); //������ �������
	int getAmountVerts() { return this->vertexes.size(); } //��������� ���������� ������
	int getAmountEdges(); //��������� ���������� ����� �����
	int getWeight(const char& vertex1, const char& vertex2); //��������� ���� ����� �����
	void addVertex(const char&);//���������� �������
	void addEdge(const char& vertex1, const char& vertex2, int weight); //���������� �����
	void solveTSP(); //����� ��� ������� ������ ������������ (Travelling Salesman Problem)

	
};