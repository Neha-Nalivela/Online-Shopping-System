# 🛒 Online Shopping System in C

A **console-based Online Shopping System** developed using the **C programming language**. The application provides basic user account management, product categories, product selection, and automatic bill calculation.

This project demonstrates the use of **structures, arrays, functions, strings, loops, conditional statements, and pointers** in C.

## 📌 Project Overview

The Online Shopping System allows users to:

* Create a new account
* Log in using a username and password
* Browse different product categories
* View available products and prices
* Select products for purchase
* Automatically calculate the total bill
* Continue shopping across multiple categories
* Exit the shopping system

## ✨ Features

### 👤 User Account Management

Users can:

* Create a new account
* Choose a username and password
* Log in using their registered credentials
* Prevent duplicate usernames

### 🛍️ Product Categories

The application contains five categories:

1. Fruits
2. Vegetables
3. Stationery
4. Electronics
5. Miscellaneous

### 💰 Bill Calculation

Whenever an item is selected, its price is added to the current bill.

The total bill is displayed when the user exits the shopping section.

### 🔐 Authentication

The system checks the entered username and password against the registered users.

If the credentials are correct:

```text
Login successful.
```

Otherwise:

```text
Invalid username or password.
```

---

## 🧠 Concepts Used

| C Concept              | Usage                           |
| ---------------------- | ------------------------------- |
| Structure              | Stores username and password    |
| Array                  | Stores registered users         |
| Functions              | Separates different operations  |
| Strings                | Handles usernames and passwords |
| Pointers               | Updates the total bill          |
| Loops                  | Menu and user operations        |
| `switch`               | Handles menu/category choices   |
| Conditional statements | Validates user input            |
| Arrays                 | Stores product prices           |

---

## 🏗️ Program Structure

```text
Online Shopping System
│
├── User Management
│   ├── Create Account
│   ├── Login
│   ├── Authenticate User
│   └── Check Username
│
├── Shopping
│   ├── Select Category
│   ├── Display Items
│   ├── Purchase Fruits
│   ├── Purchase Vegetables
│   ├── Purchase Stationery
│   ├── Purchase Electronics
│   └── Purchase Miscellaneous
│
└── Billing
    └── Calculate Total Bill
```

---

## 📂 Product Categories

### 🍎 Fruits

| Item       | Price |
| ---------- | ----: |
| Bananas    |   ₹50 |
| Mangoes    |  ₹100 |
| Apples     |  ₹150 |
| Pineapples |  ₹130 |
| Grapes     |  ₹200 |

### 🥕 Vegetables

| Item           | Price |
| -------------- | ----: |
| Eggplant       |   ₹75 |
| Beetroot       |  ₹110 |
| Green Chillies |  ₹180 |
| Sweetcorn      |  ₹300 |
| Onion          |   ₹30 |

### ✏️ Stationery

| Item             | Price |
| ---------------- | ----: |
| Gum Bottle       |   ₹10 |
| Punching Machine |   ₹30 |
| Sealing Wax      |   ₹50 |
| Tea Set          |  ₹300 |
| Cleaning Powder  |   ₹30 |

### 💻 Electronics

| Item            | Price |
| --------------- | ----: |
| Computer Items  |   ₹50 |
| Mobile Items    |   ₹50 |
| Wires           |  ₹550 |
| Appliances      |   ₹50 |
| All Electronics |   ₹50 |

### 🏠 Miscellaneous

| Item             | Price |
| ---------------- | ----: |
| Bubble Bath Card | ₹6000 |
| Kitchen Items    |   ₹50 |
| Room Items       |   ₹50 |
| Bathroom Items   |   ₹50 |

---

## 🔄 Application Flow

```text
Start
  ↓
Online Shopping Menu
  ↓
 ┌─────────────────────┐
 │ 1. Login            │
 │ 2. Create Account   │
 │ 3. Exit             │
 └─────────────────────┘
  ↓
Login
  ↓
Validate Username & Password
  ↓
Login Successful?
  ├── No → Display Error
  │
  └── Yes
       ↓
   Shopping Categories
       ↓
   Select Category
       ↓
   Display Products
       ↓
   Select Product
       ↓
   Add Price to Bill
       ↓
   Continue Shopping
       ↓
   Quit
       ↓
   Display Total Bill
       ↓
      Exit
```

---

## 🧩 Important Functions

### `createUser()`

Creates a new user account.

```c
void createUser()
```

The function:

1. Accepts a username.
2. Checks whether the username already exists.
3. Accepts a password.
4. Stores the user in the `users` array.
5. Increases the number of registered users.

---

### `login()`

Handles the login process.

```c
void login()
```

It accepts the username and password and calls `authenticateUser()` to verify the credentials.

After successful authentication, the user can access the shopping system.

---

### `authenticateUser()`

Checks whether the entered username and password match a registered user.

```c
int authenticateUser(char username[], char password[])
```

It returns:

```text
1 → Authentication successful
0 → Authentication failed
```

---

### `isUsernameExists()`

Checks whether a username is already registered.

```c
int isUsernameExists(char username[])
```

This prevents duplicate usernames.

---

### `selectCategory()`

Displays the available shopping categories.

```c
char selectCategory()
```

The user can select:

```text
1 → Fruits
2 → Vegetables
3 → Stationery
4 → Electronics
5 → Miscellaneous
q → Quit
```

---

### `displayItems()`

Displays the products and their prices based on the selected category.

```c
void displayItems(char category)
```

---

### Purchase Functions

Each category has a separate purchase function:

```c
handleFruitPurchase()
handleVegetablePurchase()
handleStationeryPurchase()
handleElectronicsPurchase()
handleMiscellaneousPurchase()
```

Each function:

1. Displays the available choices.
2. Accepts the user's item selection.
3. Validates the selection.
4. Adds the item's price to the total bill.

---

## 💵 Bill Calculation

The total bill is maintained using a pointer:

```c
double totalBill = 0.0;
```

The address of the variable is passed to the purchase functions:

```c
handleFruitPurchase(&totalBill);
```

Inside the function, the value is updated using:

```c
*totalBill += prices[choice - 1];
```

This allows the purchase functions to directly update the total bill.

---

## 🖥️ Sample Execution

```text
--- Online Shopping ---
1. Login
2. Create an account
3. Exit
Enter your choice: 2

Enter new username: user1
Enter new password: 1234
Account created successfully!

--- Online Shopping ---
1. Login
2. Create an account
3. Exit
Enter your choice: 1

Enter username: user1
Enter password: 1234

Login successful. Welcome, user1!


--------------------
 Online Shopping System
 Made By *** ANONYMOUS ***
--------------------

** GENERAL CATEGORIES **
1. Fruits
2. Vegetables
3. Stationery
4. Electronics
5. Miscellaneous
Press 'q' to Quit

Enter your choice: 1

Fruits:
1. Bananas - 50
2. Mangoes - 100
3. Apples - 150
4. Pineapples - 130
5. Grapes - 200

Enter fruit choice (1-5): 3

Item added. Current Bill: Rs. 150.00
```

After selecting `q`:

```text
Your total bill is: Rs. 150.00
```

---

## 📊 Complexity

The user database uses a simple array.

For `n` registered users:

| Operation         | Complexity |
| ----------------- | ---------: |
| Create user       |       O(1) |
| Check username    |       O(n) |
| Authenticate user |       O(n) |
| Select category   |       O(1) |
| Select product    |       O(1) |
| Bill update       |       O(1) |

---

## 🛠️ Technologies Used

* **Programming Language:** C
* **Compiler:** GCC / MinGW
* **Development Environment:** VS Code / Code::Blocks / Dev-C++ / any C IDE

### C Libraries

```c
#include <stdio.h>
#include <string.h>
```

`stdio.h` is used for:

* `printf()`
* `scanf()`

`string.h` is used for:

* `strcmp()`
* `strcpy()`

---

## 📂 Project Structure

```text
Online-Shopping-System/
│
├── online_shopping.c
└── README.md
```

---

## ▶️ How to Run

### Step 1: Clone the Repository

```bash
git clone <your-github-repository-url>
```

### Step 2: Navigate to the Project

```bash
cd Online-Shopping-System
```

### Step 3: Compile

Using GCC:

```bash
gcc online_shopping.c -o shopping
```

### Step 4: Run

On Windows:

```bash
shopping.exe
```

On Linux/macOS:

```bash
./shopping
```

---

## ⚠️ Current Limitations

* User accounts are stored only in memory.
* User data is lost when the program exits.
* Passwords are stored as plain text.
* The application does not use a database.
* Product information is hard-coded.
* Each purchase currently adds one item at a time.
* There is no quantity management.
* There is no payment gateway.
* Input validation can be improved.

---

## 🚀 Future Improvements

The project can be extended by adding:

* File-based user storage
* Database integration
* Password encryption/hashing
* Product search
* Product quantities
* Shopping cart
* Remove item from cart
* Order history
* Customer profile
* Discount and coupon system
* GST/tax calculation
* Payment integration
* Product inventory management
* Admin panel
* Better input validation
* Graphical or web-based interface

---

## 🎯 Learning Objectives

This project provides practical understanding of:

* C structures
* Arrays
* Functions
* Pointers
* String handling
* Loops
* Conditional statements
* `switch-case`
* User authentication logic
* Basic billing systems
* Modular programming

---

## 📜 License

This project is created for **educational and academic purposes**.
