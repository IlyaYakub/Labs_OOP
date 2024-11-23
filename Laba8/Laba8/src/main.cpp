#include "Classes.h"
#include <iostream>
#include <string>


void printBooksByAuthor(const std::vector<Book>& books) 
{
    for (const auto& book : books) 
    {
        std::cout << book.getTitle() << ", " << book.getYear() << ", стеллаж: " << book.getShelfNumber() << "\n";
    }
}


int main() {

    setlocale(0, "");

    Bibliophile bibliophile;
    Library library;

    // Загрузка книг из файла
    loadBooksFromFile("BooksTXT/Collection.txt", bibliophile);

    // Загрузка книг с ценами из файла
    loadPricedBooksFromFile("BooksTXT/PricedBooks.txt", library);

    // Работа с Bibliophile
    std::string author = "George Orwell";
    std::vector<Book> booksByAuthor = bibliophile.getBooksByAuthor(author);
    std::cout << "Книги автора " << author << ":\n";
    printBooksByAuthor(booksByAuthor);

    int year = 2020;
    int count = bibliophile.countBooksByYear(year);
    std::cout << "Число книг издания " << year << ": " << count << "\n";

    std::string title;
    int newShelfNumber;
    std::cout << "\nВведите название книги для обновления номера стеллажа: ";
    std::getline(std::cin, title);
    std::cout << "Введите новый номер стеллажа: ";
    std::cin >> newShelfNumber;
    bibliophile.updateShelfNumber(title, newShelfNumber);

    saveBooksToFile("BooksTXT/Collection.txt", bibliophile);

    // Работа с Library
    std::cout << "\nВведите год издания для поиска в Library: ";
    std::cin >> year;

    int totalCount;
    float totalPrice;
    library.countBooksAndTotalPriceByYear(year, totalCount, totalPrice);

    std::cout << "Число книг издания " << year << ": " << totalCount << "\n";
    std::cout << "Общая стоимость книг издания " << year << ": " << totalPrice << "\n";

    savePricedBooksToFile("BooksTXT/PricedBooks.txt", library);

    return 0;
}
