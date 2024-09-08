#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "CSVReader.h"
#include <limits>

MerkelMain::MerkelMain()
{
}

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;

    // 2 print exchange stats
    std::cout << "2: Print exchange stats " << std::endl;

    // 3 make an offer "to sell"
    std::cout << "3: Make an offer " << std::endl;

    // 4 make a bid "to buy"
    std::cout << "4: Make a bid " << std::endl;

    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;

    // 6 continue
    std::cout << "6: continue " << std::endl;

    // 7 Exit
    std::cout << "7: Exit " << std::endl;

    std::cout << "============== " << std::endl;

    std::cout << "Current time is: " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers" << std::endl;
}

void MerkelMain::printMarketStats()
{

    for (std::string const &p : orderBook.getKnownProducts())
    {
        std::cout << "Products: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max seen: " << OrderBook::getHighPrice(entries) << std::endl;
    }

    // std::cout << "OrderBook contains : " << orders.size() << " entries" << std::endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;

    // for (OrderBookEntry& e : orders ){
    //     if (e.orderType == OrderBookType::ask) {
    //         asks ++;
    //     }

    //     if ( e.orderType == OrderBookType::bid) {
    //         bids ++;
    //     }
    // }
    //         std::cout << "OrderBook  asks: " << asks << " bids:" <<  bids << std::endl;
}

void MerkelMain::enterAsk()
{
    std::cout << "Make an ask - enter the amount: product, price, amount, eg ETH/BTC, 200,0.5 " << std::endl;
    std::string input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "Bad input! " << input << std::endl;
    }
    else
    {

        OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1],
                                                     tokens[2],
                                                     currentTime,
                                                     tokens[0],
                                                     OrderBookType::ask);
    }

    std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame " << std::endl;
    currentTime = orderBook.getNextTime(currentTime);
}

bool MerkelMain::exitProgram()
{
    std::cout << "Exiting program." << std::endl;
    return false;
}

int MerkelMain::getUserOption()
{
    int userOption;

    std::cout << "type in 1-7 " << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
    if (std::cin.fail())
    {
        std::cin.clear();                                                   // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        std::cout << "Invalid input. Please enter a number between 1 and 7." << std::endl;
    }

    if (userOption < 0 || userOption > 7) // handle out of range input
    {
        std::cout << "Invalid choice. Choose a number between 1 and 7." << std::endl;
    }

    if (userOption == 1)
    {
        printHelp();
    }

    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterAsk();
    }

    else if (userOption == 4)
    {
        enterBid();
    }

    else if (userOption == 5)
    {
        printWallet();
    }

    else if (userOption == 6)
    {
        gotoNextTimeframe();
    }

    else if (userOption == 7)
    {
        exitProgram();
    }
}