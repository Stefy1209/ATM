# ATM
Proiect 1 Programare in C

Cum intrucat aceasta aplicatia nu are interfata grafica, ea va fi rulata in lini de comanda.

Pentru a deschide aplicatia trebuie scrisa comanda "./main".

Odata deschisa va aparea pe prima linie ">>>" semnaland faptul ca asteapta o comanda.

De fiecare data cand este pornita aplicatia lista de tranzactii va fi mereu goala in prima instanta.

Lista de comenzi posibile:

    add - adauga o tranzactie in lista de tranzactii
    print - afiseaza toate tranzactiile adaugate de la rularea programului
    balance - afiseaza suma de bani in functie de tranzactiile din lista de tranzactii
    load - incarca toate tranzactiile salvate in lista actuala de tranzactii
    save - salveaza intr-un fisier toate tranzactiile adaugate in lista de tranzactii pana la apelarea functiei
    between - afiseaza toate tranzactiile dintre 2 date calanderistice in ordinea regasita in lista de tranzactii
    exit - inchidere aplicatie

IMPORTANT!:

    Comenzile pot fi scrise atat cu litere mici cat si cu litere mari, in schimb imediat dupa ele daca apare un caracter,chiar si SPACE, atunci aplicatia va semnala "Invalid command!".

Toate tranzactiile vor aparea si vor fi citite sub forma:

Date: dd/mm/yyyy
Description: text
Amount: un numar pozitiv
Type: income/expense

IMPORTANT!:

    In completarea datei, ziua si luna trebuie scrise mereu cu 2 cifre.
    De exemplu: pentru 9/12/2004 va trebui completat cu 09/12/2004
                pentru 1/1/2003  va trebui completat cu 01/01/2003

    Descriptia este limitat la 300 de caractere.

    In completarea tipului de tranzactie se va completa cu "income" sau "expense".
    Nu conteaza daca este scris cu litere mici sau litere mari.

    In momentul in care una de cele 4 casute(Date, Description, Amount, Type) este completata gresit, aplicatia va semnala acest fapt asteptand sa fie reintrodus corect informatia din casuta respectiva, fara a fi nevoie sa fie reintroduse celelalte din nou.

In fisierul in care se salveaza tranzactiile, pe prima linie va aparea numarul de tranzactii iar pe urmatoarele linii vor aparea tranzactiile separate de o linie goala.

IMPORTANT!:

    In momentul in care se apeleaza comanda "save", daca inainte nu a fost apelat "load" atunci aceasta se va apela automat.

    In schimb, daca inainte de "exit" nu au fost salvate anumite tranzactii, atunci acele tranzactii nu vor fi salvate. 
