#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void QuickFindUF(int n);
int arr[];
int count;
int length;
int countNum();
bool isEmpty();
int find(int p);
// void validate(int p);
bool connected(int p, int q);
void unionF(int p, int q);
void validate(int p);
