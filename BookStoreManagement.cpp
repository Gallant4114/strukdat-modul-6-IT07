#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ItemBase
{
public:
    virtual int getId() const = 0;
    virtual string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual ~ItemBase() = default;
};

class Item : public ItemBase
{
private:
    int id;
    string name;
    double price;
    static int nextId;

public:
    Item(string name, double price)
        : id(nextId++), name(name), price(price) {}

    int getId() const override {
        return id;
    }

    string getName() const override {
        return name;
    }

    double getPrice() const override {
        return price;
    }
};

int Item::nextId = 1;

class PaperItem : public Item
{
public:
    PaperItem(string name, double price)
        : Item(name, price) {}
};

class NonPaperItem : public Item
{
public:
    NonPaperItem(string name, double price)
        : Item(name, price) {}
};

class ReceiptItem
{
private:
    const Item* item;
    int jumlah;

public:
    ReceiptItem(const Item* item, int jumlah)
        : item(item), jumlah(jumlah) {}

    const Item* getItem() const {
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
    void addItem(const Item* item, int jumlah)
    {
        for (auto& receiptItem : items) {
            if (receiptItem.getItem()->getId() == item->getId()) {
                receiptItem.setJumlah(receiptItem.getJumlah() + jumlah);
                return;
            }
        }
        items.emplace_back(item, jumlah);
    }

    void displayReceipt() const
    {
        cout << "Receipt:" << endl;
        double totalCost = 0.0;
        for (const auto& receiptItem : items) {
            double itemTotal = receiptItem.getItem()->getPrice() * receiptItem.getJumlah();
            totalCost += itemTotal;
            cout << "--------------------\nItem: " << receiptItem.getItem()->getName()
                 << "\nJumlah: " << receiptItem.getJumlah()
                 << "\nHarga Barang: " << receiptItem.getItem()->getPrice()
                 << "\nTotal Harga: " << itemTotal << endl;
        }
        cout << "--------------------\nTotal Harga Semua Item: " << totalCost << endl;
    }

    void updateItemJumlah(int itemId, int jumlah)
    {
        for (auto& receiptItem : items) {
            if (receiptItem.getItem()->getId() == itemId) {
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
                                  return receiptItem.getItem()->getId() == itemId;
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

    PaperItem Buku("Buku", 5000);
    PaperItem Folio("Folio", 40000);
    NonPaperItem Pensil("Pensil", 2500);
    NonPaperItem Penghapus("Penghapus", 4000);
    NonPaperItem Bolpoin("Bolpoin", 3000);
    NonPaperItem Penggaris("Penggaris", 10000);
    NonPaperItem Lem("Lem", 8000);
    NonPaperItem KlipKertas("Klip Kertas", 12000);
    NonPaperItem Spidol("Spidol", 5000);
    NonPaperItem Jangka("Jangka", 20000);

    vector<Item*> storeItems = {&Buku, &Pensil, &Penghapus, &Bolpoin, &Penggaris, &Lem, &KlipKertas, &Folio, &Spidol, &Jangka};

    int choice;
    do {
        displayMenu();
        cout << "Masukkan Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Item yang tersedia:" << endl;
                for (const auto& item : storeItems) {
                    cout << "ID: " << item->getId() << ", Nama: " << item->getName() << ", Harga: " << item->getPrice() << endl;
                }

                int itemId, jumlah;
                cout << "Masukkan ID Item untuk add: ";
                cin >> itemId;
                cout << "Masukkan jumlah: ";
                cin >> jumlah;

                auto it = find_if(storeItems.begin(), storeItems.end(), [itemId](const Item* item) {
                    return item->getId() == itemId;
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
                cout << "Masukkan ID Item untuk update: ";
                cin >> itemId;
                cout << "Masukkan jumlah yang baru: ";
                cin >> jumlah;
                receipt.updateItemJumlah(itemId, jumlah);
                break;
            }
            case 4: {
                int itemId;
                cout << "Masukkan ID Item untuk dihapus: ";
                cin >> itemId;
                receipt.removeItem(itemId);
                break;
            }
            case 5: {
                cout << "Berhasil Keluar" << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi!" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
