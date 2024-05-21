#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

Graph* createGraph(int _vertices)
{
	Graph* tempGraph = (Graph*)malloc(sizeof(Graph));
	tempGraph->vertices = (int*)malloc(_vertices * sizeof(int));
	tempGraph->AmoundOfVertices = _vertices;
	tempGraph->matrix = (int**)malloc(_vertices * sizeof(int*));
	tempGraph->UsedAAmoundOfVertices = 0;
	for (int i = 0; i < _vertices; i++)
	{
		tempGraph->matrix[i] = (int*)malloc(_vertices * sizeof(int));
	}
	int i, j;
	for (i = 0; i < _vertices; i++)
	{
		for (j = 0; j < _vertices; j++)
		{
			tempGraph->matrix[i][j] = NULL;
		}
	}
	for (int i = 0; i < _vertices; i++)
	{
		tempGraph->vertices[i] = NULL;
	}
	return tempGraph;
}

void insert(Graph* _tempGraph, int verticeStart, int verticeEnd, int weight)
{
	do
	{
		if (NULL == _tempGraph)
		{
			printf("create greaph firstly bro");
			break;
		}

		if (NULL == _tempGraph->vertices[verticeStart])
		{
			_tempGraph->UsedAAmoundOfVertices += 1;
			_tempGraph->vertices[verticeStart] = verticeStart;
		}

		if (NULL == _tempGraph->vertices[verticeEnd])
		{
			_tempGraph->UsedAAmoundOfVertices += 1;
			_tempGraph->vertices[verticeEnd] = verticeEnd;
		}

		_tempGraph->matrix[verticeStart][verticeEnd] = weight;
	} while (false);

}

void insertDataFromFile(Graph* _tempGraph)
{
	FILE* fl = NULL;
	fl = fopen("data.txt", "r");
	char ptr = fgetc(fl);
	while (!feof(fl))
	{
		int start = 0, end = 0, weight = 0;
		char numbers[10];
		int counter = 0;
		while (ptr != ' ')
		{
			numbers[counter++] = ptr;
			ptr = fgetc(fl);
		}
		numbers[counter] = '\0';
		counter--;
		char* tempPtr = numbers;
		while (*tempPtr != '\0')
		{
			start += (*tempPtr - '0') * pow(10, counter);
			tempPtr++;
			counter--;
		}
		counter = 0;
		numbers[0] = '\0';
		ptr = fgetc(fl);

		while (ptr != ' ')
		{
			numbers[counter++] = ptr;
			ptr = fgetc(fl);
		}
		numbers[counter] = '\0';
		counter--;
		tempPtr = numbers;
		while (*tempPtr != '\0')
		{
			end += (*tempPtr - '0') * pow(10, counter);
			tempPtr++;
			counter--;
		}
		counter = 0;
		numbers[0] = '\0';
		ptr = fgetc(fl);

		while (ptr != '\n' && !feof(fl))
		{
			numbers[counter++] = ptr;
			ptr = fgetc(fl);
		}
		numbers[counter] = '\0';
		counter--;
		tempPtr = numbers;
		while (*tempPtr != '\0')
		{
			weight += (*tempPtr - '0') * pow(10, counter);
			tempPtr++;
			counter--;
		}
		counter = 0;

		insert(_tempGraph, start, end, weight);
		//printf("%d : %d : %d\n", );;
		ptr = fgetc(fl);
	}

}

void printGraph(Graph* _tempGraph)
{
	do
	{
		if (NULL == _tempGraph)
		{
			printf("create greaph firstly bro");
			break;
		}
		for (int i = 0; i < _tempGraph->AmoundOfVertices - 1; i++)
		{
			if (NULL != _tempGraph->vertices[i])
			{
				printf("%d : ", _tempGraph->vertices[i]);
				for (int j = 1; j < _tempGraph->AmoundOfVertices - 1; j++)
				{
					if (NULL != _tempGraph->matrix[i][j])
					{
						printf("%d ", j);
					}
				}
				printf("\n");
			}
		}
	} while (false);
}


Queue* createQueue()
{
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	temp->head = NULL;
	temp->tail = NULL;
	temp->size = 0;
	return temp;
}

void addToQueue(Queue* tempQ, int value)
{
	Qnode* temp = (Qnode*)malloc(sizeof(Qnode));
	temp->data = value;
	temp->next = NULL;

	if (tempQ->tail)
	{
		tempQ->tail->next = temp;
	}
	else
	{
		tempQ->head = temp;
	}
	tempQ->tail = temp;
	tempQ->size += 1;
}

Qnode* popQueue(Queue* tempQ)
{
	if (tempQ->head == NULL) return NULL;

	Qnode* temp = tempQ->head;
	tempQ->head = tempQ->head->next;
	if (tempQ->head == NULL)
	{
		tempQ->tail = NULL;
	}
	tempQ->size -= 1;
	return temp;
}

int front(Queue* tempQ)
{
	if (tempQ->head == NULL) return -1;
	return tempQ->head->data;
}

int empty(Queue* tempQ)
{
	return tempQ->size == 0;
}

void printQueue(Queue* tempQ)
{
	Qnode* temp = tempQ->head;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void graphBSF(Graph* _tempGraph, int _v)
{
	bool* visited = (bool*)malloc(maximumVertices * sizeof(bool));
	int* arrayOfWays = (int*)malloc(maximumVertices * sizeof(int));

	for (int i = 0; i < maximumVertices; i++) visited[i] = 0;
	for (int i = 0; i < maximumVertices; i++) arrayOfWays[i] = 0;

	Queue* q = createQueue();
	addToQueue(q, _v);
	visited[_v] = 1;
	arrayOfWays[_v] = 0;

	while (!empty(q))
	{
		int top = front(q);
		popQueue(q);
		printf("%d ", top);

		for (int i = 1; i < maximumVertices; i++)
		{
			if (_tempGraph->matrix[top][i] && !visited[i])
			{
				addToQueue(q, i);
				visited[i] = 1;
				arrayOfWays[i] = arrayOfWays[top] + _tempGraph->matrix[top][i];
			}
		}
	}
	printf("\nweight to all ways : \n");
	for (int i = 0; i < maximumVertices; i++)
	{
		if (arrayOfWays[i])
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	for (int i = 0; i < maximumVertices; i++)
	{
		if (arrayOfWays[i])
		{
			printf("%d ", arrayOfWays[i]);
		}
	}
	free(visited);

}

void menu()
{
	printf("\n0 - create graph\n");
	printf("1 - insert date to graph\n");
	printf("2 - print graph\n");
	printf("3 - read from file\n");
	printf("4 - BSF\n");
	printf("5 - delete graph\n : ");
}


void deleteGraph(Graph* _tempGraph)
{
	do
	{
		if (NULL == _tempGraph)
		{
			printf("create graph firstly\n");
			break;
		}
		int i;
		for (i = 0; i < _tempGraph->AmoundOfVertices; i++)
		{
			free(_tempGraph->matrix[i]);
		}
		free(_tempGraph->matrix);
		free(_tempGraph->vertices);
		free(_tempGraph);

	} while (true);

}