#include <assert.h>

#include <gmpxx.h>
#include <iostream>

const int kMaxLen = 2 * 25000000 + 10;  // 100million bit hex encoded numbers
char *buf = NULL;

void readbuf(const char *name) {
  FILE *src = fopen(name, "r");  assert(src);
  fseek(src, 0, SEEK_END);
  size_t s = ftell(src);  assert(s <= kMaxLen);  rewind(src);
  if (!buf)  buf = reinterpret_cast<char *>(malloc(kMaxLen));
  assert(1 == fread(buf, s, 1, src));
  fclose(src);
}

int main(void) {
  mpz_class p[10], s[10], x[10], y[10];

  readbuf("top10.gp");
  strtok(buf, "\n");
  for (int i = 0; i < 10; ++i) {
    mpz_class a;
    int f, g, h;
    sscanf(strtok(NULL, "\n"), "[%d,%d,%d]", &f, &g, &h);

    mpz_ui_pow_ui(a.get_mpz_t(), g, h);
    p[i] = (f < 0) ? a*a - a + 1 : p[i] = f*a + 1;
  }

  readbuf("sqrtm1.gp");
  strtok(buf, "\n");
  for (int i = 0; i < 10; ++i) {
    char *t, *u;
    t = strtok(NULL, "\n");
    u = strchr(t, ',');  if (u) { *u = '\0'; }

    mpz_set_str(s[i].get_mpz_t(), t, 0);

    std::cerr << (s[i]*s[i] % p[i] == p[i]-1);
  }
  std::cerr << "\n";


  readbuf("sos.gp");
  strtok(buf, "\n");
  for (int i = 0; i < 10; ++i) {
    char *t, *u, *v;
    t = strchr(strtok(NULL, "\n"), '[')+1;
    u = strchr(t, ',');  *u++ = '\0';
    v = strchr(u, ']');  *v = '\0';

    mpz_set_str(x[i].get_mpz_t(), t, 0);
    mpz_set_str(y[i].get_mpz_t(), u, 0);

    std::cerr << (x[i]*x[i] + y[i]*y[i] == p[i]);
  }
  std::cerr << "\n";

  if (buf)  { free(buf); buf = NULL; }

  return 0;
}
