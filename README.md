# ENGG1340-Group-2
## Group members: Li Jialong(3035533795) Wang Xinxin(3035533563)
### Our group project is expected to use digital tools to manage users' financial status. We target to build an accounting system to help people keep track of their income and expense. 

Before using the system: 
 - Use `make main` to compile the source files.
 - Use `./main` to execute the file.
 
1. Sign up and Sign in
   - Assumptions: When one user signs up, the system will require him/her to set a username and password, and create various files to keep track of the user's financial states. Later user can sign in the system using their username and password. Also, all the usernames and corresponding passwords are stored in a specific file. 
   - 
   
2. - Statement: Users can add records which contain information like amount, date, types of income or expense (e.g., food, game, salary, etc.), account (e.g.cash, bank card, credit card, etc.) so that users can check their detailed transaction records later on. 
   - Assumptions: When user types in a specific keyword (e.g., add), the system opens a file and writes in the record.
     - format: (+/-)amount dd/mm/yyyy type account (i.e., -100 29/03/2019 breakfast cash)

3. - Statement: Users could view their records by date, type, and account so that users can look up for specific records by various information.
   - Assumptions: When user types in a specific keyword (e.g., check), the system opens the file containing the records and then searches for corresponding records according to the date/type/account the user input.
     - i.e., Search by: date   Search for: 01/03/2019

4. - Statement: Users could delete and edit any record at any time so that users can correct their mistakes when recording financial states.
   - Assumptions: When user types in a specific keyword (e.g., delete/edit), the system opens the file containing the records and receives input (record information of the record to be deleted/edited) from the user, search for the specific record in the file. Then, the user can input another record to replace the original one(automatically replacing the original one with an empty record if the command was "delete").

5. - Statement: Users can monthly reset the budget and edit it at any time. When expenses reach the budget, there will be an alert from the system. Hence, users can flexibly change their financial plan and make sure that the expenses will not be beyond expectations.
   - Assumptions: Each user has a file containing budget information. The system allows users to add, reset and edit their total budgets. This feature can open the file containing records and retrieve information, then calculate the remaining budgets and send out an alert when the remaining budget is below a predefined number.  

6. - Statement: Users can request a statistical report of users’ financial state: monthly, quarterly, yearly income and expenses, the percentage of each type of income(salary, bonus, etc.) and expenses(food, transportation, etc.) so that users can view their financial states in a more systematic long-run perspective.
   - Assumptions: When the user types in a specific keyword to ask for a statistical report, the system opens the file containing records and retrieve information which was sorted by date, then calculate that monthly/quarterly/annual income/expense along with the percentage of each type and display them.  

7. - Statement: Users can check their accounts information at any time; account information includes credit card invoice, bank account balance, etc.; accounts information will be automatically updated each time the user adds ( or delete/edit) expense or income records. Therefore, users can hold a clear idea about each account's information timely and have a quick response to any significant change of the balance.
   - Assumptions: Each user has a file containing the account information(the initial account information should be stored in this file the time a user signs up). Each time the user adds (edit, delete) a record, the system automatically opens this account-information file and updates the account information. When the user types in a specific keyword to ask to check account information, the system opens this file and displays the contents.  

8. - Statement: Users can request a report of each day's balance(graphically) of the latest seven days so that the records of the most recent seven days can be represented more concisely and straightforwardly;
   - Assumptions: When user types in a specific keyword to ask for a late report, the system opens the file containing records and retrieves records of the latest seven days, then calculates each day's balance. The balance's value is then illustrated by the number of special characters(e.g., &, *).The report will be formed by listing the date and graphical balance of each day sequentially.
