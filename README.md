# Crypto Wallet: Cryptocurrency Trading Platform Simulation

This project is a simplified cryptocurrency exchange platform simulation built in C++ as part of a 5-course specialization from the University of London’s online BSc Computer Science program. The application simulates the experience of buying and selling cryptocurrencies by processing a real dataset from an order book.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Acknowledgments](#acknowledgments)


## Overview

This project demonstrates key C++ programming skills including:

- **Control Flow & Data Structures**: Using loops, conditionals, and appropriate data types to manage trading data.
- **Object-Oriented Programming**: Implementing classes like `OrderBook` and `OrderBookEntry` to encapsulate data and behavior.
- **Algorithm Implementation**: Matching asks to bids, calculating high/low prices, and computing percentage changes.
- **Data Processing**: Reading and processing CSV files to simulate real-world trading scenarios.

## Features

### Order Book Management

- Create and manage a live order book using custom classes.
- Store and process orders with details such as price, amount, timestamp, product, and order type.

### Order Matching Engine

- Match buy (bid) and sell (ask) orders using efficient sorting and comparison methods.
- Process partial and full order matches to simulate realistic trading operations.

### Statistical Analysis

- Calculate key metrics, including highest/lowest prices and percentage change over time.

### Modular Design

- Organized codebase with separation of concerns via header and source files.
- Easily extendable for additional features or integration with real exchange APIs.

## Project Structure

```plaintext
├── include/
│   ├── OrderBook.h
│   ├── OrderBookEntry.h
│   └── CSVReader.h
├── src/
│   ├── OrderBook.cpp
│   ├── OrderBookEntry.cpp
│   └── main.cpp
├── data/
│   └── sample_data.csv
├── README.md
└── Makefile
```
## Acknowledgments
This project was developed as part of a comprehensive 5-course specialization in C++ programming, drawing on content from the University of London’s online BSc Computer Science degree. The project allowed for practical application of programming concepts in a real-world context.
