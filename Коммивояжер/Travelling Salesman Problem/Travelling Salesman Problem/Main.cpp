#include "OpenGLHelper.h"
#include <iostream>

void fill(Graph& graph) {
	graph.addVertex('A');
	graph.addVertex('B');
	graph.addVertex('C');
	graph.addVertex('D');

	graph.addEdge('A', 'B', 3);
	graph.addEdge('A', 'C', 2);
	graph.addEdge('A', 'D', 5);

	graph.addEdge('B', 'A', 4);
	graph.addEdge('B', 'C', 1);
	graph.addEdge('B', 'D', 2);

	graph.addEdge('C', 'A', 5);
	graph.addEdge('C', 'B', 6);
	graph.addEdge('C', 'D', 7);

	graph.addEdge('D', 'A', 15);
	graph.addEdge('D', 'B', 11);
	graph.addEdge('D', 'C', 8);

}
bool graphFilled = false;

void start() {
	int zero = 0;
	Graph graph;
	int choice;
	do {
		cout << "1. Cформировать граф\n"
			<< "2. Задача Коммивояжера\n"
			<< "3. Показать граф\n"
			<< "0. Выход\n>";
		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			cout << "1. Cформировать вручную\n"
				<< "2. Выбрать готовый\n>";
			int choice2;
			cin >> choice2;
			if (choice2 == 1) {
				system("cls");
				int vertexCount = 0;
				while (vertexCount <= 0) {
					cout << "\nВведите количество вершин:";
					cin >> vertexCount;
				}
				vector<char> vertexs;
				for (int i = 0; i < vertexCount; i++) {
					cout << "\nВведите вершину: ";
					char someVertex;
					cin >> someVertex;
					graph.addVertex(someVertex);
					vertexs.push_back(someVertex);
				}
				for (int i = 0; i < vertexCount; i++) {
					for (int j = 0;  j< vertexCount; j++) {
						if (i != j) {
							int value;
							cout << "Введите вес ребра от " << vertexs[i] << " до " << vertexs[j] << ": ";
							cin >> value;
							cout << endl;
							graph.addEdge(vertexs[i], vertexs[j], value);
						}
					}
				}
				graph.print();
				system("PAUSE");
				system("cls");
				graphFilled = true;
			}
			if (choice2 == 2) {
				system("cls");
				fill(graph);
				graph.print();
				system("PAUSE");
				system("cls");
				graphFilled = true;
			}
			break;
		}
		case 2: {
			system("cls");
			if (graphFilled) {
				graph.print();
				graph.solveTSP();
				system("PAUSE");
				system("cls");
			}
			else {
				cout << "\nСформируйте граф!\n";
				system("cls");
			}
			break;
		}
		case 3: {
			if (graphFilled) {
				OpenGLHelper openGLHelper = OpenGLHelper(&graph);
				openGLHelper.initWindow(zero, NULL);
				system("cls");
			}
			else {
				system("cls");
				cout << "\nСформируйте граф!\n";
				system("PAUSE");
				system("cls");
			}
			break;
		}
		}
		
	} while (choice != 0);
}



int main() {
	setlocale(LC_ALL, "ru");
	start();
	return 0;
}