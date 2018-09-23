# Testing System
Judge system created as university project. System language is armenian so I'll use some translations.

# Information
Users can register and get full access to all the problems of the system. There is also admin user who can only add problems.

## Problems
Problem has title, description and testcases. Admin should provide the title, description, input and output formats, testcases and also should specify which of them are samples. After problem is created it is inserted into database.

## Users
After resgistration user can sign in to system. The opening window consists of problem list and user's solution history with every submission that user has done before.

## Sumbitting process
When the description of a problem is opened there should be a button "Submit". After clicking that the IDE would be opened. The IDE is created manually. Specifications are:
1. There is sidebar where the line index is shown
2. Has syntax highlighter // but only for Python language
And after writing and submittiong the code the checking process starts...

## Checking
When solution is submitted the process is created. It runs python code which checks for compilation errors in our solution. If there is error then message (trans. "compilation... There are some errors in code!") is shown and process is ended. If everything is OK then process runs another program which checks our solution over all the testcases of the problem. Then process ends and if all testcases passed successfully then the message is shown (trans. "Accepted... Solution was checked, all the testcases passed successfully"). If some of testcases were unsuccessful then also a message is shown (trans. "Near... Some of testcases didn't pass"). 
At this moment system can check solutions only in python language (if there are python files in users computer :D).

## Syntax highlighting
All the keywords and their styling rules are kept in xml file. There is also regexp rules for string and comment (also multiline) recognition, so the template should be the same for other languages and adding syntax highlighting for new languages will be a lot easier.

# Built With
* [QT C++](https://www.qt.io/download) - Whole code is written with this framework
* [SQLite](https://www.sqlite.org/index.html) - The database is kept in this format, there is no security but changing the database will not be problem as code works with database commands
