/******************************
Pāvels Petrovs, pp23055
C38. Doti naturāls skaitlis n un veseli skaitļi a(1), a(2), ... a(n) (n<100) . Noteikt, vai starp šiem skaitļiem ir tādi, kas vienādi ar citu divu summu. Izdrukāt šos skaitļus formā a(k) = a(i) + a(j).
Programma izveidota: 18.11.2023
******************************/

#include <iostream>
using namespace std;

bool hasEqualSum(int n, int a[]) { //Šī rinda deklarē funkciju ar nosaukumu hasEqualSum, kas pieņem divus parametrus - veselu skaitli n un veselu skaitļu masīvu a. Funkcija atgriež vērtību 'true' vai 'false'.
    bool found = false; //Šajā rindā tiek deklarēts logaritma mainīgais 'found' un inicializēts ar 'false'. Šis mainīgais tiek izmantots, lai sekotu līdzi tam, vai ir atrasts noteiktajam nosacījumam atbilstošs elementu kopums.
    for (int i = 0; i < n; ++i) { //Šis cikls iterē visus masīva 'a' elementus, izmantojot ciklas mainīgo 'i'.
        for (int j = i + 1; j < n; ++j) { //Šis cikls iterē masīva 'a' elementus, sākot no nākamā indeksa pēc 'i'.
            for (int k = 0; k < n; ++k) { //Šis cikls iterē visus masīva 'a' elementus.
                if (k != i && k != j && a[k] == a[i] + a[j]) { //Šis nosacījums pārbauda, vai indeksi 'i', 'j' un 'k' ir atšķirīgi. Tiek arī pārbaudīts, vai elements ar indeksu 'k' masīvā 'a' ir vienāds ar elementu ar indeksiem 'i' un 'j' summu.
                    cout << "Skaitlis, kas ir vienāds ar citu divu summu:" << endl;
                    cout << "a(" << k + 1 << ") = a(" << i + 1 << ") + a(" << j + 1 << ")" << endl;
                    found = true; //Iestata mainīgajam 'found' vērtību 'true', lai norādītu, ka ir atrasts noteiktajam nosacījumam atbilstošs elementu kopums.
                }
            }
        }
    }
    return found; //Visbeidzot, funkcija atgriež atrastā mainīgā vērtību, kas būs 'true', ja ir atrasts vismaz viens nosacījumam atbilstošs elementu kopums, un 'false' pretējā gadījumā.
}

int main() {
    const int max_n = 100; //Šajā rindā ir deklarēta konstante vesels skaitlis 'max_n' ar vērtību 100.
    int n, ok;
    do {
        
        do {
            cout << "Ievadiet n: ";
            cin >> n;
            if (n >= max_n) { //Pārbaude, vai 'n' nav lielāks par 100
                cout << "N ir lielāks nekā 100" << endl;
            } else if (n <= 0) { //Pārbaude, vai 'n' ir naturāls skaitlis.
                cout << "N nav naturals skaitlis" << endl;
            }
        } while (n >= max_n || n <= 0); // Pārbauda, ​​vai nosacījums 'n >= max_n' un 'n <= 0' ir patiess.
                                        // Ja tas ir patiess, cikls atkārtosies, aicinot lietotāju vēlreiz ievadīt skaitli, līdz tiek ievadīts skaitlis, kas ir mazāks nekā 100 vai naturāls skaitlis.
        
        int a[max_n]; //Tiek deklarēts veselu skaitļu masīvs ar nosaukumu 'a'. Masīva lielumu nosaka konstante 'max_n'.
        cout << "Ievadiet veselos skaitļus a(1), a(2), ..., a(n):" << endl;
        for (int i = 0; i < n; ++i) { //Katrā cikla iterācijā lietotājs tiek aicināts ievadīt vērtību masīva elementam ar pašreizējo indeksu 'i'.
            cout << "a(" << i + 1 << "): ";
            cin >> a[i];
        }

        if (!hasEqualSum(n, a)) { //Izsauc funkciju 'hasEqualSum' ar masīvu 'a' un pārbauda, vai masīvā ir elementi, kas atbilst nosacījumam. Ja nē, tiek izdrukāts ziņojums.
            cout << "Nav atrasts skaitlis, kas ir vienāds ar citu divu summu." << endl;
        }

        cout << endl;
        cout << "Vai turpināt (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);


    return 0;
}
