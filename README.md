# Proiect-pclp3
calculator pe biti

    Am realizat o functie de creare a unui vector de biti in functie de un
numar din baza 10 si o functie de transformare a unui vector de biti intr-un
numar in baza 10. Apoi am creeat cele 4 functii(adunare, xor, interschimbare,
rotatie la stanga), toate 4 avand ca antet 2 vectori reprezentand cele 2 numere
asupra carora trebuie sa se efectueze operatia. In functiile pentru adunare si
xor am folosit 2 variabile de tip unsigned int(a si b) pentru a putea modifica
vectorul nr1 si pentru a returna valoarea acestuia in baza 10. Pentru functia
de interschimbare am folosit 2 vectori pentru a afla cele 2 pozitii care
trebuie interschimbate. La functia de rotire la stanga am folosit un for for
pentru a putea interschimba element cu element vectorul nr1. In functia main
am implmentat un vector de functii care pointeaza la fiecare din cele 4 functii
iar in functie de operatie aceasta a fost apelata si valoarea vectorului nr1 a
fost modificata. La inceput variabila 'm' a fost salvata ca binar in vectorul
biti, ca apoi cei 3 vectori (nr1, op, nr2) sa fie creati dupa vectorul de biti.
Rezultatul fiecarei operatii a fost salvat in nr1 si pus in coada iar op si nr2
au fost modificate cu fiecare avansare in vectorul de biti. La final s-au scos 
rezultatele din coada si s-au afisat subliniand care este rezultatul final tran-
sformand nr1 in baza 10 si afisandu-l.