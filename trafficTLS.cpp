#include <iostream>
using namespace std;
int main()
{

    int sec;
    string Lampu;

    cout << "Masukkan detik ";
    cin >> sec;
    if (sec < 44)
    {
        return 0;
    }
    int Merah = 80;
    int Kuning = 3;
    int Hijau = 20;
    int Total = Merah + Kuning + Hijau;

    int sisa = (sec - 45) % Total;

    if (sisa < Kuning)
    {
        Lampu = "Kuning";
    }
    else if (sisa < Kuning + Merah)
    {
        Lampu = "Merah";
    }
    else
    {
        Lampu = "Hijau";
    }

    cout << "Lampu yang menyala adalah " << Lampu << endl;
    return 0;
}