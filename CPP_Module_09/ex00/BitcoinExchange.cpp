#include "BitcoinExchange.hpp"
#include <limits>
#include <list>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdexcept>

double calculateBTC(double value, double input) {
    if (input == 0.0)
        return (0.0);
    return (value * input);
}

int dateToDays(const CryptoRate &date) {
    return (date.getYear() * 365 + date.getMonth() * 30 + date.getDay());
}

std::list<CryptoRate>::iterator getNearestDate(std::list<CryptoRate> &arr, CryptoRate &input) {
    if (arr.empty())
        return arr.end();

    int inputDays = dateToDays(input);
    std::list<CryptoRate>::iterator nearestIt = arr.begin();
    int smallestDiff = std::abs(dateToDays(*nearestIt) - inputDays);

    for (std::list<CryptoRate>::iterator it = ++arr.begin(); it != arr.end(); ++it) {
        int currentDiff = std::abs(dateToDays(*it) - inputDays);
        if (currentDiff < smallestDiff) {
            smallestDiff = currentDiff;
            nearestIt = it;
        }
    }
    return nearestIt;
}

Btc::~Btc() {}

std::ostream &operator<<(std::ostream &out, const CryptoRate &cR) {
    unsigned int tmp;

    out << cR.getYear() << "-";
    tmp = cR.getMonth();
    if (tmp < 10)
        out << "0";
    out << tmp << "-";
    tmp = cR.getDay();
    if (tmp < 10)
        out << "0";
    out << tmp << " | " << cR.getRate();
    return (out);
}

void displayDate(const CryptoRate &value) {
    std::cout << YELLOW << "|" << END << WHITE << value.getYear() << "-";
    if (value.getMonth() < 10)
        std::cout << "0";
    std::cout << value.getMonth() << "-";
    if (value.getDay() < 10)
        std::cout << "0";
    std::cout << value.getDay() << END;
}

void displayWallet(const CryptoRate &value, const CryptoRate &input) {
    displayDate(input);
    std::cout << " " << std::fixed << std::setw(20) << input.getRate();
    displayDate(value);
    std::cout << " " << std::fixed << std::setw(20) << value.getRate();
    std::cout << YELLOW << "|" << END;
    std::cout << " " << BLUE_BG << calculateBTC(value.getRate(), input.getRate()) << " Btc" << END;
    std::cout << std::endl;
}

Btc::Btc(const std::string &inputFile) : arr() {
    size_t index;

    // Lecture de la base de données
    std::ifstream dataBase("data.csv");
    if (!dataBase.is_open())
        throw std::runtime_error("Failed to open Data base !");
    std::string line;
    index = 0;
    while (std::getline(dataBase, line)) {
        try {
            arr.push_back(CryptoRate(line, index++));
        } catch (std::exception &e) {
            std::cerr << RED << "ERROR: l." << index << " data.csv : " << END << e.what() << std::endl;
        }
    }
    if (arr.empty())
        throw std::runtime_error("Empty Data base !");
    std::cout << GREEN << "Database successfully imported !" << END << std::endl;

    // Lecture du fichier d'entrée
    index = 0;
    std::ifstream inputF(inputFile.c_str());
    if (!inputF.is_open())
        throw std::runtime_error("Failed to open " + inputFile + " !");
    while (std::getline(inputF, line)) {
        try {
            if (!line.empty()) {
                CryptoRate cur(line, index++);
                std::list<CryptoRate>::iterator nearest = getNearestDate(arr, cur);
                if (nearest != arr.end())
                    displayWallet(*nearest, cur);
            }
        } catch (std::exception &e) {
            std::cerr << RED << "ERROR: l." << index << " " << inputFile << " : " << END << e.what() << std::endl;
        }
    }
}
