#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define maximumVertices 1000

typedef struct {
    int AmoundOfVertices;
    int UsedAAmoundOfVertices;
    int* vertices;
    int** matrix;
} Graph;


typedef struct Qnode
{
    int data;
    struct Qnode* next;
} Qnode;

typedef struct Queue
{
    Qnode* head;
    Qnode* tail;
    int size;
} Queue;


Graph* createGraph(int _vertices);

void insert(Graph* _tempGraph, int verticeStart, int verticeEnd, int weight);

void insertDataFromFile(Graph* _tempGraph);

void printGraph(Graph* _tempGraph);

Queue* createQueue();

void addToQueue(Queue* tempQ, int value);

void printQueue(Queue* tempQ);

Qnode* popQueue(Queue* tempQ);

int front(Queue* tempQ);

int empty(Queue* tempQ);

void graphBSF(Graph* _tempGraph, int _v);

void menu();

void deleteGraph(Graph* _tempGraph);
