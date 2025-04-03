#ifndef type_h
#define type_h

typedef struct datapenerbangan {
  char tempat[5];
  char kodepenerbangan[8];
  char waktu[7];
  char info[22];
} data;

void setflight(char *newplace, char *flightcode, char *time, char *newinfo,
               data *stream);

void printdata(data stream);

void getstring(char *stream);

void makesched(data *stream);
#endif // !type_h
