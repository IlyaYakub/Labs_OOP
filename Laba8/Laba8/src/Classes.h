#pragma once

#include <string>
#include <vector>
#include <iostream>


class Book
{
public:
    Book(const std::string& author, const std::string& title, int year, int shelfNumber);

    const std::string& getAuthor() const { return author; }
    const std::string& getTitle()  const { return title; }
    int   getYear()          const { return year; }
    int   getShelfNumber()   const { return shelfNumber; }

    void setShelfNumber(int shelfNumber) { this->shelfNumber = shelfNumber; }

private:
    std::string author;
    std::string title;
    int year;
    int shelfNumber;
};


class Bibliophile
{
public:
    Bibliophile() = default;
    virtual ~Bibliophile() = default;

    void addBook(const Book& book);
    std::vector<Book> getBooksByAuthor(const std::string& author) const;
    int countBooksByYear(int year) const;
    void updateShelfNumber(const std::string& title, int newShelfNumber);

    std::vector<Book> collection;

private:
};


class Library
{
public:
    class PricedBook
    {
    public:
        PricedBook(const std::string& author, const std::string& title, int year, int shelfNumber, float price);

        const std::string& getAuthor() const { return author; }
        const std::string& getTitle()  const { return title; }
        int   getYear()          const { return year; }
        int   getShelfNumber()   const { return shelfNumber; }
        float getPrice()         const { return price; }

        void setShelfNumber(int shelfNumber) { this->shelfNumber = shelfNumber; }

    private:
        std::string author;
        std::string title;
        int year;
        int shelfNumber;
        float price;
    };

    void addPricedBook(const PricedBook& book);
    void countBooksAndTotalPriceByYear(int year, int& count, float& totalPrice) const;

    std::vector<PricedBook> collection;
};

void loadBooksFromFile(const std::string& filename, Bibliophile& bibliophile);
void saveBooksToFile(const std::string& filename, const Bibliophile& bibliophile);
void loadPricedBooksFromFile(const std::string& filename, Library& library);
void savePricedBooksToFile(const std::string& filename, const Library& library);
