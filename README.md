# ENGG1340-Group-2
## Group members: Li Jialong(3035533795) Wang Xinxin(3035533563)
### Our group project is expected to use digital tools to manage users' financial status. We target to build an accounting system to help people keep track of their income and expense. 

Before using the system: 
 - Use `make main` to compile the source files.
 - Use `./main` to execute the file.
 
 
0. Sign up and Sign in
   - Assumptions: When one user signs up, the system will require him/her to set a username and password, and create various files to keep track of the user's financial states. Later user can sign in the system using their username and password. Also, all the usernames and corresponding passwords are stored in a specific file. 
   - sign panel:
     ```
     1. sign up
     2. sign in
     3. exit
     ```
     1: Create a new account with respective username, password, and files attracting financial status;
     2: Enter accouting system if you already have an account;
     3: Exit the program.


Overall system panel:
```
1. Add
2. Check
3. Edit
4. Delete
5. Set Budget
6. Report
7. Latest
8. Accounts Information
9. Exit
```


1. - Add records
   - Statement: Users could add record which contains information like amount, date, types of income or expense (e.g., food, game, salary, etc.), account (e.g.cash, bank card, credit card, etc.) so that users can check their detailed transaction records later on. **Note that only 1 record can be added each time.**
   - Assumptions: When user types in 1, the system opens a file and writes in the record, the user will be asked to type in record's type, amount, date, and account information sequentially.
   - Format stored in *_records.txt*: yyyy mm dd -/+ Specific_Type 100.00 Account_Type 
   - (for more details about this function please refer to *Sample implementation.pdf*). 


2. - Check records
   - Statement: Users could view their records by date, type, and account so that users are able to look up for specific records by various information; **the system can also simply list recent records, given a valid upper limit.**
   - Assumptions: When user types in 2, the system opens the file containing the records and then searches for corresponding records according to the date/type/account the user input.
   - i.e., Search by: date   Search for: 01/03/2019
   - **All records found would be automatically numbered, which can be used for further check or delete and edit functions**
   - (for more details about this function please refer to *Sample implementation.pdf*). 
     
     
3. - Edit records
   - Statement: Users could edit any record at any time so that users are able to correct their mistakes when recording financial states.
   - Assumptions: When user types in 3, the system opens the file containing the records and receives input (record information of the record to be edited) from the user, search for the specific record in the file. Then, the user can change single or multiple dimension(s) of this record.
   - Sample dimension editing:
   ```
   2019 04 01 -            Breakfast      100     Cash
      1  2  3 4                    5        7        8
   ```
   - **Note that changing dimension 4 will automatically change dimension 5; this will also be informed when system runs**
   - (for more details about this function please refer to *Sample implementation.pdf*). 


4. - Delete records
   - Statement: Users could delete any record at any time so that users are able to correct their mistakes when recording financial states.
   - Assumptions: When user types in 4, the system opens the file containing the records and receives input (record information of the record to be edited) from the user, search for the specific record in the file. User can then select **single or multiple** records and delete them **by their coding.**
   - (for more details about this function please refer to *Sample implementation.pdf*). 
   
   
5. - Set Budget
   - Statement: Users can monthly reset the budget and edit it at any time. **The remain and total budget will be printed right above the system's main panel.** When expenses reach the budget, there will be an alert from the system. Hence, users can flexibly change their financial plan and make sure that the expenses will not be beyond expectations. **The system will also warn user when it detects that the newest record is no older than the date stored in _\_budget.txt_.**
   - Assumptions: Each user has a file containing budget information. The system allows users to add, reset and edit their total budgets. This feature can open the file containing records and retrieve information, then calculate the remaining budgets and send out an alert when the remaining budget is below a predefined number. 
   - Sample:
   `You don't have your budget yet. Please set a budget!`
   `Please set a budget for a new month!`
   `Remain Budget 200 / Total budget 500`
   - (for more details about this function please refer to *Sample implementation.pdf*). 
   
   
6. - Report
   - Statement: Users can request a statistical report of users’ financial state: monthly, yearly income and expenses, the percentage of each type of income(salary, bonus, etc.) and expenses(food, transportation, etc.) so that users can view their financial states in a more systematic long-run perspective.
   - Assumptions: When the user types in a specific keyword to ask for a statistical report, the system opens the file containing records and retrieve information which was sorted by date, then calculate that monthly/annual income/expense along with the percentage of each type and display them. 
   - Sample:
   ```
   Year report:
   total balance of this year: -400
   Total income: 0
   Total expense: 400
   
   Expense type / total expense:
   Breakfast            25.00% 100
   etc.
   Income type / total expense:
   Salary                0.00% 0.00
   etc.
   ```
   - (for more details about this function please refer to *Sample implementation.pdf*). 


Account Information
Statement: Users can request a report of each day's balance(graphically) of the latest seven days 
Assumptions: Each user has a file containing the account information(the initial account information should be stored in this file the time a user signs up). Each time the user adds (edit, delete) a record, the system automatically updates the account information.  The system will display the account information when users requests.
Sample:
Account information of user: 
Initial accounts information : 100 100 100
Cash -200
...
...
(for more details about this function please refer to Sample implementation.pdf)




8. - Statement: Users can request a report of each day's balance(graphically) of the latest seven days so that the records of the most recent seven days can be represented more concisely and straightforwardly;
   - Assumptions: When user types in a specific keyword to ask for a late report, the system opens the file containing records and retrieves records of the latest seven days, then calculates each day's balance. The balance's value is then illustrated by the number of special characters(e.g., &, *).The report will be formed by listing the date and graphical balance of each day sequentially.

### Remarks:

1.*Sample implementation.pdf* illustrates how nine main functions are implemented and the specific procedures to realize the features. Assessors can observe how our project performs without running the program through this document.   
2.*sample users information.zip* contains two users' account information, including records, accounts, budgets, and userinfo.txt(all users' usernames and passwords) . Assessors can test special functions(like further checking records ) based on these files.
