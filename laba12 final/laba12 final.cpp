#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"


int main()
{
	Graph* myGraph = NULL;
	int choice;
	int flag = 0;
	while (1)
	{
		//printf("enter your choice : ");
		menu();
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 0:
			myGraph = createGraph(maximumVertices);
			break;
		case 1:
			int tempStart, tempEnd, tempWeigth;
			printf("enter start : ");
			scanf_s("%d", &tempStart);
			printf("enter end : ");
			scanf_s("%d", &tempEnd);
			printf("enter weight : ");
			scanf_s("%d", &tempWeigth);
			insert(myGraph, tempStart, tempEnd, tempWeigth);
			break;
		case 2:
			printGraph(myGraph);
			break;
		case 3:
			insertDataFromFile(myGraph);
			break;
		case 4:
			int tempPoint;
			printf("\nenter vertice to start : ");
			scanf_s("%d", &tempPoint);
			graphBSF(myGraph, tempPoint);
			break;
		case 5:
			flag = 1;
			break;
		default:
			printf("0 - 5\n");
			break;
		}
		if (flag)
		{
			break;
		}
	}

	deleteGraph(myGraph);

	return 0;
}