#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Zavdannya 1 (variant 6)
void task1(void)
{
    double v1, v2, k;
    printf("Shvydkist u km/god: ");
    scanf("%lf", &v1);
    printf("Shvydkist u m/s: ");
    scanf("%lf", &v2);

    k = v2*3.6;
    if (v1 > k) {
        printf("Bilsha persha shvydkist (%.2f km/god)\n", v1);
    } else if (k > v1) {
        printf("Bilsha druga shvydkist (%.2f km/god)\n", k);
    } else {
        printf("Shvydkosti odnakovi\n");
    }
}

// Zavdannya 2 (variant 13)
void task2(void)
{
    int n, a, k, sum;
    printf("Vvedit dvoznachne chyslo n: ");
    scanf("%d", &n);
    printf("Vvedit a: ");
    scanf("%d", &a);

    k = abs(n);
    sum = k/10 + k%10;
    printf("Suma tsyfr = %d\n", sum);

    if (sum >= 10 && sum <= 99) {
        printf("a) Tak, suma ye dvoznachnym chyslom\n");
    } else {
        printf("a) Ni, suma ne ye dvoznachnym chyslom\n");
    }

    if (sum > a) {
        printf("b) Tak, suma bilsha za a\n");
    } else {
        printf("b) Ni, suma ne bilsha za a\n");
    }
}

// Zavdannya 3 (variant 32)
void task3(void)
{
    double a, b, c;
    int count = 0;
    printf("Vvedit a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == (int)a) count++;
    if (b == (int)b) count++;
    if (c == (int)c) count++;

    printf("Kilkist tsilykh chysel: %d\n", count);
}

// Zavdannya 4 (variant 69)
void task4(void)
{
    int n, m, p;
    printf("Kilkist poverkhiv N: ");
    scanf("%d", &n);
    printf("Nomer kvartyry M: ");
    scanf("%d", &m);

    if (n <= 0 || m < 1 || m > n*3) {
        printf("Takoyi kvartyry v budynku nemaye\n");
        return;
    }

    p = (m - 1)/3 + 1;
    if (p % 2 != 0) {
        printf("Lift dostavyt na %d poverkh\n", p);
    } else if (p + 1 <= n) {
        printf("Kvartyra na %d poversi, lift dostavyt na %d (abo %d) poverkh\n", p, p + 1, p - 1);
    } else {
        printf("Kvartyra na %d poversi, lift dostavyt na %d poverkh\n", p, p - 1);
    }
}

// Zavdannya 5 (variant 17)
void task5(void)
{
    int n, c1, c2, c3;
    printf("Vvedit tryznachne chyslo: ");
    scanf("%d", &n);

    n = abs(n);
    c1 = n/100;
    c2 = (n/10)%10;
    c3 = n%10;

    if (c1 > c3) printf("a) Persha bilsha za ostannyu\n");
    else if (c3 > c1) printf("a) Ostannya bilsha za pershu\n");
    else printf("a) Persha i ostannya rivni\n");

    if (c1 > c2) printf("b) Persha bilsha za drugu\n");
    else if (c2 > c1) printf("b) Druga bilsha za pershu\n");
    else printf("b) Persha i druga rivni\n");

    if (c2 > c3) printf("v) Druga bilsha za ostannyu\n");
    else if (c3 > c2) printf("v) Ostannya bilsha za drugu\n");
    else printf("v) Druga i ostannya rivni\n");
}

void kvadrant(double x, double y)
{
    if (x > 0 && y > 0) printf("I kvadrant\n");
    else if (x < 0 && y > 0) printf("II kvadrant\n");
    else if (x < 0 && y < 0) printf("III kvadrant\n");
    else if (x > 0 && y < 0) printf("IV kvadrant\n");
    else printf("na osi koordynat\n");
}

// Zavdannya 6 (variant 108)
void task6(void)
{
    double k, b, r, a1, b1, c1, d;
    double x1, y1, x2, y2;
    printf("Vvedit k, b, R: ");
    scanf("%lf %lf %lf", &k, &b, &r);

    a1 = 1 + k*k;
    b1 = 2*k*b;
    c1 = b*b - r*r;
    d = b1*b1 - 4*a1*c1;

    if (d < -0.0001) {
        printf("Tochok peretynu nemaye\n");
    } else if (fabs(d) < 0.0001) {
        x1 = -b1/(2*a1);
        y1 = k*x1 + b;
        printf("Pryama dotykaetsya kola v tochtsi (%.2f; %.2f) -> ", x1, y1);
        kvadrant(x1, y1);
    } else {
        x1 = (-b1 + sqrt(d))/(2*a1);
        y1 = k*x1 + b;
        x2 = (-b1 - sqrt(d))/(2*a1);
        y2 = k*x2 + b;

        printf("Tochka 1: (%.2f; %.2f) -> ", x1, y1);
        kvadrant(x1, y1);
        printf("Tochka 2: (%.2f; %.2f) -> ", x2, y2);
        kvadrant(x2, y2);
    }
}

// Zavdannya 7 (variant 9)
void task7(void)
{
    double v1, m1, v2, m2, p1, p2;
    printf("V1, M1: ");
    scanf("%lf %lf", &v1, &m1);
    printf("V2, M2: ");
    scanf("%lf %lf", &v2, &m2);

    if (v1 <= 0 || v2 <= 0) {
        printf("Pomylka: obyem maye buty > 0\n");
        return;
    }

    p1 = m1/v1;
    p2 = m2/v2;
    if (p1 > p2) {
        printf("Pershe tilo maye bilshu shchilnist (%.2f > %.2f)\n", p1, p2);
    } else if (p2 > p1) {
        printf("Druge tilo maye bilshu shchilnist (%.2f > %.2f)\n", p2, p1);
    } else {
        printf("Shchilnosti odnakovi (%.2f)\n", p1);
    }
}

// Zavdannya 8 (variant 65)
void task8(void)
{
    double x, a, b, c, t;
    printf("x = ");
    scanf("%lf", &x);

    a = sin(x);
    b = cos(x);

    if (fabs(b) < 0.0001) {
        printf("tan(x) ne maye sensu pry cos(x) = 0\n");
        if (a < b) printf("U poryadku zrostannya: %.3f %.3f\n", a, b);
        else printf("U poryadku zrostannya: %.3f %.3f\n", b, a);
    } else {
        c = tan(x);
        if (a > b) { t = a; a = b; b = t; }
        if (b > c) { t = b; b = c; c = t; }
        if (a > b) { t = a; a = b; b = t; }
        printf("U poryadku zrostannya: %.3f %.3f %.3f\n", a, b, c);
    }
}

// Zavdannya 9 (variant 56)
void task9(void)
{
    double a, b, c, d, m;
    printf("Vvedit a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Vvedit d: ");
    scanf("%lf", &d);

    if (a == d || b == d || c == d) {
        if (a == d) printf("a = d\n");
        if (b == d) printf("b = d\n");
        if (c == d) printf("c = d\n");
    } else {
        m = d - a;
        if (d - b > m) m = d - b;
        if (d - c > m) m = d - c;
        printf("max = %.3f\n", m);
    }
}

// Zavdannya 10 (variant 101)
void task10(void)
{
    double x, y, x1, y1, x2, y2, x3, y3;
    double p1, p2, p3;
    printf("Tochka A (x y): ");
    scanf("%lf %lf", &x, &y);
    printf("Vershyna 1 (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Vershyna 2 (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Vershyna 3 (x3 y3): ");
    scanf("%lf %lf", &x3, &y3);

    p1 = (x1 - x)*(y2 - y1) - (x2 - x1)*(y1 - y);
    p2 = (x2 - x)*(y3 - y2) - (x3 - x2)*(y2 - y);
    p3 = (x3 - x)*(y1 - y3) - (x1 - x3)*(y3 - y);

    if ((p1 >= 0 && p2 >= 0 && p3 >= 0) || (p1 <= 0 && p2 <= 0 && p3 <= 0)) {
        printf("Tochka nalezhyt trykutnyku\n");
    } else {
        printf("Tochka ne nalezhyt trykutnyku\n");
    }
}

int main()
{
    int choice = -1;

    while (choice != 0) {
        printf("\n1 - Zavdannya 1\n");
        printf("2 - Zavdannya 2\n");
        printf("3 - Zavdannya 3\n");
        printf("4 - Zavdannya 4\n");
        printf("5 - Zavdannya 5\n");
        printf("6 - Zavdannya 6\n");
        printf("7 - Zavdannya 7\n");
        printf("8 - Zavdannya 8\n");
        printf("9 - Zavdannya 9\n");
        printf("10 - Zavdannya 10\n");
        printf("0 - Vykhid\n");
        printf("Vybir: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 9: task9(); break;
            case 10: task10(); break;
            case 0: printf("Vykhid\n"); break;
            default: printf("Nevirnyy nomer\n");
        }
    }

    return 0;
}
