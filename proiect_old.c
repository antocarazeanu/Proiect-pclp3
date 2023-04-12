#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// cu aceasta functe se transforma numarul in binar
void tr_binar(unsigned int num, int n, int biti[], int *marime_biti)
{
    int i, j = 0;
    for (i = powf(2, n * 6 + 4); i > 0; i = i / 2)
    {
        if (num & i)
        {
            biti[j] = 1;
            j++;
        }
        else
        {
            biti[j] = 0;
            j++;
        }
    }
    *marime_biti = j;
}

// cu aceasta functie se transforma in baza 10
int tr_b10(int vector[], int n)
{
    int i, b10 = 0, j = n;
    for (i = n; i > 0; i--)
    {
        b10 = b10 + vector[i] * powf(2, n - j);
        j--;
    }
    return b10;
}

// functie pentru adunare
int adunare(int nr1[], int nr2[])
{
    unsigned int a = tr_b10(nr1, 4), b = tr_b10(nr2, 4), c;
    while (b)
    {
        c = a & b;
        a = a ^ b;
        b = c << 1;
    }
    // se returneaza valoarea modificata a lui nr1(a), in baza 10
    return a;
}

// functie pentru xor
int sor(int nr1[], int nr2[])
{
    unsigned int a = tr_b10(nr1, 4), b = tr_b10(nr2, 4);
    int i, j = 0;
    for (i = powf(2, 4); i > 0; i = i / 2)
    {
        if ((a & i) && (b & i))
        {
            nr1[j] = 0;
            j++;
        }
        else if (!(a & i) && !(b & i))
        {
            nr1[j] = 0;
            j++;
        }
        else
        {
            nr1[j] = 1;
            j++;
        }
    }
    // se returneaza noua valoare a nr1 in baza 10
    a = tr_b10(nr1, 4);
    return a;
}

// functie pentru interschimbare
int interchimbare(int nr1[], int nr2[])
{
    int part1[3], part2[3], aux;
    unsigned p1, p2;
    part1[1] = nr2[1];
    part1[2] = nr2[2];
    part2[1] = nr2[3];
    part2[2] = nr2[4];
    p1 = tr_b10(part1, 2) + 1;
    p2 = tr_b10(part2, 2) + 1;
    aux = nr1[p2];
    nr1[p2] = nr1[p1];
    nr1[p1] = aux;
    // se returneaza noua valoare a nr1 in baza 10
    return tr_b10(nr1, 4);
}
// functie pentru rotirea la stanga
int rotire_st(int nr1[], int nr2[])
{
    unsigned int a, b = tr_b10(nr2, 4);
    int i, j, aux;
    // se rotesc la stanga elementele vectorului de b ori
    for (i = 0; i < b; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            aux = nr1[j];
            nr1[j] = nr1[j + 1];
            nr1[j + 1] = aux;
        }
    }
    // se returneaza noua valoare a nr1 in baza 10
    a = tr_b10(nr1, 4);
    return a;
}

int main()
{
    // vector de functii care pointeaza la fiecare functie a calculatorului
    int (*functii[5])(int *, int *) = {adunare, sor, interchimbare, rotire_st};
    int n, biti[30], marime_biti, i, nr1[5], op[3], nr2[5], j, rez[5], 
    operatii = 0, k;
    unsigned int m, rezultat;
    scanf("%d", &n);
    scanf("%d", &m);
    // se creaza vectorul de biti iar nr1 ia valorile primilor 4 biti din
    // acest vector
    tr_binar(m, n, biti, &marime_biti);
    for (i = 1; i <= 4; i++)
        nr1[i] = biti[i];
    // daca nu trebuie efecetuata nicio operatie se afiseaza direct nr1
    // in baza 10
    if (n == 0)
    {
        rezultat = tr_b10(nr1, 4);
        printf("%d", rezultat);
    }
    // daca nr de operatii este > 0 atunci se parcurge vecctorul de biti pana
    // cand nr de operatii este satisfacut sau pana la finalul acestuia
    else
    {
        i = 5;
        while (i <= marime_biti && operatii < n)
        {
            // se actualizeaza operatia si nr2
            op[1] = biti[i];
            op[2] = biti[i + 1];
            i = i + 2;
            for (j = 1; j <= 4; j++)
                nr2[j] = biti[i + j - 1];
            i = i + 4;
            operatii++;
            // daca operatia este de tip 00 se apeleaza functia adunare apoi
            // nr1 devine rezultatul binar dupa apelarea functiei
            if (tr_b10(op, 2) == 0)
            {
                rezultat = functii[0](nr1, nr2);
                tr_binar(rezultat, 0, rez, &j);
                for (k = 1; k <= 4; k++)
                    nr1[k] = rez[k];
            }
            // daca operatia este de tip 01 se apeleaza functia interschimbare
            // apoi nr1 devine rezultatul binar dupa apelarea functiei
            else if (tr_b10(op, 2) == 1)
            {
                rezultat = functii[2](nr1, nr2);
                tr_binar(rezultat, 0, rez, &j);
                for (k = 1; k <= 4; k++)
                    nr1[k] = rez[k];
            }
            // daca operatia este de tip 10 se apeleaza functia de rotire la
            // stanga apoi nr1 devine rezultatul binar dupa apelarea functiei
            else if (tr_b10(op, 2) == 2)
            {
                rezultat = functii[3](nr1, nr2);
                tr_binar(rezultat, 0, rez, &j);
                for (k = 1; k <= 4; k++)
                    nr1[k] = rez[k];
            }
            // daca operatia este de tip 11 se apeleaza functia xor apoi
            // nr1 devine rezultatul binar dupa apelarea functiei
            else if (tr_b10(op, 2) == 3)
            {
                rezultat = functii[1](nr1, nr2);
                tr_binar(rezultat, 0, rez, &j);
                for (k = 1; k <= 4; k++)
                    nr1[k] = rez[k];
            }
        }
        // rezultatul este transformat in baza 10 si apoi afisat
        rezultat = tr_b10(nr1, 4);
        printf("%d", rezultat);
    }
    return 0;
}