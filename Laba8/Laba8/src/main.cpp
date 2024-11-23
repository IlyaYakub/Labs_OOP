#include "Classes.h"
#include <iostream>
#include <string>


void printBooksByAuthor(const std::vector<Book>& books) 
{
    for (const auto& book : books) 
    {
        std::cout << book.getTitle() << ", " << book.getYear() << ", �������: " << book.getShelfNumber() << "\n";
    }
}


int main() {

    setlocale(0, "");

    Bibliophile bibliophile;
    Library library;

    // �������� ���� �� �����
    loadBooksFromFile("BooksTXT/Collection.txt", bibliophile);

    // �������� ���� � ������ �� �����
    loadPricedBooksFromFile("BooksTXT/PricedBooks.txt", library);

    // ������ � Bibliophile
    std::string author = "George Orwell";
    std::vector<Book> booksByAuthor = bibliophile.getBooksByAuthor(author);
    std::cout << "����� ������ " << author << ":\n";
    printBooksByAuthor(booksByAuthor);

    int year = 2020;
    int count = bibliophile.countBooksByYear(year);
    std::cout << "����� ���� ������� " << year << ": " << count << "\n";

    std::string title;
    int newShelfNumber;
    std::cout << "\n������� �������� ����� ��� ���������� ������ ��������: ";
    std::getline(std::cin, title);
    std::cout << "������� ����� ����� ��������: ";
    std::cin >> newShelfNumber;
    bibliophile.updateShelfNumber(title, newShelfNumber);

    saveBooksToFile("BooksTXT/Collection.txt", bibliophile);

    // ������ � Library
    std::cout << "\n������� ��� ������� ��� ������ � Library: ";
    std::cin >> year;

    int totalCount;
    float totalPrice;
    library.countBooksAndTotalPriceByYear(year, totalCount, totalPrice);

    std::cout << "����� ���� ������� " << year << ": " << totalCount << "\n";
    std::cout << "����� ��������� ���� ������� " << year << ": " << totalPrice << "\n";

    savePricedBooksToFile("BooksTXT/PricedBooks.txt", library);

    return 0;
}
