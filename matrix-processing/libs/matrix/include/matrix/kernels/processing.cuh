#pragma once


void launch(char*, char*, int rows, int columns);
__global__ void process(const char*, char*, int rows, int columns);