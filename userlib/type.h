#ifndef type_h
#define type_h

typedef struct datapenerbangan {
  char tempat[3];
  char kodepenerbangan[6];
  char waktu[5];
  char info[];
} data;

void setflight(const char *newplace, const char *flightcode, const char *time,
               const char *newinfo, data *stream);

#endif // !type_h
