# ENGG1340-Group-2
Group members:
Li Jialong(3035533795)
Wang Xinxin(3035533563)

Our group project is expected to use digital tools to manage users' financial status. We target to build an accounting system to help people keep track of their income and expense. 

1)Multiple users can manage their financial status through this accounting system;
Assumptions:
When one user signs up, the system will require him/her to set a username and password, and automatically make a directory which contains various files to keep records of user's financial states. Later user can sign in the system using their own username and password. 
   
2)Users could add records which contain information like amount, date, types of income or expense (e.g., food, game, salary, etc.), account (e.g.cash, bank card, credit card, etc.) so that users can check their detailed transaction records later on ; 
Assumptions:
When user types in a specific keyword (e.g., add), the system calls a function which opens a file and receives input (record information) from the user, writes in the record, then function closes file before it ends.

3)Users could view their records by date, type, and account so that users are able to look up for specific records by various information; 
Assumptions:
When user types in a specific keyword (e.g., check), the system calls a function which opens the file containing the records and receives input from the user(date, type, account), then searches for corresponding records and print them out, closes file before it ends.

4)Users could delete and edit any record at any time so that users are able to correct their mistakes when recording financial states;
Assumptions:
When user types in a specific keyword (e.g., delete/edit), the system calls a function which opens a file and receives input (record information of the record to be deleted/edited) from the user, search for the specific record in that file. Then, the user can input another record to replace the original one(automatically replacing the original one with a empty record if the command was "delete").After that,the function closes that file before it ends.

5)Users could monthly reset the budget and edit it at any time. When expenses reach the budget, there will be an alert from the system. Hence, users can flexibly change their financial plan and make sure that the expenses will not be beyond expectations;
Assumptions:
In the directory of each user, there's a file containing the budget information. Particular functions are used to allow users to add, reset and edit their total budgets. Another function is used to open the file containing records and retrieve information, then calculate the remaining budgets and send out an alert when the remaining budget is below a predefined number.  

6)Users could request a statistical report of users’ financial state: monthly, quarterly, yearly income and expenses, the percentage of each type of income(salary, bonus, etc.) and expenses(food, transportation, etc.) so that users can view their financial states in a more systematic long-run perspective;
Assumptions:
When the user types in a specific keyword to ask for a statistical report, the system uses a function to open the file containing records and retrieve information which was sorted by date, then calculate that monthly/quarterly/annual income/expense along with the percentage of each type and display them.  

7)Users could check their accounts information at any time; account information includes credit card invoice, bank account balance, etc.; accounts information will be automatically updated each time the user adds ( or delete edit) expense or income records.Therefore, user can hold a clear idea about each account's information timely and have a quick response to any significant change of the balance;
Assumptions:
In the directory of each user, there's a file containing the account information(the initial account information should be stored in this file the time a user signs up). Each time the user adds (edit, delete) a record, the system also calls a function to open this account-information file and update the account information. When the user types in a specific keyword to ask to check account information, the system opens this file and displays the contents.  

8)Users could request a report of each day's balance(graphically) of the latest seven days so that the records of the most recent seven days can be represented more concisely and straightforwardly;
Assumptions:
When user types in a specific keyword to ask for a late report, the system calls a function that opens the file containing records and retrieves records of the latest seven days, then calculates each day's balance. The balance's value is then illustrated by the number of special characters(e.g., &, *).The report will be formed by listing the date and graphical balance of each day sequentially.
 
Keyword		-----			    function 
Add			-----			    add records
Check			-----	 	       view records by date, type, and account 
Delete		-----			    check and delete records
Edit			-----			    check and edit records
Setbudget	-----			    monthly budget resetting and editing at any time
Mreport/Qreport/Yreport ----- ask for monthly, quarterly, yearly report
Latest 			------		    request a report of each day's balance(graphically)


