#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Item
{
private:
    int id;
    string name;
    double price;
    static int nextId;

public:
    Item(string name, double price)
        : id(nextId++), name(name), price(price) {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};

int Item::nextId = 1;

class ReceiptItem
{
private:
    Item item;
    int jumlah;

public:
    ReceiptItem(const Item& item, int jumlah)
        : item(item), jumlah(jumlah) {}

    Item getItem() const {
        return item;
    }

    int getJumlah() const {
        return jumlah;
    }

    void setJumlah(int jumlah) {
        this->jumlah = jumlah;
    }
};

class Receipt
{
private:
    vector<ReceiptItem> items;

public:
    void addItem(const Item& item, int jumlah)
    {
        for (auto& receiptItem : items) {
            if (receiptItem.getItem().getId() == item.getId()) {
                receiptItem.setJumlah(receiptItem.getJumlah() + jumlah);
                return;
            }
        }
        items.push_back(ReceiptItem(item, jumlah)); 
    }

    void displayReceipt() const
    {
        cout << "Receipt:" << endl;
        double totalCost = 0.0;
        for (const auto& receiptItem : items) {
            double itemTotal = receiptItem.getItem().getPrice() * receiptItem.getJumlah();
            totalCost += itemTotal;
            cout << "--------------------\nItem: " << receiptItem.getItem().getName()
                 << "\njumlah: " << receiptItem.getJumlah()
                 << "\nHarga Barang: " << receiptItem.getItem().getPrice()
                 << "\nTotal Harga: " << itemTotal << endl;
        }
        cout << "--------------------\nTotal Harga Semua Item: " << totalCost << endl;
    }

    void updateItemJumlah(int itemId, int jumlah)
    {
        for (auto& receiptItem : items) { 
            if (receiptItem.getItem().getId() == itemId) {
                receiptItem.setJumlah(jumlah);
                return;
            }
        }
        cout << "Item belum ditambahkan" << endl;
    }

    void removeItem(int itemId) 
    {
        items.erase(remove_if(items.begin(), items.end(),
                              [itemId](const ReceiptItem& receiptItem) {
                                  return receiptItem.getItem().getId() == itemId;
                              }),
                    items.end());
    }
};

void displayMenu()
{
    cout << "◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘" << endl;
    cout << "  Menu BookStore Management System" << endl;
    cout << "◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘" << endl;
    cout << "1. Tambahkan item ke receipt" << endl;
    cout << "2. Tampilkan receipt saat ini" << endl;
    cout << "3. Ubah jumlah item dari receipt" << endl;
    cout << "4. Hapus item dari receipt" << endl;
    cout << "5. Keluar" << endl;
}

int main()
{
    Receipt receipt;

    Item Buku("Buku", 5000);
    Item Pensil("Pensil", 2500);
    Item Penghapus("Penghapus", 4000);
    Item Bolpoin("Bolpoin", 3000);
    Item Penggaris("Penggaris", 10000);
    Item Lem("Lem", 8000);
    Item KlipKertas("Klip Kertas", 12000);
    Item Folio("Folio", 40000);
    Item Spidol("Spidol", 5000);
    Item Jangka("Jangka", 20000);

    vector<Item> storeItems = {Buku, Pensil, Penghapus, Bolpoin, Penggaris, Lem, KlipKertas, Folio, Spidol, Jangka};

    int pilihan;
    do {
        displayMenu();
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                cout << "Item yang tersedia:" << endl;
                for (const auto& item : storeItems) {
                    cout << "ID: " << item.getId() << ", Nama: " << item.getName() << ", Harga: " << item.getPrice() << endl;
                }

                int itemId, jumlah;
                cout << "Masukkan ID Item untuk ADD: ";
                cin >> itemId;
                cout << "Masukkan jumlah: ";
                cin >> jumlah;

                auto it = find_if(storeItems.begin(), storeItems.end(), [itemId](const Item& item) {
                    return item.getId() == itemId;
                });

                if (it != storeItems.end()) {
                    receipt.addItem(*it, jumlah);
                } else {
                    cout << "ID Item tidak valid!" << endl;
                }
                break;
            }
            case 2: {
                receipt.displayReceipt();
                break;
            }
            case 3: {
                int itemId, jumlah;
                cout << "Masukkan ID Item untuk UPDATE: ";
                cin >> itemId;
                cout << "Masukkan jumlah yang baru: ";
                cin >> jumlah;
                receipt.updateItemJumlah(itemId, jumlah);
                break;
            }
            case 4: {
                int itemId;
                cout << "Masukkan ID Item untuk DELETE: ";
                cin >> itemId;
                receipt.removeItem(itemId);
                break;
            }
            case 5: {
                cout << "Berhasil Keluar dari Program" << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi!" << endl;
                break;
        }
    } while (pilihan != 5);

    return 0;
}
