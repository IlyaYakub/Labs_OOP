#include "Classes.h"

#include <fstream>
#include <sstream>


Book::Book(const std::string& author, const std::string& title, int year, int shelfNumber)
    : author(author), title(title), year(year), shelfNumber(shelfNumber) 
{
}


void Bibliophile::addBook(const Book& book)
{
    collection.push_back(book);
}

std::vector<Book> Bibliophile::getBooksByAuthor(const std::string& author) const
{
    std::vector<Book> books;
    for (const auto& book : collection)
    {
        if (book.getAuthor() == author)
            books.push_back(book);
    }
    return books;
}

int Bibliophile::countBooksByYear(int year) const
{
    int count = 0;
    for (const auto& book : collection)
    {
        if (book.getYear() == year)
            count++;
    }
    return count;
}

void Bibliophile::updateShelfNumber(const std::string& title, int newShelfNumber)
{
    for (auto& book : collection)
    {
        if (book.getTitle() == title)
            book.setShelfNumber(newShelfNumber);
    }
}


void loadBooksFromFile(const std::string& filename, Bibliophile& bibliophile)
{
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string author, title;
        int year, shelfNumber;

        std::getline(ss, author, ',');
        std::getline(ss, title, ',');

        ss >> year;
        ss.ignore(1); // Игнорим запятую
        ss >> shelfNumber;

        bibliophile.addBook(Book(author, title, year, shelfNumber));
    }
    file.close();
}

void saveBooksToFile(const std::string& filename, const Bibliophile& bibliophile)
{
    std::ofstream file(filename);

    for (const auto& book : bibliophile.collection)
    {
        file << book.getAuthor() << ','
             << book.getTitle()  << ','
             << book.getYear()   << ','
             << book.getShelfNumber() << "\n";
    }
    file.close();
}


// Реализация класса PricedBook
Library::PricedBook::PricedBook(const std::string& author, const std::string& title, int year, int shelfNumber, float price)
    : author(author), title(title), year(year), shelfNumber(shelfNumber), price(price) 
{}


void Library::addPricedBook(const Library::PricedBook& book)
{
    collection.push_back(book);
}


void Library::countBooksAndTotalPriceByYear(int year, int& count, float& totalPrice) const
{
    count = 0;
    totalPrice = 0.0f;
    for (const auto& book : collection)
    {
        if (book.getYear() == year)
        {
            count++;
            totalPrice += book.getPrice();
        }
    }
}


void loadPricedBooksFromFile(const std::string& filename, Library& library)
{
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string author, title;
        int year, shelfNumber;
        float price;

        std::getline(ss, author, ',');
        std::getline(ss, title, ',');

        ss >> year;
        ss.ignore(1); // Игнорим запятую
        ss >> shelfNumber;
        ss.ignore(1); // Игнорим запятую
        ss >> price;

        library.addPricedBook(Library::PricedBook(author, title, year, shelfNumber, price));
    }
    file.close();
}

void savePricedBooksToFile(const std::string& filename, const Library& library)
{
    std::ofstream file(filename);

    for (const auto& book : library.collection)
    {
        file << book.getAuthor()     << ','
            << book.getTitle()       << ','
            << book.getYear()        << ','
            << book.getShelfNumber() << ','
            << book.getPrice() << "\n";
    }
    file.close();
}
