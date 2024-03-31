#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

vector<string> tokenize(const string& str){
    vector<string> tokens;
    string token;
    for (char c : str)
    {
        if (c == ' ')
        {
            tokens.push_back(token);
            token.clear();
        }
        else{
            token += c;
        }
    }
    tokens.push_back(token);
    return tokens;
}

void pushStack(stack<string>& dataStack, const string& data){
    dataStack.push(data);
}

int main()
{
    vector<string> namaNegara;
    vector<string> ibuKota;
    vector<string> namaPresiden;
    vector<int> tahunKemerdekaan;
    stack<string> namaNegaraStack;
    stack<string> ibuKotaStack;
    stack<string> namaPresidenStack;
    stack<int> tahunKemerdekaanStack;

    while (true)
    {
        cout << "Menu:\n1. Masukan informasi negara\n2. Cari Informasi negara\n3. Keluar\nPilih salah satu diatas : ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1)
        {
            cin.ignore();
            cout << "Masukan informasi negara : \n";
            string negara, ibukota, presiden;
            int kemerdekaan;

            cout << "Nama negara : ";
            getline(cin, negara);
            cout << "Ibu Kota : ";
            getline(cin, ibukota);
            cout << "Nama presiden : ";
            getline(cin, presiden);
            cout << "Tahun Kemerdekaan : ";
            cin >> kemerdekaan;

            namaNegara.push_back(negara);
            ibuKota.push_back(ibukota);
            namaPresiden.push_back(presiden);
            tahunKemerdekaan.push_back(kemerdekaan);

            pushStack(namaNegaraStack, negara);
            pushStack(ibuKotaStack, ibukota);
            namaPresidenStack.push(presiden);
            tahunKemerdekaanStack.push(kemerdekaan);

            cout << " Data negara telah disimpan \n\n";
        }
        else if (pilihan == 2)
        {
            cin.ignore();
            cout << "Masukan kata kunci pencarian : ";
            string kataKunci;
            getline(cin, kataKunci);

            vector<string> kunciPencarian = tokenize(kataKunci);

            cout << "Hasil Pencarian\n";
            bool ditemukan = false;
            for (size_t i = 0; i < namaNegara.size(); ++i)
            {
                bool semuaDitemukan = true;
                for (const string& kunci : kunciPencarian)
                {
                    if (namaNegara[i].find(kunci) == string::npos && ibuKota[i].find(kunci) == string::npos &&
                    namaPresiden[i].find(kunci) == string::npos)
                    {
                        semuaDitemukan = false;
                        break;
                    }
                }
                if (semuaDitemukan)
                {
                    cout << "Nama Negara = " << namaNegara[i] << endl;
                    cout << "Ibu Kota = " << ibuKota[i] << endl;
                    cout << "Nama Presiden = " << namaPresiden[i] << endl;
                    cout << "Tahun Kemerdekaan = " << tahunKemerdekaan[i] << endl;
                    ditemukan = true;
                }
            }
            if (!ditemukan)
            {
                cout << "Negara tidak ditemukan\n\n";
            }
        }
        else if (pilihan == 3)
        {
            cout << "Terimakasih telah menggunakan layanan kami. \n";
            break;
        }
        else
        {
            cout << "Pilihan tidak valid.\n";
        }
    }
    return 0;
}
