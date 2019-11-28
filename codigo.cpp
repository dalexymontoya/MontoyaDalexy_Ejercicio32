#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
/*parametros */
#define Nx 101
#define NT 300
#define rho 0.01
#define ten 40
  int m = 1;
  double c = sqrt(ten / rho);
  double cl = c;
  double radio = c * c / (cl * cl);
  double w[Nx][3];
  double Wtot[Nx][NT];

  for (int i = 0; i < Nx; i++) {
    for (int j = 0; j < 3; j++) {
      w[i][j] = sin(2.0 * M_PI * i * 0.005);
    for (int k = 0; k < NT; k++) {
      Wtot[i][k] = 0.0;
    }
    Wtot[i][0] = w[i][0];
  }
  }

  for (int t = 1; t < NT; t++) {
    if (t == 1) {
      for (int ix = 1; ix < Nx - 1; ix++) {
        w[ix][1] = w[ix][0] + 0.5 * radio * (w[ix + 1][0] + w[ix - 1][0] - 2.0 * w[ix][0]);
      }
    } else {
      for (int ix = 1; ix < Nx - 1; ix++) {
        w[ix][2] = 2.0 * w[ix][1] - w[ix][0] + radio * (w[ix + 1][1] + w[ix - 1][1] - 2. * w[ix][1]);
      }
    }
    if ((t % 1 == 0) || (t == 1)) {
      for (int i = 1; i < Nx; i++) {
        Wtot[i][m] = w[i][2];
      }
      cout << m << endl;
      m += 1;
    }
    for (int ix = 1; ix < Nx - 1; ix++) {
      w[ix][0] = w[ix][1];
      w[ix][1] = w[ix][2];
    }
  }

  ofstream datos("datos.dat");

  for (int x = 0; x < Nx; x++) {
    for (int t = 0; t < m; t++) {
      datos << Wtot[x][t] << endl;
    }
  }

  return 0;

}
