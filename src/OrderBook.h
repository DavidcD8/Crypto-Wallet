#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>


class OrderBook
{
public:
    /** construct, reading a csv data file */
    OrderBook(std::string filename);

    /** return vector of all known products in the dataset */
    std::vector<std::string> getKnownProducts();

    /** return vector of Orders according to the sent filters */
    std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);

    /** returns earliest time in the oderbook */
    std::string getEarliestTime();

    /** returns the next time after the sent time in the oderbook
     * If there is no next timestamp, wraps around to the start
    */
    std::string getNextTime(std::string timestamp);
    void insertOrder(OrderBookEntry& order);
    static double getHighPrice(std::vector<OrderBookEntry> &orders);
    static double getLowPrice(std::vector<OrderBookEntry> &orders);
    static double getPercentageChange(std::vector<OrderBookEntry>& orders);

    std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);




private:
    std::vector<OrderBookEntry> orders;
};
