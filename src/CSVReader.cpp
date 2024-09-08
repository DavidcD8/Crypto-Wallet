#include "CSVReader.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

CSVReader::CSVReader() {}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename){
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile{csvFilename};
    std::string line;

    if (csvFile.is_open()) {
    
       while (std::getline(csvFile, line)){
        try {
            OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
            entries.push_back(obe);
        }
        catch (const std::exception& e) {
            std::cout << "CSVReader::readCSV bad data: " << std::endl;
        }
  
            
         }
    }
    std::cout << "CSVReader::readCSV processed " << entries.size() << " entries" << std::endl;
            return entries;
}

   

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;

    while ((end = csvLine.find(separator, start)) != std::string::npos)
    {
        tokens.push_back(csvLine.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(csvLine.substr(start)); // Push the last token

    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    if (tokens.size() != 5)
    {
          throw std::runtime_error("Incorrect number of tokens");
    }

    double price, amount;
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception &e)
    {
      
    }

    OrderBookEntry obe{
        price,
        amount,
        tokens[0],
        tokens[1],
        OrderBookEntry::stringToOrderBookType(tokens[2])};

    return obe;
}

     OrderBookEntry CSVReader::stringsToOBE(std::string priceString,
                                                                                    std:: string amountString,
                                                                                    std::string timestamp,
                                                                                    std::string product, 
                                                                                    OrderBookType orderType)
{

double price, amount;
try{
    price = std::stod(priceString);
    amount = std::stod(amountString);
}
catch(const std::exception& e){
    std::cout << "CSVReader stromgsToBE Bad float! " << priceString<< std::endl;
    std::cout << "CSVReader stromgsToBE Bad float! " << amountString<< std::endl;
    throw;
}
    OrderBookEntry obe{price,
                                            amount,
                                            timestamp ,
                                            product,
                                            orderType};
 
    return obe;
     }