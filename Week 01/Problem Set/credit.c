#include <cs50.h>
#include <stdio.h>

int main (void) {
    long cn = get_long("Number: "); long tn = cn;
    int d = 0, t = 0, l, k;

    while (tn) {
        int x = tn % 10;
        tn /= 10; d++;

        if (!(d % 2)) x *= 2;
        while (x) { t += (x % 10); x /= 10; }
    }

    if (!(t % 10)) {
        for (int i = 0; i < d; i++) {
            int x = cn % 10; cn /= 10;
            if (i == (d - 2)) k = x;
            if (i == (d - 1)) l = x;
        }

        if (l == 3 && (k == 4 || k == 7) && d == 15) printf("%s\n", "AMEX");
        else if (l == 4 && (d == 16 || d == 13)) printf("%s\n", "VISA");
        else if (l == 5 && (k == 1 || k == 2 || k == 3 || k == 4 || k == 5) && d == 16) printf("%s\n", "MASTERCARD");
        else printf("%s\n", "INVALID");
    }
    else printf("%s\n", "INVALID");
}