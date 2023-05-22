# Proiect-pclp3
## Calculator pe biți

-Am realizat o funcție de creare a unui vector de biți în funcție de un
număr din baza 10 și o funcție de transformare a unui vector de biți într-un
număr în baza 10.

-Am creat cele 4 funcții (adunare, xor, interschimbare, rotație la stânga),
toate 4 având ca antet 2 vectori reprezentând cele 2 numere asupra cărora
trebuie să se efectueze operația.

-În funcțiile pentru adunare și xor am folosit 2 variabile de tip unsigned
int(a și b) pentru a putea modifica vectorul nr1 și pentru a returna valoarea
acestuia în baza 10. Pentru funcția de interschimbare am folosit 2 vectori
pentru a afla cele 2 poziții care trebuie interschimbate. La funcția de rotație
la stânga am folosit un for pentru a putea interschimba element cu element
vectorul nr1.

-În funcția main am implementat un vector de funcții care pointează la fiecare
din cele 4 funcții iar în funcție de operație aceasta a fost apelată și valoarea
vectorului nr1 a fost modificată. La început variabila 'm' a fost salvată ca
binar în vectorul biți, ca apoi cei 3 vectori (nr1, op, nr2) să fie creați după
vectorul de biți.

-Rezultatul fiecărei operații a fost salvat în nr1 și pus în coadă iar op și nr2
au fost modificate cu fiecare avansare în vectorul de biți. La final s-au scos
rezultatele din coadă și s-au afișat subliniind care este rezultatul final tran-
sformând nr1 în baza 10 și afișându-l.