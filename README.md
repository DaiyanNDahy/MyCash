
# myCash Mobile Banking Application

myCash is a mobile banking application similar to bKash, aimed at providing mobile financial services. This application allows users to perform various financial operations such as cash-in, cash-out, send money, pay bills, and check balance. The system ensures secure transactions with OTP (One-Time Passcode) verification for sensitive operations. This program was developed as a classwork for Object-Oriented-Programming course in my university.

## Features

- **User Registration**: Users can register with their mobile number, name, and a secure PIN.
- **Login**: Secure login with mobile number and PIN.
- **Cash-In**: Deposit money into the account.
- **Cash-Out**: Withdraw money from the account.
- **Send Money**: Transfer money to another user's account.
- **Pay Bill**: Pay utility bills like Gas, Electricity, Water, and Internet.
- **Check Balance**: View the current balance.
- **Transaction History**: View a detailed history of all transactions.
- **OTP Verification**: Secure sensitive operations with a time-limited OTP.

## Installation

1. **Clone the repository**:
    git clone https://github.com/yourusername/myCash.git
    cd myCash
    

2. **Compile the program**:
    g++ -o myCash.cpp
    

3. **Run the application**:
    ./myCash


## Usage

Upon running the application, the user will be presented with the following options:

### Login Menu

1. **Login**
2. **Register**
3. **Exit**

### Main Menu

1. **Update Me**: Update user details.
2. **Remove Me**: Delete the user account.
3. **Send Money**: Transfer money to another user.
4. **Cash-In**: Deposit money into the account.
5. **Cash-Out**: Withdraw money from the account.
6. **Pay Bill**: Pay utility bills.
7. **Check Balance**: View current balance.
8. **History**: View transaction history.
9. **Logout**: Log out of the account.

### Examples

**Register a new member**:
```plaintext
Enter Mobile No. (11-digit): 01714228567
Enter Name: John Borris
Enter pin (5-digit): *****
Reconfirm pin: *****
myCash OTP: 2319
Enter OTP: 2319
Registration is Successful
```

**Login**:
```plaintext
Enter Mobile No. (11-digit): 01714228567
Enter pin: *****
Login is Successful
```

**Send Money**:
```plaintext
Enter Destination no. (11-digit): 01713447831
Enter Amount: 2000
Sending 2000 to 01713447831
Are you sure(Y/N)? Y
myCash OTP: 2619
Enter OTP: 2619
Send Money is Successful
```


This README file provides an overview of the project, installation instructions, usage examples, file structure, contribution guidelines, and licensing information. It should help users and developers understand the "myCash" application.
