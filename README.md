Cook Booked! is a recipe management system programmed in C++ that allows users to create and store thier own recipes using a C++ compiler.
It offers a super friendly and convinient User Interface and Data Storage

Features:
- User registration and login system
- Recipe creation
- Recipe viewing
- Data persistence through file storage
- User-specific recipe files
- Aesthetic interface with ASCII art

Usage:
- Run the program on your C++ compiler and follow the Login Menu prompt.
The Demo Account holds 3 stored recipes, to access them you need to enter the following details.
    Username: Admin
    Password: BSDS

- Once logged in, you will be presented with a User Menu where you can create a new recipe, view existing recipes, view credits, or exit the program.
- To create a new recipe, select option 1 and follow the prompts to enter recipe details.
- To view existing recipes, select option 2 and browse through your recipe list.
- To view credits, select option 3 and view the program credits.
- To exit the program, select option 4 and save your recipes.
- If a new user is registered, the program will save his login data after successfully closing its first instance.

Notes:
Each user has their own unique recipe file, which is loaded and saved using
fstream C++ liberary.
The program loads class data in a vector and saves it in a specific .txt file.
The program uses ASCII art to create a visually appealing interface.
This program is a demonstration of object-oriented programming concepts included in our course outline and is not intended for commercial use.

Credits:
This program was developed by Group 9 as part of the Object-Oriented Programming course at BSDS. The team members are:

1. Abdul Rehman Jamil - Team Leader
2. Fahad Khalid - Developer
3. Tahaa Bukhari - Lead Developer
4. Ehsan Mehdi - Developer
5. Waqas Zahoor - Developer
6. Azan Akbar - N/A
