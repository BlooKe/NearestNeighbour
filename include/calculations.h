#ifndef CALCULATIONS_H
#define CALCULATIONS_H

int calculateDistances(Data_t *dataset, Data_t data);
double distance(Data_t a, Data_t b);
int getNearest(KNearest_t *nearest, Data_t *dataset);

#endif // CALCULATIONS_H
