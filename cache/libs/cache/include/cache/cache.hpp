#pragma once

const int ELEMENT_SIZE = 64;
const int ELEMENTS = ELEMENT_SIZE / sizeof(int);
const int CACHE_SIZE = 8*1024*1024;
const int OFFSET = CACHE_SIZE*2;
const int Nmax = 20;
const int ARRAY_SIZE = OFFSET * Nmax;

int * AllocArray();
void FillArray(int *array, int n);
