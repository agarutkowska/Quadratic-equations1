#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <cmath>

int main(void) {
	int a = -1;
	int b = -2;
	int c = -3;
	double err = 0.001;
	double delta, pdelta, temp, x1r, x2r, x1u, x2u;

	// wypisywanie równania kwadratowego
	if (a == 0 && b == 0 && c == 0) {
		printf("0=0 \n");
	}
	else if (b < 0 || c < 0) {
		printf("%dxx ", a);

		if (b < 0) {
			printf("+(%d)x ", b);
		}
		else {
			printf("+ %dx ", b);
		}

		if (c < 0) {
			printf("+(%d) = 0 \n\n", c);
		}
		else {
			printf("+ %d = 0 \n\n", c);
		}
	}
	else {
		printf("%dxx + %dx + %d = 0 \n\n", a, b, c);
	}

	if (a == 0) {
		if (b != 0) {
			x1r = (-c / b)*(1.0);
			printf("x1r = %f \n", x1r);
		}
		if (b == 0 && c != 0) {
			printf("Rownanie sprzeczne. \n");
		}
		if (b == 0 && c == 0) {
			printf("Rownanie tozsamosciowe. \n");
		}
	}
	else {
		// obliczanie delty
		delta = (1.0)*((b * b) - (4.0 * a * c));
		printf("delta = %f \n", delta);

		if (delta > 0) {
			pdelta = delta / 4.0;
			temp = 10.0;

		con:
			temp = (pdelta + (delta / pdelta)) / 2;
			pdelta = delta / temp;

			if ((pdelta - temp) < 0) {
				if ((temp - pdelta) >= err) {
					goto con;
				}
				else {
					goto end;
				}
			}
			else {
				if ((pdelta - temp) >= err) {
					goto con;
				}
				else {
					goto end;
				}
			}
		end:

			printf("Pierwiastek z delty to %f \n\n", pdelta);

			x1r = ((-b - pdelta) / (2.0 * a))*(1.0);
			x2r = ((-b + pdelta) / (2.0 * a))*(1.0);

			printf("x1r = %f \nx2r = %f \n\n", x1r, x2r);
		}
		else if (delta < 0) {
			if (a == 0) {
				if (b != 0) {
					x1r = (-c / b)*(1.0);
					printf("x1r = %f \n", x1r);
				}
				if (b == 0 && c != 0) {
					printf("Rownanie sprzeczne. \n");
				}
				if (b == 0 && c == 0) {
					printf("Rownanie tozsamosciowe. \n");
				}
			}
			else {
				delta = -delta;
				pdelta = delta / 4.0;
				temp = 10.0;

			con2:
				temp = (pdelta + (delta / pdelta)) / 2;
				pdelta = delta / temp;

				if ((pdelta - temp) < 0) {
					if ((temp - pdelta) >= err) {
						goto con2;
					}
					else {
						goto end2;
					}
				}
				else {
					if ((pdelta - temp) >= err) {
						goto con2;
					}
					else {
						goto end2;
					}
				}
			end2:
				printf("Pierwiastek z delty to %f \n\n", pdelta);


				if (b == 0) {
					x1r = (b / (2.0 * a))*(-1.0);
				}

				else {
					x1r = ((-b) / (2.0 * a))*(1.0);
				}

				printf("x1r = %f \n", x1r);
				x2r = x1r;
				printf("x2r = %f \n\n", x2r);

				x1u = ((-pdelta) / (2.0 * a))*(1.0);
				printf("x1u = %f \n", x1u);
				x2u = -x1u;
				printf("x2u = %f \n\n", x2u);

				printf("Pierwsze rozwiazanie: %f ", x1r);
				if (x1u < 0) {
					printf("+(%f) * i \n", x1u);
				}
				else {
					printf("+ %f * i \n", x1u);
				}

				printf("Drugie rozwiazanie: %f ", x2r);
				if (x2u < 0) {
					printf("+(%f) * i \n", x2u);
				}
				else {
					printf("+ %f * i \n", x2u);
				}
			}
		}
		else if (delta == 0) {
			if (a == 0 && b == 0) {
				printf("Nie ma rozwiazan.\n");
			}
			else {
				x1r = ((-b) / (2.0 * a))*(1.0);
				printf("x1r = %f \n\n", x1r);
			}
		}
	}
	
	getchar();
	getchar();
	return 0;
}