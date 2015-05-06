#!/usr/bin/env python

import sys

COINS = [
    ("Toonies",  2.00),
    ("Loonies",  1.00),
    ("Quarters", 0.25),
    ("Dimes",    0.10),
    ("Nickels",  0.05),
    ("Pennies",  0.01)
]

# Presentation
def divider():
    print("="*40)

def header():
    print("{0:<25}{1:<5}{2:>10}".format("Coin", "QTY", "Value"))
    divider()

def row(coin_type, count, value):
    print("{0:<25}{1:<5}{2:>10.2f}".format(coin_type, int(count), value))

def footer(amt):
    divider()
    print("{0:>40.2f}".format(amt))

# Calculation
def calculate_change(amount):
    total = amount
    header()
    for (coin_type, base_value) in COINS:
        count = total // base_value
        if count > 0:
            value = count * base_value
            row(coin_type, count, value)
            total -= value
    footer(amount)

if len(sys.argv) > 1:
    # add 0.001 to fix miniscule precision loss
    calculate_change(float(sys.argv[1]) + 0.001)
else:
    print("Usage: {0} [amount]".format(sys.argv[0]))
