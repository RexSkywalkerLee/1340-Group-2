# ENGG1340-Group-2
Group members:
Li Jialong(3035533795)
Wang Xinxin(3035533563)

Use digital tools to manage users' financial status. We target to build an accounting system to help people keep track of their income and expense. 

1)Multiple users can manage their financial status through this accounting system;
Assumptions:
When one user signs up, the system will require him to set a username and password, and automatically make a directory which contains various files to keep records of user's financial states. Later user can sign in the system using username and password. 
   
2)The system allows users to add records which contain information like amount, date, types of income or expense (e.g., food, game, salary, etc.), account (e.g.cash, bank card, credit card, etc.); 
Assumptions:
When user types in a specific keyword (e.g., add), the system calls a function which opens a file and receives input (record information) from the user, writes in the record, then function closes file before it ends.

3)Users could view their records by date, type, and account; 
Assumptions:
When user types in a specific keyword (e.g., check), the system calls a function which opens the file containing the records and receives input from the user(date, type, account), then searches for corresponding records and print them out, closes file before it ends.

4)Each user can delete and edit any record at any time;
Assumptions:
When user types in a specific keyword (e.g., delete/edit), the system calls a function which opens a file and receives input (record information of the record to be deleted/edited) from the user, search for the specific record, replace it with a new record that was input by the user(replacing the original one with empty record if command was "delete"), then function closes file before it ends.

5)The accounting system allows monthly budget resetting and editing at any time. When expenses reach the budget, there will      be an alert from the system;
Assumptions:
In the directory of each user, there's a file containing the budget information. Particular functions are used to allow users to add, reset and edit their total budgets. Another function is used to open the file containing records and retrieve information, then calculate the remaining budgets and display it.  

5)The system can provide a statistical report of users’ financial state: monthly, seasonally, yearly income and expenses, the percentage of each type of income(salary, bonus, etc.) and expenses(food, transportation, etc.);
Assumptions:
When the user types in a specific keyword to ask for a statistical report, the system uses a function to open the file containing records and retrieve information which was sorted by date, then calculate the periodic income/expenses along with the percentage of each type and display them.  

6)The system allows users to check their accounts information at any time; account information includes credit card invoice, bank account balance, etc.; accounts information will be automatically updated each time the user adds ( or delete edit) expense or income records;
Assumptions:
In the directory of each user, there's a file containing the account information(the initial account information should be stored in this file the time a user signs up). Each time the user adds (edit, delete) a record, the system also calls a function to open this account-information file and update the account information. When the user types in a specific keyword to ask to check account information, the system opens this file and displays the contents.  

8)Users can request a report of each day's balance(graphically) of the latest seven days;
Assumptions:
When user types in a specific keyword to ask for a late report, the system calls a function that opens the file containing records and retrieves records of the latest seven days, then calculates each day's balance. The balance's value is then illustrated by the number of special characters(e.g., &, *). In this way, the records of the latest seven days are represented more concisely and straightforwardly.
 
