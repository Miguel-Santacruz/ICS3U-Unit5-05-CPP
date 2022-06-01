// Copyright (c) 2022 Miguel Santacruz All rights reserved
//
// Created by: Miguel Santacruz
// Created on: May 2022
// This program writes an address as a mailing address

#include <iostream>
#include <string>
#include <algorithm>

std::string MailingAddress(std::string name, std::string streetNumber,
                           std::string streetName, std::string city,
                           std::string province, std::string postalCode,
                           std::string apartment = "") {
    std::string address;

    if (apartment != "") {
        address = name + "\n" + apartment + " - " + streetNumber + " "
        + streetName + "\n" + city + " " + province + " " + postalCode;
    } else {
        address = name + "\n" + streetNumber + " " + streetName + "\n" + city
        + " " + province + " " + postalCode;
    }
    std::for_each(address.begin(), address.end(),
    [](char & c) { c = ::toupper(c);});

    return address;
}


main() {
    // This function gets the user's info

    std::string name;
    std::string question;
    std::string streetNumber;
    std::string streetName;
    std::string city;
    std::string province;
    std::string postalCode;
    std::string address;
    std::string apartment = "";

    std::cout << "Enter your full name: ";
    getline(std::cin, name);
    std::cout << "Do you live in an apartment? (Y/N)";
    getline(std::cin, question);
    if (question == "Y") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, apartment);
    }
    std::cout << "Enter your street number: ";
    getline(std::cin, streetNumber);
    std::cout << "Enter your street name AND type: ";
    getline(std::cin, streetName);
    std::cout << "Enter your city: ";
    getline(std::cin, city);
    std::cout << "Enter your province: ";
    getline(std::cin, province);
    std::cout << "Enter your postal code: ";
    getline(std::cin, postalCode);

    // call functions
    std::cout << "" << std::endl;
    if (apartment == "") {
        address = MailingAddress(name, streetNumber, streetName,
        city, province, postalCode);
    } else {
        address = MailingAddress(name, streetNumber, streetName,
        city, province, postalCode, apartment);
    }
    std::cout << address << std::endl;
}
