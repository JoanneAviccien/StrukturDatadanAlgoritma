#ifndef data_h
#define data_h

typedef struct telepon{
  int noantri;
  char *notelp;
} data;

// Display
void printdata(data print);
// Setter
void setdata(int noantri, char *notelp, int durasi, data * out);

#endif // !kamus_h
