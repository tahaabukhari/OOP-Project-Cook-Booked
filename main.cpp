#include <iostream> // for input/output functions
#include <string>  // for line based string functions
#include <fstream> // for file input/output
#include <vector> // to store and access objects

using namespace std;
// ye limiting constants hein, ye globally act krte hein
int RECIPE_LIMIT = 36;
int USER_LIMIT = 12;

// Idhe Inheritance showcase krne ke liye 'Mealplan' ko parent bna diya he or ye category string main class 'Recipe' ko deta he.
class MealPlan {
public:
    string category;
    // har class mein 2 constructors hein
    // The purpose here is to showcase constructor overloading.

    // This is a default constructor, its intended to work even if the parameters are blank.
    MealPlan() {
        category = "";
    }
    // This is a perameterized constructor, we are using a pass by refrence method.
    MealPlan(string& mycategory) {
        category = mycategory;
    }
};

// Ye main class he, is mein meal se category inherit krwai he.
class Recipe : public MealPlan {
public:
    string name;
    string instructions;
    string ingredientCount;

    // same as above, ye default constructor he.
    Recipe() {
        name = "";
        instructions = "";
        ingredientCount = "";
    }
    // ye parameterized constructor he.
    Recipe(string& myname, string& mycategory, string& myinstructions, string& myingredientcount) : MealPlan(mycategory) {
        name = myname;
        instructions = myinstructions;
        ingredientCount = myingredientcount;
    }

    // These are some member functions, inhein hum main mein use krein ge.
    void displayRecipe() {
        cout << "-----------------------" << endl;
        cout << "| Recipe Name: " << name << endl;
        cout << "-----------------------" << endl;
        cout << "| Category: " << category << endl;
        cout << "-----------------------" << endl;
        cout << "| Ingredients: " << ingredientCount << endl;
        cout << "-----------------------" << endl;
        cout << "| Instructions: " << instructions << endl;
        cout << "-----------------------" << endl;
    }
    // ye recipe ko file mein save krne ke liye he, similar to how cout works on our compiler outFile will give the output on the assaigned file.
    void saveToFile(ofstream& outFile) {
        outFile << name << endl;
        outFile << category << endl;
        outFile << ingredientCount << endl;
        outFile << instructions << endl;
    }
    // same thing except is bar hum file se input le rhe hein exactle how hum cin kr ke compiler console se input lete hein.
    void loadFromFile(ifstream& inFile) {
        getline(inFile, name);
        getline(inFile, category);
        getline(inFile, ingredientCount);
        getline(inFile, instructions);
    }
};

// Ye User ki main class he.
class User {
private:
    string username;
    string password;

public:
// given the purpose of this program, hum users ke liye or koi information add nahi krein ge.
// instead, public mein sirf member functions hon ge jo hum inheritance ke through is ki subclass 'userLogin' mein execute krein ge.

    User() {
        username = "";
        password = "";
    }

    User(string& myusername, string& mypassword) {
        username = myusername;
        password = mypassword;
    }
    // get function since username and password private hein
    string getId() {
        return username;
    }
    string getKey() {
        return password;
    }

    // ye password ko authentication ke time pe check kre ga
    bool checkpassword(string myPassword) {
        return password == myPassword;
    }
    // set function for user and password, since login aik hi bar donon cin krwai ga to seperate functions ki zaroorat nai he.
    void setUser(string myid, string myPassword) {
        username = myid;
        password = myPassword;
    }
};

// This is the login menu.

class UserLogin : public User {
public:
// Here we have used bool so the output of the Login menu can always either be true or false, this makes it much easier to program and manage.
    static bool userLogin(vector<User>& users, string& currentUser) {
        cout << "----------------------------" << endl;
        cout << "| Welcome to Cook Booked!  |" << endl;
        cout << "----------------------------" << endl;
        cout << "| Please Login to Continue |" << endl;
        cout << "----------------------------" << endl;
        cout << "| 1. Login                 |" << endl;
        cout << "| 2. Register              |" << endl;
        cout << "| 3. Exit                  |" << endl;
        cout << "----------------------------" << endl;
        cout << "(uwu) Enter your choice: ";
        char choice;
        cin >> choice;

// Here instead of using a switch statement, ive used a if-then logic to add variation to our code. since its a demonstation of the students knowledge.
        
        if (choice == '1') {
            string id, password;
            cout << "----------------" << endl;
            cout << "Enter Username: ";
            cin >> id;
            cout << "Enter Password: ";
            cin >> password;
            cout << "----------------" << endl;
 // This matches users input data with the one stored in its file
            for (User& user : users) {
                if (user.getId() == id && user.checkpassword(password)) {
                    currentUser = id;
                cout << "--------------------------------" << endl;
                cout << "| (uwu!) Login Successfull!    |" << endl;
                cout << "--------------------------------" << endl;   
                    return true;
 // this is the only case which resuts in the bool being 'true', so no one can access the main menu until they log in. If the data doesnt match it will return 'false' and the login menu will pop up again.
                }
            }
            cout << "-----------------------------------" << endl;
            cout << "(>.<) Invalid Username or Password!" << endl;
            return false;
// incase the user forgets his password, usse new account bnana pre ga
        } else if (choice == '2') {
            string id, password;
            cout << "---------------------------" << endl;
            cout << "Enter Username: ";
            cin >> id;
            cout << "---------------------------" << endl;
            cout << "Enter Password: ";
            cin >> password;
// Yahan agar user aik aesa Username pick krta he jo already exist krta huwa to wo 'Username already exists' ka error de ga.
            for (User& user : users) {
                if (user.getId() == id) {
                    cout << "-------------------------" << endl;
                    cout << "Error!" << endl;
                    cout << "Username already exists!" << endl;
                    cout << "(>.<) Please Enter a Different Username!" << endl;
                    return false;
                }
            }
// Register krte huwe newUser ka object bne ga or wo isse <vector> mein save kre ga.         // User register krne ke baad bhi humein pehle Log In krna ho ga, ye automatic nai he.   
            User newUser(id, password);
            users.push_back(newUser);
            cout << "----------------------------------------" << endl;
            cout << "| (uwu!) User Registered Successfully! |" << endl;
            cout << "----------------------------------------" << endl;
            return false;
        } else if (choice == '3') {
            return 0;
        } else {
            cout << "(x.x) Invalid choice! Please try again." << endl;
            return false;
        }
    }
};
// Yahan tk usermenu complete he, menu 1-3 tk options de ga agr in mein se koi select na ki to error de ke wapis a jaye ga.

// Ye Global Functions hein.
// This one was made to add a more 'Geniune' feel to the program, as most apps credits ki form mein user ko more options deti hein.

void displayCredits() {
    cout << "---------------------------------" << endl;
    cout << "|||||||||||||||||||||||||||||||||" << endl;
    cout << "---------------------------------" << endl;
    cout << "This Project is Developed by Group 9" << endl
         << "Course 'Object Oriented Programming'" << endl
         << "BSDS 2nd Semester" << endl;
    cout << "Project Submitted to: Dr Ayesha Hakim" << endl;
    cout << "Project Deadline: 29th May, 2024" << endl;
    cout << endl;
    cout << endl;
    cout << "-----------------------" << endl;
    cout << "|  Group 9 - Members  |" << endl;
    cout << "-----------------------" << endl;
    cout << "Abdul Rehman Jamil - Team Leader" << endl;
    cout << "---------------------------------" << endl;
    cout << "Fahad Khalid - Developer" << endl;
    cout << "Tahaa Bukhari - Lead Developer" << endl;
    cout << "Ehsan Mehdi - Developer" << endl;
    cout << "Waqas Zahoor - Developer" << endl;
    cout << "Azan Akbar - N/A" << endl;
}

// This is the part which takes user data from <Uservector> and saves it in a file.
void saveUsers(vector<User>& users, string filename) {
    ofstream outFile(filename);
// open and closed parameters determine whether the file is available or not.    
    if (outFile.is_open()) {
        outFile << users.size() << endl;
        for (User& user : users) {
            outFile << user.getId() << endl;
            outFile << user.getKey() << endl;
        }
        outFile.close();
    } else {
        cout << "---------------------------" << endl;
        cerr << "(ouo) Unable to open file: " << filename << endl;
    }
}

// This function is responsible for fetching users data from the file to <vector>
void loadUsers(vector<User>& users, string filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        int userCount;
        inFile >> userCount;
        inFile.ignore();
        for (int i = 0; i < userCount; ++i) {
            string id, password;
            getline(inFile, id);
            getline(inFile, password);
            User user(id, password);
            users.push_back(user);
        }
        inFile.close();
    } else {
        cout << "---------------------------" << endl;
        cout << "(T.T) LOAD ERROR: " << filename << " not found!" << endl;
    }
}

// Same as user, this saves the new recipe from vector to file
void saverecipes(vector<Recipe>& recipes, string filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << recipes.size() << endl;
        for (Recipe& recipe : recipes) {
            recipe.saveToFile(outFile);
        }
        outFile.close();
    } else {
        cout << "---------------------------" << endl;
        cerr << "(T.T) Unable to open file: " << filename << endl;
    }
}

// this loads recipe from file to vector.
void loadrecipes(vector<Recipe>& recipes, string filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        int recipeCount;
        inFile >> recipeCount;
        inFile.ignore();
        for (int i = 0; i < recipeCount; ++i) {
            Recipe recipe;
            recipe.loadFromFile(inFile);
            recipes.push_back(recipe);
        }
        inFile.close();
    } else {
        cout << "---------------------------" << endl;
        cerr << "(x.x) LOAD ERROR: " << filename << " not found!" << endl;
    }
}


// if the User registers a new account, it will always give a laod error since the file its supposed to load data from doesnt exist. It will make a new file when the user attempts to save.
// This is Main.
int main() {
    // First, ye User ka vector bna ke us mein users ko load kre ga.
    // load file is always titled "users.txt" if the file doesnt exist or is deleted by accident, itll automatically make one when the user registers a new account.
    vector<User> users;
    loadUsers(users, "users.txt");

    string currentUser;
    bool loginSuccessful = false;
    // Here logis is set to false by default
    // then we call the userlogin function from its class, if the login is true then the user is logged in as intended.
    while (!loginSuccessful) {
        loginSuccessful = UserLogin::userLogin(users, currentUser);
    }

// Once the user logs in, he can access the main menu.
// Same as User, we will first make a recipe vector and then setup a file parameter.
// Each user has his own unique file which is loaded to the vector.
// the program uses the username as filename so it is easier to access.  
    vector<Recipe> recipes;
    string userFilename = currentUser + "_recipes.txt";
    loadrecipes(recipes, userFilename);
    saveUsers(users, "users.txt");
// Heres the main menu with a simple switch statement.
    char choice;
    while (true) {
        cout << "||||||||||||||||||||||||||||" << endl;
        cout << "----------------------------" << endl;
        cout << "    Welcome  " << currentUser << "!  :)" << endl;
        cout << "----------------------------" << endl;
        cout << "| Cookbook Menu -  (>w<)   |" << endl;
        cout << "----------------------------" << endl;
        cout << "| 1. New Recipe.           |" << endl;
        cout << "| 2. View Recipes.         |" << endl;
        cout << "| 3. About.                |" << endl;
        cout << "| 4. Close Program.        |" << endl;
        cout << "----------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                Recipe recipe;
                cout << "--------------------" << endl;
                cout << "Creating New Recipe" << endl;
                cout << "--------------------" << endl;
                cin.ignore();
                string name, category, instructions, ingredientCount;
// yahan hum ne getline use kia he kyun ke string complete sentences on its own save ni krti.
                cout << "Enter Recipe Name: ";
                getline(cin, name);
                cout << "Enter Recipe Category: ";
                getline(cin, category);
                cout << "Enter Ingredients: ";
                getline(cin, ingredientCount);
// cin ignore string ka function he jo space or enter ko ignore kr deta he, so the program views it as a single word.
                cout << "Enter Recipe Instructions: ";
                getline(cin, instructions);
                recipe = Recipe(name, category, instructions, ingredientCount);
                recipes.push_back(recipe);
                saverecipes(recipes, userFilename);
                cout << "-----------------------------------" << endl;
                cout << " Recipe Saved! (owo) " << endl;
                cout << "-----------------------------------" << endl;
                cout << "| Enter 4 to go back to Menu Page |" << endl;
                cout << "-----------------------------------" << endl;
                int exit;
                cin >> exit;
                if (exit == 4) {
                    continue;
                }
                break;
            }
// program mein aik 'back' option he, takye user menu page ko dubara access kr sake.         
            case '2': {
                cout << "Viewing Recipes" << endl;
                for (Recipe& recipe : recipes) {
                    recipe.displayRecipe();
                    cout << "|||||||||||||||||||||||" << endl;
                }

                cout << "-----------------------------------" << endl;
                cout << "| Enter 4 to go back to Menu Page |" << endl;
                cout << "-----------------------------------" << endl;
                int exit;
                cin >> exit;
                if (exit == 4) {
                    continue;
                }
                break;
            }
// second option sirf recipes ko display kr deta he, wo vecor se pehle hi loaded hoti hein to main mein ye part bohot simple lg rha he.   
            case '3': {
                displayCredits();
                cout << "-----------------------------------" << endl;
                cout << "| Enter 4 to go back to Menu Page |" << endl;
                cout << "-----------------------------------" << endl;
                int exit;
                cin >> exit;
                if (exit == 4) {
                    continue;
                }
                break;
            }
// third option sirf aesthetic purposes ke liye hei, program ki functionallity se ye irrelevant he.
            case '4': {
                return 0;
            }
// finally option four program ki switch statement ko bhi end kr deta he.            
            default: {
                cout << "(x.x) Invalid choice! Please try again." << endl;
                break;
            }
        }
    }
    return 0;
// User menu system mein lines ko use kr ke Boxes bnaye huwe hein takye program runtime mein clean or easy to read rhe. Program sirf new recipes ko load kr ke unhein aik user-specific file mein upload krta he, although adding a function for deleting a recipe would be possible but that would require ke hum har recipe ko us ka koi specific ID assaign krein, which is beyond my current ability.    
}
